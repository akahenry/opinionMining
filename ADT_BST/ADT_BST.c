#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ADT_BST.h"

int comp_insert_BST = 0;
int comp_search_BST = 0;

BSTNode* BST_initialize(void)
{
  return NULL;
}

BSTNode* BST_insert(BSTNode* tree, char *info, int value)
{
  comp_insert_BST++;
  if(tree)
  {
    comp_insert_BST++;
    if(strcmp(info,tree->info) > 0)
      tree->right = BST_insert(tree->right, info, value);
    else
      tree->left = BST_insert(tree->left, info, value);
  }
  else
  {
    tree = (BSTNode*)malloc(sizeof(BSTNode));
    strcpy(tree->info, info);
    tree->value = value;
    tree->right = NULL;
    tree->left = NULL;
  }

  return tree;
}

BSTNode* BST_remove(BSTNode* tree, char* info)
{
  BSTNode* answer = tree;
  BSTNode* temp;

  if(tree)  // If tree != NULL.
  {
    if(strcmp(info,tree->info) > 0)   // Checking in the right sub-tree.
    {
      tree->right = BST_remove(tree->right, info);
    }
    else if(strcmp(info,tree->info) < 0)    // Checking in the left sub-tree.
    {
      tree->left = BST_remove(tree->left, info);
    }
    else  // tree has the given info.
    {
      if(!tree->left)   // If tree->left == NULL.
      {
        temp = tree->right;
        answer = temp;
        free(tree);
      }
      else if(!tree->right)   // If tree->right == NULL.
      {
        temp = tree->left;
        answer = temp;
        free(tree);
      }
      else    // tree has two sub-trees
      {
        temp = BST_maxNode(tree->left);   // Finding the maximum key node.
        strcpy(tree->info, temp->info);   // Putting the temp->info in the tree->info.
        tree->value = temp->value;
        tree->left = BST_remove(tree->left, temp->info);  // Deleting the node which has the same temp->info, as we already have changed the nodes.
        answer = tree;
      }
    }
  }

  return answer;
}

BSTNode* BST_search(BSTNode* tree, char* info)
{
  BSTNode* answer = NULL;  // Initializing return.

  comp_search_BST++;
  if(tree)  // If tree isn't a NULL pointer, it must check the info.
  {
    comp_search_BST++;
    if(strcmp(info,tree->info) == 0)
      answer = tree;   // answer = info
    else
    {
      comp_search_BST++;
      if(strcmp(info,tree->info) > 0)   // If info is greater than info's tree, the answer will be the result of right search.
        answer = BST_search(tree->right, info);
      else                    // Else, it must be the result of left search.
        answer = BST_search(tree->left, info);
    }
  }

  return answer;
}

BSTNode* BST_maxNode(BSTNode* tree)
{
  BSTNode* answer = tree;

  if(tree)
  {
    if(tree->right)
      answer = BST_maxNode(tree->right);
  }

  return answer;
}

int BST_height(BSTNode* tree)
{
  int right = 0;
  int left = 0;
  if(tree == NULL)
    return 0;
  else
  {
    right = BST_height(tree->right);
    left = BST_height(tree->left);
    if(right > left)
      return 1 + right;
    else
      return 1 + left;
  }
}

int BST_print(BSTNode* tree, char* operation)
{
  int answer = 1;

  if(tree)
  {
    if(strcmp(operation, "PREORDER") == 1)
    {
      answer = BST_pre_order(tree, operation[8]);
    }
    else if(strcmp(operation, "POSTORDER") == 1)
    {
      answer = BST_post_order(tree, operation[9]);
    }
    else if(strcmp(operation, "INORDER") == 1)
    {
      answer = BST_in_order(tree, operation[6]);
    }
    else
      answer--;
  }
  else
    printf("Empty tree.\n");

  return answer;
}

int BST_pre_order(BSTNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    BST_pre_orderL(tree, 1);
  else if(side == 'R')
    BST_pre_orderR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void BST_pre_orderL(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);

      BST_pre_orderL(tree->left, aux+1);
      BST_pre_orderL(tree->right, aux+1);
    }
  }
  else
  {
    printf("%s\n", tree->info);

    BST_pre_orderL(tree->left, aux);
    BST_pre_orderL(tree->right, aux);
  }
}

void BST_pre_orderR(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);

      BST_pre_orderR(tree->right, aux+1);
      BST_pre_orderR(tree->left, aux+1);
    }
  }
  else
  {
    printf("%s\n", tree->info);

    BST_pre_orderR(tree->right, aux);
    BST_pre_orderR(tree->left, aux);
  }
}

int BST_post_order(BSTNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    BST_post_orderL(tree, 1);
  else if(side == 'R')
    BST_post_orderR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void BST_post_orderL(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      BST_post_orderL(tree->left, aux+1);
      BST_post_orderL(tree->right, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);
    }
  }
  else
  {
    BST_post_orderL(tree->left, aux);
    BST_post_orderL(tree->right, aux);

    printf("%s\n", tree->info);
  }
}

void BST_post_orderR(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      BST_post_orderR(tree->right, aux+1);
      BST_post_orderR(tree->left, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);
    }
  }
  else
  {
    BST_post_orderR(tree->right, aux);
    BST_post_orderR(tree->left, aux);

    printf("%s\n", tree->info);
  }
}

int BST_in_order(BSTNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    BST_in_orderL(tree, 1);
  else if(side == 'R')
    BST_in_orderR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void BST_in_orderL(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      BST_in_orderL(tree->left, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);

      BST_in_orderL(tree->right, aux+1);
    }
  }
  else
  {
    BST_in_orderL(tree->left, aux);

    printf("%s\n", tree->info);

    BST_in_orderL(tree->right, aux);
  }
}

void BST_in_orderR(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      BST_in_orderR(tree->right, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);

      BST_in_orderR(tree->left, aux+1);
    }
  }
  else
  {
    BST_in_orderR(tree->right, aux);

    printf("%s\n", tree->info);

    BST_in_orderR(tree->left, aux);
  }
}

BSTNode* BST_destroy(BSTNode* tree)
{
  if(tree)
  {
    BST_destroy(tree->left);
    BST_destroy(tree->right);
    free(tree);
  }

  return NULL;
}
