#include <stdio.h>
#include <stdlib.h>

struct block
{
    int data;
    struct block *next;
};

void traverseLinkedList(struct block *head)
{
    while (head != NULL)
    {
        printf("%d\n", head->data);
        head = head->next;
    }

    printf("********\n");
}

struct block *insertAtFirst(struct block *head, int data)
{
    struct block *newhead = (struct block *)malloc(sizeof(struct block));

    newhead->next = head;
    newhead->data = data;

    return newhead;
}

void insertInBetween(struct block *head, int index, int data)
{

    struct block *newblock = (struct block *)malloc(sizeof(struct block));
    int i = 0;
    while (i != index - 1)
    {
        head = head->next;

        i++;
    }

    newblock->next = head->next;
    head->next = newblock;
    newblock->data = data;
}

void insertAtEnd(struct block *head, int data)
{
    struct block *newblock = (struct block *)malloc(sizeof(struct block));

    while (head->next != NULL)
    {
        head = head->next;
    }

    head->next = newblock;
    newblock->data = data;
    newblock->next = NULL;
}

struct block *deleteAtFirst(struct block *head)
{
    struct block *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}

void deleteAtIndex(struct block *head, int index)
{

    int i = 0;

    while (i != index - 1)
    {
        head = head->next;
        i++;
    }

    struct block *ptr = head->next;
    head->next = ptr->next;
    free(ptr);
}

void deleteAtLast(struct block *head)
{

    struct block *ptr = head;

    while (ptr->next != NULL)
    {
        head = head->next;
        ptr = head->next;
    }

    head->next = NULL;

    free(ptr);
}

struct block *deleteValue(struct block *head, int value)
{
    struct block *ptr = head->next;
    while (ptr->data != value)
    {
        
        head = head->next;
        ptr = head->next;
    }

    head->next = ptr->next;
    free(ptr);

    return head;
}

int main()
{

    struct block *block1;
    struct block *block2;
    struct block *block3;

    block1 = (struct block *)malloc(sizeof(struct block));
    block2 = (struct block *)malloc(sizeof(struct block));
    block3 = (struct block *)malloc(sizeof(struct block));

    block1->data = 99;
    block2->data = 98;
    block3->data = 97;

    block1->next = block2;
    block2->next = block3;
    block3->next = NULL;

    traverseLinkedList(block1);

    block1 = insertAtFirst(block1, 101);

    traverseLinkedList(block1);

    insertInBetween(block1, 2, 505);

    traverseLinkedList(block1);

    insertAtEnd(block1, 120);

    insertAtEnd(block1, 240);

    traverseLinkedList(block1);

    // block1 = deleteAtFirst(block1);
    deleteAtIndex(block1, 1);

    traverseLinkedList(block1);

    deleteAtLast(block1);

    traverseLinkedList(block1);

    deleteAtLast(block1);

    traverseLinkedList(block1);

   deleteValue(block1,97);

     traverseLinkedList(block1);

    return 0;
}