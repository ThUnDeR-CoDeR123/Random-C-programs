#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * link;

};


//function to print the link list

void printlink(struct node * ptr){
    while(ptr!=NULL)
    {
        printf("ELEMENT : %d \n",ptr->data);
        ptr = ptr->link;
    }
}
int main(){
    struct node *head;
    struct node *first;
    struct node *second;
    struct node *third;
    struct node *fourth;

 // Allocate memory for nodes in the linked list in Heap
    head= (struct node*) malloc(sizeof(struct node));
    first= (struct node*) malloc(sizeof(struct node));
    second= (struct node*) malloc(sizeof(struct node));
    third= (struct node*) malloc(sizeof(struct node));
    fourth= (struct node*) malloc(sizeof(struct node));
    // head= (struct node*) malloc(sizeof(struct node));


    //allocate value

    head->data=10;
    head->link=first;

    first->data=20;
    first->link=second;

    second->data=30;
    second->link=third;

    third->data=40;
    third->link=fourth;

    fourth->data=50;
    fourth->link=NULL;

    printlink(head);
    return 0;
}