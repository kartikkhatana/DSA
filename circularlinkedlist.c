#include<stdio.h>
#include<stdlib.h>

struct block{
   int val;
   struct block* next;
};

void traverse(struct block* head){

    struct block* ptr = head;
    do{
      printf("Element %d\n",ptr->val);
      ptr = ptr->next;
    }
    while(ptr != head);

    printf("**********\n");
}

struct block* insertAtFirst(struct block* head, int val){
    struct block* ptr = head;
    struct block* newblock = (struct block*)malloc(sizeof(struct block));

    do{
      ptr = ptr->next;
    }
    while(ptr->next != head);

    ptr->next = newblock;
    newblock->next = head;
    newblock->val = val;

    return newblock;
}

int main(){

    struct block* head;
    struct block* block1;
    struct block* block2;
    struct block* block3;

    head = (struct block*)malloc(sizeof(struct block));
    block1 = (struct block*)malloc(sizeof(struct block));
    block2 = (struct block*)malloc(sizeof(struct block));
    block3 = (struct block*)malloc(sizeof(struct block));

    head->next = block1;
    block1->next = block2;
    block2->next = block3;
    block3->next = head;

    head->val = 1;
    block1->val = 2;
    block2->val = 3;
    block3->val = 4;

    traverse(head);

    head = insertAtFirst(head,50);

    traverse(head);

    head = insertAtFirst(head,100);

    traverse(head);

    return 0;
}