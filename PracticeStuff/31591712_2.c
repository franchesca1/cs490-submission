#include <stdio.h>
#define MAX_SIZE 100
#define BASE 16  // 16 buckets for hexadecimal radix sort

// Convert signed int to sortable unsigned int
unsigned int int_to_sortable(int x) {
    // Flip the sign bit to preserve order in unsigned representation
    return (unsigned int)x ^ 0x80000000;
}

// Convert sortable unsigned int back to signed int
int sortable_to_int(unsigned int u) {
    return (int)(u ^ 0x80000000);
}

// Radix sort for unsigned ints (hexadecimal version)
void radix_sort_unsigned(unsigned int A[], int n) {
    unsigned int buckets[BASE][MAX_SIZE];
    int counts[BASE];

    for (int digit = 0; digit < 8; digit++) { // 32 bits / 4 = 8 nibbles
        int shift = digit * 4;

        // Reset bucket counts
        for (int i = 0; i < BASE; i++) counts[i] = 0;

        // Place into buckets based on current 4-bit digit
        for (int i = 0; i < n; i++) {
            int index = (A[i] >> shift) & 0xF;
            buckets[index][counts[index]++] = A[i];
        }

        // Rebuild array from buckets
        int k = 0;
        for (int i = 0; i < BASE; i++) {
            for (int j = 0; j < counts[i]; j++) {
                A[k++] = buckets[i][j];
            }
        }
    }
}

// Radix sort for signed 4-byte integers
void radix_sort_signed(int A[], int n) {
    unsigned int transformed[MAX_SIZE];

    // Step 1: Transform to sortable unsigned ints
    for (int i = 0; i < n; i++) {
        transformed[i] = int_to_sortable(A[i]);
    }

    // Step 2: Sort
    radix_sort_unsigned(transformed, n);

    // Step 3: Convert back
    for (int i = 0; i < n; i++) {
        A[i] = sortable_to_int(transformed[i]);
    }
}

int main() {
    int A[MAX_SIZE];
    int count;

    scanf("%d", &count);

    if (count < 1 || count > MAX_SIZE) return 1;

    for (int i = 0; i < count; i++) {
        scanf("%d", &A[i]);
    }

    radix_sort_signed(A, count);

    for (int i = 0; i < count; i++) {
        printf("%d\n", A[i]);
    }

    return 0;
}

