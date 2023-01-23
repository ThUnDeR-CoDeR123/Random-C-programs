#include<stdio.h>
#include<stdlib.h>

//structure 

struct stack{
    int size;
    int top;
    int * arr;
};


//functions

int isempty(struct stack * ptr){
    if(ptr->top==-1){
        return 1;

    }
    else{
        return 0;
    }
}

int isfull(struct stack * ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int push(struct stack * st, int val){
    if(isfull(st)){
        printf("stack Overflow");
        return -1;
    }
    else{
        st->top++;
        st->arr[st->top]=val;
        return st->top;
    }
}
int pop(struct stack * st){
    if(isempty(st)){
        printf("stack Underflow\n");
        return -1;
    }
    else{
        int val=st->arr[st->top];
        st->top--;
        return val;
    }
}
//---------------------------------------------peek--------------------------------
int peek(struct stack * st,int i){
    if(st->top-i+1<0){
        printf("not a valid position\n");
        return -1;
    }
    else{
        printf("found element : %d",st->arr[st->top-i+1]);
        return st->arr[st->top-i+1];
    }
}
int main(){
    struct stack *s;
    s->size = 5;
    s->top=-1;
    s->arr=(int *) malloc(s->size*sizeof(int));
    
    
    push(s,10);
    push(s,20);
    push(s,30);
    push(s,40);
    push(s,90);
    push(s,70);
    //chk is stack is empty
    //arrow operator( -> ) = does first deferencing and then dot
    if(isempty(s)){
        printf("the stack is empty\n");

    }
    else{
        printf("stack is not empty\n");
    }
    peek(s,2);
    return 0;


}