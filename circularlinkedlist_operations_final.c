// KARTIK KHATANA BTECH CSE 2nd Year 00816403221
// DATE - 10 November, 2022
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *head;

// display List
void displayList();

void menu();

// insert elements in circular linked list.
void insert();
void insertBeginning();
void insertLocation();
void insertEnd();

// delete elements from circular linked list.
void delete ();
void deleteBeginning();
void deleteLocation();
void deleteEnd();

int main()
{

    head = (struct node *)malloc(sizeof(struct node));
    head = NULL;
    menu();
    return 0;
}

void menu()
{
    int choice;

    while (choice != 4)
    {
        printf("Press 1 to display your Circular Linked List.\nPress 2 to insert element in the Circular Linked List.\nPress 3 to delete element from the Circular Linked List.\nPress 4 to exit.\n");
        printf("\nEnter operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayList();
            break;
        case 2:
            insert();
            break;
        case 3:
            delete ();
            break;
        case 4:
            break;
        default:
            printf("Invalid Option Recieved.\n");
            break;
        }
    }
}

void displayList()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("Your Circular Linked List is Empty.\n");
    }
    else
    {
        while (temp->next != head)
        {
            printf("%d ", temp->value);
            temp = temp->next;
        }

        printf("%d ", temp->value);
        printf("\n");
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

    printf("Circular Linked List After Insertion\n");
    displayList();
}

void insertBeginning()
{

    int val;
    printf("Enter value: ");
    scanf("%d", &val);

    struct node *block = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        block->value = val;
        block->next = block;
        head = block;
    }
    else
    {
        struct node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }

        block->value = val;
        block->next = head;
        temp->next = block;
        head = block;
    }
}

void insertLocation()
{
    if (head == NULL)
    {
        printf("Your Circular Linked List is Empty. Can't Enter elements by Location.\n");
    }
    else
    {
        int positionvalue;
        printf("Enter value of the element after which you want to insert the new element: ");
        scanf("%d", &positionvalue);

        struct node *block = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;

        while (temp->value != positionvalue && temp->next != head)
        {
            temp = temp->next;
        }

        if (temp->value == positionvalue)
        {
            int val;
            printf("Enter value: ");
            scanf("%d", &val);

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
        insertBeginning();
    }
    else
    {
        int val;
        printf("Enter value: ");
        scanf("%d", &val);

        struct node *block = (struct node *)malloc(sizeof(struct node));
        struct node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        block->value = val;
        block->next = head;
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

        printf("Circular Linked List After Deletion\n");
        displayList();
    }
    else
    {
        printf("Your Circular Linked List is Empty. Can't Delete More Elements.\n");
    }
}

void deleteBeginning()
{
    struct node *ptr = head;

    // check if single element is left in the list
    if (head->next == head)
    {
        head = NULL;
        free(ptr);
    }
    else
    {
        struct node *temp = head;

        while (temp->next != head)
        {
            temp = temp->next;
        }

        temp->next = head->next;
        head = head->next;
        free(ptr);
    }
}

void deleteLocation()
{
    int val;
    printf("Enter value of the element which you want to delete: ");
    scanf("%d", &val);

    if (head->value == val)
    {
        deleteBeginning();
    }
    else
    {
        struct node *temp = head;
        struct node *prev = head;
        while (temp->value != val && temp->next != head)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp->value == val)
        {

            struct node *ptr = temp;

            if (head->next == head)
            {
                head = NULL;
                free(ptr);
            }
            else
            {

                prev->next = ptr->next;
                free(ptr);
            }
        }
        else
        {
            printf("No Such Element Found.\n");
        }
    }
}

void deleteEnd()
{
    struct node *temp = head;

    if (head->next == head)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        while (temp->next->next != head)
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = head;
    }
}