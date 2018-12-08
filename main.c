#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#include "ADT_BST/ADT_BST.h"
#include "ADT_AVL/ADT_AVL.h"

#define STRINGSIZE 1000
#define INPUTPY  "python_input.txt"

int main(int argc, char *argv[])
{
  int i;

  FILE* sentences;
  FILE* words;
  FILE* output;
  FILE* pythonInput;

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

  SYSTEMTIME auxiliarTime;
  long bst_milliseconds, avl_milliseconds, T0ms, T1ms;

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
  else if((pythonInput = fopen(INPUTPY, "w")) == NULL)
  {
    printf("Error opening %s.", INPUTPY);
    error_flag = 5;
  }
  else
  {
    /// AVL Mode
    // Initializing T0 to calculate how many milliseconds it took
    GetSystemTime(&auxiliarTime);
    T0ms = (auxiliarTime.wSecond*1000) + auxiliarTime.wMilliseconds;

    // Inserting in the tree the words of lexic file.
    while(fgets(auxiliarString, STRINGSIZE, words))
    {
      pointerString = strtok(auxiliarString, separator_lex);

      if(auxiliarString != NULL)
      {
        strcpy(bufferString, auxiliarString); // Saving word to use in insert.

        pointerString = strtok(NULL, separator_lex); // Word's value string.

        auxiliarValue = atoi(pointerString); // Converting string to value.

        avl_Tree = AVL_insert(avl_Tree, bufferString, factorFlag, auxiliarValue);  // Inserting in AVL.

        word_count++; // Incrementing word count for future analysis
      }
    }

    // For each word in the sentences file
    while(fgets(sentenceString, STRINGSIZE, sentences))
    {
      strcpy(auxiliarString, sentenceString);

      // Deletes tab at the end of each sentence
      for(i = 0; auxiliarString[i]; i++)
      {
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
      while(word_review != NULL)
      {

        // Makes the whole string lowercase
        for(i = 0; word_review[i]; i++)
          word_review[i] = tolower(word_review[i]);

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
    // Setting T1 to calculate the time taken with AVL Mode.
    GetSystemTime(&auxiliarTime);
    T1ms = (auxiliarTime.wSecond*1000) + auxiliarTime.wMilliseconds;
    avl_milliseconds = T1ms - T0ms;

    // Reinitializing to use in BST mode.
    rewind(sentences);
    rewind(output);
    rewind(words);


    /// BST Mode
    // Initializing T0 to calculate how many milliseconds it took
    GetSystemTime(&auxiliarTime);
    T0ms = (auxiliarTime.wSecond*1000) + auxiliarTime.wMilliseconds;

    // Inserting in the tree the words of lexic file.
    while(fgets(auxiliarString, STRINGSIZE, words))
    {
      pointerString = strtok(auxiliarString, separator_lex);

      if(auxiliarString != NULL)
      {
        strcpy(bufferString, auxiliarString); // Saving word to use in insert.

        pointerString = strtok(NULL, separator_lex); // Word's value string.

        auxiliarValue = atoi(pointerString); // Converting string to value.

        bst_Tree = BST_insert(bst_Tree, bufferString, auxiliarValue);  // Inserting in AVL.
      }
    }

    // For each word in the sentences file
    while(fgets(sentenceString, STRINGSIZE, sentences))
    {
      strcpy(auxiliarString, sentenceString);

      // Deletes tab at the end of each sentence
      for(i = 0; auxiliarString[i]; i++)
      {
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
      while(word_review != NULL)
      {

        // Makes the whole string lowercase
        for(i = 0; word_review[i]; i++)
          word_review[i] = tolower(word_review[i]);

        // Calculate sentiment (per word)
        aux_node_bst = BST_search(bst_Tree, word_review);

        if(aux_node_bst != NULL)
          sentiment += aux_node_bst->value;

        // Get next word
        word_review = strtok(NULL, separator_sentences);
      }
      sentiment = 0;
    }
    // Setting T1 to calculate the time taken with BST Mode.
    GetSystemTime(&auxiliarTime);
    T1ms = (auxiliarTime.wSecond*1000) + auxiliarTime.wMilliseconds;
    bst_milliseconds = T1ms - T0ms;

    printf("\nnumber of words: %d\n\n", word_count);

    printf("BST height: %d\n", BST_height(bst_Tree));
    printf("comp_insert_BST: %d\n", comp_insert_BST);
    printf("comp_search_BST: %d\n", comp_search_BST);
    printf("bst_milliseconds: %li\n\n", bst_milliseconds);

    printf("AVL height: %d\n", AVL_height(avl_Tree));
    printf("comp_insert_AVL: %d\n", comp_insert_AVL);
    printf("comp_search_AVL: %d\n", comp_search_AVL);
    printf("avl_milliseconds: %li\n\n", avl_milliseconds);

    // Writing in pythonInput
    fprintf(pythonInput, "amount_of_data %d\n", word_count);
    fprintf(pythonInput, "BST_height %d\n", BST_height(bst_Tree));
    fprintf(pythonInput, "AVL_height %d\n", AVL_height(avl_Tree));
    fprintf(pythonInput, "comp_insert_BST %d\n", comp_insert_BST);
    fprintf(pythonInput, "comp_insert_AVL %d\n", comp_insert_AVL);
    fprintf(pythonInput, "comp_search_BST %d\n", comp_search_BST);
    fprintf(pythonInput, "comp_search_AVL %d\n", comp_search_AVL);
    fprintf(pythonInput, "BST_time %li\n", bst_milliseconds);
    fprintf(pythonInput, "AVL_time %li\n", avl_milliseconds);
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
  if(pythonInput != NULL)
    fclose(pythonInput);

  return error_flag;
}
