#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int c, n, queue[10], front = -1, rear = -1, i;

int queueEmpty()
{
    if(front == -1)
    {
        printf("Queue is empty! ");
        return 1;
    }
    else
        return 0;
}

void enque()
{
    system("cls");
    if((front == 0 && rear == n - 1) || front == rear + 1)
    {
        printf("Queue is full! ");
        getch();
        return;
    }
    else if(front == -1)
        front = rear = 0;
    else if(rear == n - 1)
        rear = 0;
    else
        rear++;
    printf("Enter element you want to enqueue: ");
    scanf("%d", &queue[rear]);
    printf("\n%d enqueued ", queue[rear]);
    getch();
}

void deque()
{
    int deque;
    system("cls");
    if(queueEmpty() == 1)
    {
        getch();
        return;
    }
    deque = queue[front]; 
    if(rear != n - 1 && front == n - 1)
        front = 0;
    else if(front == rear)
        front = rear = -1;
    else
        front++;
    printf("%d dequeued ", deque);
    getch();
}

void peek()
{
    system("cls");
    if(queueEmpty() == 1)
    {
        getch();
        return;
    }
    printf("Front element of queue is %d ", queue[front]);
    getch();
}

void view()
{
    system("cls");
    if(queueEmpty() == 1)
    {
        getch();
        return;
    }
    if(front <= rear)
    {
        for(i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    else
    {
        for(i = front; i < n; i++)
            printf("%d ", queue[i]);
        for(i = 0; i < rear; i++)
            printf("%d ", queue[i]);
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
        printf("\n1 - Select size for Queue");
        printf("\n2 - Enqueue");
        printf("\n3 - Dequeue");
        printf("\n4 - Peek front element of queue");
        printf("\n5 - View whole queue");
        printf("\n6 - Exit");
        if (run == 0)   // Make user enter size of queue if running for first time
        {
            printf("\n\n(Please enter size of queue first before performing any other operation)\n");
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
                i:
                system("cls");
                printf("Enter size for queue (Max size - 10): ");
                scanf("%d", &n);
                if(n<1 || n>n)
                {
                    printf("Invalid Input! ");
                    getch();
                    goto i;
                }
                break;
            case 2:
                enque();
                break;
            case 3:
                deque();
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
                printf("Invalid input!"); 
                getch();
                break;
        }
    } while (c != 6);
    
}