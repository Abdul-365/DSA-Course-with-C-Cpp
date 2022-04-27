#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int lb, int mid, int ub)
{
	int n1 = mid - lb + 1;
	int n2 = ub - mid;
    int l[n1], r[n2];
    int i, j, k;
	for (i = 0; i < n1; i++)
		l[i] = a[lb + i];
	for (j = 0; j < n2; j++)
		r[j] = a[mid + 1 + j];
	i = j = 0;
    k = lb;
    while (i < n1 && j < n2)
    {
        if (l[i] <= r[j])
        {
            a[k] = l[i];
            i++;
        }
        else
        {
            a[k] = r[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = l[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = r[j];
        j++;
        k++;
    }
}

void merge_sort(int a[], int lb, int ub)
{
	if (lb < ub)
	{
		int mid = (lb + ub) / 2;
		merge_sort(a, lb, mid);
		merge_sort(a, mid + 1, ub);
		merge(a, lb, mid, ub);
	}
}

void main()
{
    int a[20], i, n;
    system("cls");
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    merge_sort(a, 0, n - 1);
    printf("Sorted array: \n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
}
