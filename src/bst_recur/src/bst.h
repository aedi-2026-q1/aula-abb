#ifndef BST_H
#define BST_H

#include <stdbool.h>

#include "element.h"

typedef struct BST BST;

BST* bst_create();
void bst_destroy(BST* bst);
bool bst_search(BST* bst, Element key);
void bst_insert(BST* bst, Element key);
void bst_remove(BST* bst, Element key);
void bst_print_in_order(BST* bst);
void bst_print_pre_order(BST* bst);
void bst_print_post_order(BST* bst);
void bst_print_tree(BST* bst);

#endif