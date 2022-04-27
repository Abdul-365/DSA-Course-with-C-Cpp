#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int i, n;
struct node
{
    int info;
    int priority;
    struct node *next;
}*p, *front, *(rear[6]), *new;

int queueEmpty()
{
    if(i == 0)
    {
        printf("Queue is empty! ");
        getch();
        return 1;
    }
    else
        return 0;
}

void insert()
{
    int priority;
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
    printf("Enter its priority(1-5): ");
    p:
    scanf("%d", &new->priority);
    if(new->priority < 1 || new->priority > 5)
    {
        printf("Priority can be set only from 1-5: ");
        goto p;
    }
    if(i == 0)
    {
        for(priority = 0; priority < 6; priority++)
            rear[priority] = NULL;
        new->next = NULL;
        front = rear[new->priority] = new;
    }
    else
    {
        if(front->priority > new->priority)
        {
            new->next = front;
            front = new;
        }
        else
        {
            for(priority = new->priority; priority >= 0; priority--)
            {
                if(rear[priority] != NULL)
                {
                    new->next = rear[priority]->next;
                    rear[priority]->next = new;
                    break;
                }
            }
        }
        rear[new->priority] = new;
    }
    i++;
    printf("%d has been inserted into queue with priority %d ", rear[new->priority]->info, rear[new->priority]->priority);
    getch();
}

void delete()
{
    system("cls");
    if(queueEmpty() == 1)
        return;
    int del_info = front->info;
    int del_priority = front->priority;
    p = front;
    front = front->next;
    if(front != NULL && p->priority != front->priority)
        rear[p->priority] = NULL;
    free(p);
    i--;
    printf("%d with priority %d deleted from of queue ", del_info, del_priority);
    getch();
}

void peek()
{
    system("cls");
    if(queueEmpty() == 1)
        return;
    printf("Front element of queue is %d with priority %d ", front->info, front->priority);
    getch();
}

void view()
{
    system("cls");
    if(queueEmpty() == 1)
        return;
    p = front;
    printf("Element\tPriority\n");
    while (p != NULL)
    {
        printf("%d\t%d\n", p->info, p->priority);
        p = p->next;
    }
    getch();
}

void main() 
{
    int c, run = 0;
    do
    {
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
            y:
            scanf("%d", &c);
            if (c != 1 && c != 6)
            {
                printf("Press 1 to enter size of queue first!\n");
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
                i = 0;
                system("cls");
                printf("Enter size for queue (Max size - 20): ");
                s:
                scanf("%d", &n);
                if(n < 1 || n > 20)
                {
                    printf("Size must be between 1 and 20!\n");
                    goto s;
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
    } while (c);  
}