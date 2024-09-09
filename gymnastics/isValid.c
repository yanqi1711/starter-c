//
// Created by yanqi on 2024/9/4.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char E;
struct LNode {
    E element;
    struct LNode* next;
};

typedef struct LNode* Node;

void initStack(Node head) {
    head->next = NULL;
}

bool pushStack(Node head, E element) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) return false;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return true;
}

bool isEmpty(Node head) {
    return head->next == NULL;
}

E popStack(Node head) {
    Node top = head->next;
    int tmp = top->element;
    head->next = head->next->next;
    free(top);
    return tmp;
}

bool isValid(char* s) {
    unsigned long len = strlen(s);
    if (len % 2 == 1) return false;
    struct LNode head;
    initStack(&head);
    for (int i = 0; i < len; ++i) {
        char c = s[i];
        if (c == '(' || c == '[' || c == '{') {
            pushStack(&head, c);
        } else {
            if (isEmpty(&head)) {
                return false;
            }
            if (c == ')') {
                if (popStack(&head) != '(') return false;
            } else if (c == ']') {
                if (popStack(&head) != '[') return false;
            } else {
                if (popStack(&head) != '{') return false;
            }
        }
    }
    return isEmpty(&head);
}