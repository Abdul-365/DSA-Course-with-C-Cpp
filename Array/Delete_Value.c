#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
    int a[50], i, n, item, pos, del, flag = 0;
    system("cls");

    // creating array
    printf("Enter number of elements for array: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("All elements have been entered...");
    getch();

    // entering element to be deleted
    printf("\nEnter element you want to delete from array: ");
    scanf("%d", &item);

    // searching for element to be deleted
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            // deleting element after being found
            pos = i + 1;
            del = a[i];
            for (i = pos - 1; i < n; i++)
                a[i] = a[i + 1];
            n = n - 1;

            // printing new array after deleting
            printf("\nNew array is:");
            for (i = 0; i < n; i++)
                printf("\n%d", a[i]);
            printf("\n\nDeleted item was %d", del);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("\nElement not found!");
}