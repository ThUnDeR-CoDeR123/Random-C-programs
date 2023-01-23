#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int * arr;

};
int isempty(struct stack *s){ // why here * and variable name should be together???? why cant there be space between them
    if(s->top==-1) return 1;
    else return 0;
}
int isfull(struct stack *s){
    if(s->top==s->size-1) return 1;
    else return 0;
}
int push(struct stack *s,int val){
    if(isfull(s)){
        printf("Stac Overflow");
        return -1;
    }
    else{
        s->top++;
        s->arr[s->top]=val;
        return s->top;
    }
}
int pop(struct stack *s){
    if(isempty(s)){
        printf("Stack Underflow");
        return -1;
    }
    else {
        int val=s->arr[s->top];
        s->top--;
        return val;
    }
}
int peek(struct stack *s,int i){
    if(s->top-i+1<0){
        printf("invalid position");
        return -1;

    }
    else{
        printf("Element found : %d ",s->arr[s->top-i+1]);
        return s->arr[s->top-i+1];
    }
}
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);
    push(sp, 89);
    push(sp, 6);  
    push(sp, 5);  
    push(sp, 75);  

    // Printing values from the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    return 0;
}