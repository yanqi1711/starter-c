//
// Created by yanqi on 2024/10/25.
//
#include "../tree/heap.c"

// 快速排序
// 取一个基准元素，通过数组的首位指针不断比较该基准元素，大的放在右边，小的放在左边，最后就可以确定该基准元素的位置了
void quickSort(int arr[], int start, int end) {
    if (start >= end) return;
    int left = start, right = end, pivot = arr[left];
    while (left < right) {
        // 规定左边为基准元素，从右边开始比较
        while (left < right && arr[right] >= pivot) right--;
        arr[left] = arr[right];
        while (left < right && arr[left] <= pivot) left++;
        arr[right] = arr[left];
    }
    // 左右指针碰撞到一起
    // 最后确定基准元素的位置
    arr[left] = pivot;
    quickSort(arr, start, left - 1);
    quickSort(arr, left + 1, end);
}

// 希尔排序
void shellSort(int arr[], int size){
    int delta = size / 2;
    while (delta >= 1) {
        //这里依然是使用之前的插入排序，不过此时需要考虑分组了
        for (int i = delta; i < size; ++i) {   //我们需要从delta开始，因为前delta个组的第一个元素默认是有序状态
            int j = i, tmp = arr[i];   //这里依然是把待插入的先抽出来
            while (j >= delta && arr[j - delta] > tmp) {
                //注意这里比较需要按步长往回走，所以说是j - delta，此时j必须大于等于delta才可以，如果j - delta小于0说明前面没有元素了
                arr[j] = arr[j - delta];
                j -= delta;
            }
            arr[j] = tmp;
        }
        delta /= 2;    //分组插排完事之后，重新计算步长
    }
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 这个函数就是对start顶点位置的子树进行堆化（大顶堆）
void makeHeap(int* arr, int start, int end) {
    while (start * 2 + 1 <= end) {    //如果有子树，就一直往下，因为调整之后有可能子树又不满足性质了
        int child = start * 2 + 1;    //因为下标是从0开始，所以左孩子下标就是i * 2 + 1，右孩子下标就是i * 2 + 2
        if(child + 1 <= end && arr[child] < arr[child + 1])   //如果存在右孩子且右孩子比左孩子大
            child++;    //那就直接看右孩子
        if(arr[child] > arr[start])   //如果上面选出来的孩子，比父结点大，那么就需要交换，大的换上去，小的换下来
            swap(&arr[child], &arr[start]);
        start = child;   //继续按照同样的方式前往孩子结点进行调整
    }
}

// 堆排序
void heapSort(int arr[], int size) {
    for(int i= size/2 - 1; i >= 0; i--)   //我们首选需要对所有非叶子结点进行一次堆化操作，需要从最后一个到第一个，这里size/2计算的位置刚好是最后一个非叶子结点
        makeHeap(arr, i, size - 1);
    for (int i = size - 1; i > 0; i--) {   //接着我们需要一个一个把堆顶元素搬到后面，有序排列
        swap(&arr[i], &arr[0]);    //搬运实际上就是直接跟倒数第i个元素交换，这样，每次都能从堆顶取一个最大的过来
        makeHeap(arr, 0, i - 1);   //每次搬运完成后，因为堆底元素被换到堆顶了，所以需要再次对根结点重新进行堆化
    }
}

int main() {
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int len = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, 10);

    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
}
