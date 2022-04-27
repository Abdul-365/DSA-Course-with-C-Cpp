#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[ub];
    int i = lb;
    for (int j = lb; j < ub; j++)
    {
        if (a[j] <= pivot)
        {
            swap(&a[i], &a[j]);
            i++;
        }
    }
    swap(&a[i], &a[ub]);
    return i;
}

int partition_r(int a[], int lb, int ub)
{
    srand(time(NULL));
    int random = lb + rand() % (ub - lb);
    swap(&a[random], &a[ub]);
    return partition(a, lb, ub);
}

void quick_sort(int a[], int lb, int ub)
{
    if (lb < ub)
    {
        int pivot = partition_r(a, lb, ub);
        quick_sort(a, lb, pivot - 1);
        quick_sort(a, pivot + 1, ub);
    }
}

void main()
{
    int a[20], n;
    system("cls");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    quick_sort(a, 0, n - 1);
    printf("\nSorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}