#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;
struct node
{
    int data;
    struct node *next;
};

void enqueue(int val)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
        printf("Queue Full");
    else
    {
        n->data = val;
        n->next = NULL;
        if (f == NULL && r == NULL)
        {
            f = r = n;
        }
        else
        {
            r->next = n;
            r = n;
        }
    }
}

// printing the elements of the linked list
void printlink(struct node *ptr)
{
    printf("printing the elements of the linked list");
    struct node *p = ptr;
    while (p != NULL)
    {
        printf("ELEMENT : %d \n", p->data);
        p = p->next;
    }
}

int dequeue()
{
    int val = -1;
    struct node *ptr = f;
    if (f == NULL)
    {
        printf("queue Empty\n");
    }
    else
    {
        f = f->next;
        val = ptr->data;
        free(ptr);
        // return val;
    }
    return val;
}
int main()
{

    printlink(f);
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(1560);
    printlink(f);
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
    printf("Dequeuing element %d\n", dequeue());
}