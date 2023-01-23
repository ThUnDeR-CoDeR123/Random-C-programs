#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * prev;
    struct node * next;

};

void traversalboth(struct node * head){
    struct node * ptr = head;
    //for forward traversal
    do{
        printf("Element next %d \n",ptr->data);
        ptr=ptr->next;    
    }while(ptr!=head);
    //for backward traversal
        ptr=ptr->prev;
    do{
        ptr=ptr->prev;
        printf("Element before %d \n",ptr->data);
        
        
    }while(ptr!=head);
    
}
struct node * createnode(struct node * hread,int data){
    struct node * p=(struct node *)
}
void insertatany(struct node * head,int data,int index){
    struct node * p=(struct node *)malloc(sizeof(struct node));
    struct node * ptr=head;
    
    int i=0;
    while(i!=index-1){
        ptr=ptr->next;
        i++;
    }
    p->data=data;
    p->next=ptr->next;
    ptr->next->prev=p;
    p->prev=ptr;
    ptr->next=p;

}

int main(){
    

    //declaring

    struct node * dl1=(struct node *) malloc(sizeof(struct node));
    struct node * dl2=(struct node *) malloc(sizeof(struct node));
    struct node * dl3=(struct node *) malloc(sizeof(struct node));
    struct node * dl4=(struct node *) malloc(sizeof(struct node));
    struct node * dl5=(struct node *) malloc(sizeof(struct node));
    struct node * dl6=(struct node *) malloc(sizeof(struct node));
    struct node * dl7=(struct node *) malloc(sizeof(struct node));
    struct node * dl8=(struct node *) malloc(sizeof(struct node));
    struct node * dl9=(struct node *) malloc(sizeof(struct node));
    struct node * head=dl1;


    //initialize
    dl1->data=110;
    dl1->next=dl2;
    dl1->prev=dl9;

    dl2->data=120;
    dl2->next=dl3;
    dl2->prev=dl1;

    dl3->data=130;
    dl3->next=dl4;
    dl3->prev=dl2;

    dl4->data=140;
    dl4->next=dl5;
    dl4->prev=dl3;

    dl5->data=150;
    dl5->next=dl6;
    dl5->prev=dl4;

    dl6->data=160;
    dl6->next=dl7;
    dl6->prev=dl5;

    dl7->data=170;
    dl7->next=dl8;
    dl7->prev=dl6;

    dl8->data=180;
    dl8->next=dl9;
    dl8->prev=dl7;

    dl9->data=190;
    dl9->next=dl1;
    dl9->prev=dl8;
    insertatmid(head,5,2);
    insertatmid(head,5,5);
    traversalboth(head);
    return 0;
}