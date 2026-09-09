#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *START=NULL;
void create_node()
{
    struct node *p;
    int value;
    p=malloc(sizeof(struct node));
    printf("enter the value to insert:");
    scanf("%d",&value);
    p->data=value;
    p->next=NULL;
    
}
void main()
{
    int i;
    create_node();

}