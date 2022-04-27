#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int a[25], i, j, k, n, pos, del;
    system("cls");

    // creating array
    printf("Enter number of elements for array: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("All elements have been entered...");
    getch();

    // deleting duplicates
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                for (k = j; k < n; k++)
                    a[k] = a[k + 1];
                n--;
                j--;
            }
        }
    }

    // printing new array after deleting
    printf("\n\nNew array is:");
    for (i = 0; i < n; i++)
        printf("\n%d", a[i]);
}
