//
// Created by yanqi on 2024/9/4.
//
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* res = head;
    if (res == NULL) return NULL;
    while (head->next != NULL) {
        if (head->val == head->next->val) {
            head->next = head->next->next;
        } else {
            head = head->next;
        }
    }
    return res;
}