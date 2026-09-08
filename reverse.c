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

struct node *mid_point_address()
{
    struct node *odd, *even;
    if(START==NULL)
    {
        printf("The list is empty\n");
        return NULL;
    }
    else
    {
        odd=START;
        even=START;
        
        while(even!=NULL && even->next!=NULL)
        {
            odd=odd->next;
            even=even->next->next;
        }
    }
    
    return odd;
}

// Function to reverse the singly linked list 

void reverse_nodes()
 {
    int temp,len=1,i;
    struct node *first,*last,*mid;
    last=START;
    while(last->next!=NULL)//stop at the last node of the linked list
    {
        len++;
        last=last->next;
    }
    first=START;//stop at the first node of the linked list
    mid=mid_point_address();//stop at the middle node of the linked list
    for(i=0;i<len/2;i++)
    {
        while(mid->next!=last)//stop at the middle node of the linked list
        {
            mid=mid->next;//move mid pointer to its position
        }
        //logic for swapping the data of first and last node of the linked list
        temp=first->data;
        first->data=last->data;
        last->data=temp;
        first=first->next;//move first pointer to the next node
        last=mid;//move last pointer to the middle node
        mid=mid_point_address();//move mid pointer to the middle node of the linked list
    }
 }

int main()
{
    int size;
    printf("enter the size of linked list:");
    scanf("%d",&size);
    while(size>0)
    {
        create_node();
        size--;
    }
    printf("Original linked list:\n");
    display();
    reverse_nodes();
    printf("\nReversed linked list:\n");
    display();
}