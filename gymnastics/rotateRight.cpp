//
// Created by yanqi on 2024/9/4.
//
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || k == 0) return head;
    int len = 1;
    struct ListNode* node = head;
    while (node->next) {
        node = node->next;
        len++;
    }
    node->next = head;
    int index = len - k % len;
    while (--index) {
        head = head->next;
    }
    struct ListNode* res = head->next;
    head->next = NULL;
    return res;
}