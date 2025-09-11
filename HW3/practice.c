#include <stdio.h>

// Global variable
int globalVar = 100;

// Function declaration
void myFunction() {
    int localVar = 42;  // Local variable
    printf("Hello, World!\n");
}

int main() {
    myFunction();
    return 0;
}

// Invalid identifiers (should not match)
9invalidVar;
float 123number;
char my-var;
