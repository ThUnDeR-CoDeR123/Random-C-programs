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
int matched(char a,char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }
    return 0;
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
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='[') {
            push(&s1,exp[i]);
            // printf("pushed : %c\n",exp[i]);
            }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(isempty(&s1)){
                return 0;
            }
            char poped=pop(&s1);
            if(!matched(poped,exp[i])){
                return 0;
            }
        }
    }
    if(!isempty(&s1)) return 0;
    return 1;

}
int main(){
    char * exp="((8-)[63-4])";
    if(parenthesismatch(exp)){
        printf("yes matching!");

    }
    else printf("not matching");
    
}


