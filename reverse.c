#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *START=NULL;

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

int mid_point_address()
{
    struct node *slow,*fast;
    if(START==NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        slow=fast=START;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
    }
    return slow;
}
// Function to reverse the singly linked list 
void reverse_nodes()
 {
    int temp,length=0,i;
    struct node *first,*last,*mid;
    
    
 }