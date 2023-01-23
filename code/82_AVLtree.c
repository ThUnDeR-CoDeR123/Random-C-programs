#include <stdio.h>
#include <stdlib.h>

struct avl
{
    int data;
    struct avl * left;
    struct avl * right;
    int hight;
};

struct avl *create_avl(int key)
{
    struct avl * n = (struct avl *)malloc(sizeof(struct avl));
    n->left = NULL;
    n->right = NULL;
    n->hight = 1;
    n->data = key;
    return n;
}

int gethight(struct avl * root){
    if(root==NULL) return 0;
    return root->hight;
}
int Max(int a, int b)
{
    return (a>b)?a:b;
}
int getbalancefactor(struct avl * n)
{
    if(n==NULL){
        return 0;
    }
    return gethight(n->left) - gethight(n->right);
}

struct avl * left_rotate(struct avl * x)
{

    struct avl *y = x->right;
    struct avl *t2 = y->left;
    y->left = x;
    x->right = t2;
    x->hight = Max(gethight(x->left), gethight(x->right)) + 1;
    y->hight = Max(gethight(y->left), gethight(y->right)) + 1;
    return y;
}
struct avl * right_rotate(struct avl * y)
{
    struct avl *x = y->left;
    struct avl *t2 = x->right;
    x->right = y;
    y->left = t2;
    x->hight = Max(gethight(x->left), gethight(x->right)) + 1;
    y->hight = Max(gethight(y->left), gethight(y->right)) + 1;
    return x;
}
struct avl * insert(struct avl * root, int key)
{
    if (root == NULL){

        return (create_avl(key));
    }
    if (key < root->data){

        root->left = insert(root->left, key);
    }
    else if (key > root->data){
        root->right = insert(root->right, key);


    }
    root->hight = 1 + Max(gethight(root->left),gethight(root->right));
    int bf = getbalancefactor(root);
  
    // insertion done at left left case
    if (bf > 1 && key < root->left->data)
    {
        return right_rotate(root);
    }
    // right right case
    else if (bf < -1 && key > root->right->data)
    {
       
        return left_rotate(root);
    }
    // left right case
    else if (bf > 1 && key > root->left->data)
    {
        root->left=left_rotate(root->left);
        return right_rotate(root);
    }
    // right left case
    else if (bf < -1 && key < root->right->data)
    {
        root->right=right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}
void inOrder(struct avl *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
void preOrder(struct avl  *root)
{
    if (root != NULL)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
int main(){
    struct avl * root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 0);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 0);
    preOrder(root);

    printf("\n");

    inOrder(root);
    return 0;
};