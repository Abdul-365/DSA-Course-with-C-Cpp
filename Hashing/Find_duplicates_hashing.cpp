#include <iostream>
#include <unordered_set>
#include <conio.h>
using namespace std;

void Find_Duplicates(int arr[], int n)
{
    unordered_set<int> duplicates;
    unordered_set<int> hash;
    for (int i = 0; i < n; i++)
    {
        if (hash.find(arr[i]) == hash.end())
            hash.insert(arr[i]);
        else 
            duplicates.insert(arr[i]);
    }
    cout << "\nDuplicate elements are: ";
    for(auto i : duplicates)
        cout << i << " ";
}

int main()
{
    int arr[20], n;
    system("cls");
    cout << "Enter number of elements for array: ";
    cin >> n;
    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "All elements have been entered...";
    getch();
    Find_Duplicates(arr, n);
    return 0;
}