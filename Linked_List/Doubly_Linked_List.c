#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int c, i, j, n, s, found, pos, swap;
struct node *head, *p, *p2, *tail, *new, *min, *start;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

void create()
{
    system("cls");
    printf("Enter number of elements for linked list: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    p = malloc(sizeof(struct node));
    head = p;
    head->prev = NULL;
    scanf("%d", &p->info);
    for (i = 1; i < n; i++)
    {
        tail = malloc(sizeof(struct node));
        tail->prev = p;
        p->next = tail;
        p = tail;
        scanf("%d", &p->info);
    }
    p->next = NULL;
    printf("\nAll elements have been entered... ");
    getch();
}

void view()
{
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
}

void search()
{
    found = pos = 0;
    p = head;
    scanf(" %d", &s);
    while (p != NULL)
    {
        pos++;
        if (p->info == s)
        {
            found = 1;
            break;
        }
        p = p->next;
    }
}

void insert()
{
p:
    system("cls");
    new = malloc(sizeof(struct node));
    printf("Linked List: ");
    view();
    printf("\nEnter element you want to insert in Linked List: ");
    scanf("%d", &new->info);
    printf("Enter position for new element(1-%d): ", n + 1);
    scanf("%d", &pos);
    if (pos < 1 || pos > n + 1)
    {
        printf("\nInvalid Position! ");
        getch();
        goto p;
    }
    else if (pos == 1) // Insert at beginning of list
    {
        new->prev = NULL;
        new->next = head;
        head->prev = new;
        head = new;
    }
    else if (pos == n + 1) // Insert at the end of list
    {
        tail->next = new;
        new->prev = tail;
        new->next = NULL;
        tail = new;
    }
    else // Insert in the middle of list
    {
        p = head;
        for (int i = 1; i < pos - 1; i++)  
            p = p->next;
        new->prev = p;
        new->next = p->next;
        p->next->prev = new;
        p->next = new; 
    }
    n++;
    printf("\nNew Linked List: ");
    view();
    getch();
}

void delete ()
{
    system("cls");
    printf("Delete by searching or entering position?");
    printf("\n1 - Searching");
    printf("\n2 - Entering position");
    printf("\nEnter choice(1-2): ");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        system("cls");
        printf("Enter element you want to delete from linked list: ");
        search();
        if (found == 0)
        {
            printf("%d not found in linked list!", s);
            getch();
            return;
        }
        break;
    case 2:
    p:
        system("cls");
        printf("Linked List: ");
        view();
        printf("\nEnter position of element you want to delete from linked list(1-%d): ", n);
        scanf("%d", &pos);
        if (pos < 1 || pos > n)
        {
            printf("\nInvalid Position! ");
            getch();
            goto p;
        }
        break;
    default:
        printf("Invalid Input!");
        break;
    }
    if (pos == 1)       // Delete first element of list
    {
        p = head;
        head = head->next;
        head->prev = NULL;
        free(p);
    }
    else if (pos == n)  // Delete last element of list
    {
        p = tail;
        tail->prev->next = NULL;
        tail = tail->prev;
        free(p);
    }
    else                // Delete a middle element of list
    {
        p = head;
        for (int i = 1; i < pos; i++)
            p = p->next;
        p->prev->next = p->next;
        p->next->prev = p->prev;
        free(p);
    }
    n--;
    printf("\nNew Linked List: ");
    view();
    getch();
}

void main()
{
    int run = 0;
    do
    {
    y:
        system("cls");
        printf("Enter choice");
        printf("\n1 - Create a Linked List");
        printf("\n2 - View Linked List");
        printf("\n3 - Search an element in Linked List");
        printf("\n4 - Insert an element into Linked List");
        printf("\n5 - Delete an element from Linked List");
        printf("\n6 - Exit");
        if (run == 0) // Make user create Linked List if running for first time
        {
            printf("\n\n(Please create Linked List first before performing any other operation)\n");
            scanf("%d", &c);
            if (c != 1 && c != 6)
            {
                printf("Press 1 to create Linked List first!\n");
                getch();
                goto y;
            }
            run = 1;
        }
        else
        {
            printf("\n\n");
            scanf("%d", &c);
        }
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            system("cls");
            view();
            getch();
            break;
        case 3:
            system("cls");
            printf("Enter the element you want to search: ");
            search();
            if (found == 1)
                printf("\n%d found in linked list at location: %d", s, pos);
            else
                printf("\n%d not found in linked list!", s);
            getch();
            break;
        case 4:
            insert();
            break;
        case 5:
            delete ();
            break;
        case 6:
            exit(0);
        default:
            printf("\nInvallid Input!");
            getch();
            break;
        }
    } while (c != 6);
}