#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node *next;
};

// Create a new node with given value
struct Node* createNode(int data) {
    struct Node *node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Print all values in the linked list
void printList(struct Node *head) {
    while (head != NULL) {
        printf("Data = %d\n", head->data);
        head = head->next;
    }
}

// Reverse the linked list by creating a new one
struct Node* reverseList(struct Node *head) {
    struct Node *reversed = NULL;
    while (head != NULL) {
        struct Node *copy = createNode(head->data);
        copy->next = reversed;
        reversed = copy;
        head = head->next;
    }
    return reversed;
}

// Free all nodes in the linked list
void freeList(struct Node *head) {
    struct Node *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node *head = NULL, *tail = NULL;
    int num;

    printf("Enter integers to add to the linked list (press Ctrl+D to finish):\n");

    while (scanf("%d", &num) != EOF) {
        struct Node *newNode = createNode(num);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    printf("Data entered in the list are:\n");
    printList(head);

    struct Node *reversed = reverseList(head);
    printf("The list in reverse are:\n");
    printList(reversed);

    freeList(head);
    freeList(reversed);

    return 0;
}
