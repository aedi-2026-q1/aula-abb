#include "bst.h"

#include <stdio.h>

int main(void) {
    BST* bst = bst_create();

    // int values[] = {5, 3, 7, 2, 4, 6, 8};
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8}; 

    for (int i = 0; i < 7; i++) {
        bst_insert(bst, values[i]);
    }

    bst_print_in_order(bst);
    printf("\n");
    bst_print_tree(bst);

    bst_destroy(bst);

    return 0;
}