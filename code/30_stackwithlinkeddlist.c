#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node * top=NULL;
int isfull(struct node* top){
    struct node * new_node=(struct node *)malloc(sizeof(struct node));
    if(new_node==NULL){
        return 1;
    }
    else return 0;
}
int isempty(struct node* top){
    if(top->next==NULL) return 1;
    else return 0;
}
struct node * push(struct node* top,int val){
    if(isfull(top)){
        printf("stack overflow");
    }
    else{
        struct node* new_node=(struct node *)malloc(sizeof(struct node));
        new_node->data=val;
        new_node->next=top;
        top=new_node;
        return top;
    }
}
int pop(struct node ** top) 
//if we doont use double pointer then the chages will not be storedd in
// the initial top; resulting in the free of the stack memory and breaking of stack chain
{
    
    struct node *next_node=*top;
    *top=(*top)->next;
    int val=next_node->data;
    free(next_node);
    return val;
}
void print(struct node *top){
    
    while(top!=NULL){
        printf("elemet is : %d \n",top->data);
        top=top->next;
    }
}
int main(){
    struct node * s=(struct node *)malloc(sizeof(struct node));
    struct node * s1=(struct node *)malloc(sizeof(struct node));
    struct node * s2=(struct node *)malloc(sizeof(struct node));
    struct node * s3=(struct node *)malloc(sizeof(struct node));
    struct node * s4=(struct node *)malloc(sizeof(struct node));
    struct node * s5=(struct node *)malloc(sizeof(struct node));

    s->data=10;
    s->next=s1;
    s1->data=23;
    s1->next=s2;
    s2->data=43;
    s2->next=s3;
    s3->data=45;
    s3->next=s4;
    s4->data=56;
    s4->next=s5;
    s5->data=65;
    s5->next=NULL;

    print(s);
    printf("%d",isfull(s));
    s=push(s,2);
    printf("\t pushed element \t \n");
    print(s);
    printf("\n the poped val is : %d \n",pop(&s));
    print(s);
}