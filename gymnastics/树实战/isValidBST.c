//
// Created by yanqi on 2024/9/20.
//
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool isValid(struct TreeNode *root, long min, long max) {
    if (root == NULL) return true;
    if (root->left != NULL && (root->val <= root->left->val || root->left->val <= min)) {
        return false;
    }
    if (root->right != NULL && (root->val >= root->right->val || root->right->val >= max)) {
        return false;
    }
    return isValid(root->left, min, root->val) && isValid(root->right, root->val, max);
}

bool isValidBST(struct TreeNode* root) {
    return isValid(root, -2147483649, 2147483648);
}