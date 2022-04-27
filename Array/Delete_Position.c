#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[50], i, n, pos, del;
    system("cls");

    // creating array
    printf("Enter number of elements for array: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nAll elements have been entered...");

    // deleting element from array
    printf("\nEnter position of element you want to delete from array: ");
    scanf("%d", &pos);
    del = a[pos - 1];
    for (i = pos; i < n; i++)
        a[i - 1] = a[i];
    n = n - 1;

    // printing new array after deleting
    printf("\nNew array is:");
    for (i = 0; i < n; i++)
        printf("\n%d", a[i]);
    printf("\n\nDeleted element was %d", del);
}
