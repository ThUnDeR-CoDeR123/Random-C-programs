#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};
void printlist(struct node * head){
    struct node * ptr=head;
    do{
        printf("Element : %d \n",ptr->data);
        ptr=ptr->next;
    }while(ptr!=head);
}
struct node * insertfirst(struct node * head,int data){
    struct node * ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    struct node * p=head->next;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    return ptr;

}
int main(){
    struct node * head = (struct node *) malloc(sizeof(struct node));
    struct node * first = (struct node *) malloc(sizeof(struct node));
    struct node * second = (struct node *) malloc(sizeof(struct node));
    struct node * third = (struct node *) malloc(sizeof(struct node));
    struct node * fourth = (struct node *) malloc(sizeof(struct node));
    struct node * fifth = (struct node *) malloc(sizeof(struct node));
    head->data=0;
    head->next=first;
    first->data=5;
    first->next=second;
    second->data=4;
    second->next=third;
    third->data=3;
    third->next=fourth;
    fourth->data=2;
    fourth->next=fifth;
    fifth->data=1;
    fifth->next=head;
    printf("before\n");
    printlist(head);
    head=insertfirst(head,58);
    printf("after\n");
    printlist(head);
    
    return 0;
}