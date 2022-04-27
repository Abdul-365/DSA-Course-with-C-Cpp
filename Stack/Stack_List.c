#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int c, i = 0, n, s, found, pos, swap;
struct node *p, *p2, *p3, *top, *new, *min, *start, *top;

struct node
{
    int info;
    struct node *below;
};

int stackEmpty()
{
    if(i == 0)
    {
        printf("Stack is empty! ");
        getch();
        return 1;
    }
    else 
        return 0;
}

void push()
{
    system("cls");
    if(i == n)
    {
        printf("Stack is full! ");
        getch();
        return;
    }
    printf("Enter element you want to push into stack: ");
    new = malloc(sizeof(struct node));
    scanf("%d",&new->info);
    if(i == 0) 
        new->below = NULL;
    else
        new->below = top;
    top = new;
    i++;
    printf("\n%d pushed into stack ", top->info);
    getch();
}

void pop()
{
    int pop;
    system("cls");
    if(stackEmpty() == 1)
        return;
    pop = top->info;
    p = top;
    top = top->below;
    free(p);
    i--;
    printf("%d popped out of stack ", pop);
    getch();
}

void peek()
{
    system("cls");
    if(stackEmpty() == 1)
        return;
    printf("Top element of stack is %d ", top->info);
    getch();
}

void view()
{
    system("cls");
    if(stackEmpty() == 1)
        return;
    p = top;
    while (p != NULL)
    {
        printf("%d\n", p->info);
        p = p->below;
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
        printf("\n1 - Select size for stack");
        printf("\n2 - Push element into Stack");
        printf("\n3 - Pop element out of Stack");
        printf("\n4 - Peek top element of stack");
        printf("\n5 - View whole stack");
        printf("\n6 - Exit");
        if (run == 0)   // Make user enter size of stack if running for 1st time
        {
            printf("\n\n(Please enter size of stack first before performing any other operation)\n");
            scanf("%d", &c);
            if (c != 1 && c != 6)
            {
                printf("Press 1 to enter size of stack first!\n");
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
                printf("Enter size for stack (Max size - 10): ");
                scanf("%d", &n);
                if(n<1 || n>10)
                {
                    printf("Invalid Input! ");
                    getch();
                    goto i;
                }
                break;
            case 2:
                push();
                break;
            case 3:
                pop();
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