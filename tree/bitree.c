//
// Created by yanqi on 2024/9/9.
//
#include <stdio.h>
#include <stdlib.h>

typedef char E;

struct TreeNode {
    E element;
    struct TreeNode* left;
    struct TreeNode* right;
    int flag;
};

typedef struct TreeNode* Node;

// region 栈
typedef Node T;   //这里栈内元素类型定义为上面的Node，也就是二叉树结点指针

struct StackNode {
    T element;
    struct StackNode * next;
};

typedef struct StackNode * SNode;  //这里就命名为SNode，不然跟上面冲突了就不好了

void initStack(SNode head){
    head->next = NULL;
}

_Bool pushStack(SNode head, T element){
    SNode node = malloc(sizeof(struct StackNode));
    if(node == NULL) return 0;
    node->next = head->next;
    node->element = element;
    head->next = node;
    return 1;
}

_Bool isStackEmpty(SNode head){
    return head->next == NULL;
}

T popStack(SNode head){
    SNode top = head->next;
    head->next = head->next->next;
    T e = top->element;
    free(top);
    return e;
}

T peekStack(SNode head) {
    return head->next->element;
}
// endregion

// region 队列
typedef Node T;   //还是将Node作为元素

struct QueueNode {
    T element;
    struct QueueNode * next;
};

typedef struct QueueNode * QNode;

struct Queue{
    QNode front, rear;
};

typedef struct Queue * LinkedQueue;

_Bool initQueue(LinkedQueue queue){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    queue->front = queue->rear = node;
    return 1;
}

_Bool offerQueue(LinkedQueue queue, T element){
    QNode node = malloc(sizeof(struct QueueNode));
    if(node == NULL) return 0;
    node->element = element;
    queue->rear->next = node;
    queue->rear = node;
    return 1;
}

_Bool isQueueEmpty(LinkedQueue queue){
    return queue->front == queue->rear;
}

T pollQueue(LinkedQueue queue){
    T e = queue->front->next->element;
    QNode node = queue->front->next;
    queue->front->next = queue->front->next->next;
    if(queue->rear == node) queue->rear = queue->front;
    free(node);
    return e;
}
// endregion

// 前序遍历
void preOrderTraversal(Node head) {
    if (head == NULL) return;
    printf("%c ", head->element);
    preOrderTraversal(head->left);
    preOrderTraversal(head->right);
}

// 中序遍历
void inOrderTraversal(Node root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%c ", root->element);
    inOrderTraversal(root->right);
}

// 后序遍历
void postOrderTraversal(Node root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%c ", root->element);
}

// 层序遍历
void levelOrderTraversal(Node root) {
    struct Queue queue;
    initQueue(&queue);
    offerQueue(&queue, root);
    while (!isQueueEmpty(&queue)) {
        Node node = pollQueue(&queue);
        printf("%c ", node->element);
        if (node->left != NULL) {
            offerQueue(&queue, node->left);
        }
        if (node->right != NULL) {
            offerQueue(&queue, node->right);
        }
    }
}

// 前序遍历-非递归
void preOrder(Node root) {
    struct StackNode stack;
    initStack(&stack);
    while (root || !isStackEmpty(&stack)) {
        // 遍历左子树
        while (root) {
            pushStack(&stack, root);
            printf("%c ", root->element);
            root = root->left;
        }
        root = popStack(&stack);
        root = root->right;
    }
}

// 中序遍历-非递归
void inOrder(Node root) {
    struct StackNode stack;
    initStack(&stack);
    while (root || !isStackEmpty(&stack)) {
        while (root) {
            pushStack(&stack, root);
            root = root->left;
        }
        root = popStack(&stack);
        printf("%c ", root->element);
        root = root->right;
    }
}

// 后序遍历-非递归
void postOrder(Node root) {
    struct StackNode stack;
    initStack(&stack);
    while (root || !isStackEmpty(&stack)) {
        while (root) {
            pushStack(&stack, root);
            root->flag = 0;
            root = root->left;
        }
        root = peekStack(&stack);// 此时只是获取结点，并没有出栈
        if (root->flag == 0) {
            root->flag = 1;
            root = root->right;
        } else {
            printf("%c ", root->element);
            popStack(&stack);// 当flag为1的时候再出栈
            root = NULL;
        }
    }
}

int main() {
    Node a = malloc(sizeof(struct TreeNode));
    Node b = malloc(sizeof(struct TreeNode));
    Node c = malloc(sizeof(struct TreeNode));
    Node d = malloc(sizeof(struct TreeNode));
    Node e = malloc(sizeof(struct TreeNode));
    Node f = malloc(sizeof(struct TreeNode));

    a->element = 'A';
    b->element = 'B';
    c->element = 'C';
    d->element = 'D';
    e->element = 'E';
    f->element = 'F';

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->right = f;

    preOrderTraversal(a);
    printf("\n");
    preOrder(a);
    printf("\n");
    inOrderTraversal(a);
    printf("\n");
    inOrder(a);
    printf("\n");
    postOrderTraversal(a);
    printf("\n");
    postOrder(a);
    printf("\n");
    levelOrderTraversal(a);
}