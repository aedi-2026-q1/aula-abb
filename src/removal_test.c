// #include "bst.h"

// int main() {
//     BST* bst = bst_create();
//     int insertSeq[] = {5, 3, 8, 2, 4, 7, 9, 1, 6};
//     int removeSeq[] = {6, 1, 4, 7, 2, 3, 9, 8, 5};

//     for (int i = 0; i < 9; i++) {
//         bst_insert(bst, insertSeq[i]);
//     }
//     bst_print_in_order(bst);

//     for (int i = 0; i < 9; i++) {
//         bst_remove(bst, removeSeq[i]);
//         bst_print_in_order(bst);
//     }

//     bst_destroy(bst);

//     return 0;
// }