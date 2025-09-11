//RADIX SORT LECTURE

#include <stdio.h>
#define MAX_SIZE 100

void radix(unsigned int A[], int n, int k){ //The input array to sort, the number of elements, the number of bits
    //create two buckets
    unsigned int bucket0[MAX_SIZE], bucket1[MAX_SIZE];
    unsigned int mask, count0, count1;

    //distribute based on bits from least significant to most significant
    for(int d=0; d<k; d++){
        //mask is used to determine if the bit is a 0 or a 1
        mask = 1<<d;
        count0=count1=0;
        //sort the values in A using d-th bit as key
        for(int i=0; i<n; i++){

            if ((A[i] & mask) == 0){
                bucket0[count0++] = A[i];
            }else{
                bucket1[count1++] = A[i];
            }

        }

        //join the buckets
        //first bits with 0 then bits with 1
        for(int i=0; i<count0; i++){
            A[i] = bucket0[i];
        }
        for(int i=0; i<count1; i++){
            A[i+count0] = bucket1[i];
        }
    }
}

int main(){
    unsigned int A[] = {5,4,1,5,64,6,575,672,2,8,9,6};
    int n = sizeof(A) / sizeof(A[0]); //gives you the number of elements
    int k = sizeof(int)*8; //gives you the number of bits

    printf("Before Sorting \n");
    for(int i=0; i<n; i++){
        printf("%4d", A[i]);
    }

    radix(A, n, k);
    printf("\nAfter Sorting \n");
    for(int i=0; i<n; i++){
        printf("%4d", A[i]);
    }
}

//Radix sort integers with signs
//how to deal with sign bits
//two's complement representation of negative integers

//Method 1:
//separate positive numbers and negative numbers
//radix-sort positive number in ascending order based on low 31 bits
//radix-sort negative number in ascending order based on low 31 bits
//join positive numbers and negative numbers

//Method 2:
//sort all values as if ther were unsigned
//in the last round joining the two buckets, put values from bucket 1 before values from bucket 0

void radix_sort_signed(int A[], int n, int k){
    //create two buckets for positive and negative
    int positive[MAX_SIZE], negative[MAX_SIZE];
    int neg_count=0; pos_count=0;

    for(int i=0; i<n; i++){
        if (A[i] >= 0){
            positive[pos_count++] = A[i];
        }else{
            negative[neg_count++] = ~A[i];
        }
    }
    radix(positive, n, k);
    radix(negative, n, k);

    //join the buckets
    //negative first
    for(int i=neg_count-1; i>=0; i--){
        //negating to maintain original order
        A[neg_count-i-1] = ~negative[i];
    }

    for(int i=0; i<pos_count; i++){
        A[neg_count+i] = positive[i];
    }
}

//Learn to use radix-sort with floating point numbers
//Bit-wise operations
//Exponent bits in float-point numbers are special
//Use pointer casting (Use the binary representation of the float number as a unsigned int)
//Non-negative float point values->Larger digit(bit)represents larger value
//When joining, the digit smaller comes then first followed by larger(ascending)
//Radix Sort Negative float point values
//Larger digit(bit) represents smaller value
//When joining, the digit larger comes first then followed by smaller(descending)
//Both negative and non-negative float point values
//Method 1: sort non-negative numbers and negative numbers separately
//pay attention to the way of joining the buckets
//put all non-negative numbers after negative number
//Method 2: what if we sort non-negative and negative numbers?
//step 1: sort all the numbers as if they were all unsiged integers
//join the buckets in the same way(smaller digits first) for all the numbers
//when step 1 is finished 
//all the negative numbers
//radix sort for hexadecimal die
//counters:arrays(how many elements in each bucket?)
//offsets:array(# elements?); total size of the buckets with lower indices(partial sum of counters)
