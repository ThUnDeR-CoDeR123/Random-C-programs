#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size ;
    int top;
    char * arr;
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
 
void push(struct stack* ptr, char val){
    if(isFull(ptr)){
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}
 
char pop(struct stack* ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else{
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stackTop(struct stack* sp){
    return sp->arr[sp->top];
}
int matched(char a,char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    return 0;
    
}
char stackBottom(struct stack* sp){
    return sp->arr[0];
}
int parenthesismatch( char * exp){
    struct stack s1;
    s1.size=100;
    s1.top=-1;
    s1.arr=(char *)malloc(s1.size*sizeof(char));

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[') {
            push(&s1,exp[i]);
            // printf("pushed : %c\n",exp[i]);
            }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isEmpty(&s1)){
                return 0;
            }
            char poped=pop(&s1);
            if(!matched(poped,exp[i])){
                return 0;
            }
        }
    }
    if(!isEmpty(&s1)) return 0;
    return 1;

}
int priority(char a){
    if(a=='+'||a=='-') return 1;
    else if(a=='*'||a=='/') return 2;
    else if(48<=a<=57) return 0;
}
int main(){
    // struct stack s;
    // s.size=100;
    // s.top=-1;
    // s.arr=(char *)malloc(s.size*sizeof(char));
    char * exp="182-45*3-65/3*4/6-8/4+3";
    // printf("%d",parenthesismatch(exp));
    // printf("%d to %d",'0','9'); //-> 48 to 57
    char * post=(char *)malloc(strlen(exp));
    for(int i=0;exp[i]!='\0';i++){
        if(priority(exp[i]==0)) post[i]=
    }
    return 0;

}