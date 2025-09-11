//practicing linked lists
#include <stdio.h>
#include <stdlib.h>

//intialize the node structure

struct node{
    int x;
    struct node *next;
};

int main(){

    struct node *head = malloc(sizeof(struct node)); //make space for head first node
    head->x = 15; //assign value for first node
    head->next = malloc(sizeof(struct node)); //make space for the second node
    head->next->x = -2; //assign value for second node
    head->next->next = NULL; //Only two nodes
    
    //insert nodes at the beginning of my linked list
    //struct node *new_node = malloc(sizeof(struct node)); //make space for another node
    //new_node->x = 4; //assign value to this node
    //new_node->next = head; //link the new node to the old head
    //head = new_node; //Update head to point to the new node

    //insert nodes at the end of my linked list
    //struct node *end_node = malloc(sizeof(struct node));
    //end_node->x = 18;
    //end_node->next = NULL;
    //head->next->next = end_node;
    //only works if the list has exactly two nodes

    //better version
    //struct node *end_node = malloc(sizeof(struct node));
    //end_node->x = 18;
    //end_node->next = NULL;
    //struct node *tail = head;
    //while(tail->next != NULL){
    //    tail = tail->next;
   // }
   // tail->next = end_node;

    //inserting nodes in the middle of my linked list
    //struct node *middle_node = malloc(sizeof(struct node));
    //middle_node->x = 16;
    //middle_node->next = head->next;
    //head->next = middle_node;

    //printf("First: %d\n", curr->value);
    //printf("Second: %d\n", curr->next->value); 
    //struct node *curr = head;
    //while(curr != NULL){
    //    printf("%d->", curr->x);
    //    curr = curr->next;
   // }
   // printf("NULL\n");

    //Free Memory
    //while(head != NULL){
    //    struct node *temp = head;
    //    head = head->next;
    //    free(temp);
   // }



}