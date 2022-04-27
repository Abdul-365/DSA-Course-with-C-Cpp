#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int choice, n;

struct node
{
    int info;
    struct node *next;
}*head, *p, *p2, *p3, *tail, *new, *min, *start;

void create()
{
    system("cls");
    printf("Enter number of elements for linked list: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    tail = malloc(sizeof(struct node));
    head = p = tail;
    scanf("%d", &p->info);
    for(int i = 1; i < n; i++)
    { 
        tail = malloc(sizeof(struct node));     
        p->next = tail; 
        p = tail;
        scanf("%d", &p->info);
    }
    p->next = NULL;
    printf("\nAll elements have been entered... ");
    getch();
}

void view ()
{
    p = head;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
}

void search ()
{
    int found, pos, item;
    char q;
    found = pos = 0;
    p = head;
    scanf(" %d", &item);
    if(q == 'n')    // For normal linked list
    {
        while (p != NULL)
        {
            pos++;
            if (p->info == item)
            {
                found = 1;
                break;
            }
            p = p->next;
        }
    }
    else            // For sorted linked list
    {
        while (p != NULL && p->info <= item)       
        {
            pos++;
            if (p->info == item)
            {
                found = 1;
                break;
            }
            p = p->next;
        }
    }
}

void insert()
{
    p:
    int pos;
    system("cls");
    new = malloc(sizeof(struct node));
    printf("Linked List: ");
    view();
    printf("\nEnter element you want to insert in Linked List: ");
    scanf("%d", &new->info);
    printf("Enter position for new element(1-%d): ", n+1);
    scanf("%d", &pos);
    if(pos < 1 || pos > n+1)
    {
        printf("\nInvalid Position! ");
        getch();
        goto p;
    }
    else if(pos == 1)   // Insert at beginning of list
    {
        new->next = head;
        head = new;
    }
    else if(pos == n+1) // Insert at the end of list
    {
        tail->next = new;
        new->next = NULL;
        tail = new;
        /*p = head;
        while(p->next != NULL)
            p = p->next;
        p->next = new;
        new->next = NULL;*/
    }
    else                // Insert in the middle of list
    {
        p = head;
        for (int i = 1; i < pos - 1; i++) 
            p = p->next;
        new->next = p->next;
        p->next = new;
    }
    n++;
    printf("\nNew Linked List: ");
    view();
    getch();
}

void delete ()
{
    int found, pos, item;
    system("cls");
    printf("Delete by searching or entering position?");
    printf("\n1 - Searching");
    printf("\n2 - Entering position");
    printf("\nEnter choice(1-2): ");
    scanf("%d", &choice);
    switch (choice) 
    {
        case 1:
            char q;
            system("cls");
            printf("Enter element you want to delete from linked list: ");
            q = 'n';
            search();
            if(found == 0)
            { 
                printf("%d not found in linked list!", item);
                goto s;
            }
            break; 
        case 2: 
            p:
            system("cls");
            printf("Linked List: ");
            view();
            printf("\nEnter position of element you want to delete from linked list(1-%d): ", n);
            scanf("%d", &pos);
            if(pos < 1 || pos > n)
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
    if(pos == 1)        // Delete first element of list
    {
        p = head;
        head = head->next;
        free(p);
    }
    else if(pos == n)   // Delete last element of list
    {
        p = head;
        while(p->next->next != NULL)
            p = p->next;
        free(p->next);
        p->next = NULL;
    }
    else                // Delete a middle element of list
    {
        p = head;
        for (int i = 1; i < pos; i++)
        {
            p2 = p; 
            p = p->next;
        }
        p2->next = p->next;
        free(p);
    }
    n--;
    printf("\nNew Linked List: ");
    view();
    s:
    getch();
}

void bub_sort ()
{
    int swap;
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        view();
        p = head;
        for (int j = 0; j < n-i-1; j++)
        {
            p2 = p;
            p = p->next;
            if (p2->info > p->info)
            {
                swap = p2->info;
                p2->info = p->info;
                p->info = swap;
            }
        }
    }
}

void select_sort ()
{
    int swap;
    start = head;
    for (int i = 0; i < n - 1; i++)
    {
        printf("\n");
        view();
        min = p = start;
        for (int j = i; j < n - 1; j++)
        {
            p = p->next;
            if (min->info > p->info)
                min = p;
        }
        swap = start->info;
        start->info = min->info;
        min->info = swap;
        start = start->next;
    }
}

void reverse () 
{
    tail = p3 = head;
    p2 = head->next;
    head->next = NULL;
    p = p2;
    while(p2 != NULL)
    {
        p = p->next;
        p2->next = p3;                                           
        p3 = p2;        
        p2 = p;
    }
    head = p3;
}

void rotate()
{
    int k, count = 1;
    system("cls");
    printf("Enter no. of rotations: ");
    scanf("%d", &k);
	if(k >= n)
        k = k % n;
    if(k == 0)
		return;
    /*  
    p = head;
    while(count <= k)
    {
        p2 = p;
        p = p->next;
        count++;
    }
    p2->next = NULL;
    tail->next = head;
    head = p;  
	*/
	///*
    p = head;
    while(p->next != NULL)
        p = p->next;
    p->next = head;
    while(count <= k)
    {
        p = p->next;
        count++;
    }
    head = p->next;
    p->next = NULL;
    //*/
}

void length()
{
    int length = 0;
    system("cls");
    p = head;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    printf("Length of list = %d", length); 
    getch();
}

void main ()
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
        printf("\n6 - Sort Linked List");
        printf("\n7 - Reverse Linked List");
		printf("\n8 - Rotate Linked List");
        printf("\n9 - Check length of Linked List");
        printf("\n10 - Exit");
        if (run == 0)   // Make user create Linked List if running for first time
        {
            printf("\n\n(Please create Linked List first before performing any other operation)\n");
            scanf("%d", &choice);
            if (choice != 1 && choice != 10)
            {
                printf("Press 1 to create Linked List first!\n");
                goto y;
            }
            run = 1;
        }
        else
        {
            printf("\n\n");
            scanf("%d", &choice);
        }
        switch (choice)
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
            s:
            int found, pos, item;
            char q;
            system("cls");
            printf("Is it sorted?(y/n) ");
            scanf(" %c", &q);
            if(q != 'y' && q != 'n')
            {
                printf("\nInvalid Input! ");
                goto s;
            }
            printf("Enter the element you want to search: ");
            search();
            if(found == 1)
                printf("\n%d found in linked list at location: %d", item, pos); 
            else
                printf("\n%d not found in linked list!", item);               
            getch();
            break;
        case 4:
            insert();
            break;
        case 5:
            delete();
            break;
        case 6:
            sort:
            system("cls");
            printf("Enter choice:");
            printf("\n1 - Bubble Sort ");
            printf("\n2 - Selection Sort\n\n");
            scanf("%d", &choice);
            switch (choice) 
            {
                case 1: 
                    bub_sort();
                    break;
                case 2: 
                    select_sort();
                    break;
                default: 
                    printf("\nInvalid Input! ");
                    getch();
                    goto sort;    
            }
            printf("\n\nFinal Sorted List: ");
            view();
            getch();
            break;
        case 7: 
            system("cls");
            reverse();
            printf("Reversed linked list:\n");
            view();
            getch();
            break;
        case 8:
            rotate();
            view();
            getch();
            break;
        case 9:
            length();
            break;
		case 10:
            exit(0);
        default:
            printf("\nInvalid Input!");
            getch();
            break;
        }
    } while (choice);
}