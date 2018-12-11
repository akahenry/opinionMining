#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ADT_AVL.h"

int comp_insert_AVL = 0;
int comp_search_AVL = 0;

AVLNode* AVL_initialize(void)
{
  return NULL;
}

AVLNode* AVL_insert(AVLNode* tree, char *info, int* flag, int value)
{
  comp_insert_AVL++;
  if(tree)
  {
    comp_insert_AVL++;
    if(strcmp(info, tree->info) > 0)
    {
      tree->right = AVL_insert(tree->right, info, flag, value);   // Inserts node

      comp_insert_AVL++;
      if(*flag) // If flag != 0
      {
        comp_insert_AVL++;
        if(tree->balanceFactor == -1)  // It'll be a problem 'cause we'll decrement it and the factor will be -2.
        {
          comp_insert_AVL++;
          if(tree->right->balanceFactor == -1)   // If right child has -1 as factor, just a rotate to left fixes it.
            tree = AVL_rotateLeft(tree);
          else                                  // Else, a double rotate to left will fixes it (double rotate left = rotate right && rotate left, in this order).
            tree = AVL_double_rotateLeft(tree);

          tree->balanceFactor = 0;            // Now, the tree is balanced and everything is fine.
          *flag = 0;
        }
        else
        {
          comp_insert_AVL++;
          if(tree->balanceFactor == 1)
            *flag = 0;

          tree->balanceFactor--;  // Only decrement it 'cause we are inserting a node in the right tree.
        }
      }
    }
    else
    {
      tree->left = AVL_insert(tree->left, info, flag, value);   // Inserts node

      comp_insert_AVL++;
      if(*flag) // If flag != 0
      {
        comp_insert_AVL++;
        if(tree->balanceFactor == 1)  // It'll be a problem 'cause we'll increcrement it and the factor will be 2.
        {
          comp_insert_AVL++;
          if(tree->left->balanceFactor == 1)   // If right child has 1 as factor, just a rotate to right fixes it.
            tree = AVL_rotateRight(tree);
          else                                  // Else, a double rotate to right will fixes it (double rotate right = rotate left && rotate right, in this order).
            tree = AVL_double_rotateRight(tree);

          tree->balanceFactor = 0;            // Now, the tree is balanced and everything is fine.
          *flag = 0;
        }
        else
        {
          comp_insert_AVL++;
          if(tree->balanceFactor == -1)
            *flag = 0;

          tree->balanceFactor++;  // Only increment it 'cause we are inserting a node in the left tree.
        }
      }
    }
  }
  else  // The tree is NULL
  {
    tree = (AVLNode*)malloc(sizeof(AVLNode));
    strcpy(tree->info, info);
    tree->value = value;
    tree->right = NULL;
    tree->left = NULL;
    tree->balanceFactor = 0;
    *flag = 1;
  }
  return tree;
}

AVLNode* AVL_rotateLeft(AVLNode* tree)
{
  AVLNode* auxiliar;

  auxiliar = tree->right;
  tree->right = auxiliar->left;
  auxiliar->left = tree;
  tree->balanceFactor = 0;
  tree = auxiliar;

  return tree;
}

AVLNode* AVL_rotateRight(AVLNode* tree)
{
  AVLNode* auxiliar;

  auxiliar = tree->left;
  tree->left = auxiliar->right;
  auxiliar->right = tree;
  tree->balanceFactor = 0;
  tree = auxiliar;

  return tree;
}

AVLNode* AVL_double_rotateLeft(AVLNode* tree)
{
  tree->right = AVL_rotateRight(tree->right);
  tree = AVL_rotateLeft(tree);

  return tree;
}

AVLNode* AVL_double_rotateRight(AVLNode* tree)
{
  tree->left = AVL_rotateLeft(tree->left);
  tree = AVL_rotateRight(tree);

  return tree;
}

AVLNode* AVL_remove(AVLNode* tree, char *info)
{
  AVLNode* answer = tree;
  AVLNode* temp;

  if(tree)  // If tree != NULL.
  {
    if(strcmp(info, tree->info) > 0)   // Checking in the right sub-tree.
    {
      tree->right = AVL_remove(tree->right, info);
    }
    else if(strcmp(info, tree->info) < 0)    // Checking in the left sub-tree.
    {
      tree->left = AVL_remove(tree->left, info);
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
        temp = AVL_maxNode(tree->left);   // Finding the maximum key node.
        strcpy(tree->info, temp->info);      // Putting the temp->info in the tree->info.
        tree->left = AVL_remove(tree->left, temp->info);  // Deleting the node which has the same temp->info, as we already have changed the nodes.
        answer = tree;
      }
    }
  }

  return answer;
}

AVLNode* AVL_search(AVLNode* tree, char *info)
{
  AVLNode* answer = NULL;  // Initializing return.

  comp_search_AVL++;
  if(tree)  // If tree isn't a NULL pointer, it must check the info.
  {
    comp_search_AVL++;
    if(strcmp(info, tree->info) == 0)
      answer = tree;   // answer = info
    else
    {
      comp_search_AVL++;
      if(strcmp(info,tree->info) > 0)   // If info is greater than info's tree, the answer will be the result of right search.
        answer = AVL_search(tree->right, info);
      else                    // Else, it must be the result of left search.
        answer = AVL_search(tree->left, info);
    }
  }

  return answer;
}

AVLNode* AVL_maxNode(AVLNode* tree)
{
  AVLNode* answer = tree;

  if(tree)
  {
    if(tree->right)
      answer = AVL_maxNode(tree->right);
  }

  return answer;
}

int AVL_height(AVLNode* tree)
{
    int right = 0;
    int left = 0;
    if(tree == NULL)
      return 0;
    else
    {
      right = AVL_height(tree->right);
      left = AVL_height(tree->left);
      if(right > left)
        return 1 + right;
      else
        return 1 + left;
    }
}

int AVL_print(AVLNode* tree, char* operation)
{
  int answer = 1;

  if(tree)
  {
    if(strcmp(operation, "PREFIXED") == 1)
    {
      answer = AVL_pre_order(tree, operation[8]);
    }
    else if(strcmp(operation, "POSTFIXED") == 1)
    {
      answer = AVL_post_order(tree, operation[9]);
    }
    else if(strcmp(operation, "CENTER") == 1)
    {
      answer = AVL_in_order(tree, operation[6]);
    }
    else
      answer--;
  }
  else
    printf("Empty tree.\n");

  return answer;
}

int AVL_pre_order(AVLNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    AVL_pre_orderL(tree, 1);
  else if(side == 'R')
    AVL_pre_orderR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void AVL_pre_orderL(AVLNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      puts(tree->info);

      AVL_pre_orderL(tree->left, aux+1);
      AVL_pre_orderL(tree->right, aux+1);
    }
  }
  else
  {
    puts(tree->info);

    AVL_pre_orderL(tree->left, aux);
    AVL_pre_orderL(tree->right, aux);
  }
}

void AVL_pre_orderR(AVLNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      puts(tree->info);

      AVL_pre_orderR(tree->right, aux+1);
      AVL_pre_orderR(tree->left, aux+1);
    }
  }
  else
  {
    puts(tree->info);

    AVL_pre_orderR(tree->right, aux);
    AVL_pre_orderR(tree->left, aux);
  }
}

int AVL_post_order(AVLNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    AVL_post_orderL(tree, 1);
  else if(side == 'R')
    AVL_post_orderR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void AVL_post_orderL(AVLNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      AVL_post_orderL(tree->left, aux+1);
      AVL_post_orderL(tree->right, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      puts(tree->info);
    }
  }
  else
  {
    AVL_post_orderL(tree->left, aux);
    AVL_post_orderL(tree->right, aux);

    puts(tree->info);
  }
}

void AVL_post_orderR(AVLNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      AVL_post_orderR(tree->right, aux+1);
      AVL_post_orderR(tree->left, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      puts(tree->info);
    }
  }
  else
  {
    AVL_post_orderR(tree->right, aux);
    AVL_post_orderR(tree->left, aux);

    puts(tree->info);
  }
}

int AVL_in_order(AVLNode* tree, char side)
{
  int answer = 1;

  if(side == 'L')
    AVL_in_orderL(tree, 1);
  else if(side == 'R')
    AVL_in_orderR(tree, 1);
  else
    answer--;   // Answer = 0;

  return answer;
}

void AVL_in_orderL(AVLNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      AVL_in_orderL(tree->left, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      puts(tree->info);

      AVL_in_orderL(tree->right, aux+1);
    }
  }
  else
  {
    AVL_in_orderL(tree->left, aux);

    puts(tree->info);

    AVL_in_orderL(tree->right, aux);
  }
}

void AVL_in_orderR(AVLNode* tree, int aux)
{
  int i; // Counter

  if(aux)   // If aux == 0, won't print the "stairs".
  {
    if(tree)
    {
      AVL_in_orderR(tree->right, aux+1);

      for(i = 0; i < aux; i++)  // Printing the "stairs".
        printf("=");

      puts(tree->info);

      AVL_in_orderR(tree->left, aux+1);
    }
  }
  else
  {
    AVL_in_orderR(tree->right, aux);

    puts(tree->info);

    AVL_in_orderR(tree->left, aux);
  }
}

AVLNode* AVL_destroy(AVLNode* tree)
{
  if(tree)
  {
    AVL_destroy(tree->left);
    AVL_destroy(tree->right);
    free(tree);
  }

  return NULL;
}
