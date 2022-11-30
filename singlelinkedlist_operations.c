// KARTIK KHATANA BTECH CSE 2nd Year 00816403221
// DATE - 10 November, 2022
#include <stdio.h>
#include <stdlib.h>
void menu();

struct node
{
    int value;
    struct node *next;
};

// delete in linked list
void delete (struct node **head);
void deleteBeginning(struct node **headpointer);
void deleteEnd(struct node **headpointer);
void deleteLocation(struct node **headpointer);

// insert in linked list
void insert(struct node **head);
void insertBeginning(struct node **head);
void insertEnd(struct node *head);
void insertLocation(struct node *head);

// display linked list
void displayLinkedList(struct node *head);

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    displayLinkedList(head);

    while (choice != 3)
    {
        printf("Press 1 to insert element in the Single Linked List.\nPress 2 to delete element from the Single Linked List.\nPress 3 to exit.\n");
        printf("\nEnter operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert(&head);
            break;
        case 2:
            delete (&head);
            break;
        case 3:
            break;
        default:
            printf("Invalid Option Recieved.\n");
            break;
        }
    }
}

void insert(struct node **head)
{
    int choice;
    printf("Where do you want to insert the element? \n1. Beginning\n2. Location\n3. End\n4. Exit\nEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insertBeginning(head);
        break;
    case 2:
        insertLocation(*head);
        break;
    case 3:

        insertEnd(*head);
        break;
    case 4:
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }

    printf("Linked List After Insertion\n");
    displayLinkedList(*head);
}

void insertBeginning(struct node **head)
{
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct node *block = (struct node *)malloc(sizeof(struct node));

    block->value = val;
    block->next = (*head);
    *head = block;
}

void insertLocation(struct node *head)
{

    if (head == NULL)
    {
        printf("Linked List is empty. Please first insert element in beginning.\n");
    }
    else
    {

        int positionvalue;
        printf("Enter value of the element after which you want to insert the new element: ");
        scanf("%d", &positionvalue);
        while (head->value != positionvalue && head->next != NULL)
        {
            head = head->next;
        }

        if (head->value == positionvalue)
        {
            int val;
            printf("Enter value: ");
            scanf("%d", &val);
            struct node *block = (struct node *)malloc(sizeof(struct node));

            block->value = val;
            block->next = head->next;
            head->next = block;
        }
        else
        {
            printf("No Such Element Found.\n");
        }
    }
}

void insertEnd(struct node *head)
{

    if (head == NULL)
    {
        printf("Linked List is empty. Please first insert element in beginning.\n");
    }
    else
    {
        int val;
        printf("Enter value: ");
        scanf("%d", &val);
        struct node *block = (struct node *)malloc(sizeof(struct node));
        while (head->next != NULL)
        {
            head = head->next;
        }

        block->value = val;
        block->next = NULL;
        head->next = block;
    }
}

void delete (struct node **headpointer)
{
    if (*headpointer != NULL)
    {
        int choice;
        printf("From where do you want to delete the element? \n1. Beginning\n2. Location\n3. End\n4. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            deleteBeginning(headpointer);
            break;
        case 2:
            deleteLocation(headpointer);
            break;
        case 3:
            deleteEnd(headpointer);
            break;
        case 4:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }

        printf("Linked List After Deletion\n");
        displayLinkedList(*headpointer);
    }
    else
    {
        printf("The Linked List is Empty. Can't Delete More Elements.\n");
    }
}

void deleteBeginning(struct node **headpointer)
{
    struct node *temp = *headpointer;
    *headpointer = (*headpointer)->next;
    free(temp);
}

void deleteLocation(struct node **headpointer)
{

    int val;
    printf("Enter value of the element which you want to delete: ");
    scanf("%d", &val);
    struct node *head = *headpointer;
    if (head->value != val)
    {
        struct node *prev = head;
        while (head->value != val && head->next != NULL)
        {
            prev = head;
            head = head->next;
        }

        if (head->value == val)
        {
            struct node *temp = prev->next;
            prev->next = temp->next;
            free(temp);
        }
        else
        {
            printf("No Such Element Found.\n");
        }
    }
    else
    {
        deleteBeginning(headpointer);
    }
}

void deleteEnd(struct node **headpointer)
{
    struct node *head = *headpointer;

    if (head->next != NULL)
    {
        struct node *prev = head;

        while (head->next != NULL)
        {
            prev = head;
            head = head->next;
        }

        prev->next = NULL;
        free(head);
    }
    else
    {
        deleteBeginning(headpointer);
    }
}

void displayLinkedList(struct node *head)
{
    if (head == NULL)
    {
        printf("Your Single Linked List is Empty\n");
    }
    else
    {
        struct node *temp = head;
        // printf("%d",head->value);
        while (temp != NULL)
        {
            printf("%d ", temp->value);
            temp = temp->next;
        }

        printf("\n");
    }
}