typedef struct STR_BSTNode
{
  char info[50];
  int value;
  struct STR_BSTNode *left;
  struct STR_BSTNode *right;
}BSTNode;

/// BST_initialize: void -> BSTNode*
/* Returns a NULL pointer */
BSTNode* BST_initialize(void);

/// BST_insertion: BSTNode* char* int -> BSTNode*
/* Inserts a new node in the tree, returning the new tree with it. */
BSTNode* BST_insertion(BSTNode* tree, char* info, int value);

/// BST_remove: BSTNode* char* -> BSTNode*
/* Given an info and a tree, it returns another tree without the node which had this info. */
BSTNode* BST_remove(BSTNode* tree, char* info);

/// BST_consult: BSTNode* char* -> BSTNode*
/* Given an info and a tree, it returns a pointer to a node which has this info. If there isn't a info with this info, returns NULL. */
BSTNode* BST_consult(BSTNode* tree, char* info);

/// BST_maxNode: BSTNode* -> BSTNode*
/* Given a tree, this function returns a node which has the maximum key value. */
BSTNode* BST_maxNode(BSTNode* tree);

/// BST_print: BSTNode* char* -> int
/* Given a tree and a string, if given string is:
    - "PREFIXEDL": it prints according pre-fixed left algorythm.
    - "POSTFIXEDL": it prints according post-fixed left algorythm.
    - "CENTERL": it prints according center left algorythm.
    - "PREFIXEDR": it prints according pre-fixed right algorythm.
    - "POSTFIXEDR": it prints according post-fixed right algorythm.
    - "CENTERR": it prints according center right algorythm.
  This function uses three others functions:
    - BST_prefixed
    - BST_postfixed
    - BST_centerside
  If the given string isn't valid, the function returns 0. Else, returns 1. */
int BST_print(BSTNode* tree, char* operation);

/// BST_prefixed: BSTNode* char -> int
/* Given a tree and a char, it prints the tree according pre-fixed algorythm.
   According the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - BST_prefixedL
      - BST_prefixedR*/
int BST_prefixed(BSTNode* tree, char side);

/// BST_prefixedL: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according pre-fixed left algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_prefixedL(BSTNode* tree, int aux);

/// BST_prefixedR: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according pre-fixed right algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_prefixedR(BSTNode* tree, int aux);

/// BST_postfixed: BSTNode* char -> int
/* Given a tree and a char, it prints the tree according post-fixed algorythm.
   According the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - BST_postfixedL
      - BST_postfixedR*/
int BST_postfixed(BSTNode* tree, char side);

/// BST_postfixedL: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according post-fixed left algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_postfixedL(BSTNode* tree, int aux);

/// BST_postfixedR: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according post-fixed right algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_postfixedR(BSTNode* tree, int aux);

/// BST_centerside: BSTNode* char -> int
/* Given a tree and a char, it prints the tree according center-side algorythm.
   According the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - BST_centerL
      - BST_centerR*/
int BST_centerside(BSTNode* tree, char side);

/// BST_centerL: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according center-left algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_centerL(BSTNode* tree, int aux);

/// BST_centerR: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according center-right algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_centerR(BSTNode* tree, int aux);

/// BST_destroy: BSTNode* -> BSTNode*
/* Given a tree, this function destroys it releasing used memory. */
BSTNode* BST_destroy(BSTNode* tree);
