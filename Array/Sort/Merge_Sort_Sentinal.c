#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int lb, int mid, int ub)
{
	int n1 = mid - lb + 1;
	int n2 = ub - mid;
    int l[n1 + 1], r[n2 + 1];
    int i, j, k;
	for (i = 0; i < n1; i++)
		l[i] = a[lb + i];
	for (j = 0; j < n2; j++)
		r[j] = a[mid + 1 + j];
	l[n1] = INT_MAX;
	r[n2] = INT_MAX;
	i = j = 0;
	for (k = lb; k < ub + 1; k++)
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
	int arr[20], n, i;
	system("cls");
	printf("Enter number of elements: ");
	scanf("%d", &n);
	printf("Enter numbers:\n");
	for (i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	merge_sort(arr, 0, n - 1);
	printf("Sorted array:\n");
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
}