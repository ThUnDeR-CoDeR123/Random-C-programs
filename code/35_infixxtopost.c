#include <stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int val)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow! Cannot push %d to the stack\n", val);
    }
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

// func for in post
int isoperand(char a)
{
    if (48 <= a <= 57)
    {
        return 1;
    }
    return 0;
}
int isoperator(char a)
{
    if (a == '+' || a == '-' || a == '*' || a == '/')
    {
        return 1;
    }
    return 0;
}
int precedence(char a)
{
    if (a == '*' || a == '/')
    {
        /* code */
        return 1;
    }
    else if (a == '+' || a == '-')
    {
        return 0;
    }
    return -1;
}
char * infixtopostfix(char *exp)
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (char *)malloc(s->size * (sizeof(char)));
    char * postfix=(char * )malloc((strlen(exp)+1)*sizeof(char));
    int i=0; //to track infix traversal
    int j=0; //to track postfix traversal
    while (exp[i]!='\0')
    {
        if(!isoperator(exp[i])){
            postfix[j] = exp[i];
            j++;
            i++;
        }
        else{
            if(precedence(exp[i])> precedence(s->arr[s->top])){
                push(s, exp[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
                //note here we do not incrementing the i cuz you know why
                //to pop untill above if is true
                //# the beauty of while loop
            }
        }
    }
    while (!isEmpty(s))    
    {
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}
int main()
{
    char exp[100] = "1-4*2+36/3";
    printf("%s",infixtopostfix(exp));
    /*
    int i=0;
    while(postfix[i]!='\0'){
        printf("%c",postfix[i]);
    }*/
    return 0;
}
