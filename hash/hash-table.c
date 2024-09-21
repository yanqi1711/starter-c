//
// Created by yanqi on 2024/9/22.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

// 定义一个结构体存储需要插入的元素
typedef struct Element {
    int key;
} * Elelment;

// 定义一个Element类型的数组，这个数组是哈希表中的元素
typedef struct HashTable {
    Elelment *table;
} * HashTable;

void init(HashTable hashTable) {
    hashTable->table = malloc(sizeof(struct Element)*SIZE);
}

int hash(int key) {
    return key % SIZE;
}

void insert(HashTable hashTable, Elelment elelment) {
    int hashCode = hash(elelment->key);
    hashTable->table[hashCode] = elelment;
}

_Bool find(HashTable hashTable, int key) {
    int hashCode = hash(key);
    if (hashTable->table[key] == NULL)
        return false;
    return hashTable->table[key]->key == key;
}

Elelment create(int key) {
    Elelment elelment = malloc(sizeof(struct Element));
    elelment->key = key;
    return elelment;
}

int main() {
    struct HashTable table;
    init(&table);

    insert(&table, create(10));
    insert(&table, create(2));
    insert(&table, create(5));
    insert(&table, create(17));

    for (int i = 0; i < SIZE; ++i) {
        if (table.table[i] == NULL) {
            printf("NULL ");
        } else {
            printf("%d ", table.table[i]->key);
        }
    }

    printf("\n");
    printf("%d ", find(&table, 2));
    printf("%d ", find(&table, 3));
}