#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void del(struct node * head,int indx){
    struct node * ptr=head;
    struct node * ptr_af=head;
    while(--indx){
        ptr=ptr->next;
    }
    ptr_af=ptr->next;
    ptr->next=ptr_af->next;
    free(ptr_af);
}

void printlink(struct node * ptr){
    while(ptr!=NULL)
    {
        printf("ELEMENT : %d \n",ptr->data);
        ptr = ptr->next;
    }
}
int main()
{
    // printf("hello\n");
    struct node *head= (struct node *)malloc(sizeof(struct node));
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));
    struct node *sixth = (struct node *)malloc(sizeof(struct node));
    // printf("therre \n");
    head->data = 11;
    head->next = first;
    first->data = 12;
    first->next = second;
    second->data = 13;
    second->next = third;
    third->data = 14;
    third->next = fourth;
    fourth->data = 15;
    fourth->next = fifth;
    fifth->data = 16;
    fifth->next = sixth;
    sixth->data = 77;
    sixth->next = NULL;
    // printf("fds");
    // printf("ELEMENT : %d \n",first->data);
    printlink(head);
    del(head,3);
    printf("%d \n",third->data);
    printlink(head);
    return 0;
}