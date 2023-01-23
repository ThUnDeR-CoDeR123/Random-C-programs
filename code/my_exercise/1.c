#include<stdio.h>
int main(){
    int i=1;//100
    int * p ;//= &i;//100
    int *q;
    q=&i;
    p=q;
    *q=5;
    printf("%d",*p);

    return 0;
}