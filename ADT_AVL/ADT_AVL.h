typedef struct STR_AVLNode
{
  char info[50];
  int balanceFactor;
  int value;
  struct STR_AVLNode *left;
  struct STR_AVLNode *right;
}AVLNode;

/// AVL_initialize: void -> AVLNode*
/* Returns a NULL pointer */
AVLNode* AVL_initialize(void);

/// AVL_insertion: AVLNode* char* int* int -> AVLNode*
/* Inserts a new node in the given AVL tree, returning the new AVL tree with it.
   This function uses 4 others functions to balance the new tree:
    - AVL_rotateLeft
    - AVL_rotateRight
    - AVL_double_rotateLeft
    - AVL_double_rotateRight */
AVLNode* AVL_insertion(AVLNode* tree, char *info, int* flag, int value);

/// AVL_rotateLeft: AVLNode* -> AVLNode*
/* Rotate to left the tree, usually to balance it. */
AVLNode* AVL_rotateLeft(AVLNode* tree);

/// AVL_rotateRight: AVLNode* -> AVLNode*
/* Rotate to right the tree, usually to balance it. */
AVLNode* AVL_rotateRight(AVLNode* tree);

/// AVL_double_rotateLeft: AVLNode* -> AVLNode*
/* Double rotate to left, usually to balance it.
   Basically, this functions does first a right rotate with the right child of the given tree and
  , then, a left rotate. Therefore, this function uses two others functions:
    - AVL_rotateRight
    - AVL_rotateLeft  */
AVLNode* AVL_double_rotateLeft(AVLNode* tree);

/// AVL_double_rotateRight: AVLNode* -> AVLNode*
/* Double rotate to right, usually to balance it.
   Basically, this functions does first a left rotate with the right child of the given tree and
  , then, a right rotate. Therefore, this function uses two others functions:
    - AVL_rotateLeft
    - AVL_rotateRight */
AVLNode* AVL_double_rotateRight(AVLNode* tree);

/// AVL_remove: AVLNode* char* -> AVLNode*
/* Given an info and a tree, it returns another tree without the node which had this info. */
AVLNode* AVL_remove(AVLNode* tree, char *info);

/// AVL_consult: AVLNode* char* -> AVLNode*
/* Given an info and a tree, it returns a pointer to a node which has this info. If there isn't a info with this info, returns NULL. */
AVLNode* AVL_consult(AVLNode* tree, char *info);

/// AVL_maxNode: AVLNode* -> AVLNode*
/* Given a tree, this function returns a node which has the maximum key value. */
AVLNode* AVL_maxNode(AVLNode* tree);

/// AVL_print: AVLNode* char* -> int
/* Given a tree and a string, if given string is:
    - "PREFIXEDL": it prints according pre-fixed left algorythm.
    - "POSTFIXEDL": it prints according post-fixed left algorythm.
    - "CENTERL": it prints according center left algorythm.
    - "PREFIXEDR": it prints according pre-fixed right algorythm.
    - "POSTFIXEDR": it prints according post-fixed right algorythm.
    - "CENTERR": it prints according center right algorythm.
  This function uses three others functions:
    - AVL_prefixed
    - AVL_postfixed
    - AVL_centerside
  If the given string isn't valid, the function returns 0. Else, returns 1. */
int AVL_print(AVLNode* tree, char* operation);

/// AVL_prefixed: AVLNode* char -> int
/* Given a tree and a char, it prints the tree according pre-fixed algorythm.
   According the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - AVL_prefixedL
      - AVL_prefixedR*/
int AVL_prefixed(AVLNode* tree, char side);

/// AVL_prefixedL: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according pre-fixed left algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_prefixedL(AVLNode* tree, int aux);

/// AVL_prefixedR: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according pre-fixed right algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_prefixedR(AVLNode* tree, int aux);

/// AVL_postfixed: AVLNode* char -> int
/* Given a tree and a char, it prints the tree according post-fixed algorythm.
   According the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - AVL_postfixedL
      - AVL_postfixedR*/
int AVL_postfixed(AVLNode* tree, char side);

/// AVL_postfixedL: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according post-fixed left algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_postfixedL(AVLNode* tree, int aux);

/// AVL_postfixedR: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according post-fixed right algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_postfixedR(AVLNode* tree, int aux);

/// AVL_centerside: AVLNode* char -> int
/* Given a tree and a char, it prints the tree according center-side algorythm.
   According the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - AVL_centerL
      - AVL_centerR*/
int AVL_centerside(AVLNode* tree, char side);

/// AVL_centerL: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according center-left algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_centerL(AVLNode* tree, int aux);

/// AVL_centerR: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according center-right algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_centerR(AVLNode* tree, int aux);

/// AVL_destroy: AVLNode* -> AVLNode*
/* Given a tree, this function destroys it releasing used memory. */
AVLNode* AVL_destroy(AVLNode* tree);
