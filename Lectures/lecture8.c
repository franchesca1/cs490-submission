//Structures and Linked Lists
//A linked list is a sequence of connected bodes
//each node contains at least:
//some data
//a pointer to the next node in the list
//the head pointer points to the first node
//the last node points to NULL
//the tail pointer(optional) points to the last node
//When adding and deleting in arrays the overhead is really high compared to linked lists which only occupies space as it needs
//building a linked list
//declare a node type --self-referential struct
//create nodes-- allocate memory on demand, initialize members
//link nodes to the list--find a location on the list
//keep the head pointer updated
//ensure the next pointer of the last node is NULL
//if there is a tail pointer, keep it updated

//what are structures?-You are able to create your own datatype
#include <stdio.h>
#include <stdlib.h>

struct person{
    int id;
    char name[8];
    float score;
};

int main(){
    struct person name1={1, "John", 123.45};
    struct person *ptr = &name1;

    printf("%d \n", name1.id); 

    printf("%d \n", ptr -> id);
}