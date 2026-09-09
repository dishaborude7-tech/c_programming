#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *START = NULL;

// delete last node
void deleteNode()
{
    struct node *t, *p;
    if (START == NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        t = START;
        while (t!= NULL)
        {
            p = t;
            t = t->next;
        }
        p->next = NULL;
        printf("the delete node is %d\n",p->data);
        free(p);
        
    }
}

void create_node()
{
    struct node*p,*t;
    int value;
    p=malloc(sizeof(struct node));
    printf("enter value:");
    scanf("%d",&value);
    p->data=value;
    p->next=NULL;
    if(START==NULL)
    {
        START=p;
    }
    else
    {
        t=START;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=p;
    }
}

void main()
{
    int i, size, value;
    struct node *f;

    f = malloc(sizeof(struct node));

    printf("Enter size of linked list");
    scanf("%d", &size);
    while(size>0)//new node create
    {
        create_node();
        size--;
    }
    deleteNode();
    
}
