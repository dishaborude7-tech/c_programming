#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
};
struct node * START=NULL,*START_temp=NULL;
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

void create_node()
{
    int value;
    struct node *p, *temp;
    p = malloc(sizeof(struct node));
    
    if (p == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("enter any value of linked list: ");
    scanf("%d",&value);
    p->data=value;
    p->next=NULL;

    if (START==NULL)
    {
        START=p;
    }
    else
    {
        temp=START;
        // Traverse until temp points to the LAST node
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        // Link the last node to the new node p
        temp->next=p;//logic of inserting a new node at the end of the linked list
    }
}

void create_2nd_list()
{
    int value;
    struct node *p, *temp;
    p = malloc(sizeof(struct node));
    printf("enter any value of new linked list: ");
    scanf("%d",&value);
    p->data=value;
    p->next=NULL;

    if (START_temp==NULL)
    {
        START_temp=p;
    }
    else
    {
        temp=START_temp;
        // Traverse until temp points to the LAST node
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=p;//logic of inserting a new node at the end of the linked list
    }
}

void concate()
{
    struct node *temp;
    // Concatenate the two lists at the end of 1st singly linked list which is pointed by START and 2nd singly linked list which is pointed by START_temp
    if(START==NULL)
    {
        START=START_temp;
    }
    else
    {
        temp=START;
        while(temp->next!=NULL)// Traverse until pointer stops at the last node of the first linked list
        {
            temp=temp->next;
        }
        temp->next=START_temp;// Link the last node of the first list to the head of the second list
    }
    START_temp=NULL;// Reset START_temp after concatenation to NULL
    printf("the new list is:");
    display();

}

int main()
{
    int size1,size2;
    printf("enter the size of first linked list:");
    scanf("%d",&size1);
    for(int i=0;i<size1;i++)
    {
        create_node();
    }
    printf("enter the size of second linked list:");
    scanf("%d",&size2);
    for(int i=0;i<size2;i++)
    {
        create_2nd_list();
    }
    concate();
    return 0;
}

