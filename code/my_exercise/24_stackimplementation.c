#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int * arr;
};
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
int main(){
    struct stack *s;
    s->size = 80;
    s->top=-1;
    s->arr=(int *) malloc(s->size*sizeof(int));
    
    
    s->arr[0]=7;
    s->top++;
    //chk is stack is empty
    if(isempty(s)){
        printf("the stack is empty\n");
    }
    else{
        printf("stack is not empty\n");
    }
    
    return 0;


}