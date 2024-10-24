//
// Created by yanqi on 2024/8/11.
//
#include <stdio.h>
#include <stdlib.h>

typedef int E;

struct List {
    E *array;
    int capacity;
    int size;
};

typedef struct List *ArrayList;

_Bool arrayList_init(ArrayList list) {
    list->array = malloc(sizeof(E) * list->capacity);
    // 如果内存分配失败，直接返回0，不改动表中任何内容
    if (list->array == NULL) return 0;
    list->capacity = 10;
    list->size = 0;
    return 1;
}

_Bool arrayList_insert(ArrayList list, E element, int index) {
    if (index < 1 || index > list->size + 1) return 0;

    if (list->size == list->capacity) {
        int newCapacity = list->capacity + (list->capacity >> 1);
        E *newArray = realloc(list->array, sizeof(E) * newCapacity);
        if (newArray == NULL) return 0;
        list->array = newArray;
        list->capacity = newCapacity;
    }

    // 当前表中数据元素的个数大于index-1时，需要将数据从后往前移动
    for (int i = list->size; i > index - 1; --i) {
        list->array[i] = list->array[i - 1];
    }
    list->array[index - 1] = element;
    list->size++;
    return 1;
}

_Bool arrayList_delete(ArrayList list, int index) {
    if (index < 1 || index > list->size) return 0;
    for (int i = index - 1; i < list->size - 1; ++i) {
        list->array[i] = list->array[i + 1];
    }
    list->size--;
    return 1;
}

int arrayList_size(ArrayList list) {
    return list->size;
}

E *arrayList_get(ArrayList list, int index) {
    if (index < 1 || index > list->size) return NULL;
    return &list->array[index - 1];
}

int arrayList_find(ArrayList list, E element) {
    for (int i = 0; i < list->size; ++i) {
        if (list->array[i] == element) return i + 1;
    }
    return -1;
}

// 打印表中数据的函数
void arrayList_print(ArrayList list) {
    for (int i = 0; i < list->size; ++i) {
        printf("%d ", list->array[i]);
    }
    printf("\n");
}

// int main() {
//     struct List list;
//     if(arrayList_init(&list)){
//         for (int i = 0; i < 30; ++i)
//             arrayList_insert(&list, i, i);
//         arrayList_print(&list);
//     } else{
//         printf("顺序表初始化失败，无法启动程序！");
//     }
// }
