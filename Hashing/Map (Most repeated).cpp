#include <iostream>
#include <unordered_map>
using namespace std;

void frequencies(int arr[], int &n)
{
    unordered_map<int, int> hash;
    int maxFreq = 0, maxFreqNo;
    for(int i = 0; i < n; i++)
        hash[arr[i]]++;
    for(int i = 0; i < n; i++)
    {
        if(hash[arr[i]] > maxFreq)
        {
            maxFreq = hash[arr[i]];
            maxFreqNo = arr[i];
        }
    }
    cout << "Element that has been repeated most: " << maxFreqNo;
}

int main()
{
    int arr[10], i, n;
    system("cls");
    cout << "Enter number of elements for array: ";
    cin >> n;
    cout << "Enter elements: \n";
    for (i = 0; i < n; i++)
        cin >> arr[i];
    frequencies(arr, n);
}