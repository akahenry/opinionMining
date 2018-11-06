#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ADT_BST.h"


BSTNode* BST_initialize(void)
{
  return NULL;
}

BSTNode* BST_insertion(BSTNode* tree, char *info, int value)
{
  if(tree)
  {
    if(strcmp(info,tree->info) > 0)
      tree->right = BST_insertion(tree->right, info, value);
    else
      tree->left = BST_insertion(tree->left, info, value);
  }
  else
  {
    tree = malloc(sizeof(BSTNode));
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

BSTNode* BST_consult(BSTNode* tree, char* info)
{
  BSTNode* answer = NULL;  // Initializing return.

  if(tree)  // If tree isn't a NULL pointer, it must check the info.
  {
    if(strcmp(info,tree->info) == 0)
      answer = tree;   // answer = info
    else
    {
      if(strcmp(info,tree->info) > 0)   // If info is greater than info's tree, the answer will be the result of right consult.
        answer = BST_consult(tree->right, info);
      else                    // Else, it must be the result of left consult.
        answer = BST_consult(tree->left, info);
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

int BST_print(BSTNode* tree, char* operation)
{
  int answer = 1;

  if(tree)
  {
    if(strcmp(operation, "PREFIXED") == 1)
    {
      answer = BST_prefixed(tree, operation[8]);
    }
    else if(strcmp(operation, "POSTFIXED") == 1)
    {
      answer = BST_postfixed(tree, operation[9]);
    }
    else if(strcmp(operation, "CENTER") == 1)
    {
      answer = BST_centerside(tree, operation[6]);
    }
    else
      answer--;
  }
  else
    printf("Empty tree.\n");

  return answer;
}

int BST_prefixed(BSTNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    BST_prefixedL(tree, 1);
  else if(side == 'R')
    BST_prefixedR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void BST_prefixedL(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);

      BST_prefixedL(tree->left, aux+1);
      BST_prefixedL(tree->right, aux+1);
    }
  }
  else
  {
    printf("%s\n", tree->info);

    BST_prefixedL(tree->left, aux);
    BST_prefixedL(tree->right, aux);
  }
}

void BST_prefixedR(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);

      BST_prefixedR(tree->right, aux+1);
      BST_prefixedR(tree->left, aux+1);
    }
  }
  else
  {
    printf("%s\n", tree->info);

    BST_prefixedR(tree->right, aux);
    BST_prefixedR(tree->left, aux);
  }
}

int BST_postfixed(BSTNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    BST_postfixedL(tree, 1);
  else if(side == 'R')
    BST_postfixedR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void BST_postfixedL(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      BST_postfixedL(tree->left, aux+1);
      BST_postfixedL(tree->right, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);
    }
  }
  else
  {
    BST_postfixedL(tree->left, aux);
    BST_postfixedL(tree->right, aux);

    printf("%s\n", tree->info);
  }
}

void BST_postfixedR(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      BST_postfixedR(tree->right, aux+1);
      BST_postfixedR(tree->left, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);
    }
  }
  else
  {
    BST_postfixedR(tree->right, aux);
    BST_postfixedR(tree->left, aux);

    printf("%s\n", tree->info);
  }
}

int BST_centerside(BSTNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    BST_centerL(tree, 1);
  else if(side == 'R')
    BST_centerR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void BST_centerL(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      BST_centerL(tree->left, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);

      BST_centerL(tree->right, aux+1);
    }
  }
  else
  {
    BST_centerL(tree->left, aux);

    printf("%s\n", tree->info);

    BST_centerL(tree->right, aux);
  }
}

void BST_centerR(BSTNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      BST_centerR(tree->right, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      printf("%s\n", tree->info);

      BST_centerR(tree->left, aux+1);
    }
  }
  else
  {
    BST_centerR(tree->right, aux);

    printf("%s\n", tree->info);

    BST_centerR(tree->left, aux);
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
