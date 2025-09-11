#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Append to linked list
void appendNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Print the list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

// Bubble sort using node swapping
void bubbleSort(struct Node** head) {
    int swapped;
    if (*head == NULL || (*head)->next == NULL)
        return;

    do {
        swapped = 0;
        struct Node **curr = head;

        while ((*curr)->next != NULL) {
            struct Node* first = *curr;
            struct Node* second = first->next;

            if (first->data > second->data) {
                // Swap nodes
                first->next = second->next;
                second->next = first;
                *curr = second;
                swapped = 1;
            }
            curr = &((*curr)->next);
        }
    } while (swapped);
}

int main() {
    struct Node* head = NULL;
    int num;

    printf("Enter integers (press Ctrl+D to finish):\n");
    while (scanf("%d", &num) != EOF) {
        appendNode(&head, num);
    }

    bubbleSort(&head);

    printf("Sorted integers:\n");
    printList(head);

    return 0;
}
