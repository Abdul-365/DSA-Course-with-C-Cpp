#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int a[5][5], b[5][5], m, n, i, j, c;

void sum()
{
    printf("\nSum of matrices is: ");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j] + b[i][j]);
    }
}

void diff()
{
    printf("\nDifference of matrices is: ");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j] - b[i][j]);
    }
}

void main()
{
    system("cls");
    printf("Enter size for matrixes: ");
    printf("\nRows: ");
    scanf("%d", &m);
    printf("Columns: ");
    scanf("%d", &n);

    printf("\nEnter vales for matrix 1: \n");
    for (i = 0; i < m; i++)
    {
        printf("Enter elements for row %d: \n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    printf("\nEnter vales for matrix 2: \n");
    for (i = 0; i < m; i++)
    {
        printf("Enter elements for row %d: \n", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &b[i][j]);
    }

    system("cls");
    printf("\nEnter choice: ");
    printf("\n1 - Sum");
    printf("\n2 - Difference\n\n");
    scanf("%d", &c);
    switch (c)
    {
    case 1:
        sum();
        break;
    case 2:
        diff();
        break;
    default:
        printf("\n Invalid Input");
        getch();
        break;
    }
    getch();
}