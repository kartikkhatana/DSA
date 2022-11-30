// KARTIK KHATANA BTECH CSE 2nd Year 00816403221
// DATE - 23 November, 2022
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *next;
    struct node *prev;
};

void menu();

void displayList();

void insert();
void insertBeginning();
void insertLocation();
void insertEnd();

void delete ();
void deleteBeginning();
void deleteLocation();
void deleteEnd();

struct node *head;

int main()
{
    menu();
    return 0;
}

void menu()
{
    head = NULL;
    int choice;
    while (choice != 4)
    {
        printf("What action do you want to perform?\n1. Display Circular Double Linked List\n2. Insert Element in Circular Double Linked List.\n3. Delete Element from Circular Double Linked List.\n4. Exit\n");
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
            printf("Incorrect choice please try again.\n");
            break;
        }
    }
}

void displayList()
{
    printf("*******************************************************\n");
    if (head == NULL)
    {
        printf("Your Circular Double Linked List is Empty.\n");
    }
    else
    {
        struct node *temp = head;
        printf("Circular Double Linked List - \n");
        while (temp->next != head)
        {
            printf("%d ", temp->val);
            temp = temp->next;
        }

        printf("%d", temp->val);
        printf("\n");
    }
    printf("*******************************************************\n");
}

void insert()
{
    int choice;
    printf("Where do you want to insert the value?\n");
    printf("1. Beginning\n2. Location\n3. End\n");
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
    default:
        printf("Incorrect choice please try again.\n");
        break;
    }

    displayList();
}

void insertBeginning()
{
    struct node *block = (struct node *)malloc(sizeof(struct node));
    int value;
    printf("Enter the value you want to insert.\n");
    scanf("%d", &value);
    if (head == NULL)
    {
        block->val = value;
        block->prev = block;
        block->next = block;
        head = block;
    }
    else
    {

        block->val = value;
        head->prev->next = block;
        block->prev = head->prev;
        block->next = head;
        head->prev = block;
        head = block;
    }
}

void insertLocation()
{
    if (head == NULL)
    {
        printf("Please insert element in beginning first. Not able to insert Element in between in empty Circular Double Linked List.\n");
    }
    else
    {
        int choice;
        printf("Enter the value of the element after which you want to insert the new element.\n");
        scanf("%d", &choice);
        struct node *temp = head;
        while (temp->val != choice && temp->next != head)
        {
            temp = temp->next;
        }

        if (temp->val == choice)
        {

            if (temp->next != head)
            {
                int value;
                printf("Enter the value you want to insert.\n");
                scanf("%d", &value);
                struct node *block = (struct node *)malloc(sizeof(struct node));
                block->val = value;
                block->next = temp->next;
                block->prev = temp;
                temp->next->prev = block;
                temp->next = block;
            }
            else
            {
                insertEnd();
            }
        }
        else
        {
            printf("No such element found in the Circular Double Linked List.\n");
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
        int value;
        printf("Enter the value you want to insert.\n");
        scanf("%d", &value);

        struct node *block = (struct node *)malloc(sizeof(struct node));

        block->val = value;
        block->next = head;
        block->prev = head->prev;
        head->prev->next = block;
        head->prev = block;
    }
}

void delete ()
{
    if (head != NULL)
    {

        int choice;
        printf("From which position you want to delete the element?\n");
        printf("1. Beginning\n2. Location\n3. End\n");
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
        default:
            printf("Incorrect choice please try again.\n");
            break;
        }
    }
    else
    {
        printf("List is already Empty. Not able to delete more elements.\n");
    }

    displayList();
}

void deleteBeginning()
{
    struct node *temp = head;
    if (temp->next == head)
    {
        head = NULL;
        free(temp);
    }
    else
    {
        head->next->prev = head->prev;
        head->prev->next = head->next;
        head = head->next;
        free(temp);
    }
}

void deleteLocation()
{
    int choice;
    printf("Enter the value you want to delete from the List.\n");
    scanf("%d", &choice);
    struct node *temp = head;

    if (temp->val == choice)
    {
        deleteBeginning();
    }
    else
    {

        while (temp->val != choice && temp->next != head)
        {
            temp = temp->next;
        }

        if (temp->val == choice)
        {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
        }
        else
        {
            printf("No such Element Found.\n");
        }
    }
}

void deleteEnd()
{

    struct node *temp = head;
    if (temp->next == head)
    {
        deleteBeginning();
    }
    else
    {
        temp = head->prev;
        head->prev->prev->next = head;
        head->prev = head->prev->prev;
        free(temp);
    }
}