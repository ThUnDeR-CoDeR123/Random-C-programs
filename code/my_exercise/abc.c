#include<stdio.h>
#include<math.h>
#include <stdlib.h>

struct node
{
    int data;
    int pos;
    struct node *left;
    struct node *right;
};
struct node * createnode(int val,int pos){
    struct node * n = (struct node *)malloc(sizeof(struct node));
    n->data=val;
    n->pos=pos;
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
void insert(struct node * root,int key,int pos){
    struct node * prev =NULL;
    while(root!=NULL){
        if(root->data==key){
            printf("Cant insert value already exist");
            return;
        }
        else if(root->data>key){
            prev=root;
            root=root->left;
        }
        else{
            prev=root;
            root=root->right;
        }
    }
    struct node * new=createnode(key,pos);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
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
int main() {
	//code

	int n,q;
	scanf("%d %d",&n,&q);
	int m=2*(n-1);
	int arr[(2*n-1)];
    struct node * root=NULL;
	for(int i=0;i<2*(n-1);i++) {
            if(i%2!=0){
                int key;
                scanf("%d",&key);
                insert(root,key,i);
            }
    }
	while(q--){
	    int a,b;
	    scanf("%d %d",&a,&b);
	    if(a<=arr[m-1]&&b<=arr[m-1]){
	        int i=searchIter(root,a)->pos;
	        int j=searchIter(root,b)->pos;
	        int a1=(int)floor(log2(i));
	        int b1=(int)floor(log2(j));
	        int ans=(a1>b1)?a1-b1:b1-a1;
            printf("%d %d     %f %f     %d %d\n",a1,b1,log2(a),log2(b),a,b);
	    }
	    
	}
	    
	
	return 0;
}