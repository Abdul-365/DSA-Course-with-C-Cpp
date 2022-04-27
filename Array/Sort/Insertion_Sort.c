#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[25], n, i, j, t;
    system("cls");

    // create array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // sort array
    for (i = 1; i <= n - 1; i++)
    {
        t = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > t)
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = t;
    }

    // print sorted array
    printf("\n\nSorted array in ascending order:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}