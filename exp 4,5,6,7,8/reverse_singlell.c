// KARTIK KHATANA BTECH CSE 2nd Year 00816403221
// DATE - 24 November, 2022
#include <stdio.h>
#include <stdlib.h>
void menu();

struct node
{
    int value;
    struct node *next;
};

struct node *head;

// delete in linked list
void delete ();
void deleteBeginning();
void deleteEnd();
void deleteLocation();

// insert in linked list
void insert();
void insertBeginning();
void insertEnd();
void insertLocation();

// display linked list
void displayLinkedList();

// count no of nodes
void countNodes();

// reverse List
void reverse();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;

    head = NULL;
    displayLinkedList();

    while (choice != 5)
    {
        printf("Press 1 to insert element in the Single Linked List.\nPress 2 to delete element from the Single Linked List.\nPress 3 to Show Node Count.\nPress 4 to reverse Single Linked List.\nPress 5 to exit.");
        printf("\nEnter operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            countNodes();
            break;
        case 4:
            reverse();
            break;
        case 5:
            break;
        default:
            printf("Invalid Option Recieved.\n");
            break;
        }
    }
}

void insert()
{
    int choice;
    printf("Where do you want to insert the element? \n1. Beginning\n2. Location\n3. End\n4. Exit\nEnter Choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        insertBeginning();
        break;
    case 2:
        insertLocation();
        break;
    case 3:

        insertEnd();
        break;
    case 4:
        break;
    default:
        printf("Invalid Choice\n");
        break;
    }

    printf("Linked List After Insertion\n");
    displayLinkedList();
}

void insertBeginning()
{
    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct node *block = (struct node *)malloc(sizeof(struct node));

    block->value = val;
    block->next = head;
    head = block;
}

void insertLocation()
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
        struct node *temp = head;
        while (temp->value != positionvalue && temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->value == positionvalue)
        {
            int val;
            printf("Enter value: ");
            scanf("%d", &val);
            struct node *block = (struct node *)malloc(sizeof(struct node));

            block->value = val;
            block->next = temp->next;
            temp->next = block;
        }
        else
        {
            printf("No Such Element Found.\n");
        }
    }
}

void insertEnd()
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
        struct node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        block->value = val;
        block->next = NULL;
        temp->next = block;
    }
}

void delete ()
{
    if (head != NULL)
    {
        int choice;
        printf("From where do you want to delete the element? \n1. Beginning\n2. Location\n3. End\n4. Exit\nEnter Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            deleteBeginning();
            break;
        case 2:
            deleteLocation();
            break;
        case 3:
            deleteEnd();
            break;
        case 4:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }

        printf("Linked List After Deletion\n");
        displayLinkedList();
    }
    else
    {
        printf("The Linked List is Empty. Can't Delete More Elements.\n");
    }
}

void deleteBeginning()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
}

void deleteLocation()
{

    int val;
    printf("Enter value of the element which you want to delete: ");
    scanf("%d", &val);
    struct node *temp = head;
    if (temp->value != val)
    {
        struct node *prev = head;
        while (temp->value != val && temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->value == val)
        {
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
        deleteBeginning();
    }
}

void deleteEnd()
{
    struct node *temp = head;

    if (temp->next != NULL)
    {
        struct node *prev = head;

        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }

        prev->next = NULL;
        free(temp);
    }
    else
    {
        deleteBeginning();
    }
}

void displayLinkedList()
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

void countNodes()
{
    int counter = 0;
    struct node *temp = head;
    while (temp != NULL)
    {
        counter += 1;
        temp = temp->next;
    }

    printf("No of Nodes in the Linked List are - %d", counter);
    printf("\n");
}

void reverse()
{
    if (head == NULL)
    {
        printf("Your Single Linked List is Empty. Add atleast 2 elements to reverse the List.\n");
    }
    else
    {
        struct node *current = head;
        struct node *prev = NULL;
        struct node *next = NULL;
        if (current->next != NULL)
        {
            while (current != NULL)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }

            head = prev;

            displayLinkedList();
        }
        else
        {
            printf("Your Single Linked List has only 1 Element. Add atleast 2 elements to reverse the List.\n");
        }
    }
}