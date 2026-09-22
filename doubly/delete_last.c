#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next,*prev;
};
struct node *START=NULL;

void delete_last()
{
    struct node *t=START;
    if (START==NULL)
    {
        printf("Linked list is empty");
    }
    else
    {
        if(t->prev==NULL && t->next==NULL)//check for single node 
        {
            printf("Delete node data:%d\n",t->data);
            free(t);
            START=NULL;
        }
        else
        {
            while(t->next!=NULL)
            {
                t=t->next;
            }
            printf("Delete node data:%d\n",t->data);
            t->prev->next=NULL;//t->prev goes to sec.last node  and then sec.last node's next will become NULL
            free(t);
        }
    }
    
}

void insert_last()
{
    struct node *t,*p;
    t=malloc(sizeof(struct node));
    printf("\nEnter value for node:");
    scanf("%d",&t->data);
    t->prev=t->next=NULL;
    if(START==NULL)
    {
        START=t;
    }
    else
    {
        p=START;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        t->prev=p;
        p->next=t;
    }
    
}

void display()
{
    struct node *t=START;
    if(START==NULL)
    {
        printf("\nLinked list is empty");
    }
    else
    {
        while(t!=NULL)
        {
            printf("%d\t",t->data);
            t=t->next;
        }
    }
    printf("\n");
}

int main()
{
    int ch;
    while(1)
    {
        printf("\n=====MENU=====");
        printf("\n1.INSERT AT LAST\n2.DELETE AT LAST\n3.DISPLAY\n4.EXIT\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                insert_last();
                break;
            case 2:
                delete_last();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Enter valid choice\n");
        }
    }
}