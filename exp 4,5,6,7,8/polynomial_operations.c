// KARTIK KHATANA BTECH CSE 2nd Year 00816403221
// DATE - 25 November, 2022
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val, degree;
    struct node *next;
};

struct node *head1;
struct node *head2;
struct node *head3;
int count1;
int count2;
void displayList(struct node *head);
void insertElement(struct node **head, int value, int deg);
void mergeSort();
int main()
{

    // first linked list
    printf("Enter how many elements you want to enter in first polynomial?.\n");
    scanf("%d", &count1);

    for (int i = 0; i < count1; i++)
    {
        printf("Enter coefficient of node %d -", i + 1);
        int value;
        scanf("%d", &value);
        printf("Enter degree of node %d -", i + 1);
        int deg;
        scanf("%d", &deg);
        insertElement(&head1, value, deg);
    }

    printf("First polynomial is - \n");
    displayList(head1);

    // second linked list
    printf("Enter how many elements you want to enter in second polynomial?.\n");
    scanf("%d", &count2);

    for (int i = 0; i < count2; i++)
    {
        printf("Enter coefficient of node %d -", i + 1);
        int value;
        scanf("%d", &value);
        printf("Enter degree of node %d -", i + 1);
        int deg;
        scanf("%d", &deg);
        insertElement(&head2, value, deg);
    }

    printf("Second polynomial is - \n");
    displayList(head2);

    mergeSort();

    printf("Final polynomial is - \n");
    displayList(head3);

    if (count1 == 0 && count2 == 0)
    {
        printf("You have not entered any polynomial.\n");
    }

    return 0;
}

void insertElement(struct node **head, int value, int deg)
{

    struct node *block = (struct node *)malloc(sizeof(struct node));

    if (*head == NULL)
    {
        block->val = value;
        block->next = NULL;
        block->degree = deg;
        *head = block;
    }
    else
    {
        struct node *temp = *head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        block->val = value;
        block->degree = deg;
        block->next = NULL;
        temp->next = block;
    }
}

void displayList(struct node *head)
{
    printf("**************************************\n");

    struct node *temp = head;

    if (temp == NULL)
    {
        printf("Empty");
    }

    while (temp != NULL)
    {
        printf("%dx^%d  ", temp->val, temp->degree);
        temp = temp->next;
    }

    printf("\n");

    printf("**************************************\n");
}

void mergeSort()
{

    struct node *temp1 = head1;
    struct node *temp2 = head2;

    if (count1 == 0)
    {
        head3 = head2;
        return;
    }

    if (count2 == 0)
    {
        head3 = head1;
        return;
    }

    while (temp1 != NULL && temp2 != NULL)
    {

        struct node *temp = temp1->degree > temp2->degree ? temp1 : temp2;

        if (temp1->degree == temp2->degree)
        {
            insertElement(&head3, temp1->val + temp2->val, temp->degree);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
        {

            insertElement(&head3, temp->val, temp->degree);
            if (temp1->degree > temp2->degree)
            {
                temp1 = temp1->next;
            }
            else
            {
                temp2 = temp2->next;
            }
        }
    }

    struct node *remainingList;
    remainingList = temp1 != NULL ? temp1 : temp2;

    while (remainingList != NULL)
    {
        insertElement(&head3, remainingList->val, remainingList->degree);
        remainingList = remainingList->next;
    }
}