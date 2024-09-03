//
// Created by yanqi on 2024/8/12.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct LNode {
    E element;
    struct LNode *next;
};

typedef struct LNode *Node;

void linkedStack_init(Node stack) {
    stack->next = NULL;
}

_Bool linkedStack_push(Node head, E element) {
    Node node = malloc(sizeof(struct LNode)); //创建新的结点
    if (node == NULL) return 0; //失败就返回0
    node->next = head->next; //将当前结点的下一个设定为头结点的下一个
    node->element = element; //设置元素
    head->next = node; //将头结点的下一个设定为当前结点
    return 1;
}

_Bool linkedStack_isEmpty(Node head) {
    return head->next == NULL; //判断栈是否为空只需要看头结点下一个是否为NULL即可
}

E linkedStack_pop(Node head) {
    Node top = head->next;
    head->next = head->next->next;
    E e = top->element;
    free(top); //别忘了释放结点的内存
    return e; //返回出栈元素
}

void linkedStack_print(Node head) {
    printf("| ");
    head = head->next;
    while (head) {
        printf("%d ", head->element);
        head = head->next;
    }
    printf("\n");
}

// int main() {
//     struct LNode stack;
//     linkedStack_init(&stack);
//     linkedStack_push(&stack, 1);
//     linkedStack_push(&stack, 2);
//     linkedStack_push(&stack, 3);
//     linkedStack_print(&stack);
//     printf("%d\n", linkedStack_pop(&stack));
//     linkedStack_print(&stack);
//     return 0;
// }
