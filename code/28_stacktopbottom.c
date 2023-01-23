#include<stdio.h>
#include<stdlib.h>
 
struct stack{
    int size ;
    int top;
    int * arr;
};
 
int isEmpty(struct stack* ptr){
    if(ptr->top == -1){
            return 1;
        }
        else{
            return 0;
        }
}
 
int isFull(struct stack* ptr){
    if(ptr->top == ptr->size - 1){
        return 1;
    }
    else{
        return 0;
    }
}
 
void push(struct stack* ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
int pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}
 
int peek(struct stack* sp, int i){
    int arrayInd = sp->top -i + 1;
    if(arrayInd < 0){
        printf("Not a valid position for the stack\n");
        return -1;
    }
    else{
        return sp->arr[arrayInd];
    }
}
 
int stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
 
int stackBottom(struct stack* sp){
    return sp->arr[0];
}
void swap(struct stack *s, int i, int j)
{
    // i>j
    int k = 0;
    int p = s->top;
    int temp1, temp2;
    int n = s->size - 2;
    int arr[n];

    //pop
    while (s->top > i && k < n)
    {
        arr[k] = pop(s);

        k++;
    }
    if (s->top == i)
    {
        temp1 = pop(s);
    }
    while (s->top > j && k < n)
    {
        arr[k] = pop(s);
        k++;
    }
    //push
    if (s->top == j)
    {
        temp2 = pop(s);
        push(s, temp1);
    }

    while (s->top < i && k>=0)
    {
        push(s, arr[k]);
        k--;
    }
    if (s->top == i)
    {
        push(s, temp2);
    }
    while(s->top<p && k>=0){
        push(s,arr[k]);
        k--;
    }
}
int main(){
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 50;
    sp->top = -1;
    sp->arr = (int *) malloc(sp->size * sizeof(int));
    printf("Stack has been created successfully\n");
 
    printf("Before pushing, Full: %d\n", isFull(sp));
    printf("Before pushing, Empty: %d\n", isEmpty(sp));
    push(sp, 1);
    push(sp, 23);
    push(sp, 99);
    push(sp, 75);
    push(sp, 3);
    push(sp, 64);
    push(sp, 57);
    push(sp, 46);

    swap(sp,3,2);
    
    // Printing values from the stack
    for (int j = 1; j <= sp->top + 1; j++)
    {
        printf("The value at position %d is %d\n", j, peek(sp, j));
    }
    //      printf("The top most value of this stack is %d\n", stackTop(sp));
    // printf("The bottom most value of this stack is %d\n", stackBottom(sp));
    return 0;
}
