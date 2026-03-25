#ifndef NODE_H
#define NODE_H

#include "bst_element.h"

typedef struct BSTNode {
    BSTElement key;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

BSTNode* node_create(BSTElement key);


#endif