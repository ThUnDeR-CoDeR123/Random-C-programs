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
void preorder(struct node * root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
int main(){

    struct node * p=createnode(2);
    struct node * p1=createnode(1);
    struct node * p2=createnode(4);
    p->left=p1;
    p->right=p2;
    preorder(p);
}