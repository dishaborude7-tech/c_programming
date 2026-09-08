#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *START = NULL, *START_temp = NULL;

void display()
{
    struct node *temp;
    if (START == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        temp = START;
        while (temp->next != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
        printf("%d\t", temp->data);
    }
}

void create_node()
{
    int value;
    struct node *p, *temp;
    p = malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("enter any value of linked list: ");
    scanf("%d", &value);
    p->data = value;
    p->next = NULL;

    if (START == NULL)
    {
        START = p;
    }
    else
    {
        temp = START;
        // Traverse until temp points to the LAST node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Link the last node to the new node p
        temp->next = p; // logic of inserting a new node at the end of the linked list
    }
}

void create_2nd_list()
{
    int value;
    struct node *p, *temp;
    p = malloc(sizeof(struct node));

    if (p == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("enter any value of new linked list: ");
    scanf("%d", &value);
    p->data = value;
    p->next = NULL;

    if (START_temp == NULL)
    {
        START_temp = p;
    }
    else
    {
        temp = START_temp;
        // Traverse until temp points to the LAST node
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p; // logic of inserting a new node at the end of the linked list
    }
}

void insert_1st()

{
    struct node *p;
    int value;
    p = malloc(sizeof(struct node));
    printf("enter value to insert at first: ");
    scanf("%d", &value);
    p->data = value;
    p->next = START;
    START = p;
    printf("the new list is:");
    display();
}

void insert_last()
{
    int value;
    struct node *p, *temp;
    if (START == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        printf("enter value to insert at last");
        scanf("%d", &value);
        p = malloc(sizeof(struct node));
        p->data = value;
        p->next = NULL;
        temp = START;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = p;
        printf("the new list is:");
        display();
    }
}

void delete_1st()
{
    struct node *temp;
    if (START == NULL)
    {
        printf("linked list is empty");
    }
    else
    {
        temp = START;
        START = START->next;
        printf("the deleted value is: %d", temp->data);
        temp->next = NULL;
        free(temp);
    }
}

void delete_last()
{
    struct node *temp;
    if (START == NULL)
    {
        printf("linked list is empty");
    }
    else if (START->next == NULL)
    {
        START = NULL;
    }
    else
    {
        temp = START;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        printf("the deleted value is: %d", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

void count_nodes()
{
    struct node *t;
    int c = 0;
    if (START == NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        t = START;
        while (t != NULL)
        {
            c++;
            t = t->next;
        }
        printf("the number of nodes in the list is %d\n", c);
    }
}

void sum_nodes()
{
    struct node *t;
    int sum = 0;
    if (START == NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        t = START;
        while (t != NULL)
        {
            sum += t->data;
            t = t->next;
        }
        printf("the sum of nodes in the list is %d\n", sum);
    }
}

void min_node()
{
    struct node *t;
    int min;
    if (START == NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        t = START;
        min = t->data;
        while (t != NULL)
        {
            if (t->data < min)
            {
                min = t->data;
            }
            t = t->next;
        }
        printf("the minimum value in the list is %d\n", min);
    }
}

void max_node()
{
    struct node *t;
    int max;
    if (START == NULL)
    {
        printf("the list is empty\n");
    }
    else
    {
        t = START;
        max = t->data;
        while (t != NULL)
        {
            if (t->data > max)
            {
                max = t->data;
            }
            t = t->next;
        }
        printf("the maximum value in the list is %d\n", max);
    }
}

void insert_at_position()
{
    struct node *p, *t;
    int pos, value, i = 1;
    printf("enter the position to insert:");
    scanf("%d", &pos); // pos is the position to insert the new node
    printf("enter the value to insert:");
    scanf("%d", &value);
    p = malloc(sizeof(struct node)); // p is the pointer to the new node to be inserted
    p->data = value;
    p->next = NULL;
    t = START; // t is the pointer to traverse the list
    while (i < pos - 1 && t != NULL)
    {
        t = t->next;
        i++;
    }
    if (t == NULL)
    {
        printf("position not found"); // there is nothing to insert at the given position
    }
    else
    {
        p->next = t->next;
        t->next = p;
    }
    printf("the new list is:");
    display();
}

void delete_at_position()
{
    struct node *t, *p;
    int pos, i = 1;
    printf("enter the position to delete:");
    scanf("%d", &pos);
    t = START;
    while (i < pos - 1 && t != NULL)
    {
        t = t->next;
        i++;
    }
    if (t == NULL || t->next == NULL)
    {
        printf("position not found");
    }
    else
    {
        p = t->next;
        t->next = p->next;
        p->next = NULL;
        printf("the deleted value is: %d", p->data);
        free(p);
    }
}

struct node *mid_point_address()
{
    struct node *even = START, *odd = START;
    while (even != NULL && even->next != NULL)
    {
        even = even->next->next;
        odd = odd->next;
    }
    return odd;
}

void concate()
{
    int size1, size2;
    struct node *temp;
    printf("enter the size of first linked list:");
    scanf("%d", &size1);
    while (size1 > 0)
    {
        create_node();
        size1--;
    }
    printf("1st linked list created successfully\n");
    display();
    printf("\nenter the size of second linked list:");
    scanf("%d", &size2);
    while (size2 > 0)
    {
        create_2nd_list();
        size2--;
    }
    // Concatenate the two lists at the end of 1st singly linked list which is pointed by START and 2nd singly linked list which is pointed by START_temp
    if (START == NULL)
    {
        START = START_temp;
    }
    else
    {
        temp = START;
        while (temp->next != NULL) // Traverse until pointer stops at the last node of the first linked list
        {
            temp = temp->next;
        }
        temp->next = START_temp; // Link the last node of the first list to the head of the second list
    }
    START_temp = NULL; // Reset START_temp after concatenation to NULL
    printf("the new list is:");
    display();
}

void reverse_nodes()
{
    int temp, len = 1, i;
    struct node *first, *last, *mid;
    last = START;
    while (last->next != NULL) // stop at the last node of the linked list
    {
        len++;
        last = last->next;
    }
    first = START;             // stop at the first node of the linked list
    mid = mid_point_address(); // stop at the middle node of the linked list
    for (i = 0; i < len / 2; i++)
    {
        while (mid->next != last) // stop at the middle node of the linked list
        {
            mid = mid->next; // move mid pointer to its position
        }
        // logic for swapping the data of first and last node of the linked list
        temp = first->data;
        first->data = last->data;
        last->data = temp;
        first = first->next;       // move first pointer to the next node
        last = mid;                // move last pointer to the middle node
        mid = mid_point_address(); // move mid pointer to the middle node of the linked list
    }
}

int main()
{
    struct node *mid;
    int ch, size, value;
    printf("======linked list operations=====");
    printf("\n1.create node\n2.insert at first\n3.insert at last\n4.delete at first\n5.delete at last\n6.display\n7.count nodes\n8.sum nodes\n9.minimum node\n10.maximum node\n11.insert at the given position\n12.delete at the given position\n13.mid point\n14.create 2nd list\n15.concate lists\n16.reverse list\n17.exit");
    while (1)
    {
        printf("\n enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {

            printf("enter the size of linked list:");
            scanf("%d", &size);
            while (size > 0)
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
        case 7:
            count_nodes();
            break;
        case 8:
            sum_nodes();
            break;
        case 9:
            min_node();
            break;
        case 10:
            max_node();
            break;
        case 11:
            insert_at_position();
            break;
        case 12:
            delete_at_position();
            break;
        case 13:
            mid=mid_point_address();
            printf("the mid point value is: %d", mid->data);
            break;
        case 14:
            printf("enter the size of second linked list:");
            scanf("%d", &size);
            while (size > 0)
            {
                create_2nd_list();
                size--;
            }
            break;
        case 15:
            concate();
            break;
        case 16:
            printf("Original linked list:\n");
            display();
            reverse_nodes();
            printf("\nReversed linked list:\n");
            display();
            break;
        case 17:
            exit(0);
        default:
            printf("invalid choice");
        }
    }
    return 0;
}
