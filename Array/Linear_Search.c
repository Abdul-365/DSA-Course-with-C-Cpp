#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int a[25], n, i, item, flag = 0;
    system("cls");

    // create array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("All elements have been entered...");
    getch();

    printf("\n\nEnter element you want to search: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            printf("Element found at location %d", i + 1);
            flag = 1;
        }
    }
    if (flag == 0)
        printf("Element not found!");
}