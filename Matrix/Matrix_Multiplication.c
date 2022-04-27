#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void Matrix_multiply(int m, int n, int p, int a[][9], int b[][9], int c[][9])
{
    // Matrix Multiplication
    int i, j, k;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < n; k++)
                c[i][j] += (a[i][k] * b[k][j]);
        }
    }
}

void main()
{
    int a[9][9], b[9][9], c[9][9], i, j, k, m, n, o, p;

// Entering Matrix Size
x:
    system("cls");
    printf("For Matrix 1(max size - 9):");
    printf("\nEnter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    printf("\nFor Matrix 2(max size - 9):");
    printf("\nEnter number of rows: ");
    scanf("%d", &o);
    printf("Enter number of columns: ");
    scanf("%d", &p);
    if (m < 1 || m > 10 || n < 1 || n > 10 || o < 1 || o > 10 || p < 1 || p > 10)
    {
        printf("\nDimensions cannot be negative/0/more than 10!");
        printf("\nEnter correct dimensions again...");
        getch();
        goto x;
    }
    if (n != o)
    {
        printf("\nColumns of first matrix must be equal to rows of second matrix!");
        printf("\nEnter correct dimensions again...");
        getch();
        goto x;
    }

    // Entering Matrix Elements
    printf("\nEnter elements for matrix 1:\n");
    for (i = 0; i < m; i++)
    {
        printf("Enter elements for row %d: ", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }
    printf("\nEnter elements of matrix 2:\n");
    for (i = 0; i < n; i++)
    {
        printf("Enter elements for row %d: ", i + 1);
        for (j = 0; j < p; j++)
            scanf("%d", &b[i][j]);
    }

    Matrix_multiply(m, n, p, a, b, c);

    // Printing Matrixes with their Product
    system("cls");
    printf("Matrix 1:");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%d\t", a[i][j]);
    }
    printf("\n\nMatrix 2:");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < p; j++)
            printf("%d\t", b[i][j]);
    }
    printf("\n\nProduct of both Matrixes:");
    for (i = 0; i < m; i++)
    {
        printf("\n");
        for (j = 0; j < p; j++)
            printf("%d\t", c[i][j]);
    }
}
