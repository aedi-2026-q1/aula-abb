// #include <stdio.h>

// #include "bst.h"

// void print_tree(BST* bst) {
//     printf("In-Order: ");
//     bst_print_in_order(bst);
//     printf("Pre-Order:\n");
//     bst_print_tree(bst);
// }

// int main() {
//     BST* bst = bst_create();
//     int valid_keys[] = {5, 3, 7, 2, 4, 6, 8};
//     int invalid_keys[] = {0, 1, 9};

//     for (int i = 0; i < 7; i++) {
//         bst_insert(bst, valid_keys[i]);
//     }

//     for (int i = 0; i < 7; i++) {
//         printf("%d: %s\n", valid_keys[i], bst_search(bst, valid_keys[i]) ? "true" : "false");
//     }

//     for (int i = 0; i < 3; i++) {
//         printf("%d: %s\n", invalid_keys[i], bst_search(bst, invalid_keys[i]) ? "true" : "false");
//     }

//     print_tree(bst);

//     bst_destroy(bst);
//     return 0;
// }