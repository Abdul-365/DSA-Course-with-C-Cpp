#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[50], i, n, larg = -32768, slarg = -32758;
    system("cls");

    // Creating array
    printf("Enter number of inputs: ");
    scanf("%d", &n);
    printf("\nEnter %d numbers:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Finding largest number
    for (i = 0; i < n; i++)
    {
        if (a[i] > larg)
        {
            slarg = larg;
            larg = a[i];
        }
        else if (a[i] < larg && a[i] > slarg)
            slarg = a[i];
    }
    // Printing Largest number
    printf("\nLargest number is %d", larg);
    printf("\n2nd largest number is %d", slarg);
}
