#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    Element key;
    struct Node* left;
    struct Node* right;
} Node;

struct BST {
    Node* root;
};

Node* node_create(Element key) {
    Node* new_node = malloc(sizeof(Node));

    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}


BST* bst_create() {
    BST* bst = malloc(sizeof(BST));

    bst->root = NULL;

    return bst;
}

void bst_destroy_recur(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL) {
        bst_destroy_recur(node->left);
    }
    if (node->right != NULL) {
        bst_destroy_recur(node->right);
    }
    free(node);
}

void bst_destroy(BST* bst) {
    bst_destroy_recur(bst->root);
    free(bst);
}

bool bst_search_recur(Node* node, Element key) {
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

bool bst_search(BST* bst, Element key) {
    return bst_search_recur(bst->root, key);
}

Node* bst_insert_recur(Node* node, Element key) {
    if (node == NULL) {
        return node_create(key);
    }
    if (key < node->key) {
        node->left = bst_insert_recur(node->left, key);
    } else if (key > node->key) {
        node->right = bst_insert_recur(node->right, key);
    }

    return node;
}

void bst_insert(BST* bst, Element key) {
    bst->root = bst_insert_recur(bst->root, key);
}

Node* bst_successor(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->left == NULL) {
        return node;
    }

    return bst_successor(node->left);
}

Node* bst_remove_recur(Node* node, Element key) {
    if (node == NULL) {
        return node;
    }
    if (key < node->key) {
        node->left = bst_remove_recur(node->left, key);
    } else if (key > node->key) {
        node->right = bst_remove_recur(node->right, key);
    } else {
        if (node->left == NULL) {
            Node* trash = node;

            node = node->right;
            free(trash);
        } else if (node->right == NULL) {
            Node* trash = node;

            node = node->left;
            free(trash);
        } else {
            Node* temp = bst_successor(node->right);

            node->key = temp->key;
            node->right = bst_remove_recur(node->right, temp->key);
        }
    }

    return node;
}

void bst_remove(BST* bst, Element key) {
    bst->root = bst_remove_recur(bst->root, key);
}

void bst_print_in_order_recur(Node* node) {
    if (node == NULL) {
        return;
    }
    bst_print_in_order_recur(node->left);
    element_print(node->key);
    printf(" ");
    bst_print_in_order_recur(node->right);
}

void bst_print_in_order(BST* bst) {
    bst_print_in_order_recur(bst->root);
    printf("\n");
}

void print_pre_order_recur(Node* node) {
    if (node == NULL) {
        return;
    }
    element_print(node->key);
    printf(" ");
    print_pre_order_recur(node->left);
    print_pre_order_recur(node->right);
}

void bst_print_pre_order(BST* bst) {
    print_pre_order_recur(bst->root);
    printf("\n");
}

void print_post_order_recur(Node* node) {
    if (node == NULL) {
        return;
    }
    print_post_order_recur(node->left);
    print_post_order_recur(node->right);
    element_print(node->key);
    printf(" ");
}

void bst_print_post_order(BST* bst) {
    print_post_order_recur(bst->root);
    printf("\n");
}

void bst_print_tree_recur(Node* node, int level) {
  if (node == NULL) {
      return;
  }
  for (int i = 0; i < level; i++) {
    printf("  ");
  }
  element_print(node->key);
  printf("\n");
  bst_print_tree_recur(node->left, level + 1);  
  bst_print_tree_recur(node->right, level + 1);
}

void bst_print_tree(BST* bst) {
  bst_print_tree_recur(bst->root, 0);
}