//
// Created by yanqi on 2024/9/20.
//
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int sumNumbersImp(struct TreeNode *root, int parent) {
    if (root == NULL) return 0;
    int sum = root->val + parent * 10;
    if (root->left == NULL && root->right == NULL) return sum;
    return sumNumbersImp(root->left, sum) + sumNumbersImp(root->right, sum);
}

int sumNumbers(struct TreeNode *root) {
    return sumNumbersImp(root, 0);
}
