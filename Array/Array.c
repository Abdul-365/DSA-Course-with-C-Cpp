
//--------------------------ULTIMATE-ARRAY-PROGRAM----------------------------

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int a[50], i, j, k, n, item, pos, c, p = 0, del, swap, temp;

//-------------------------------CREATE-Array---------------------------------

void create()
{
    system("cls");
    printf("\nEnter number of elements for array: ");
    scanf("%d", &n);
    printf("Enter elements: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("\nAll elements have been entered...");
    getch();
}

//--------------------------------VIEW-Array----------------------------------

void view()
{
    printf("\n");
    for (k = 0; k < n; k++)
    {
        printf("%d ", a[k]);
    }
}

//-------------------------------Linear-SEARCH---------------------------------

void lin_search()
{
    system("cls");
    int flag = 0;
    printf("\nEnter element you want to search: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            printf("\nElement found at location %d", i + 1);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("\nElement not found!");
    }
    getch();
}

//-------------------------------Binary-SEARCH---------------------------------

void bin_search()
{
    system("cls");
    int mid, lb = 0, ub = n - 1;
    printf("\nEnter element you want to search: ");
    scanf("%d", &item);
    while (lb <= ub)
    {
        mid = (lb + ub) / 2;
        if (a[mid] == item)
        {
            printf("\nElement found at location %d", mid + 1);
            break;
        }
        else if (a[mid] > item)
        {
            ub = mid - 1;
        }
        else
        {
            lb = mid + 1;
        }
    }
    if (lb > ub)
    {
        printf("\nElement not found!");
    }
    getch();
}

//-------------------------------INSERT-element---------------------------------

void insert()
{
    system("cls");
    printf("\nEnter element you want to insert into array: ");
    scanf("%d", &item);
    printf("Enter position for new element (1-%d): ", n + 1);
Y:
    scanf("%d", &pos);
    if (pos > n + 1 || pos < 1)
    {
        printf("\nInvalid Input!\nEnter correct position: ");
        getch();
        goto Y;
    }
    for (i = n - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = item;
    n = n + 1;
    view();
    getch();
}

//----------------------------DELETE-by-position-------------------------------

void del_pos()
{
    system("cls");
    printf("\nEnter position of element you want to delete from array");
    printf("(1-%d): ", n);
    view();
    printf("\n\n");
x:
    scanf("%d", &pos);
    del = a[pos - 1];
    if (pos > n + 1 || pos < 1)
    {
        printf("\nInvalid Input!\nEnter correct position: ");
        getch();
        goto x;
    }
    for (i = pos - 1; i < n; i++)
    {
        a[i] = a[i + 1];
    }
    n = n - 1;
    printf("\nNew array is:");
    view();
    printf("\nDeleted item was %d ", del);
    getch();
}

//------------------------------DELETE-by-value---------------------------------

void del_val()
{
    system("cls");
    int flag = 0;
    printf("\nEnter element you want to delete from array: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
        {
            pos = i + 1;
            del = a[i];
            for (i = pos - 1; i < n; i++)
            {
                a[i] = a[i + 1];
            }
            n = n - 1;
            printf("\nNew array is:");
            view();
            printf("\nDeleted item was %d ", del);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\nElement not found!");
    }
    getch();
}

//-----------------------------DELETE-Duplicates------------------------------

void del_dup()
{
    system("cls");
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                for (k = j + 1; k < n; k++)
                {
                    a[k] = a[k + 1];
                }
                n = n - 1;
            }
        }
    }
    view();
    getch();
}

//------------------------------Ascending-SORT----------------------------------

void asc_sort()
{
    system("cls");
    for (i = 1; i <= n - 1; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > temp)
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = temp;
    }
    printf("\nSorted array in ascending order: ");
    view();
    getch();
}

//------------------------------Descending-SORT-------------------------------

void desc_sort()
{
    system("cls");
    for (i = 1; i <= n - 1; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] < temp)
            {
                a[j + 1] = a[j];
            }
            else
                break;
        }
        a[j + 1] = temp;
    }
    printf("\nSorted array in descending order: ");
    view();
    getch();
}

//--------------------------------BUBBLE-Sort---------------------------------

void bub_sort()
{
    system("cls");
    view();
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap = a[j];
                a[j] = a[j + 1];
                a[j + 1] = swap;
            }
        }
        view();
    }
}

//------------------------------SELECTION-Sort--------------------------------

void sel_sort()
{
    system("cls");
    int min;
    view();
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap = a[i];
            a[i] = a[min];
            a[min] = swap;
        }
        view();
    }
}

//------------------------------INSERTION-Sort--------------------------------

void ins_sort()
{
    system("cls");
    view();
    for (i = 1; i <= n - 1; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
                break;
        }
        a[j + 1] = temp;
        view();
    }
}

//-----------------------------------MAIN-------------------------------------

void main()
{
    int run = 0;
    do
    {
        X:
        system("cls");
        printf("\n_______________________________________________________________________________");
        printf("\n|                                                                             |");
        printf("\n|                                   Main Menu                                 |");
        printf("\n|_____________________________________________________________________________|");
        printf("\n|                                                                             |");
        printf("\n|  Select choice (1-8):                                                       |");
        printf("\n|                                                                             |");
        printf("\n|  1 - Create Array                                                           |");
        printf("\n|  2 - View array                                                             |");
        printf("\n|  3 - Search element                                                         |");
        printf("\n|  4 - Insert element                                                         |");
        printf("\n|  5 - Delete element                                                         |");
        printf("\n|  6 - Sort Array                                                             |");
        printf("\n|  7 - Understand Sort                                                        |");
        printf("\n|  8 - Exit                                                                   |");
        printf("\n|_____________________________________________________________________________|");

        if (run == 0)
        {
            printf("\n\n(Please create array first to perform any other operation)");
            printf("\n\n");
            y:
            scanf("%d", &c);
            if (c != 1 && c != 8)
            {
                printf("\nPress 1 to create array first! ");
                goto y;
            }
            run = 1;
        }
        else
        {
            printf("\n\n");
            scanf("%d", &c);
        }
        
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            system("cls");
            view();
            getch();
            break;
        case 3:
            s:
            system("cls");
            printf("\nSelect type of search:");
            printf("\n1 - Linear Search");
            printf("\n2 - Binary Search (Array must be sorted)");
            printf("\n3 - Back\n\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                lin_search();
                break;
            case 2:
                bin_search();
                break;
            case 3:
                goto X;
            default:
                printf("\nInvalid Input!");
                getch();
                goto s;
            }
            break;
        case 4:
            insert();
            break;
        case 5:
            d:
            system("cls");
            printf("\nSelect type of deletion:");
            printf("\n1 - Delete by entering position of element");
            printf("\n2 - Delete by entering value of element");
            printf("\n3 - Delete all duplicate elements");
            printf("\n4 - Back\n\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                del_pos();
                break;
            case 2:
                del_val();
                break;
            case 3:
                del_dup();
                break;
            case 4:
                goto X;
            default:
                printf("\nInvalid Input!");
                getch();
                goto d;
            }
            break;
        case 6:
            a:
            system("cls");
            printf("\nSelect type of sorting ");
            printf("\n1 - Ascending");
            printf("\n2 - Descending");
            printf("\n3 - Back\n\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                asc_sort();
                break;
            case 2:
                desc_sort();
                break;
            case 3:
                goto X;
            default:
                printf("\nInvalid Input!");
                getch();
                goto a;
            }
            break;
        case 7:
            system("cls");
            printf("\nThis feature is designed for educational purposes. It helps users to understand the working of sort algorithm by printing output after each pass.\n");
            printf("\nYou can also exit the program after the output of all passes has been printed and view the output through output window and algorithm side by side to understand better... ;)\n");
            printf("\nSelect method of sorting:");
            printf("\n1 - Bubble Sort");
            printf("\n2 - Selection Sort");
            printf("\n3 - Insertion Sort");
            printf("\n4 - Back\n\n");
            scanf("%d", &c);
            switch (c)
            {
            case 1:
                bub_sort();
                goto u;
            case 2:
                sel_sort();
                goto u;
            case 3:
                ins_sort();
                goto u;
                u:
                printf("\n\n1 - Return to Main Menu");
                printf("\n2 - Exit Program\n\n");
                t:
                scanf("%d", &c);
                switch (c)
                {
                case 1:
                    break;
                case 2:
                    p = 1;
                    break;
                default:
                    printf("\nInvalid Input!");
                    getch();
                    goto t;
                }
                break;
            case 4:
                goto X;
            default:
                printf("\nInvalid Input!");
                getch();
                break;
            }
            break;
        case 8:
            p = 1;
            break;
        default:
            printf("\nInvalid Input!");
            getch();
            break;
        }
    } while (p == 0);
}

//-----------------------------------END--------------------------------------