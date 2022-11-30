#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coe, deg;
    struct node *next;
};

void List_Entry(struct node **head, int n);
void display(struct node **head);
void insert_end(struct node ***head, int coe, int deg);
void polynomial_merge(struct node **head, struct node **l1, struct node **l2);

int main()
{
    struct node *head = NULL;
    struct node *l1 = NULL;
    struct node *l2 = NULL;

    int n1, n2;

    printf("\n\nEnter number of terms in 1st Polynomial: ");
    scanf("%d", &n1);
    List_Entry(&l1, n1);
    printf("\n\nPolynomial 1 :\n\n");
    display(&l1);

    printf("\n\nEnter number of terms in 2nd polynomial: ");
    scanf("%d", &n2);
    List_Entry(&l2, n2);
    printf("\n\nPolynomial 2 :\n\n");
    display(&l2);

    polynomial_merge(&head, &l1, &l2);

    printf("\n\nPolynomials after merging:\n\n");
    display(&head);

    return 0;
}

void List_Entry(struct node **head, int n)
{
    int z = n;
    while (z--)
    {
        int coe, deg;

        printf("Enter coefficient of term %d: ", n - z);
        scanf("%d", &coe);
        printf("Enter degree of term %d: ", n - z);
        scanf("%d", &deg);

        insert_end(&head, coe, deg);
    }
}

void insert_end(struct node ***head, int coe, int deg)
{
    if (**head == NULL)
    {
        struct node *temp = (struct node *)malloc(sizeof(struct node));

        temp->next = **head;
        temp->coe = coe;
        temp->deg = deg;
        **head = temp;
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));

    struct node *head1 = **head;
    struct node *list = **head;

    while (head1 != NULL)
    {
        list = head1;
        head1 = head1->next;
    }
    list->next = temp;
    temp->coe = coe;
    temp->deg = deg;
    temp->next = NULL;
}

void display(struct node **head)
{
    if (*head == NULL)
    {
        printf("\n\n0\n\n");
        return;
    }
    struct node *head1 = *head;

    printf("\n\n");

    while (head1 != NULL)
    {
        printf("( %d (x^%d) )", head1->coe, head1->deg);
        if (head1->next != NULL)
            printf(" + ");
        head1 = head1->next;
    }

    printf("\n\n");
}

void polynomial_merge(struct node **head, struct node **l1, struct node **l2)
{
    struct node *list1 = *l1;
    struct node *list2 = *l2;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->deg == list2->deg)
        {
            insert_end(&head, (list1->coe + list2->coe), list1->deg);
            list1 = list1->next;
            list2 = list2->next;
        }
        else if (list1->deg > list2->deg)
        {
            insert_end(&head, list1->coe, list1->deg);
            list1 = list1->next;
        }
        else
        {
            insert_end(&head, list2->coe, list2->deg);
            list2 = list2->next;
        }
    }
    while (list1 != NULL)
    {
        insert_end(&head, list1->coe, list1->deg);
        list1 = list1->next;
    }
    while (list2 != NULL)
    {
        insert_end(&head, list2->coe, list2->deg);
        list2 = list2->next;
    }
}