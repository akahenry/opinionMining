#include <stdio.h>
#include <stdlib.h>

#include "ADT_AVL.h"

int main()
{
  AVLNode *tree, *auxTree;
  int op, aux, flag;

  tree = AVL_initialize();  // Initializing tree

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
        tree = AVL_initialize();
        break;

      case 2:
        printf("Enter with a value to put in the tree: ");
        scanf("%d", &aux);

        tree = AVL_insertion(tree, aux, &flag);
        break;

      case 3:
        printf("Enter with a value to consult: ");
        scanf("%d", &aux);

        auxTree = AVL_consult(tree, aux);

        if(auxTree && aux == auxTree->info)
          printf("Value is in the tree.\n");
        else
          printf("Value isn't in the tree.\n");

        break;

      case 4:
        printf("1 - Pre-fixed left.\n");
        printf("2 - Pre-fixed right.\n");
        printf("3 - Post-fixed left.\n");
        printf("4 - Post-fixed right.\n");
        printf("5 - Center-left.\n");
        printf("6 - Center-right.\n");
        scanf("%d", &aux);

        switch(aux)
        {
          case 1:
            AVL_print(tree, "PREFIXEDL");
            break;

          case 2:
            AVL_print(tree, "PREFIXEDR");
            break;

          case 3:
            AVL_print(tree, "POSTFIXEDL");
            break;

          case 4:
            AVL_print(tree, "POSTFIXEDR");
            break;

          case 5:
            AVL_print(tree, "CENTERL");
            break;

          case 6:
            AVL_print(tree, "CENTERR");
            break;

          default:
            printf("Error! Try again.\n");
            break;
        }

        break;

      case 5:
        printf("Enter a value which you want to delete: ");
        scanf("%d", &aux);

        tree = AVL_remove(tree, aux);
        break;

      case 6:
        tree = AVL_destroy(tree);

        printf("Tree destroyed.\n");
        break;

      case 0:
        AVL_destroy(tree);
        break;

      default:
        system("CLS");
        break;
    }
  }while(op != 0);

  return 0;
}
