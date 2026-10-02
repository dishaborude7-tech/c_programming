#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int data;
    struct stack *next;
};
struct stack *START=NULL;
int TOP=-1, MAX=1000;

void push()//logic is same as insert_last() in singly linked list
{
    struct stack *t;
    t=malloc(sizeof(struct stack));
    if(TOP==MAX-1)
    {
        printf("Stack is full");
    }
    else
    {
        printf("\nEnter value for node:");
        scanf("%d",&t->data);
        t->next=NULL;
        if(START==NULL)
        {
            START=t;
            TOP++;
        }
        else if(TOP==MAX-1)
        {
            printf("Stack is full");
        }
        else
        {
            struct stack *p=START;
            while(p->next!=NULL)
            {
                p=p->next;
            }
            p->next=t;
            TOP++;
        }
    }
}

void pop()//logic is same as delete_last() in singly linked list
{
    struct stack *t=START,*p=START;
    if(START==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        if(t->next==NULL)//check for single node 
        {
            printf("Delete node data:%d\n",t->data);
            free(t);
            START=NULL;
            TOP--;
        }
        else
        {
            while(t->next!=NULL)
            {
                t=t->next;
            }
            printf("Delete node data:%d\n",t->data);
            while(p->next!=t)//p will go to sec.last node
            {
                p=p->next;
            }
            p->next=NULL;
            free(t);
            TOP--;
        }
    }
}

void display()
{
    struct stack *t=START;
    if(START==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        while(t!=NULL)
        {
            printf("%d ",t->data);
            t=t->next;
        }
    }
}

void peek()
{
    struct stack *t=START;
    if(START==NULL)
    {
        printf("Stack is empty");
    }
    else
    {
        while(t->next!=NULL)
        {
            t=t->next;
        }
        printf("Top element is:%d",t->data);
    }
}


int main()
{
    int choice;
    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();
                break;
            case 2:pop();
                break;
            case 3:peek();
                break;
            case 4:display();
                break;
            case 5:exit(0);
                break;
            default:printf("Invalid choice");
        }
    }
    return 0;
}



