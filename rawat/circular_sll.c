#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node* next;
};
struct node* head=NULL;

void menu();
void display();
void ins();
void insert_beginning(int ele);
void insert_location(int ele);
void insert_end(int ele);
void del();
void delete_beginning();
void delete_location(int num);
void delete_end();


int main()
{
        menu();
    return 0;
}

void menu()
{
    int ch;
    do
    {
        printf("Press '1' to display the List\nPress '2' to insert element in List\nPress '3' to delete element from List\nPress '4' to exit\n");
        printf("\nEnter operation: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            display();
            break;
        case 2:
            ins();
            break;
        case 3:
            del();
            break;
        case 4:
            printf("\n\n\nExiting....");
            break;
        
        default:
            printf("\n\n\nInvalid choice....");
            break;
        }
    } while (ch!=4);
    
}

//Display

void display()
{
    if(head==NULL)
    {
        printf("\n\nList is Empty\n\n");
        return;
    }
    struct node* head1=head;

    printf("\n\n");

    do
    {
        printf("%d ",head1->info);
        head1=head1->next;
    }
    while(head1!=head);

    printf("\n\n");
}

//Insertion

void ins()
{
    int ch;
    int ele;
    int num;

    printf("\n\nPress '1' to insert element at the beginning\nPress '2' to insert element before some element already present in List\nPress '3' to insert element at the end\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);
    printf("\nEnter number you want to insert: ");
    scanf("%d",&ele);

    switch (ch)
    {
    case 1:
        insert_beginning(ele);
        display();
        break;
    case 2:
        insert_location(ele);
        // display();
        break;
    case 3:
        insert_end(ele);
        display();
        break;
    
    default:
        printf("\n\n\nInvalid choice....\n\n");
        break;
    }
}

void insert_beginning(int ele)
{
    if(head==NULL)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node*));
        head=temp;
        head->info=ele;
        head->next=head;
        return;
    }
    struct node* head1=head->next;
    struct node* list=head;

    while(head1!=head)
    {
        list=head1;
        head1=head1->next;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node*));
    temp->info=ele;
    temp->next=head;
    list->next=temp;
    head=temp;
    
}

void insert_location(int ele)
{
    int num;

    if(head==NULL)
    {
        printf("\n\nList is empty, cannot use this operation!!!\n\n");
        return;
    }

    printf("\nEnter number in list before which you want to enter element: ");
    scanf("%d",&num);

    if(head->info==num)
    {
        insert_beginning(ele);
        display();
        return;
    }

    struct node* head1=head->next;
    struct node* list=NULL;

    while(head1!=head)
    {
        if(head1->info==num)
        {
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->info=ele;
            temp->next=head1;
            list->next=temp;
            display();
            return;
        }
        list=head1;
        head1=head1->next;
    }

    printf("\n\nNumber not present in List, cannot insert\n\n");
}

void insert_end(int ele)
{
    if(head==NULL)
    {
        struct node* temp=(struct node*)malloc(sizeof(struct node*));
        head=temp;
        head->info=ele;
        head->next=head;
        return;
    }
    
    struct node* head1=head->next;
    struct node* list=head;

    while(head1!=head)
    {
        list=head1;
        head1=head1->next;
    }
    struct node* temp=(struct node*)malloc(sizeof(struct node*));
    list->next=temp;
    temp->info=ele;
    temp->next=head;
}

//Deletion

void del()
{
    int ch;
    int num;

    if(head==NULL)
    {
        printf("\nList already empty.\n\n");
        return;
    }

    printf("\n\nPress '1' to delete element from the beginning\nPress '2' to delete element from in between the List\nPress '3' to delete element from the end\n");
    printf("\nEnter your choice: ");
    scanf("%d",&ch);

    switch (ch)
    {
    case 1:
        delete_beginning();
        display();
        break;
    case 2:
        printf("\nEnter element you want to delete : ");
        scanf("%d",&num);
        delete_location(num);
        display();
        break;
    case 3:
        delete_end();
        display();
        break;
    
    default:
        printf("\n\n\nInvalid choice....\n\n");
        break;
    }
}

void delete_beginning()
{    
    if(head->next==head)
    {
        struct node* temp=head;
        head=NULL;
        free(temp);
        return;
    }
    struct node* head1=head->next;
    struct node* list=head;

    while(head1!=head)
    {
        list=head1;
        head1=head1->next;
    }
    
    list->next=head1->next;
    head=head->next;
    free(head1);
}

void delete_location(int num)
{
    if(head->info==num)
    {
        delete_beginning();
        return;
    }

    struct node* head1=head->next;
    struct node* list=NULL;

    while(head1!=head)
    {
        if(head1->info==num)
        {
            list->next=head1->next;
            free(head1);
            return;
        }
        list=head1;
        head1=head1->next;
    }
    
    printf("\n\nElement not present in list\n\n");
}
void delete_end()
{
    if(head->next==head)
    {
        struct node* temp=head;
        head=NULL;
        free(temp);
        return;
    }

    struct node* head1=head->next;
    struct node* list=head;
    struct node* temp=NULL;

    while(head1!=head)
    {
        temp=list;
        list=head1;
        head1=head1->next;
    }
    temp->next=head;
    free(list);
}