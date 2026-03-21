#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * WARNING:
 * - This code is only for testing the search functions, so it is not optimized for memory management (e.g., no free() calls)
 * - The tree is hardcoded for testing purposes 
 * - Later, we will implement a more robust ADT (Abstract Data Type) approach
 */

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;

/** @brief Allocates and initializes a new tree node. */
Node* node_create(int key) {
    Node* node = malloc(sizeof(Node));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/** @brief Builds the fixed BST used by the search tests. */
Node* createTree() {
    Node* root = node_create(50);
    root->left = node_create(43);
    root->left->left = node_create(3);
    root->left->right = node_create(48);
    root->left->right->left = node_create(45);
    root->right = node_create(61);
    root->right->left = node_create(58);
    root->right->right = node_create(70);

    return root;
}

/** @brief Searches for a key in the BST using recursion. */
bool bst_search_recur(Node* node, int key) {
    if (node == NULL) {
        return false;
    }
    if (node->key == key) {
        return true;
    }
    if (key < node->key) {
        return bst_search_recur(node->left, key);
    } 
    
    return bst_search_recur(node->right, key);
}

/** @brief Searches for a key in the BST using iteration. */
bool bst_search_iter(Node* node, int key) {
    while (node != NULL) {
        if (node->key == key) {
            return true;
        }
        if (key < node->key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }
    return false;
}

/** @brief Runs simple output-based tests for both search versions. */
int main() {
    Node* root = createTree();
    int contains[] = {50, 43, 3, 48, 45, 61, 58, 70};
    int notContains[] = {0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 90, 100};

    printf("Testing recursive search:\n");

    for (int i = 0; i < 8; i++) {
        printf("%d: %sfound\n", contains[i], bst_search_recur(root, contains[i]) ? "" : "not ");
    }

    for (int i = 0; i < 12; i++) {
        printf("%d: %sfound\n", notContains[i], bst_search_recur(root, notContains[i]) ? "" : "not ");
    }

    printf("\nTesting iterative search:\n");

    for (int i = 0; i < 8; i++) {
        printf("%d: %sfound\n", contains[i], bst_search_iter(root, contains[i]) ? "" : "not ");
    }

    for (int i = 0; i < 12; i++) {
        printf("%d: %sfound\n", notContains[i], bst_search_iter(root, notContains[i]) ? "" : "not ");
    }


    return 0;
}

