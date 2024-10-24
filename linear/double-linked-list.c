//
// Created by yanqi on 2024/8/12.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode *next;
    struct ListNode *prev;
};

typedef struct ListNode *Node;

void linkedList_init(Node node) {
    node->next = NULL;
    node->prev = NULL;
}

_Bool linkedList_insert(Node head, E element, int index) {
    if (index < 1) return 0; //跟单链表一样，还是先找到对应的位置
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    Node node = malloc(sizeof(struct ListNode)); //创建新的结点
    if (node == NULL) return 0;
    node->element = element;

    if (head->next) {
        //首先处理后继结点，现在有两种情况，一种是后继结点不存在的情况，还有一种是后继结点存在的情况
        head->next->prev = node; //如果存在则修改对应的两个指针
        node->next = head->next;
    } else {
        node->next = NULL; //不存在直接将新结点的后继指针置为NULL
    }

    head->next = node; //接着是前驱结点，直接操作就行
    node->prev = head;
    return 1;
}

_Bool linkedList_delete(Node head, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    // 如果要删除的这个节点为空，直接返回0
    if (head->next == NULL) return 0;
    Node node = head->next;
    head->next = head->next->next;
    if (head->next) { head->next->prev = head; } else { head->next = NULL; }
    free(node);
    return 1;
}

// int main() {
//     struct ListNode head;
//     linkedList_init(&head);
//     for (int i = 1; i <= 5; ++i) //插5个元素吧
//         linkedList_insert(&head, i * 100, i);
//
//     linkedList_delete(&head, 2);
//
//     Node node = &head; //先来正向遍历一次
//     do {
//         node = node->next;
//         printf("%d -> ", node->element);
//     } while (node->next != NULL);
//
//     printf("\n"); //再来反向遍历一次
//     do {
//         printf("%d -> ", node->element);
//         node = node->prev;
//     } while (node->prev != NULL);
// }
