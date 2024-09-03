//
// Created by yanqi on 2024/8/29.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int E;

struct LNode {
    E element;
    struct LNode *next;
};

typedef struct LNode *Node;

struct Queue {
    Node front, rear;
};

typedef struct Queue *LinkedQueue;

bool linkedQueue_init(LinkedQueue queue) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) return false;
    queue->rear = queue->front = node;
    node->next = NULL;
    return true;
}

bool linkedQueue_offer(LinkedQueue queue, E element) {
    Node node = malloc(sizeof(struct LNode));
    if (node == NULL) return false;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    node->next = NULL;
    return true;
}

bool isEmpty(LinkedQueue queue) {
    return queue->rear == queue->front;
}

E linkedQueue_poll(LinkedQueue queue) {
    Node tmp = queue->front->next;
    E e = tmp->element;
    queue->front->next = queue->front->next->next;
    if (queue->rear == tmp) {
        queue->rear = queue->front;
    }
    free(tmp);
    return e;
}

void printQueue(LinkedQueue queue) {
    printf("<<< ");
    Node node = queue->front->next;
    while (node) {
        printf("%d ", node->element);
        node = node->next;
    }
    printf("<<<\n");
}

int main() {
    struct Queue queue;
    linkedQueue_init(&queue);
    for (int i = 0; i < 5; ++i) {
        linkedQueue_offer(&queue, i * 100);
    }
    printQueue(&queue);
    while (!isEmpty(&queue)) {
        printf("%d ", linkedQueue_poll(&queue));
    }
    for (int i = 0; i < 5; ++i) {
        linkedQueue_offer(&queue, i * 100);
    }
    printQueue(&queue);
}
