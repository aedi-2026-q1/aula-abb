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

void bst_printDiagram(BSTNode* node, int level) {
  if (node == NULL) {
      return;
  }
  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  element_print(node->key);
  printf("\n");
  bst_printDiagram(node->left, level + 1);  
  bst_printDiagram(node->right, level + 1);
}

int main() {
    BSTNode* root = createTree();
    bst_printDiagram(root, 0);
    return 0;
}