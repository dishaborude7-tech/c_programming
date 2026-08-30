#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * START=NULL;

void create_node()
{
    int value;
    struct node *p, *temp;
    p = malloc(sizeof(struct node));
    printf("enter any value of linked list: ");
    scanf("%d",&value);
    p->data=value;
    p->next=NULL;
    if(START==NULL)
    {
        START=p;
    }
    else
    {
        temp=START;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
    }
}

void insert_1st()


{
    struct node *p;
    int value;
    p=malloc(sizeof(struct node));
    printf("enter value to insert at first: ");
    scanf("%d", &value);
    p->data=value;
    p->next=START;
    START=p;
}

void insert_last()
{
    int value;
    struct node *p,*temp;
    if(START==NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        printf("enter value to insert at last");
        scanf("%d",&value);
        p=malloc(sizeof(struct node));
        p->data=value;
        p->next=NULL;
        temp=START;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;
    
    }
}

void delete_1st()
{
    struct node *temp;
    if(START==NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        temp=START;
        START=START->next;
        temp->next=NULL;
        free(temp);
    }
}

void delete_last()
{
    struct node *temp;
    if(START==NULL)
    {
        printf("linked list is empty");
    }
    else if(START->next==NULL)
    {
        free(START);
        START=NULL;
    }
    else
    {
        temp=START;

        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        free(temp->next);
        temp->next=NULL;
    }
}

void display()
{
    struct node *temp;
    if(START==NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        temp=START;
        while(temp->next!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("%d\t",temp->data);
    }
    
}

int main()
{
    int ch,size,value;
    char ans='y';
    printf("======linked list operations=====");
    printf("\n1.create node\n2.insert at first\n3.insert at last\n4.delete at first\n5.delete at last\n6.display");
    while(ans=='y' || ans=='Y')
    {
        printf("\n enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            {
                
                printf("enter the size of linked list:");
                scanf("%d",&size);
                while(size>0)
                {
                    create_node();
                    size--;
                }
                break;
            }
            case 2:
                insert_1st();
                break;
            case 3:
            
            insert_last();
            break;
            case 4:
                delete_1st();
                break;
            case 5:
                delete_last();
                break;
            case 6:
                display();
                break;
            default:
                printf("invalid choice");
        }
        printf("\n do you want to continue(y/n):");
        scanf(" %c",&ans);   
    }
    return 0;
}


        