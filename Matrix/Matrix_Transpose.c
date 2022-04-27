#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[10][10], i, j, m, n;

    system("cls");
    printf("Enter number of rows for matrix: ");
    scanf("%d", &m);
    printf("Enter number of columns for matrix: ");
    scanf("%d", &n);
    printf("\nEnter elements for matrix:\n");
    for (i = 0; i < m; i++)
    {
        printf("Enter elements for row %d: ", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    system("cls");
    printf("\nOrignal Matrix:");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
    }
    printf("\n\nTranspose of matrix:");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", a[j][i]);
    }
}
