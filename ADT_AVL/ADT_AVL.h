typedef struct STR_AVLNode
{
  char info[50];
  int balanceFactor;
  int value;
  struct STR_AVLNode *left;
  struct STR_AVLNode *right;
}AVLNode;

// Global variables used to count comparisons, that are used to compare performances
int comp_insert_AVL;
int comp_search_AVL;

/// AVL_initialize: void -> AVLNode*
/* Returns a NULL pointer */
AVLNode* AVL_initialize(void);

/// AVL_insert: AVLNode* char* int* int -> AVLNode*
/* Inserts a new node in the given AVL tree, returning the new AVL tree with it.
   This function uses 4 others functions to balance the new tree:
    - AVL_rotateLeft
    - AVL_rotateRight
    - AVL_double_rotateLeft
    - AVL_double_rotateRight */
AVLNode* AVL_insert(AVLNode* tree, char *info, int* flag, int value);

/// AVL_rotateLeft: AVLNode* -> AVLNode*
/* Rotate the tree to the left, usually to balance it. */
AVLNode* AVL_rotateLeft(AVLNode* tree);

/// AVL_rotateRight: AVLNode* -> AVLNode*
/* Rotate the tree to the right, usually to balance it. */
AVLNode* AVL_rotateRight(AVLNode* tree);

/// AVL_double_rotateLeft: AVLNode* -> AVLNode*
/* Double rotate the tree to the left, usually to balance it.
   Basically, this functions does first a right rotate with the right child of the given tree and,
   then, a left rotate. Therefore, this function uses two others functions:
    - AVL_rotateRight
    - AVL_rotateLeft  */
AVLNode* AVL_double_rotateLeft(AVLNode* tree);

/// AVL_double_rotateRight: AVLNode* -> AVLNode*
/* Double rotate to right, usually to balance it.
   Basically, this functions does first a left rotate with the right child of the given tree and,
   then, a right rotate. Therefore, this function uses two others functions:
    - AVL_rotateLeft
    - AVL_rotateRight */
AVLNode* AVL_double_rotateRight(AVLNode* tree);

/// AVL_remove: AVLNode* char* -> AVLNode*
/* Given an info and a tree, it returns another tree without the node which had this info. */
AVLNode* AVL_remove(AVLNode* tree, char *info);

/// AVL_search: AVLNode* char* -> AVLNode*
/* Given an info and a tree, it returns a pointer to a node which has this info. If there isn't a info with this info, returns NULL. */
AVLNode* AVL_search(AVLNode* tree, char *info);

/// AVL_maxNode: AVLNode* -> AVLNode*
/* Given a tree, this function returns a node which has the maximum key value. */
AVLNode* AVL_maxNode(AVLNode* tree);

/// AVL_height: AVLNode* -> int
/* Returns the height of an AVL */
int AVL_height(AVLNode* tree);

/// AVL_print: AVLNode* char* -> int
/* Given a tree and a string, if given string is:
    - "PREORDERL": prints according to the left pre-order traversal algorythm.
    - "POSTORDERL": prints according to the left post-order traversal algorythm.
    - "INORDERL": prints according to the left center traversal algorythm.
    - "PREORDERR": prints according to the right pre-order traversal algorythm.
    - "POSTORDERR": prints according to the right post-order traversal algorythm.
    - "CENTERR": prints according to the right center traversal algorythm.
  This function uses three others functions:
    - AVL_pre_order
    - AVL_post_order
    - AVL_in_order
  If the given string isn't valid, the function returns 0. Else, returns 1. */
int AVL_print(AVLNode* tree, char* operation);

/// AVL_pre_order: AVLNode* char -> int
/* Given a tree and a char, it prints the tree according to the pre-order traversal algorythm.
   According to the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - AVL_pre_orderL
      - AVL_pre_orderR*/
int AVL_pre_order(AVLNode* tree, char side);

/// AVL_pre_orderL: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the left pre-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_pre_orderL(AVLNode* tree, int aux);

/// AVL_pre_orderR: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the right pre-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_pre_orderR(AVLNode* tree, int aux);

/// AVL_post_order: AVLNode* char -> int
/* Given a tree and a char, it prints the tree according to the post-order traversal algorythm.
   According to the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - AVL_post_orderL
      - AVL_post_orderR*/
int AVL_post_order(AVLNode* tree, char side);

/// AVL_post_orderL: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the left post-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_post_orderL(AVLNode* tree, int aux);

/// AVL_post_orderR: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the right post-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_post_orderR(AVLNode* tree, int aux);

/// AVL_in_order: AVLNode* char -> int
/* Given a tree and a char, it prints the tree according to the in-order traversal algorythm.
   According to the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - AVL_in_orderL
      - AVL_in_orderR*/
int AVL_in_order(AVLNode* tree, char side);

/// AVL_in_orderL: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the left in-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_in_orderL(AVLNode* tree, int aux);

/// AVL_centerR: AVLNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the right in-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void AVL_in_orderR(AVLNode* tree, int aux);

/// AVL_destroy: AVLNode* -> AVLNode*
/* Given a tree, this function destroys it releasing used memory. */
AVLNode* AVL_destroy(AVLNode* tree);
