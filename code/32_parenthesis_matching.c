#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char * arr;
};
int isempty(struct stack * s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isfull(struct stack * s){
    if(s->top==s->size-1){
        return 1;
    }
    return 0;
}
void push(struct stack * s,char val){
    if(!isfull(s)){
    s->top++;
    s->arr[s->top]=val;
    }
    else printf("stack overflow");
}
char pop(struct stack * s){
    if(!isempty(s)){
        char val= s->arr[s->top];
        s->top--;
        return val;
    }
    else{
        printf("stack underflow");
    }
}
int parenthesismatch( char * exp){
    struct stack s1;
    s1.size=100;
    s1.top=-1;
    s1.arr=(char *)malloc(s1.size*sizeof(char));

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(') push(&s1,exp[i]);
        else if(exp[i]==')'){
            if(!isempty(&s1)){
                pop(&s1);
            }
            else{
                return 0;
            }
        }
    }
    if(!isempty(&s1)) return 0;
    return 1;

}
int main(){
    char * exp="(8-63-4))";
    if(parenthesismatch(exp)){
        printf("yes matching!");

    }
    else printf("not matching");
    
}














/*-----------------parenthesis matching using linked list---------------------*/
// struct node{
//     char data;
//     struct node * next;
    
// };
// struct node * push(struct node* top,char val){
//     if (isfull(top)){
//         printf("stack overflow");
//     }
//     else{
//         struct node* new_node=(struct node *)malloc(sizeof(struct node));
//         new_node->data=val;
//         new_node->next=top;
//         top=new_node;
//         return top;
//     }
// }

// int isfull(struct node* top){
//     struct node * new_node=(struct node *)malloc(sizeof(struct node));
//     if(new_node==NULL){
//         return 1;
//     }
//     else return 0;
// }
// int isempty(struct node* top){
//     if(top->next==NULL) return 1;
//     else return 0;
// }
// int pop(struct node ** top) 
// //if we doont use double pointer then the chages will not be storedd in
// // the initial top; resulting in the free of the stack memory and breaking of stack chain
// {
//     struct node * next_node=*top;
//     *top=(*top)->next;
//     int val=next_node->data;
//     free(next_node);
//     return val;
// }
// int parenthesismatch( char * exp){
//     struct node * st= (struct node *)malloc(sizeof(struct node));
//     st=NULL;
//     for(int i=0;exp[i]!='\0';i++){
//         if(exp[i]=='(') push(st,exp[i]);
//         else if(exp[i]==')'){
//             if(st!=NULL){
//                 pop(&st);
//             }
//             else{
//                 return 0;
//             }
//         }
//     }
//     if(st!=NULL) return 0;
//     return 1;

// }
// int main(){
//     char * exp="(8*9-2-1)";
//     if(parenthesismatch(exp)) printf("yes");
//     else printf("no");
// }