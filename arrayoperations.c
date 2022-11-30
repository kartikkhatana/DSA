// KARTIK KHATANA BTECH CSE 2nd Year 00816403221
// DATE - 2 November, 2022
#include <stdio.h>

void menu();

// display element
void displayArray(int myarray[], int *size);

// insert element
void insert(int myarray[], int *size);
void insertElementBeginning(int myarray[], int *size, int *valuesdone);
void insertElementEnd(int myarray[], int *size, int *valuesdone);
void insertElementLocation(int myarray[], int *size, int *valuesdone);

// delete element
void delete (int myarray[], int *size);
void deleteElementBeginning(int myarray[], int *size);
void deleteElementEnd(int myarray[], int *size);
void deleteElementLocation(int myarray[], int *size);

// search the element
void searchElement(int myarray[], int *size);

// sort array
void sortArray(int myarray[], int *size);

void showPadding();

int main()
{

    menu();
    return 0;
}

void menu()
{

    int choice;
    int arraySize = 0;
    int myarray[100];
    while (choice != 6)
    {
        printf("Press 1 to display the array.\nPress 2 to insert element in the array.\nPress 3 to delete element from the array.\nPress 4 to search element in the array.\nPress 5 to sort the array.\nPress 6 to exit.\n");
        printf("\nEnter operation: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayArray(myarray, &arraySize);
            break;
        case 2:
            insert(myarray, &arraySize);
            break;
        case 3:
            delete (myarray, &arraySize);
            break;
        case 4:
            searchElement(myarray, &arraySize);
            break;
        case 5:
            sortArray(myarray, &arraySize);
            break;
        case 6:
            break;
        default:
            printf("Invalid Option Recieved.\n");
            break;
        }

        showPadding();
    }
}

void displayArray(int myarray[], int *size)
{
    int arraySize = *size;

    if (arraySize == 0)
    {
        printf("Your array is empty.\n");
    }
    else
    {

        for (int i = 0; i < arraySize; i++)
        {
            printf("%d ", myarray[i]);
        }

        printf("\n");
    }
}

void insert(int myarray[], int *size)
{

    if (*size < 10)
    {
        int valuesno;
        int valuesdone = 0;
        printf("How many values do you want to insert?.\nEnter Choice: ");
        scanf("%d", &valuesno);
        if ((10 - (*size)) >= valuesno)
        {
            while (valuesdone < valuesno)
            {
                int choice;
                printf("\n");
                printf("Where do you want to insert the element (%d)?\n1. Beginning\n2. Location\n3. End\n4. Exit\nEnter Choice: ",valuesdone);
                scanf("%d", &choice);
                switch (choice)
                {
                case 1:
                    insertElementBeginning(myarray, size, &valuesdone);
                    break;
                case 2:
                    insertElementLocation(myarray, size, &valuesdone);
                    break;
                case 3:
                    insertElementEnd(myarray, size, &valuesdone);
                    break;
                case 4:
                    valuesdone = 10;
                    break;
                default:
                    printf("Invalid Choice\n");
                    break;
                }

                printf("Array after insertion\n");
                displayArray(myarray, size);
            }
        }
        else
        {
            printf("Cant insert %d values in the array. Array will overflow.\n", valuesno);
        }
    }
    else
    {
        printf("Array is full. No more elements can be inserted.\n");
    }
}

void insertElementBeginning(int myarray[], int *size, int *valuesdone)
{
    int value;
    printf("Enter value of the element you want to insert: ");
    scanf("%d", &value);

    for (int i = *size; i > 0; i--)
    {
        myarray[i] = myarray[i - 1];
    }

    myarray[0] = value;

    (*size)++;
    (*valuesdone)++;

    printf("Element inserted successfully in Beginning\n");
}

void insertElementEnd(int myarray[], int *size, int *valuesdone)
{
    int value;
    printf("Enter value of the element you want to insert: ");
    scanf("%d", &value);

    myarray[*size] = value;

    (*size)++;
    (*valuesdone)++;

    printf("Element inserted successfully at End\n");
}

void insertElementLocation(int myarray[], int *size, int *valuesdone)
{

    if (*size > 0)
    {
        int value;
        printf("Enter value of the element you want to insert: ");
        scanf("%d", &value);

        int location;
        printf("Enter element location where you want to insert: ");
        scanf("%d", &location);

        if (0 <= location && location <= *size)
        {
            for (int i = *size; i > location; i--)
            {
                myarray[i] = myarray[i - 1];
            }

            myarray[location] = value;

            (*size)++;
            (*valuesdone)++;

            printf("Element inserted successfully at Location\n");
        }
        else
        {
            printf("Error - Invalid Location Recieved.\n");
        }
    }
    else
    {
        printf("Error - Array is empty. Can't Insert Element at Location.\n");
    }
}

void delete (int myarray[], int *size)
{
    if (*size > 0)
    {
        int choice;
        printf("\n");
        printf("At Which position you want to delete?\n1. Beginning\n2. Location\n3. End\n4. Exit\nEnter Choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            deleteElementBeginning(myarray, size);
            break;
        case 2:
            deleteElementLocation(myarray, size);
            break;
        case 3:
            deleteElementEnd(myarray, size);
            break;
        case 4:
            break;
        default:
            printf("Invalid Choice\n");
            break;
        }

        printf("Array after deletion\n");
        displayArray(myarray, size);
    }
    else
    {
        printf("Error - Array is empty. Can't delete anymore elements.\n");
    }
}

void deleteElementBeginning(int myarray[], int *size)
{

    for (int i = 0; i < *size; i++)
    {
        myarray[i] = myarray[i + 1];
    }

    (*size)--;

    printf("Element successfully deleted from Beginning.\n");
}

void deleteElementEnd(int myarray[], int *size)
{
    (*size)--;

    printf("Element successfully deleted from End.\n");
}

void deleteElementLocation(int myarray[], int *size)
{
    int location;
    printf("Enter element location from where you want to delete: ");
    scanf("%d", &location);

    if (0 <= location && location < *size)
    {
        for (int i = location; i < *size - 1; i++)
        {
            myarray[i] = myarray[i + 1];
        }

        (*size)--;

        printf("Element successfully deleted at Location.\n");
    }
    else
    {
        printf("Error - Invalid Location Recieved.\n");
    }
}

void searchElement(int myarray[], int *size)
{
    if (*size > 0)
    {
        int val;
        printf("Enter value of the element you want to search for: ");
        scanf("%d", &val);

        for (int i = 0; i < *size; i++)
        {
            if (myarray[i] == val)
            {
                printf("Element found at index %d\n", i);
                return;
            }
        }

        printf("Element not found\n");
    }
    else
    {
        printf("Error - Can't search because Array is empty.\n");
    }
}

void sortArray(int myarray[], int *size)
{
    if (*size > 0)
    {
        int minElement, temp;
        for (int i = 0; i < (*size) - 1; i++)
        {
            minElement = i;

            for (int j = minElement + 1; j < (*size); j++)
            {

                if (myarray[minElement] > myarray[j])
                {
                    minElement = j;
                }
            }

            temp = myarray[minElement];
            myarray[minElement] = myarray[i];
            myarray[i] = temp;
        }

        printf("Result after sorting\n");
        // showPadding();
        displayArray(myarray, size);
    }
    else
    {
        printf("Error - Can't sort because Array is empty.\n");
    }
}

void showPadding()
{
    printf("******************************");
    printf("\n");
}