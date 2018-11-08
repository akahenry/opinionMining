#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ADT_BST.h"

int main()
{
  BSTNode *tree, *auxTree;
  int op, auxiliar;
  char bufferString[100];


  tree = BST_initialize();  // Initializing tree

  do
  {
    printf("1 - Initialize tree.\n");
    printf("2 - Add node.\n");
    printf("3 - Consult node.\n");
    printf("4 - Draw tree.\n");
    printf("5 - Delete a node.\n");
    printf("6 - Destroy tree.\n");
    printf("0 - Exit.\n");
    printf("Any other option will clear the screen.\n");
    scanf("%d", &op);

    switch(op)
    {
      case 1:
        tree = BST_initialize();
        break;

      case 2:
        printf("Enter with a string to put in the tree: ");
        fflush(stdin);
        gets(bufferString);

        tree = BST_insertion(tree, bufferString, 0);
        break;

      case 3:
        printf("Enter with a string to consult: ");
        fflush(stdin);
        gets(bufferString);

        auxTree = BST_consult(tree, bufferString);

        if(auxTree && strcmp(bufferString, auxTree->info) == 0)
          printf("String is in the tree.\n");
        else
          printf("String isn't in the tree.\n");

        break;

      case 4:
        printf("1 - Pre-fixed left.\n");
        printf("2 - Pre-fixed right.\n");
        printf("3 - Post-fixed left.\n");
        printf("4 - Post-fixed right.\n");
        printf("5 - Center-left.\n");
        printf("6 - Center-right.\n");
        scanf("%d", &auxiliar);

        switch(auxiliar)
        {
          case 1:
            BST_print(tree, "PREFIXEDL");
            break;

          case 2:
            BST_print(tree, "PREFIXEDR");
            break;

          case 3:
            BST_print(tree, "POSTFIXEDL");
            break;

          case 4:
            BST_print(tree, "POSTFIXEDR");
            break;

          case 5:
            BST_print(tree, "CENTERL");
            break;

          case 6:
            BST_print(tree, "CENTERR");
            break;

          default:
            printf("Error! Try again.\n");
            break;
        }

        break;

      case 5:
        printf("Enter a string which you want to delete: ");
        fflush(stdin);
        gets(bufferString);

        tree = BST_remove(tree, bufferString);
        break;

      case 6:
        tree = BST_destroy(tree);

        printf("Tree destroyed.\n");
        break;

      case 0:
        BST_destroy(tree);
        break;

      default:
        system("CLS");
        break;
    }
  }while(op != 0);

  return 0;
}
