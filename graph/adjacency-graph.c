//
// Created by yanqi on 2024/10/22.
//
#include <stdio.h>
#include <stdlib.h>

#define MaxVertex 6

typedef char E;
typedef int T;

typedef struct QueueNode {
    T element;
    struct QueueNode * next;
} * QNode;

typedef struct Queue {
    QNode front, rear;
} * LinkedQueue;

_Bool initQueue(LinkedQueue queue) {
    QNode node = malloc(sizeof(struct QueueNode));
    if (node == NULL) return 0;
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

_Bool isEmpty(LinkedQueue queue){
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

typedef struct Node {   //结点和头结点分开定义，普通结点记录邻接顶点信息
    int nextVertex;
    struct Node * next;
} * Node;

struct HeadNode {   //头结点记录元素
    E element;
    struct Node * next;
};

typedef struct AdjacencyGraph {
    int vertexCount;   //顶点数
    int edgeCount;     //边数
    struct HeadNode vertex[MaxVertex];
} * Graph;

Graph create() {
    Graph graph = malloc(sizeof(struct AdjacencyGraph));
    graph->vertexCount = graph->edgeCount = 0;
    return graph;
}

void addVertex(Graph graph, E element){
    if(graph->vertexCount >= MaxVertex) return;   //跟之前一样
    graph->vertex[graph->vertexCount].element = element;   //添加新结点时，再来修改也行
    graph->vertex[graph->vertexCount].next = NULL;
    graph->vertexCount++;
}

void addEdge(Graph graph, int a, int b){
    Node node = graph->vertex[a].next;
    Node newNode = malloc(sizeof(struct Node));
    newNode->next = NULL;
    newNode->nextVertex = b;
    if(!node) {    //如果头结点下一个都没有，那么直接连上去
        graph->vertex[a].next = newNode;
    } else {   //否则说明当前顶点已经连接了至少一个其他顶点了，有可能会出现已经连接过的情况，所以说要特别处理一下
        do {
            if(node->nextVertex == b) return;   //如果已经连接了对应的顶点，那么直接返回
            if(node->next) node = node->next;   //否则继续向后遍历
            else break;   //如果没有下一个了，那就找到最后一个结点了，直接结束
        } while (1);
        node->next = newNode;
    }
    graph->edgeCount++;   //边数计数+1
}

void printGraph(Graph graph){
    for (int i = 0; i < graph->vertexCount; ++i) {
        printf("%d | %c", i, graph->vertex[i].element);
        Node node = graph->vertex[i].next;
        while (node) {
            printf(" -> %d", node->nextVertex);
            node = node->next;
        }
        putchar('\n');
    }
}

/**
 * 广度优先遍历
 * @param graph 图
 * @param startVertex 起点顶点下标
 * @param targetVertex 目标顶点下标
 * @param visited 已到达过的顶点数组
 * @param queue 辅助队列
 */
void bfs(Graph graph, int startVertex, int targetVertex, int * visited, LinkedQueue queue) {
    offerQueue(queue, startVertex);  //首先把起始位置顶点丢进去
    visited[startVertex] = 1;   //起始位置设置为已走过
    while (!isEmpty(queue)) {
        int next = pollQueue(queue);
        printf("%c -> ", graph->vertex[next].element);  //从队列中取出下一个顶点，打印
        Node node = graph->vertex[next].next;    //同样的，把每一个分支都遍历一下
        while (node) {
            if(!visited[node->nextVertex]) {   //如果没有走过，那么就直接入队
                offerQueue(queue, node->nextVertex);
                visited[node->nextVertex] = 1;   //入队时就需要设定为1了
            }
            node = node->next;
        }
    }
}

/**
 * 深度优先搜索算法
 * @param graph 图
 * @param startVertex 起点顶点下标
 * @param targetVertex 目标顶点下标
 * @param visited 已到达过的顶点数组
 */
void dfs(Graph graph, int startVertex, int targetVertex, int * visited){
    printf("%c -> ", graph->vertex[startVertex].element);
    visited[startVertex] = 1;
    Node node = graph->vertex[startVertex].next;
    // 遍历当前结点的所有分支
    while (node) {
        if (!visited[node->nextVertex])
            dfs(graph, node->nextVertex, targetVertex, visited);
        node = node->next;
    }
}

int main(){
    Graph graph = create();
    for (int c = 'A'; c <= 'F' ; ++c)
        addVertex(graph, (char) c);
    addEdge(graph, 0, 1);   //A -> B
    addEdge(graph, 1, 2);   //B -> C
    addEdge(graph, 1, 3);   //B -> D
    addEdge(graph, 1, 4);   //B -> E
    addEdge(graph, 4, 5);   //E -> F

    int arr[graph->vertexCount];
    for (int i = 0; i < graph->vertexCount; ++i) {
        arr[i] = 0;
    }
    // dfs(graph, 0, 5, arr);
    struct Queue queue;
    initQueue(&queue);
    bfs(graph, 0, 5, arr, &queue);
}