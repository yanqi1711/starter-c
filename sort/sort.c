//
// Created by yanqi on 2024/10/25.
//
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int flag = 1;
        for (int j = 0; j < size - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                flag = 0;
                int tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
        if (flag) break;
    }
}

void insertSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int tmp = arr[i], j = i;
        // 这里是j>0
        while (j > 0 && arr[j - 1] > tmp) {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = tmp;
    }
}

void selectSort(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int min = i;
        for (int j = i; j < size; ++j) {
            if (arr[j] < arr[min]) min = j;
        }
        int tmp = arr[min];
        arr[min] = arr[i];
        arr[i] = tmp;
    }
}

int main() {
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

    selectSort(arr, 9);

    for (int i = 0; i < 9; ++i) {
        printf("%d ", arr[i]);
    }
}
