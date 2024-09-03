//
// Created by yanqi on 2024/8/17.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct Queue {
    E *array;
    int capacity;
    int front, rear;
};

typedef struct Queue *ArrayQueue;

_Bool arrayQueue_init(ArrayQueue queue) {
    queue->array = malloc(sizeof(E) * 10);
    if (queue->array == NULL) return 0;
    queue->capacity = 10;
    queue->front = queue->rear = 0;
    return 1;
}

_Bool isEmpty(ArrayQueue queue) {
    return queue->front == queue->rear;
}

_Bool arrayQueue_offer(ArrayQueue queue, E element) {
    int pos = (queue->rear + 1) % queue->capacity;
    if (pos == queue->front) return 0;
    queue->rear = pos;
    queue->array[queue->rear] = element;
    return 1;
}

E arrayQueue_poll(ArrayQueue queue) {
    queue->front = (queue->front + 1) % queue->capacity;
    return queue->array[queue->front];
}

void arrayQueue_print(ArrayQueue queue) {
    printf("<<< ");
    int i = queue->front;
    do {
        i = (i + 1) % queue->capacity;
        printf("%d ", queue->array[i]);
    } while (i != queue->rear);
    printf("<<<\n");
}

int main() {
    struct Queue queue;
    arrayQueue_init(&queue);
    for (int i = 0; i < 5; ++i) {
        arrayQueue_offer(&queue, i * 100);
    }
    arrayQueue_print(&queue);
    while (!isEmpty(&queue)) {
        printf("%d ", arrayQueue_poll(&queue));
    }
    return 0;
}
