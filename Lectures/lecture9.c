#include <stdio.h>
#include <stdlib.h>

//building a linked list
//insertion sort
//pointer will always be 8 bytes


//declare the node type
struct node {
    int id;
    struct node *next;
};

int main(){
    //create nodes and allocate memory

    struct node *a = (struct node *)malloc(sizeof(struct node));
    struct node *b = (struct node *)malloc(sizeof(struct node));
    struct node *c = (struct node *)malloc(sizeof(struct node));

    a->id = 1;
    b->id = 2;
    c->id = 3;

    a->next = b;
    b->next = c;
    c->next = NULL;

    struct node *head = a;

    //traverse through the linked list
    //1.start from the head pointer.
    //2.proceed along the next pointer of each node.
    //3.stop when the last node is reached.
    //last node is when the next pointer of node is NULL or check what the tail pointer is pointing to
    for(struct node *p=head; p!=NULL; p=p->next){
        printf("%d -> ", p->id);
    }



}


//make it more dynamic
//declare the node type
struct node {
    int data;
    char name[20];
    struct node *next;
};

int main(){
    //create nodes and allocate memory

    struct node *head = NULL;, *tail = NULL; *pnode;
    //pnode will be used to create new nodes
    while(1){
        pnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter id: ");
        scanf("%d", &(pnode -> data));
        if (pnode -> data < 0){
            break;
        }
        printf("Please enter name: ");
        scanf("%s", pnode -> name);
        pnode -> next = NULL;

        if(head == NULL){
            head=pnode;

        }

        if(tail != NULL){
            //connecting the nodes
            tail -> next = pnode;

        }

        tail = pnode;
    }

    //traverse
    pnode=head;
    while (p!=NULL){
        printf("%d %s -> ", pnode -> data, pnode -> name);
        pnode = pnode -> next;
    }
  
    



}

//insert nodes at the beginning, middle, and at the end
//declare the node type
struct node {
    int id;
    struct node *next;
};

int main(){
    //create nodes and allocate memory

    struct node *a = (struct node *)malloc(sizeof(struct node));
    struct node *b = (struct node *)malloc(sizeof(struct node));
    struct node *c = (struct node *)malloc(sizeof(struct node));

    a->id = 1;
    b->id = 2;
    c->id = 3;

    a->next = b;
    b->next = c;
    c->next = NULL;

    struct node *head = a;

    //add new node b to the beginning of the linked list
    b->next = head;
    head = b;

    //add new node b to the middle of the linked list
    b->next = a->next;
    a->next = b;

    //add new node b to the end of the linked list
    b->next = NULL;
    struct node *p = a;
    while(p->next!=NULL){
        p = p->next;
    }
    p->next = b;

    //deletion of the nodes in the beginning
    //use a temporary pointer to point to the beginning
    struct node *p = head;
    head = head -> next;
    free(p);

    //deletion of the nodes in the middle
    struct node *p = a->next;
    a->next = a->next->next;
    free(p);

    //deletion at the end
    b->next=NULL;
    struct node *p=a;
    while()
    


}

//insertion sort

struct node {
    int data;
    struct node *next;
};

void show_list(struct node *head){
    struct node *p=head;
    if(head==NULL) return;
    while(p!=NULL){
        printf("->%d", p->data);
        p=p->next;
    }
    printf("\n");
}

struct node *add_to_sorted_list(struct node *head, struct node *p){
    struct node *prev_node, *curr_node;

    if(head==NULL) return p;

    if(p->data < head->data){
        p->next=head;
        return p;
    }

    prev_node=head;
    curr_node=prev_node->next;
    while(curr_node != NULL){
        if(p->data < curr_node->data){
            break;
        }
        prev_node=curr_node;
        curr_node=curr_node->next;
    }
    
    prev_node->next=p;
    p->next=curr_node;
    return head;

    
}

int main(){
    int i;
    struct node *p, *head=NULL;
    while(scanf("%d", &i)!=EOF){
        p=(struct node *)malloc(sizeof(struct node));
        p->data=i;
        p->next=NULL;
        head=add_to_sorted_list(head, p);
    }
    show_list(head);
}
