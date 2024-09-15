//
// Created by yanqi on 2024/9/16.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode *left;
    struct TreeNode *right;
    int height;
} *Node;

Node createNode(E element) {
    Node root = malloc(sizeof(struct TreeNode));
    root->left = root->right = NULL;
    root->height = 1;
    root->element = element;
    return root;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int getHeight(Node root) {
    if (root == NULL) {
        return 0;
    }
    return root->height;
}

// 传入原本的根结点，返回新的根结点
// 左旋
Node leftRotation(Node root) {
    Node newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;

    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;

    return newRoot;
}

// 右旋
Node rightRotation(Node root) {
    Node newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    root->height = max(getHeight(root->right), getHeight(root->left)) + 1;
    newRoot->height = max(getHeight(newRoot->right), getHeight(newRoot->left)) + 1;
    return newRoot;
}

// 先左旋再右旋
Node leftRightRotation(Node root ) {
    root->left = leftRotation(root->left);
    return rightRotation(root);
}

// 先右旋再左旋
Node rightLeftRotation(Node root) {
    root->right = rightRotation(root->right);
    return leftRotation(root);
}

Node insert(Node root, E element) {
    if (root == NULL) {
        root = createNode(element);
    } else if (root->element > element) {
        root->left = insert(root->left, element);
        if (getHeight(root->left) - getHeight(root->right) > 1) {
            if (root->left->element > element) {
                root = rightRotation(root);
            } else {
                root = leftRightRotation(root);
            }
        }
    } else if (root->element < element) {
        if (getHeight(root->left) - getHeight(root->right) < -1) {
            if (root->right->element > element) {
                root = rightLeftRotation(root);
            } else {
                root = rightRotation(root);
            }
        }
    }

    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    return root;
}

int main() {
    Node root = NULL;
    while (1) {
        E e;

    }
}
