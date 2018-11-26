#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ADT_BST/ADT_BST.h"
#include "ADT_AVL/ADT_AVL.h"

#define STRINGSIZE 1000

int main(int argc, char *argv[])
{
  int i;

  FILE* sentences;
  FILE* words;
  FILE* output;

  int word_count = 0;

  int error_flag = 0;
  int factorFlagValue = 0;
  int *factorFlag = &factorFlagValue;
  int auxiliarValue;

  char *pointerString;
  char bufferString[STRINGSIZE];
  char auxiliarString[STRINGSIZE];
  char sentenceString[STRINGSIZE]; // used for reading the sentences
  const char separator_lex[4] = " \t\n";

  char *word_review;
  const char separator_sentences[3] = " \t";
  int sentiment = 0;
  BSTNode* aux_node_bst;
  AVLNode* aux_node_avl;

  BSTNode* bst_Tree;
  AVLNode* avl_Tree;

  bst_Tree = BST_initialize();
  avl_Tree = AVL_initialize();

  if(argc != 4)
  {
    printf("Wrong parameters. To call this program, type: application <lexicographicWordsFile> <sentencesFile> <outputFile>.");
    error_flag = 1;
  }
  else if((words = fopen(argv[1], "r")) == NULL)
  {
    printf("Error opening %s.", argv[1]);
    error_flag = 2;
  }
  else if((sentences = fopen(argv[2], "r")) == NULL)
  {
    printf("Error opening %s.", argv[2]);
    error_flag = 3;
  }
  else if((output = fopen(argv[3], "w")) == NULL)
  {
    printf("Error opening %s.", argv[3]);
    error_flag = 4;
  }
  else
  {
    while(fgets(auxiliarString, STRINGSIZE, words))
    {
      pointerString = strtok(auxiliarString, separator_lex);

      if(auxiliarString != NULL)
      {
        strcpy(bufferString, auxiliarString); // Saving word to use in insert.

        pointerString = strtok(NULL, separator_lex); // Word's value string.

        auxiliarValue = atoi(pointerString); // Converting string to value.

        bst_Tree = BST_insert(bst_Tree, bufferString, auxiliarValue);  // Inserting in BST.
        avl_Tree = AVL_insert(avl_Tree, bufferString, factorFlag, auxiliarValue);  // Inserting in AVL.

        word_count++; // Incrementing word count for future analysis
      }
    }

    // For each word in the sentences file
    while(fgets(sentenceString, STRINGSIZE, sentences))
    {
      strcpy(auxiliarString, sentenceString);

      // Deletes tab at the end of each sentence
      for(i = 0; auxiliarString[i]; i++){
        if(auxiliarString[i] == '\t')
        {
          if(auxiliarString[i+1] == '\n')
          {
            auxiliarString[i] = '\n';
            auxiliarString[i+1] = '\0';
          }
        }
      }

      // For each word in the sentence
      word_review = strtok(sentenceString, separator_sentences);
      while(word_review != NULL) {

        // Makes the whole string lowercase
        for(i = 0; word_review[i]; i++){
          word_review[i] = tolower(word_review[i]);
        }

        // Calculate sentiment (per word)
        aux_node_avl = AVL_search(avl_Tree, word_review);
        if(aux_node_avl != NULL)
          sentiment += aux_node_avl->value;

        // Get next word
        word_review = strtok(NULL, separator_sentences);
      }

      // Printing to file
      fprintf(output, "%d ", sentiment);
      fputs(auxiliarString, output);
      sentiment = 0;
    }

    printf("\nnumber of words: %d\n\n", word_count);

    printf("BST height: %d\n", BST_height(bst_Tree));
    printf("comp_insert_BST: %d\n", comp_insert_BST);
    printf("comp_search_BST: %d\n\n", comp_search_BST);

    printf("AVL height: %d\n", AVL_height(avl_Tree));
    printf("comp_insert_AVL: %d\n", comp_insert_AVL);
    printf("comp_search_AVL: %d\n\n", comp_search_AVL);

    //BST_print(bst_Tree, "PREORDERL");
  }

  // Cleaning up
  BST_destroy(bst_Tree);
  AVL_destroy(avl_Tree);

  // There could be errors opening one of the files, that's why testing for NULLs is needed
  if(words != NULL)
    fclose(words);
  if(sentences != NULL)
    fclose(sentences);
  if(output != NULL)
    fclose(output);

  return error_flag;
}
