#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int a[25], i, n, pos, item;
    system("cls");

    // creating array
    printf("Enter number of elements for array: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("All elements have been entered...");
    getch();

    // inserting element in array
    printf("\n\nEnter element you want to insert into array: ");
    scanf("%d", &item);
    printf("Enter position for new element: ");
    scanf("%d", &pos);
    for(i = n; i >= pos - 1; i--)           
        a[i] = a[i - 1];
    a[pos - 1] = item;
    n = n + 1;

    // printing new array after inserting element
    printf("\nNew array is:");
    for (i = 0; i < n; i++)
        printf("\n%d", a[i]);
}