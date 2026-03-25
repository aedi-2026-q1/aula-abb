#include "bst_node.h"

#include <stdlib.h>

BSTNode* node_create(BSTElement key) {
    BSTNode* newNode = malloc(sizeof(BSTNode));

    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}