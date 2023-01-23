#include<stdio.h>
#include<stdlib.h>

struct queue{
    int size;
    int frontInd;
    int backInd;
    int * arr;
};

int isFull(struct queue * q){
    if(q->backInd==q->size-1){
        return 1;
    }

    return 0;
}
int isEmpty(struct queue * q){
    if(q->backInd==q->frontInd){
        return 1;
    }
    return 0;
}
void enqueue(struct queue * q,int data){
    if(!isFull(q)){
        q->backInd++;
        q->arr[q->backInd]=data;
    }
    
}
int dequeue(struct queue * q){
    int returned =-1;
    if(!isEmpty(q)){
        
        q->frontInd++;
        returned =q->frontInd;
    }
    return returned;
}

int main(){
    struct queue  q;
    q.size=100;
    q.frontInd=0;
    q.backInd=0;
    q.arr=(int *)malloc(q.size*sizeof(int));
    // printf("%d",q->arr[q->backInd+1]);

    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    for(int i=q.frontInd+1;i<=q.backInd;i++){
        printf("%d ",q.arr[i]);
    }
    dequeue(&q);
    printf("\n");
    for(int i=q.frontInd+1;i<=q.backInd;i++){
        printf("%d ",q.arr[i]);
    }

}