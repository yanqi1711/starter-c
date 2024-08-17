#include <stdio.h>

// o(n) 线性阶
int search(int *nums, int numsSize, int target) {
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            return i;
        }
        if (nums[i] > target) {
            break;
        }
    }
    return -1;
}

// o(logn) 对数阶 二分查找
int binarySearch(int *nums, int left, int right, int target) {
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main(void) {
    int num[7] = {1, 2, 3, 4, 5, 6, 7};
    int target = 7;

    int result = binarySearch(num, 0, 6, target);

    printf("tartget: %d, result: %d\n", target, result);
    return 0;
}
