#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int c, n, stack[10], top = -1, i;

void push()
{
    system("cls");
    if(top == n-1)
    {
        printf("Stack is full! ");
        getch();
        return;
    }
    printf("Enter element you want to push into stack: ");
    top++;
    scanf("%d", &stack[top]);
    printf("\n%d pushed into stack ", stack[top]);
    getch();
}

void pop()
{
    int pop;
    system("cls");
    if(top == -1)
    {
        printf("Stack is empty! ");
        getch();
        return;
    }
    pop = stack[top];
    top--;
    printf("%d popped out of stack ", pop);
    getch();
}

void peek()
{
    system("cls");
    if(top == -1)
    {
        printf("Stack is empty! ");
        getch();
        return;
    }
    printf("Top element of stack is %d ", stack[top]);
    getch();
}

void view()
{
    system("cls");
    if(top == -1)
    {
        printf("Stack is empty! ");
        getch();
        return;
    }
    for(i = top; i >= 0; i--) 
        printf("%d\n", stack[i]);
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
            printf("\n\n(Please create stack first before performing any other operation)\n");
            scanf("%d", &c);
            if (c != 1 && c != 6)
            {
                printf("Press 1 to create stack first!\n");
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