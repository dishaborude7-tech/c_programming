#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *START=NULL, *START_COPY=NULL;
void create_node()
{
    struct node *p,*t;
    int value;
    p=malloc(sizeof(struct node));
    printf("enter the value to insert:");
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

int len_list()
{
    struct node *t;
    int count=0;
    t=START;
    while(t!=NULL)
    {
        count++;
        t=t->next;
    }
    return count;
}

void display()
{
    struct node *t;
    if(START_COPY==NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        t=START_COPY;
        while(t->next!=NULL)
        {
            printf("%d\t",t->data);
            t=t->next;
        }
        printf("%d\t",t->data);
    }
}

void copy_list()
{
    struct node *copy,*og=START,*temp;
    int len=len_list();
    while(len>0)
    {
        copy=malloc(sizeof(struct node));
        copy->data=og->data;
        copy->next=NULL;
        if(START_COPY==NULL)
        {
            START_COPY=copy;
        }
        else
        {
            temp=START_COPY;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=copy;
        }
        len--;
        og=og->next;
    }

}

int main()
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
    printf("the copy list is:");
    copy_list();
    display();
}