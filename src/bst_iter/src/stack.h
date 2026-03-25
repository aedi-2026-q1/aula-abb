#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

#include "stack_element.h"

typedef struct Stack Stack;

Stack* stack_create(void);
void stack_destroy(Stack* stack);
bool stack_push(Stack* stack, StackElement value);
StackElement stack_pop(Stack* stack);
StackElement stack_peek(Stack* stack);
bool stack_is_empty(Stack* stack);
size_t stack_size(Stack* stack);
void stack_print(Stack* stack);

#endif