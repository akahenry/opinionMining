#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ADT_BST/ADT_BST.h"
#include "ADT_AVL/ADT_AVL.h"

#define STRINGSIZE 1000


int main(int argc, char *argv[])
{
  FILE* sentences;
  FILE* words;
  FILE* output;

  int word_count = 0;

  int flag = 0;
  int factorFlagValue = 0;
  int *factorFlag = &factorFlagValue;
  int auxiliarValue;

  char *pointerString;
  char bufferString[STRINGSIZE];
  char auxiliarString[STRINGSIZE];
  char separateChars[3] = "\t\n";

  BSTNode* bst_Tree;
  AVLNode* avl_Tree;

  bst_Tree = BST_initialize();
  avl_Tree = AVL_initialize();

  if(argc != 4)
  {
    printf("Wrong parameters. To call this program, type: application <lexicographicWordsFile> <sentencesFile> <outputFile>.");
    flag = 1;
  }
  else
  {
    words = fopen(argv[1], "r");

    if(words == NULL)
    {
      printf("Error to open %s.", argv[1]);
      flag = 1;
    }
    else
    {
      sentences = fopen(argv[2], "r");

      if(sentences == NULL)
      {
        printf("Error to open %s.", argv[2]);
        flag = 1;
      }
      else
      {
        output = fopen(argv[2], "w");

        if(output == NULL)
        {
          printf("Error to open %s.", argv[3]);
          flag = 1;
        }
        else
        {
          while(fgets(auxiliarString, STRINGSIZE, words))
          {
            pointerString = strtok(auxiliarString, separateChars);

            if(auxiliarString != NULL)
            {
              strcpy(bufferString, auxiliarString); // Saving word to use in insertion.

              pointerString = strtok(NULL, separateChars); // Word's value string.

              auxiliarValue = atoi(pointerString); // Converting string to value.

              bst_Tree = BST_insertion(bst_Tree, bufferString, auxiliarValue);  // Inserting in BST.
              avl_Tree = AVL_insertion(avl_Tree, bufferString, factorFlag, auxiliarValue);  // Inserting in AVL.

              word_count++; // Incrementing word count for future analysis
            }
          }
        }
      }
    }
  }

  printf("number of words: %d\n", word_count);
  printf("BST height: %d\n", BST_height(bst_Tree));
  printf("AVL height: %d\n", AVL_height(avl_Tree));

  return flag;
}
