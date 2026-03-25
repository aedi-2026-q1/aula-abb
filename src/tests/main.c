#include <stdio.h>

#include "bst.h"

// redefine a node here just for testing purposes




int main() {
    BST* bst = bst_create();

    bst_insert(bst, 5);
    bst_insert(bst, 3);
    bst_insert(bst, 7);
    bst_insert(bst, 2);
    bst_insert(bst, 4);
    bst_insert(bst, 6);
    bst_insert(bst, 8);

    bst_print_in_order(bst);

    bst_destroy(bst);

    return 0;
}