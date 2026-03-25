#include "stack_element.h"

#include <stdio.h>

void stack_element_print(StackElement element) {
    if (element == NULL) {
        printf("NULL");
    } else {
        bst_element_print(element->key);
    }
}