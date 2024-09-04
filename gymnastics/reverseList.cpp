//
// Created by yanqi on 2024/9/4.
//
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *res = NULL, *tmp;
    while (head) {
        tmp = head; // 存储head
        head = head->next; // head后移
        tmp->next = res; // 改变next指针
        res = tmp; // 保存刚刚已经改变了next指针的结点
    }
    return res;
}