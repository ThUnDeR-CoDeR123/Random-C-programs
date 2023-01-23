#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head)
{
    if (head == NULL)
    {
        return;
    }
    struct node *p = head;
    while (p->next != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
struct node *insertatbegining(struct node *head, int d)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = d;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        return head;
    }
    p->next = head;
    head = p;
    return head;
}
struct node *insertatend(struct node *head, int d)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    p->data = d;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        return head;
    }
    while (ptr->next != NULL)
    {
        printf("%d\n", ptr->data);
        printf("%d\n", ptr->next);
        ptr = ptr->next;
    }
    printf("----%d\n", p);

    ptr->next = p;
    printf("%d\n", ptr->data);
    printf("%d\n", ptr->next);
    return head;
}
struct node *particularlocation(struct node *head, int d)
{
    int pos;
    printf("Enter the position where to insert ");
    scanf("%d", &pos);
    struct node *p = (struct node *)malloc(sizeof(struct node));
    p->data = d;
    p->next = NULL;
    if (head == NULL)
    {
        head = p;
        return head;
    }
    struct node *ptr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    p->next = ptr->next;
    ptr->next = p;
    return head;
}
struct node *deletebegining(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
}
struct node *deleteatend(struct node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    struct node *ptr = head;
    struct node *p = NULL;
    while (ptr->next != NULL)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return head;
}
struct node *deleteatposition(struct node *head)
{
    if (head == NULL)
    {

        return NULL;
    }
    int pos;
    printf("Enter the position where to delete ");
    scanf("%d", &pos);
    struct node *p = NULL;
    struct node *ptr = head;
    for (int i = 1; i < pos; i++)
    {
        p = ptr;
        ptr = ptr->next;
    }
    p->next = ptr->next;
    free(ptr);
    return head;
}
void createlist(struct node *head)
{
    char ch;
    int i = 1;
    printf("\n Enter the value for %d node : ", i);
    scanf("%d", &head->data);
    head->next = NULL;
    i++;
    printf("\n press n to quit ,any other value to continue\n");
    fflush(stdin);
    ch = getchar();
    while (ch != 'n')
    {
        head->next = (struct node *)malloc(sizeof(struct node));
        if (head->next == NULL)
        {
            printf("\n out of memory");
            exit(0);
        }
        head = head->next;
        printf("\n Enter the value for %d node : ", i);
        scanf("%d", &head->data);
        head->next = NULL;
        i++;
        printf("\n press 'n' to quit any other key to continue");
        fflush(stdin);
        ch = getchar();
    }
}
int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("\n out of memory");
        exit(0);
    }
    int d;
    createlist(head);
    int ch;
    printf("\n 1. to insert at begining, 2. to insert at end, 3. to insert at particular position, \n4. to delete at begining, 5. to delete at end, 6. to delete at particular position "); 
 printf("\n enter the choice "); 
 scanf("%d",&ch); 
 switch(ch) 
 {
    case 1:
        printf("\nEnter the value of data : ");
        scanf("%d", &d);
        head = insertatbegining(head, d);
        break;
    case 2:
        printf("\nEnter the value of data : ");
        scanf("%d", &d);
        head = insertatend(head, d);
        break;
    case 3:
        printf("\nEnter the value of data : ");
        scanf("%d", &d);
        head = particularlocation(head, d);
        break;
    case 4:
        head = deletebegining(head);
        break;
    case 5:
        head = deleteatend(head);
        break;
    case 6:
        head = deleteatposition(head);
        break;
    default:
        printf("Wrong choice");
        break; 
 } 
 printf("The final Linked list \n"); 
 traverse(head); 
 return 0;
}