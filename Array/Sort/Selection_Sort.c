#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    system("cls");
    int a[20], i, j, n, min, swap;

    // creating array
    printf("Enter number of elements for array: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("All elements have been entered...");
    getch();

    // selection sort
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
                min = j;
        }
        swap = a[i];
        a[i] = a[min];
        a[min] = swap;
    }

    // printing new array
    printf("\nSorted array in ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    getch();
}