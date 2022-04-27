#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int m1[10][10], m2[10][10], sum[20][3], s1[20][3], s2[20][3], r1, c1, r2, c2;
    int i, j, k = 1, l = 1, x, t, n1, n2;
    printf("\nEnter the size of matrix 1(rows, columns): ");
    scanf("%d%d", &r1, &c1);
    printf("\nEnter elements of matrix 1\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    s1[0][0] = r1;
    s1[0][1] = c1;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            if (m1[i][j] != 0)
            {
                s1[k][0] = i;
                s1[k][1] = j;
                s1[k][2] = m1[i][j];
                k++;
            }
        }
    }
    s1[0][2] = k - 1;

    printf("\n Sparse matrix 1 is \n");
    for (i = 0; i < k; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", s1[i][j]);
        }
        printf("\n");
    }

    printf("\nEnter the size of matrix 2(rows, columns): ");
    scanf("%d%d", &r2, &c2);
    printf("\nEnter elements of matrix 2\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("[%d][%d]: ", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    s2[0][0] = r2;
    s2[0][1] = c2;
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            if (m2[i][j] != 0)
            {
                s2[l][0] = i;
                s2[l][1] = j;
                s2[l][2] = m2[i][j];
                l++;
            }
        }
    }
    s2[0][2] = l - 1;

    printf("\n Sparse matrix 2 is \n");
    for (i = 0; i < l; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", s2[i][j]);
        }
        printf("\n");
    }

    if (s1[0][0] != s2[0][0] || s1[0][1] != s2[0][1])
    {
        printf("\nYou have entered invalid matrix ! Size must be equal! ");
        exit(0);
    }
    n1 = s1[0][2];
    n2 = s2[0][2];
    i = j = x = 0;
    sum[0][0] = r1;
    sum[0][1] = c1;

    while (i <= n1 && j <= n2)
    {
        if (s1[i][0] < s2[j][0]) //r1 numbers are not equal
        {
            sum[x][0] = s1[i][0];
            sum[x][1] = s1[i][1];
            sum[x][2] = s1[i][2];
            x++;
            i++;
        }
        else if (s2[j][0] < s1[i][0]) //r1 numbers are not equal
        {
            sum[x][0] = s2[j][0];
            sum[x][1] = s2[j][1];
            sum[x][2] = s2[j][2];
            x++;
            j++;
        }
        else if (s1[i][1] < s2[j][1]) //r1 numbers are equal, compare c1
        {
            sum[x][0] = s1[i][0];
            sum[x][1] = s1[i][1];
            sum[x][2] = s1[i][2];
            x++;
            i++;
        }
        else if (s2[j][1] < s1[i][1]) //r1 numbers are equal, compare c1
        {
            sum[x][0] = s2[j][0];
            sum[x][1] = s2[j][1];
            sum[x][2] = s2[j][2];
            x++;
            j++;
        }
        else /*r1 and c1 numbers are equal*/
        {
            sum[x][0] = s1[i][0];
            sum[x][1] = s1[i][1];
            sum[x][2] = s1[i][2] + s2[j][2];
            x++;
            i++;
            j++;
        }
    }

    while (i <= k) /*copy remaining terms from b1*/
    {
        sum[x][0] = s1[i][0];
        sum[x][1] = s1[i][1];
        sum[x][2] = s1[i][2];
        i++;
        x++;
    }

    while (j <= l) /*copy remaining terms from b2*/
    {
        sum[x][0] = s2[j][0];
        sum[x][1] = s2[j][1];
        sum[x][2] = s2[j][2];
        j++;
        x++;
    }
    sum[0][2] = x - 1; /*set number of terms in sum*/
    printf("\nSum of sparse matrices is: \n");
    for (i = 0; i < x; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}