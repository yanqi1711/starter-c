//
// Created by yanqi on 2024/8/12.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Stack {
    E *array;
    int capacity;
    int top; // 表示栈顶元素的位置
};

typedef struct Stack *ArrayStack;

_Bool arrayStack_init(ArrayStack stack) {
    stack->array = malloc(sizeof(E) * 10);
    if (stack->array == NULL) return 0;
    stack->capacity = 10;
    stack->top = -1;
    return 1;
}

// todo
_Bool arrayStack_push(ArrayStack stack, E element) {
    if (stack->top+ 1 == stack->capacity) {
        int newCapacity = stack->capacity + (stack->capacity >> 1);
        E *newArray = realloc(stack->array, sizeof(E) * newCapacity);
        if (newArray == NULL) return 0;
        stack->array = newArray;
        stack->capacity = newCapacity;
    }
    stack->array[stack->top + 1] = element;
    stack->top++;
    return 1;
}

_Bool arrayStack_isEmpty(ArrayStack stack) {
    return stack->top == -1;
}

E arrayStack_pop(ArrayStack stack) {
    return stack->array[stack->top--];
}

void arrayStack_print(ArrayStack stack) {
    printf("| ");
    for (int i = 0; i <= stack->top; ++i) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");

}

// int main() {
//     struct Stack stack;
//     arrayStack_init(&stack);
//     for (int i = 1; i <= 10; ++i) {
//         arrayStack_push(&stack, i * 100);
//     }
//     arrayStack_print(&stack);
//     while (!arrayStack_isEmpty(&stack)) {
//         printf("%d ", arrayStack_pop(&stack));
//     }
//     return 0;
// }