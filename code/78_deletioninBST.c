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

void insert(struct node * root,int key){
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
    struct node * new=createnode(key);
    if(key<prev->data){
        prev->left=new;
    }
    else{
        prev->right=new;
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
struct node * inorderprevious(struct node *root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct node * deletenode(struct node * root,int key){
    struct node * inpre = NULL;
    if(root==NULL){
        printf("empty");
        return NULL;
    }
    if(root->left==NULL &&root->right==NULL){
        free(root);
        return NULL;
    }
    //searching for the node to be deleted
    if(key<root->data){
        root->left=deletenode(root->left,key);
    }
    else if(key>root->data){
        root->right=deletenode(root->right,key);
    }
    //deletion strateggy when the node is found
    else{
        inpre=inorderprevious(root);
        root->data=inpre->data;
        root->left=deletenode(root->left,inpre->data);
    }
    return root;
}

struct node * inordersuccessor(struct node *root){
    root=root->right;
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
struct node * deletenodesuc(struct node * root,int key){
    struct node * insuc = NULL;

    //main tree updation part
    if(root==NULL){
        printf("empty");
        return NULL;
    }
    if(root->left==NULL &&root->right==NULL){
        free(root);
        return NULL;
    }


    //searching for the node to be deleted
    if(key<root->data){
        root->left=deletenodesuc(root->left,key);
    }
    else if(key>root->data){
        root->right=deletenodesuc(root->right,key);
    }


    //deletion strateggy when the node is found
    else{
        insuc=inordersuccessor(root);
        root->data=insuc->data;
        root->right=deletenodesuc(root->right,insuc->data);
    }
    return root;
}
void insertpractice(struct node * root,int value){
    if(root==NULL){
        printf("empty");
        return;
    }
    struct node * prev =NULL;
    while(root!=NULL){
        if(value==root->data){
            printf("\n cant delete cuz val already exista \n");
            return;
        }
        else if(value>root->data){
            prev=root;
            root=root->right;
        }
        else{
            prev=root;
            root=root->left;
        }


    }
    struct node * new = createnode(value);
    if(value>prev->data) prev->right=new;
    else prev->left=new; 

}
struct node * dele(struct node * root,int value){
    struct node * inpre = NULL;

    //deleting part
    if(root==NULL){
        printf("empty");
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }

    //searching for the node
    if (value<root->data) root->left=dele(root->left,value);
    else if (value>root->data) root->right=dele(root->right,value);

    //deletion strategy
    else{
        inpre=inorderprevious(root);
        root->data=inpre->data;
        //sincec replacing with inorder previous
        root->left=dele(root->left,inpre->data);
    }
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
    // printf("\n %d \n",search(r,60)->data);
    printf("\n");
    dele(r,31);
    inOrder(r);
    printf("\n");
    insertpractice(r,25);
    inOrder(r);
    printf("\n");
    // printf("\n");
    // preOrder(r);
    // struct node* n = searchIter(r, 10);
    // if(n!=NULL){
    // printf("Found: %d", n->data);
    // }
    // else{
    //     printf("Element not found");
    // }
};