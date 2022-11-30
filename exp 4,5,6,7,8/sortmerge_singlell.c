// KARTIK KHATANA BTECH CSE 2nd Year 00816403221
// DATE - 25 November, 2022
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
};

struct node *head1;
struct node *head2;
struct node *head3;
int count1;
int count2;
void displayList(struct node *head);
void insertElement(struct node **head, int value);
void mergeSort();
int main()
{

    // first linked list
    printf("Enter how many elements you want to enter in first linked list?.\n");
    scanf("%d", &count1);

    for (int i = 0; i < count1; i++)
    {
        printf("Enter value of node %d -", i + 1);
        int value;
        scanf("%d", &value);
        insertElement(&head1, value);
    }

    printf("First Linked List is - \n");
    displayList(head1);

    // second linked list
    printf("Enter how many elements you want to enter in second linked list?.\n");
    scanf("%d", &count2);

    for (int i = 0; i < count2; i++)
    {
        printf("Enter value of node %d -", i + 1);
        int value;
        scanf("%d", &value);
        insertElement(&head2, value);
    }

    printf("Second Linked List is - \n");
    displayList(head2);

    mergeSort();

    printf("Final Merged and Sorted Linked List is - \n");
    displayList(head3);

    if (count1 == 0 && count2 == 0)
    {
        printf("You have not entered any linked list.\n");
    }

    return 0;
}

void insertElement(struct node **head, int value)
{

    struct node *block = (struct node *)malloc(sizeof(struct node));

    if (*head == NULL)
    {
        block->val = value;
        block->next = NULL;
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
        block->next = NULL;
        temp->next = block;
    }
}

void displayList(struct node *head)
{
    struct node *temp = head;

    if (temp == NULL)
    {
        printf("Empty");
    }

    while (temp != NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }

    printf("\n");
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
        int value = temp1->val < temp2->val ? temp1->val : temp2->val;
        insertElement(&head3, value);

        if (temp1->val < temp2->val)
        {
            temp1 = temp1->next;
        }
        else
        {
            temp2 = temp2->next;
        }
    }

    struct node *remainingList;
    remainingList = temp1 != NULL ? temp1 : temp2;

    while (remainingList != NULL)
    {
        insertElement(&head3, remainingList->val);
        remainingList = remainingList->next;
    }
}