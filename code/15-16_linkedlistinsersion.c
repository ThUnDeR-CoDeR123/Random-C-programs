#include<stdio.h>
#include<stdlib.h>


//4 ways last ta given pointer thakbe bole constant time hobe insertion

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

//insert at begining
struct node* insertbegin(struct node* head,int data){
    struct node* ptr=(struct node*) malloc(sizeof(struct node));
    ptr->data=data;
    ptr->link=head;
    return ptr;
}

//insert at end
struct node* insertatend(struct node * head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));    
    struct node * p=head;
    while((p->link)!=NULL){
        p=p->link;

    }
    p->link=ptr;
    ptr->data=data;
    ptr->link=NULL;

}

void insertatmid(struct node * head,int data,int index){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    struct node * p=head;
    
    int i=0;
    while(i!=index-1){
        p=p->link;
        i++;
    }
    ptr->link=p->link;
    p->link=ptr;
    ptr->data=data;

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
    printf("\n\n");
    insertatend(head,169); //not for 0th index
    printlink(head);
    return 0;
}