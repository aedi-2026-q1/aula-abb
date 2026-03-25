#include "bst.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "bst_node.h"
#include "stack.h"

struct BST {
    BSTNode* root;
};

BST* bst_create() {
    BST* bst = malloc(sizeof(BST));

    bst->root = NULL;

    return bst;
}

void bst_destroy(BST* bst) {
    Stack* stack = stack_create();
    Stack* postorder = stack_create();

    if (bst->root != NULL) {
        stack_push(stack, bst->root);
    }

    while (!stack_is_empty(stack)) {
        BSTNode* node = stack_pop(stack);

        stack_push(postorder, node);

        if (node->left != NULL) {
            stack_push(stack, node->left);
        }
        if (node->right != NULL) {
            stack_push(stack, node->right);
        }
    }

    while (!stack_is_empty(postorder)) {
        BSTNode* node = stack_pop(postorder);
        free(node);
    }

    stack_destroy(stack);
    stack_destroy(postorder);
    free(bst);
}

bool bst_search(BST* bst, BSTElement key) {
    BSTNode* cur = bst->root;

    while (cur != NULL) {
        if (cur->key == key) {
            return true;
        } else if (key < cur->key) {
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }

    return false;
}

// TODO: Implement bst_insert, bst_remove 

void bst_print_in_order(BST* bst) {
    Stack* stack = stack_create();
    BSTNode* cur = bst->root;

    while (cur != NULL || !stack_is_empty(stack)) {
        while (cur != NULL) {
            stack_push(stack, cur);
            cur = cur->left;
        }

        cur = stack_pop(stack);
        bst_element_print(cur->key);
        printf(" ");
        cur = cur->right;
    }

    stack_destroy(stack);
    printf("\n");
}

void bst_print_pre_order(BST* bst) {
    Stack* stack = stack_create();

    if (bst->root != NULL) {
        stack_push(stack, bst->root);
    }

    while (!stack_is_empty(stack)) {
        BSTNode* node = stack_pop(stack);

        bst_element_print(node->key);
        printf(" ");

        if (node->right != NULL) {
            stack_push(stack, node->right);
        }
        if (node->left != NULL) {
            stack_push(stack, node->left);
        }
    }

    stack_destroy(stack);
    printf("\n");
}

void bst_print_post_order(BST* bst) {
    Stack* stack = stack_create();
    Stack* postorder = stack_create();

    if (bst->root != NULL) {
        stack_push(stack, bst->root);
    }

    while (!stack_is_empty(stack)) {
        BSTNode* node = stack_pop(stack);

        stack_push(postorder, node);

        if (node->left != NULL) {
            stack_push(stack, node->left);
        }
        if (node->right != NULL) {
            stack_push(stack, node->right);
        }
    }

    while (!stack_is_empty(postorder)) {
        BSTNode* node = stack_pop(postorder);
        bst_element_print(node->key);
        printf(" ");
    }

    stack_destroy(stack);
    stack_destroy(postorder);
    printf("\n");
}