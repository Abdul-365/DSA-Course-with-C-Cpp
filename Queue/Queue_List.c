#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int c, i = 0, n, s, found, pos, swap;
struct node *p, *p2, *p3, *front, *rear, *new, *min, *start;

struct node
{
    int info;
    struct node *next;
};

void insert()
{
    system("cls");
    if(i == n)
    {
        printf("Queue is Full! ");
        getch();
        return;
    }
    printf("Enter element you want to insert into queue: ");
    new = malloc(sizeof(struct node));
    scanf("%d", &new->info);
    new->next = NULL;
    if(i == 0)
        front = rear = new;
    else
    {
        rear->next = new;
        rear = new;
    }
    i++;
    printf("%d has been inserted into queue. ", rear->info);
    getch();
}

void delete()
{
    int delete;
    system("cls");
    if(i == 0)
    {
        printf("Queue is empty! ");
        getch();
        return;
    }
    delete = front->info;
    p = front;
    front = front->next;
    free(p);
    printf("%d deleted out of queue ", delete);
    i--;
    getch();
}

void peek()
{
    system("cls");
    if(i == 0)
    {
        printf("Queue is empty! ");
        getch();
        return;
    }
    printf("Front element of queue is %d ", front->info);
    getch();
}

void view()
{
    system("cls");
    if(i == 0)
    {
        printf("Queue is empty! ");
        getch();
        return;
    }
    p = front;
    while (p != NULL)
    {
        printf("%d ", p->info);
        p = p->next;
    }
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
        printf("\n1 - Select size for queue");
        printf("\n2 - Insert element into queue");
        printf("\n3 - Delete element out of queue");
        printf("\n4 - Peek front element of queue");
        printf("\n5 - View whole queue");
        printf("\n6 - Exit");
        if (run == 0)   // Make user enter size of queue if running for 1st time
        {
            printf("\n\n(Please enter size of queue first before performing any other operation)\n");
            scanf("%d", &c);
            if (c != 1 && c != 6)
            {
                printf("Press 1 to enter size of queue first!\n");
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
        switch(c)
        {
            case 1:
                i:
                system("cls");
                printf("Enter size for queue (Max size - 10): ");
                scanf("%d", &n);
                if(n<1 || n>10)
                {
                    printf("Invalid Input! ");
                    getch();
                    goto i;
                }
                break;
            case 2:
                insert();
                break;
            case 3:
                delete();
                break;
            case 4:
                peek();
                break;
            case 5:
                view();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid input! ");
                getch();
                break;
        }
    } while (c != 6);  
}