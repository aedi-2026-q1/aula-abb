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

bool bst_insert(BST* bst, BSTElement key) {
    if (bst->root == NULL) { // empty tree
        bst->root = node_create(key);

        return true;
    }

    BSTNode* parent = NULL;
    BSTNode* cur = bst->root;    

    while (cur != NULL) { // non-empty tree, find the parent leaf
        if (cur->key == key) {
            return false;
        } else if (key < cur->key) {
            parent = cur;
            cur = cur->left;
        } else {
            parent = cur;
            cur = cur->right;
        }
    }

    if (key < parent->key) { // insert in the leaf node
        parent->left = node_create(key);
    } else {
        parent->right = node_create(key);
    }

    return true;
}

void bst_remove_iter(BST* bst, BSTElement key) {
    BSTNode* parent = NULL;
    BSTNode* cur = bst->root;

    while (cur != NULL) {
        if (cur->key == key) {
            break;
        } else if (key < cur->key) {
            parent = cur;
            cur = cur->left;
        } else {
            parent = cur;
            cur = cur->right;
        }
    }

    if (cur == NULL) {
        return;
    }

    if (cur->left == NULL) {
        if (parent == NULL) {
            bst->root = cur->right;
        } else if (parent->left == cur) {
            parent->left = cur->right;
        } else {
            parent->right = cur->right;
        }
        free(cur);
    } else if (cur->right == NULL) {
        if (parent == NULL) {
            bst->root = cur->left;
        } else if (parent->left == cur) {
            parent->left = cur->left;
        } else {
            parent->right = cur->left;
        }
        free(cur);
    } else {
        BSTNode* successor = cur->right;
        parent = cur;

        while (successor->left != NULL) {
            parent = successor;
            successor = successor->left;
        }

        cur->key = successor->key;

        if (parent->left == successor) {
            parent->left = successor->right;
        } else {
            parent->right = successor->right;
        }

        free(successor);
    }
}

void bst_remove(BST* bst, BSTElement key) {
    bst_remove_iter(bst, key);
}

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

typedef struct TreePrintFrame {
    BSTNode* node;
    int level;
    struct TreePrintFrame* next;
} TreePrintFrame;

void bst_print_tree(BST* bst) {
    if (bst->root == NULL) {
        return;
    }

    TreePrintFrame* frames = malloc(sizeof(TreePrintFrame));
    frames->node = bst->root;
    frames->level = 0;
    frames->next = NULL;

    while (frames != NULL) {
        TreePrintFrame* current = frames;
        BSTNode* node = current->node;
        int level = current->level;

        frames = current->next;
        free(current);

        for (int i = 0; i < level; i++) {
            printf("  ");
        }
        bst_element_print(node->key);
        printf("\n");

        if (node->right != NULL) {
            TreePrintFrame* right = malloc(sizeof(TreePrintFrame));
            right->node = node->right;
            right->level = level + 1;
            right->next = frames;
            frames = right;
        }

        if (node->left != NULL) {
            TreePrintFrame* left = malloc(sizeof(TreePrintFrame));
            left->node = node->left;
            left->level = level + 1;
            left->next = frames;
            frames = left;
        }
    }
}