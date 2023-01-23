#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node * createnode(int data){
    struct node * p = (struct node * )malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;
    p->data=data;
    return p;

}
int main(){
    //root node
    // struct node * p = (struct node * )malloc(sizeof(struct node));
    // p->left=NULL;
    // p->right=NULL;
    // p->data=2;
    // //second node
    // struct node * p1 = (struct node * )malloc(sizeof(struct node));
    // p1->left=NULL;
    // p1->right=NULL;
    // p1->data=1;
    // //third node
    // struct node * p2 = (struct node * )malloc(sizeof(struct node));
    // p2->left=NULL;
    // p2->right=NULL;
    // p2->data=4;
    // //linkng the root node with children
    // p->left=p1;
    // p->right=p2;
    struct node * p=createnode(2);
    struct node * p1=createnode(1);
    struct node * p2=createnode(4);
    p->left=p1;
    p->right=p2;
}