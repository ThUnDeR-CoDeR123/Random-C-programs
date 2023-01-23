#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node * createnode(int val){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        // NOTE : since we are doinid in order traversal in BST prev will always be smaller than the root
        if (prev != NULL && prev->data > root->data)
        {
            return 0;
        }
        prev = root;
        isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *search(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == key)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct node * searchIter(struct node* root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }
        else if(key<root->data){
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return NULL;
}
int main(){
    struct node * r =createnode(50);
    struct node * r1 =createnode(30);
    struct node * r2 =createnode(60);
    struct node * r3 =createnode(20);
    struct node * r4 =createnode(35);
    struct node * r5 =createnode(55);
    struct node * r6 =createnode(65);
    struct node * r7 =createnode(32);
    struct node * r8 =createnode(40);

    /*
              50
            /   \ 
    //     /     \
    //    30      60
    //   / \      /  \
    // 20   35   55  65
           / \
    //    32 40
 
    */
   r->left=r1;
   r->right=r2;
   
   r1->left=r3;
   r1->right=r4;
   
   
   r2->left=r5;
   r2->right=r6;
   
   r4->left=r7;
   r4->right=r8;
   
    inOrder(r);
    printf("\n %d \n",search(r,60)->data);
    struct node* n = searchIter(r, 10);
    if(n!=NULL){
    printf("Found: %d", n->data);
    }
    else{
        printf("Element not found");
    }
};