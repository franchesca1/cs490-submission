#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100
#define BASE 16
#define SHIFT 4

void countSort(int nums[], int length, int shift) {
    int result[length];
    int bucket[BASE] = {0};

    for (int i = 0; i < length; i++) {
        int digit = (nums[i] >> shift) & (BASE - 1);
        bucket[digit]++;
    }

    for (int i = 1; i < BASE; i++) {
        bucket[i] += bucket[i - 1];
    }

    for (int i = length - 1; i >= 0; i--) {
        int digit = (nums[i] >> shift) & (BASE - 1);
        result[bucket[digit] - 1] = nums[i];
        bucket[digit]--;
    }

    for (int i = 0; i < length; i++) {
        nums[i] = result[i];
    }
}

void radixSort(int nums[], int length) {
    for (int shift = 0; shift < 32; shift += SHIFT) {
        countSort(nums, length, shift);
    }
}

int main() {
    int count;

    printf("Enter the count of integers (max 100): ");
    scanf("%d", &count);

    if (count < 1 || count > MAX_LEN) {
        printf("Invalid number of integers\n");
        return 1;
    }

    int data[MAX_LEN];

    printf("Enter the integers:\n");
    for (int i = 0; i < count; i++) {
        scanf("%d", &data[i]);
    }

    int negatives[MAX_LEN];
    int positives[MAX_LEN];
    int negSize = 0, posSize = 0;

    for (int i = 0; i < count; i++) {
        if (data[i] < 0) {
            negatives[negSize++] = data[i];
        } else {
            positives[posSize++] = data[i];
        }
    }

    radixSort(negatives, negSize);
    radixSort(positives, posSize);

    for (int i = 0; i < negSize / 2; i++) {
        int temp = negatives[i];
        negatives[i] = negatives[negSize - 1 - i];
        negatives[negSize - 1 - i] = temp;
    }

    int sorted[MAX_LEN];
    int idx = 0;

    for (int i = 0; i < negSize; i++) {
        sorted[idx++] = negatives[i];
    }

    for (int i = 0; i < posSize; i++) {
        sorted[idx++] = positives[i];
    }

    printf("Sorted integers:\n");
    for (int i = 0; i < count; i++) {
        printf("%d\n", sorted[i]);
    }

    return 0;
}

