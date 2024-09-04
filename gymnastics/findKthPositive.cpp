//
// Created by yanqi on 2024/9/4.
//
int findKthPositive(int* arr, int arrSize, int k){
    int i = 0, j = 1;
    while (i < arrSize) {
        if (arr[i] == j) {
            i++;
        } else {
            if (!--k) return j;
        }
        j++;
    }
    return j + k - 1;
}