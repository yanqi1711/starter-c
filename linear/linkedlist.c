//
// Created by yanqi on 2024/8/11.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct ListNode {
    E element;
    struct ListNode *next;
};

typedef struct ListNode *Node;

void linkedList_init(Node node) {
    node->next = NULL;
}

_Bool linkedList_insert(Node head, E element, int index) {
    if (index < 1) return 0;
    // 使用--index，提前减了1，因为头结点不存数据
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    Node node = malloc(sizeof(struct ListNode));
    if (node == NULL) return 0; //创建一个新的结点，如果内存空间申请失败返回0
    node->element = element; //将元素保存到新创建的结点中
    node->next = head->next; //先让新插入的节点指向原本位置上的这个结点
    head->next = node; //接着将前驱结点指向新的这个结点
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
    head->next = node->next;
    free(node);
    return 1;
}

E *linkedList_get(Node head, int index) {
    if (index < 1) return 0;
    while (--index) {
        head = head->next;
        if (head == NULL) return 0;
    }
    if (head->next == NULL) return 0;
    return &head->next->element;
}

int linkedList_find(Node head, E element) {
    head = head->next;    //先走到第一个结点
    int i = 1;   //计数器
    while (head) {
        if(head->element == element) return i;   //如果找到，那么就返回i
        head = head->next;   //没找到就继续向后看
        i++;   //i记住要自增
    }
    return -1;   //都已经走到链表尾部了，那么就确实没找到了，返回-1
}

int linkedList_size(Node head) {
    int tmp = 0;
    while ((head = head->next) != NULL) {
        tmp++;
    }
    return tmp;
}

void linkedList_printList(Node head) {
    while (head->next) {
        head = head->next;
        printf("%d ", head->element); //因为头结点不存放数据，所以从第二个开始打印
    }
    printf("\n");
}

// int main() {
//     struct ListNode head;
//     linkedList_init(&head);
//     printf("%d\n", linkedList_size(&head));
//     linkedList_insert(&head, 100, 1); //依次插入3个元素
//     linkedList_insert(&head, 200, 2); //依次插入3个元素
//     linkedList_insert(&head, 300, 3); //依次插入3个元素
//     printf("%d\n", linkedList_size(&head));
//
//     linkedList_printList(&head); //打印一下看看
//
//     printf("%d\n", *linkedList_get(&head, 1));
//     printf("%d\n", linkedList_find(&head, 100.5));
// }
