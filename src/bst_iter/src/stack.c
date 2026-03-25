#include "stack.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode {
    StackElement value;
    struct StackNode* next;
} StackNode;

struct Stack {
    StackNode* top;
    size_t size;
};

void stack_error(const char* message) {
    fprintf(stderr, "Stack error: %s\n", message);
}

Stack* stack_create() {
    Stack* stack = malloc(sizeof(Stack));
    stack->top = NULL;
    stack->size = 0;

    return stack;
}

void stack_destroy(Stack* stack) {
    StackNode* cur = stack->top;

    while (cur != NULL) {
        StackNode* trash = cur;
        cur = cur->next;
        free(trash);
    }

    free(stack);
}

bool stack_push(Stack* stack, StackElement value) {
    StackNode* new_node = malloc(sizeof(StackNode));

    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;

    return true;
}

StackElement stack_pop(Stack* stack) {
    if (stack_is_empty(stack)) {
        stack_error("Stack empty");

        return NULL;
    }

    StackNode* trash = stack->top;
    StackElement value = trash->value;

    stack->top = trash->next;
    free(trash);
    stack->size--;

    return value;
}

StackElement stack_peek(Stack* stack) {
    if (stack_is_empty(stack)) {
        stack_error("Stack empty");

        return NULL;
    }

    return stack->top->value;
}

bool stack_is_empty(Stack* stack) {
    return stack->top == NULL;
}

size_t stack_size(Stack* stack) {
    return stack->size;
}

void stack_print(Stack* stack) {
    StackNode* cur = stack->top;

    while (cur != NULL) {
        stack_element_print(cur->value);
        printf(" ");
        cur = cur->next;
    }

    printf("\n");
}
