#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int a[50], i, n, item, mid, lb = 0, ub;
    system("cls");

    // creating sorted array for binary search
    printf("Enter number of elements for sorted array: ");
    scanf("%d", &n);
    ub = n - 1;
    printf("Enter elements in ascending order: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("All elements have been entered...");
    getch();

    // entering element to be searched
    printf("\n\nEnter element you want to search: ");
    scanf("%d", &item);

    // binary search
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (a[mid] == item)
        {
            printf("\nElement found at location: %d", mid + 1);
            break;
        }
        else if (item < a[mid])
            ub = mid - 1;
        else
            lb = mid + 1;
    }
    if (lb > ub)
        printf("\nElement not found!");
}