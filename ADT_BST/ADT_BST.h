typedef struct STR_BSTNode
{
  char info[50];
  int value;
  struct STR_BSTNode *left;
  struct STR_BSTNode *right;
}BSTNode;

// Global variables used to count comparisons, that are used to compare performances
int comp_insert_BST;
int comp_search_BST;

/// BST_initialize: void -> BSTNode*
/* Returns a NULL pointer */
BSTNode* BST_initialize(void);

/// BST_insert: BSTNode* char* int -> BSTNode*
/* Inserts a new node in the tree, returning the new tree with it. */
BSTNode* BST_insert(BSTNode* tree, char* info, int value);

/// BST_remove: BSTNode* char* -> BSTNode*
/* Given an info and a tree, it returns another tree without the node which had this info. */
BSTNode* BST_remove(BSTNode* tree, char* info);

/// BST_search: BSTNode* char* -> BSTNode*
/* Given an info and a tree, it returns a pointer to a node which has this info. If there isn't a node with this info, returns NULL. */
BSTNode* BST_search(BSTNode* tree, char* info);

/// BST_maxNode: BSTNode* -> BSTNode*
/* Given a tree, this function returns a node which has the maximum key value. */
BSTNode* BST_maxNode(BSTNode* tree);

/// BST_height: BSTNode* -> int
/* Returns the height of a BST */
int BST_height(BSTNode* tree);

/// BST_print: BSTNode* char* -> int
/* Given a tree and a string, if given string is:
    - "PREORDERL": prints according to the left pre-order traversal algorythm.
    - "POSTORDERL": prints according to the left post-order traversal algorythm.
    - "INORDERL": prints according to the left in-order traversal algorythm.
    - "PREORDERR": prints according to the right pre-order traversal algorythm.
    - "POSTORDERR": prints according to the right post-order traversal algorythm.
    - "INORDERR": prints according to the right in-order traversal algorythm.
  This function uses three others functions:
    - BST_pre_order
    - BST_post_order
    - BST_in_order
  If the given string isn't valid, the function returns 0. Else, returns 1. */
int BST_print(BSTNode* tree, char* operation);

/// BST_pre_order: BSTNode* char -> int
/* Given a tree and a char, it prints the tree according to the pre-order traversal algorythm.
   According the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - BST_pre_orderL
      - BST_pre_orderR*/
int BST_pre_order(BSTNode* tree, char side);

/// BST_pre_orderL: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the left pre-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_pre_orderL(BSTNode* tree, int aux);

/// BST_pre_orderR: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the right pre-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_pre_orderR(BSTNode* tree, int aux);

/// BST_post_order: BSTNode* char -> int
/* Given a tree and a char, it prints the tree according to the post-order algorythm.
   According to the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - BST_post_orderL
      - BST_post_orderR*/
int BST_post_order(BSTNode* tree, char side);

/// BST_post_orderL: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the post-order left algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_post_orderL(BSTNode* tree, int aux);

/// BST_post_orderR: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the post-order right algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_post_orderR(BSTNode* tree, int aux);

/// BST_in_order: BSTNode* char -> int
/* Given a tree and a char, it prints the tree according to the in-order traversal algorythm.
   According the char:
      - 'L': left algorythm and returns 1.
      - 'R': right algorythm and returns 1.
      - Any other char: returns 0.
   This function uses two others functions:
      - BST_in_orderL
      - BST_in_orderR */
int BST_in_order(BSTNode* tree, char side);

/// BST_in_orderL: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the left in-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_in_orderL(BSTNode* tree, int aux);

/// BST_in_orderR: BSTNode* int -> void
/* Given a tree and an auxiliar parameter, it prints the tree according to the right in-order traversal algorythm.
   Aux could be:
      - 0: will print number above number.
      - 1: will print the tree "like stairs". */
void BST_in_orderR(BSTNode* tree, int aux);

/// BST_destroy: BSTNode* -> BSTNode*
/* Given a tree, this function destroys it releasing used memory. */
BSTNode* BST_destroy(BSTNode* tree);
