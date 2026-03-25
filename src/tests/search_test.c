#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#include "element.h"

typedef struct BSTNode {
    Element key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* node_create(Element key) {
    BSTNode* node = malloc(sizeof(BSTNode));

    node->key = key;
    node->left = NULL;
    node->right = NULL;

    return node;
}

BSTNode* createTree() {
    BSTNode* root = node_create(50);
    root->left = node_create(43);
    root->left->left = node_create(3);
    root->left->right = node_create(48);
    root->left->right->left = node_create(45);
    root->right = node_create(61);
    root->right->left = node_create(58);
    root->right->right = node_create(70);

    return root;
}

void destroy_tree(BSTNode* root) {
    if (root->left != NULL) {
        destroy_tree(root->left);
    }
    if (root->right != NULL) {
        destroy_tree(root->right);
    }
    free(root);
}

bool bst_searchNode(BSTNode* node, Element key) {
    if (node == NULL) {
        return false;
    }
    if (node->key == key) {
        return true;
    }
    if (key < node->key) {
        return bst_searchNode(node->left, key);
    } 
    
    return bst_searchNode(node->right, key);
}

int main() {
    BSTNode* root = createTree();
    Element contains[] = {50, 43, 3, 48, 45, 61, 58, 70};
    Element notContains[] = {0, 1, 2, 4, 5, 6, 7, 8, 9, 10, 90, 100};

    for (int i = 0; i < 8; i++) {
        printf("%d: %sfound\n", contains[i], bst_searchNode(root, contains[i]) ? "" : "not ");
    }

    for (int i = 0; i < 12; i++) {
        printf("%d: %sfound\n", notContains[i], bst_searchNode(root, notContains[i]) ? "" : "not ");
    }

    destroy_tree(root);


    return 0;
}

