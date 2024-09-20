//
// Created by yanqi on 2024/9/20.
//
#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *creatNode(int val) {
    struct TreeNode *node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->val = val;
    return node;
}

struct TreeNode *deduceTreeCore(int *preorder, int *inorder, int start, int end, int index) {
    if (start > end) return NULL;
    if (start == end) return creatNode(preorder[index]);
    struct TreeNode *node = creatNode(preorder[index]);
    int pos = 0;
    while (node->val != inorder[pos]) pos++;
    node->left = deduceTreeCore(preorder, inorder, start, pos - 1, index + 1);
    node->right = deduceTreeCore(preorder, inorder, pos + 1, end, index + (pos - start) + 1);
    return node;
}

struct TreeNode *deduceTree(int *preorder, int preorderSize, int *inorder, int inorderSize) {
    return deduceTreeCore(preorder, inorder, 0, preorderSize - 1, 0);
}
