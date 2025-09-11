#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENTS 100

// Function to perform radix sort on an array of floating-point numbers
void radixSortFloats(float *data, int size) {
    unsigned int *floatAsInt = (unsigned int *) data;  // Treat float array as unsigned int
    unsigned int buckets[256][MAX_ELEMENTS]; // Buckets for sorting each byte
    int bucketSizes[256]; // Track the number of elements in each bucket
    unsigned int byteMask = 0xFF; // Mask to isolate each byte
    unsigned int byteShift; // Shift for each byte (0, 8, 16, 24)

    
    for (byteShift = 0; byteShift < 32; byteShift += 8) {

        for (int i = 0; i < 256; i++) {
            bucketSizes[i] = 0;
        }

      
        for (int i = 0; i < size; i++) {
            unsigned int byteValue = (floatAsInt[i] >> byteShift) & byteMask;
            buckets[byteValue][bucketSizes[byteValue]++] = floatAsInt[i];
        }

        
        int idx = 0;
        for (int i = 0; i < 256; i++) {
            for (int j = 0; j < bucketSizes[i]; j++) {
                floatAsInt[idx++] = buckets[i][j];
            }
        }
    }
}


void divideNumbers(float *data, int size, float *negList, float *posList, int *negCount, int *posCount) {
    for (int i = 0; i < size; i++) {
        if (data[i] < 0) {
            negList[*negCount] = data[i];
            (*negCount)++;
        } else {
            posList[*posCount] = data[i];
            (*posCount)++;
        }
    }
}

int main() {
    int totalNumbers;
    float inputNumbers[MAX_ELEMENTS], negativeNumbers[MAX_ELEMENTS], positiveNumbers[MAX_ELEMENTS];
    int negativeCount = 0, positiveCount = 0;

    printf("Enter the number of elements (max %d): ", MAX_ELEMENTS);
    scanf("%d", &totalNumbers);

    if (totalNumbers > MAX_ELEMENTS) {
        printf("The number of elements cannot exceed %d.\n", MAX_ELEMENTS);
        return 1;
    }

 
    printf("Enter the floating-point numbers:\n");
    for (int i = 0; i < totalNumbers; i++) {
        scanf("%f", &inputNumbers[i]);
    }

  
    divideNumbers(inputNumbers, totalNumbers, negativeNumbers, positiveNumbers, &negativeCount, &positiveCount);

    
    if (negativeCount > 0) {
        radixSortFloats(negativeNumbers, negativeCount);
    }
    if (positiveCount > 0) {
        radixSortFloats(positiveNumbers, positiveCount);
    }

  
    printf("Sorted numbers:\n");

   
    for (int i = negativeCount - 1; i >= 0; i--) {  
        printf("%.2f\n", negativeNumbers[i]);
    }

   
    for (int i = 0; i < positiveCount; i++) {
        printf("%.2f\n", positiveNumbers[i]);
    }

    return 0;
}
