//
// Created by yanqi on 2024/9/15.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

typedef struct TreeNode {
    E element;
    struct TreeNode *left;
    struct TreeNode *right;
} *Node;

Node createNode(E element) {
    Node node = malloc(sizeof(struct TreeNode));
    node->left = node->right = NULL;
    node->element = element;
    return node;
}

Node insert(Node root, E element) {
    if (root) {
        // 如果插入结点小于当前结点往左走
        if (root->element > element) {
            root->left = insert(root->left, element);
        } else if (root->element < element) {
            //如果插入结点大于当前结点往右走
            root->right = insert(root->right, element);
        }
    } else {
        root = createNode(element); //走到空直接令当前结点元素等于插入元素
    }
    //返回
    return root;
}

Node find(Node root, E target) {
    while (root) {
        if (root->element > target) {
            root = root->left;
        } else if (root->element < target) {
            root = root->right;
        } else {
            return root;
        }
    }
    return NULL;
}

Node findMax(Node root) {
    while (root && root->right) {
        root = root->right;
    }
    return root;
}

Node delete(Node root, E target) {
    if (root == NULL) return NULL;
    if (root->element > target)
        root->left = delete(root->left, target);
    else if (root->element < target)
        root->right = delete(root->right, target);
    else {
        if (root->left && root->right) {
            //最麻烦的情况，左右孩子都有
            Node max = findMax(root->left);
            root->element = max->element;
            root->left = delete(root->left, root->element);
        } else {
            Node tmp = root;
            if (root->left) {
                root = root->left;
            } else {
                root = root->right;
            }
            free(tmp);
        }
    }
    return root;
}


void inOrder(Node root) {
    if (root == NULL) return;
    inOrder(root->left);
    printf("%d ", root->element);
    inOrder(root->right);
}

int main() {
    Node root = insert(NULL, 18); //插入后，得到根结点
    insert(root, 11);
    insert(root, 20);
    insert(root, 7);
    insert(root, 15);
    insert(root, 22);
    insert(root, 9);
    insert(root, 8);
    insert(root, 10);

    inOrder(root);printf("\n");
    delete(root, 10);
    inOrder(root);printf("\n");

    printf("%p\n", find(root, 17));
    printf("%p\n", find(root, 9));
    printf("%d", findMax(root)->element);
}
