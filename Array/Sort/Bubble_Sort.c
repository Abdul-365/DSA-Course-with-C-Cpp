#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int a[25], n, i, j, swap;
    system("cls");

    // create array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("All elements have been entered...");
    getch();

    // sort array
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap;
            }
        }
    }

    // print sorted array
    printf("\n\nSorted array in ascending order: ");
    for (i = 0; i < n; i++)
        printf("\n%d", a[i]);
}