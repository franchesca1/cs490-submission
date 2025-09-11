#include <stdio.h>
#define MAX_SIZE 100

// Convert float to sortable unsigned int using pointer cast
unsigned int float_to_sortable(float f) {
    unsigned int bits = *(unsigned int *)&f;
    if (bits & 0x80000000) {
        return ~bits; // Negative: invert all bits
    } else {
        return bits ^ 0x80000000; // Positive: flip sign bit
    }
}

// Convert sortable unsigned int back to float
float sortable_to_float(unsigned int bits) {
    if (bits & 0x80000000) {
        bits ^= 0x80000000;
    } else {
        bits = ~bits;
    }
    return *(float *)&bits;
}

// Radix sort for unsigned integers using 16 buckets
void radix_sort_unsigned(unsigned int A[], int n) {
    unsigned int buckets[16][MAX_SIZE];
    int counts[16];
    int shift;

    for (int d = 0; d < 8; d++) { // 32 bits / 4 = 8 hex digits
        shift = d * 4;

        // Reset bucket counts
        for (int i = 0; i < 16; i++) counts[i] = 0;

        // Distribute into buckets
        for (int i = 0; i < n; i++) {
            int index = (A[i] >> shift) & 0xF;
            buckets[index][counts[index]++] = A[i];
        }

        // Rebuild array from buckets
        int k = 0;
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < counts[i]; j++) {
                A[k++] = buckets[i][j];
            }
        }
    }
}

// Radix sort for float
void radix_sort_float(float A[], int n) {
    unsigned int transformed[MAX_SIZE];

    // Convert to sortable ints
    for (int i = 0; i < n; i++) {
        transformed[i] = float_to_sortable(A[i]);
    }

    // Sort the transformed values
    radix_sort_unsigned(transformed, n);

    // Convert back to floats
    for (int i = 0; i < n; i++) {
        A[i] = sortable_to_float(transformed[i]);
    }
}

int main() {
    float numbers[MAX_SIZE];
    int count;

    printf("Enter the number of floating point values (max 100): ");
    scanf("%d", &count);

    if (count <= 0 || count > MAX_SIZE) {
        printf("Invalid count. Must be between 1 and 100.\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%f", &numbers[i]);
    }

    radix_sort_float(numbers, count);

    printf("\nSorted numbers:\n");
    for (int i = 0; i < count; i++) {
        printf("%.6f\n", numbers[i]);
    }

    return 0;
}
