#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int main()
{
    int a[10][10], b2[MAX][3], b[MAX][3], row, column;
    int i, t, n, j, k = 1;
    printf("\nEnter the size of matrix 1(rows, columns): ");
    scanf("%d%d", &row, &column);
    printf("\nEnter elements of matrix 1\n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    b[0][0] = row;
    b[0][1] = column;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
    }
    b[0][2] = k - 1;

    printf("\n Sparse matrix 1 is \n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    //transpose
    b2[0][0] = b[0][1];
    b2[0][1] = b[0][0];
    b2[0][2] = b[0][2];
    t = 1;
    n = b[0][2];
    for (i = 0; i < b[0][1]; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == b[j][1])
            {
                b2[t][0] = i;
                b2[t][1] = b[j][0];
                b2[t][2] = b[j][2];
                t++;
            }
        }
    }
    printf("\n Sparse matrix 1 is \n");
    for (i = 0; i < t; i++)
    {
        for (j = 0; j < 3; j++)
            printf("%d ", b2[i][j]);
        printf("\n");
    }
    return 0;
}