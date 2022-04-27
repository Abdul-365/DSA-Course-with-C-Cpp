#include <iostream>
#include <conio.h>
#include <list>
using namespace std;

class Hashing
{
    int buckets; // No. of buckets
public:
    list<int> *table;                        // Pointer to an array containing buckets
    void createHash();                       // creates hash table and inserts keys in it
    list<int>::iterator searchItem(int key); // searches a key in the hash table
    void insertItem();                       // inserts a key in the hash table
    void deleteItem();                       // deletes a key from hash table
    int hashFunction(int x)                  // hash function to map values to key
    {
        return (x % buckets);
    }
    void displayHash();
};

void Hashing::createHash()
{
    system("cls");
    int key, n;
    cout << "Enter the number of elements you want to enter: ";
    cin >> n;
    this->buckets = n * 2;
    table = new list<int>[buckets]; // array of lists
    cout << "Enter elements: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        int index = hashFunction(key);
        table[index].push_back(key);
    }
    cout << "All elements have been entered...";
    getch();
}

void Hashing::insertItem()
{
    system("cls");
    int key, n;
    cout << "Enter elements: you want to insert into the hash table: ";
    cin >> key;
    int index = hashFunction(key);
    table[index].push_back(key);
    cout << endl
         << key << " has been inserted into the hash table at index " << index << " ";
    getch();
}

list<int>::iterator Hashing::searchItem(int key)
{
    int index = hashFunction(key);
    list<int>::iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++) // find the key in (index)th list
    {
        if (*i == key)
            break;
    }
    return i;
}

void Hashing::deleteItem()
{
    int key;
    system("cls");
    cout << "Enter the element you want to delete: ";
    cin >> key;
    int index = hashFunction(key);
    auto i = searchItem(key);
    if (i != table[index].end()) // if key is found in hash table, remove it
    {
        table[index].erase(i); 
        cout << endl
             << key << " deleted from hash table ";
    }
    else
        cout << endl << key << " not found! ";
    getch();
        
}

void Hashing::displayHash()
{
    system("cls");
    for (int i = 0; i < buckets; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
    getch();
}

int main()
{
    Hashing hash;
    list<int>::iterator i;
    int choice;
    do
    {
        system("cls");
        cout << "Enter choice: ";
        cout << "\n1 - Create hash table and enter elements in it";
        cout << "\n2 - Search element in hash table";
        cout << "\n3 - Insert element in hash table";
        cout << "\n4 - Delete element from hash table";
        cout << "\n5 - Display the hash table";
        cout << "\n6 - Exit\n\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            hash.createHash();
            break;
        case 2:
            system("cls");
            int key;
            cout << "Enter item you want to search in the hash table: ";
            cin >> key;
            int index;
            index = hash.hashFunction(key); 
            i = hash.searchItem(key);
            if (i != hash.table[index].end())
                cout << endl 
                     << key << " found at index " << index << " in hash table ";
            else
                cout << endl
                     << key << " not found! ";
            getch();
            break;
        case 3:
            hash.insertItem();
            break;
        case 4:
            hash.deleteItem();
            break;
        case 5:
            hash.displayHash();
            break;
        case 6:
            exit(0);
        }
    } while (choice);
}