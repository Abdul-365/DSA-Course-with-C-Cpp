#include <iostream>
#include <conio.h>
#include <stack>
#include <queue>
using namespace std;

struct node
{
    int info;
    struct node *left;
    struct node *right;
} *p, *root = NULL;

int treeEmpty()
{
    if (root == NULL)
    {
        printf("Tree is empty! ");
        getch();
        return 1;
    }
    else return 0;
}

int height(node *p)
{
    if (p == NULL)
        return 0;
    int leftHeight = height(p->left); 
    int rightHeight = height(p->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
} 

node *findEmpty(struct node *p, int level)
{
    if(level == 1)
    {
        if(p->left == NULL || p->right == NULL)
            return p;
        else
            return NULL;
    }
    node *emptyLeft = findEmpty(p->left, level - 1);
    node *emptyRight = findEmpty(p->right, level - 1);
    if(emptyLeft == NULL && emptyRight == NULL)
        return NULL;
    else if(emptyLeft != NULL)
        return emptyLeft;
    else
        return emptyRight;
}

node *findInsert(node *p)
{
    node *insert = NULL;
    int h = height(p);
    for(int i = 1; i <= h && insert == NULL; i++)
        insert = findEmpty(p, i);
    return insert;
}

void create()
{
    int n;
    node *newNode, *insert;
    system("cls");
    cout << "Enter number of elements for Tree: ";
    scanf("%d", &n); 
    cout << "Enter elements:\n";
    root = new node;
    p = root;
    scanf("%d", &p->info);
    p->left = NULL;
    p->right = NULL;
    for(int i = 1; i < n; i++)
    {
        newNode = new node;
        cin >> newNode->info;
        newNode->left = NULL;
        newNode->right = NULL;
        insert = findInsert(root);
        if(insert->left == NULL)
            insert->left = newNode;
        else
            insert->right = newNode;
    }
    cout << "\nAll elements have been entered... ";
    getch();
}

void insertNode()
{
    node *newNode, *insert;
    system("cls");
    cout << "Enter element you want to insert in tree: ";
    newNode = new node;
    cin >> newNode->info;
    newNode->left = NULL;
    newNode->right = NULL;
    insert = findInsert(root);
    if(insert->left == NULL)
        insert->left = newNode;
    else
        insert->right = newNode;
    cout << endl << newNode->info << " has been inserted in tree ";
    getch();
}

node *search(node *p, int item)
{
    if (p == NULL)
        return NULL;
    if(p->info == item)
        return p;
    node *searchLeft = search(p->left, item);
    node *searchRight = search(p->right, item);
    if(searchLeft != NULL)
        return searchLeft;
    else if(searchRight != NULL)
        return searchRight;
    else return NULL;
}

void preorder(node *p)
{
    if (p == NULL)
        return;
    printf("%d ", p->info);
    preorder(p->left);
    preorder(p->right);
}

void preorder_Stack(node *p)
{
    stack<node *> s;
    s.push(p);
    while(!s.empty())
    {
        p = s.top();
        cout << p->info << " ";
        s.pop();
        if(p->right != NULL) s.push(p->right);
        if(p->left != NULL) s.push(p->left);
    }
}

void preorder_Stack2(node *p)
{
    stack<node *> s;
    int e = 0;
    while(p->left != NULL || !s.empty() || e == 1)
    {
        cout << p->info << " ";
        if (p->right != NULL) s.push(p->right);
        if (p->left != NULL) 
            p = p->left;
        else 
        {
            if (e == 1) break;
            p = s.top();
            s.pop();
            if (s.empty()) e = 1;
        }
    }
}

void inorder(node *p)
{
    if (p == NULL)
        return;
    inorder(p->left);
    printf("%d ", p->info);
    inorder(p->right);
}

void inorderStack(node *p)
{
    stack<node *> s;
    left:
    while(p != NULL)
    {
        s.push(p);
        p = p->left;
    }
    if(!s.empty())
    {
        cout << s.top()->info << " ";
        p = s.top()->right;
        s.pop();
        goto left;
    }
}

void postorder(node *p)
{
    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ", p->info);
} 

void postorder_Stack(node *p)
{
    stack<node *> s;
    stack<node *> s2; 
    s.push(p);
    while(!s.empty())
    {
        p = s.top();
        s2.push(p);
        s.pop();
        if (p->left != NULL) s.push(p->left);
        if (p->right != NULL) s.push(p->right);
    }
    while(!s2.empty())
    {
        p = s2.top();
        s2.pop();
        cout << p->info << " ";
    }
}
/*
void postorder_Stack2(node *p)
{
    stack<node *> s;

    while(!s.empty())
    {
        p = s.top();
        if(p->left != NULL)
        {
            while(p != NULL)
            {
                s.push(p);
                p = p->left;
            }
        }
        p = s.top();
        if (p->right != NULL)
        { 
            p = p->right;
            while(p != NULL)
            {
                s.push(p);
                p = p->left;
            }
        }
    }
        p = s.top();
        cout << p->info << " ";
        s.pop();      
}*/

void printCurrentLevel(struct node *p, int level)
{
    if(p == NULL)
        return;
    else if(level == 1)
        printf("%d ", p->info);
    else
    {
        printCurrentLevel(p->left, level - 1);
        printCurrentLevel(p->right, level - 1);
    }
}

void levelOrder(node *p)
{
    for(int i = 1; i <= height(root); i++)
    {
        printf("\n");
        printCurrentLevel(p, i);
    }
}

void levelOrder_Queue(node *p)
{
    queue<node *> q;
    q.push(p);
    while(!q.empty())
    {
        p = q.front();
        cout << p->info << " ";
        if(p->left != NULL) q.push(p->left);
        if(p->right != NULL) q.push(p->right);
        q.pop();
    }
}

void leaves(node *p)
{
    if(p == NULL) return;
    if(p->left == NULL && p->right == NULL)
    {
        cout << p->info << " ";
        return;
    }
    leaves(p->left);
    leaves(p->right);
}

void boundary_traversal(node *root)
{
    node *p = root;
    while(p->left != NULL) 
    {
        cout << p->info << " ";
        p = p->left;
    }
    leaves(root);
    stack<node *> s;
    p = root->right;
    while(p->right != NULL)
    {
        s.push(p);
        p = p->right;
    }
    while(!s.empty())
    {
        p = s.top();
        cout << p->info << " ";
        s.pop();
    }
}

//Density of Binary Tree = Size / Height 

int density(node *p, int &n, int &height)
{
    if (p == NULL)
        return 0;
    n++;
    int leftHeight = density(p->left, n , height); 
    int rightHeight = density(p->right, n , height);
    if (leftHeight > rightHeight)
        height = leftHeight;
    else
        height = rightHeight;
    height++;
    return height; 
}

node *bottom_RightNode_Parent(node *p)
{
    while(height(p) > 2)
    {
        if(height(p->left) > height(p->right))
            p = p->left;
        else if(height(p->left) <= height(p->right))
            p = p->right;
    }
    return p;
}

void deleteNode()
{
    system("cls");
    if(treeEmpty() == 1)
        return;
    int item;
    node *replace, *del;
    cout << "Enter number you want to delete from tree: ";
    cin >> item;
    del = search(root, item);
    if(del == NULL)
    {
        cout << endl << item << " not found in tree ";
        getch();
        return;
    }
    replace = bottom_RightNode_Parent(root);
    if(replace->right != NULL)
    {        
        del->info = replace->right->info;
        replace->right = NULL;
    }
    else if(replace->left != NULL)
    {
        del->info = replace->left->info;
        replace->left = NULL;
    }
    else
        root = NULL ;
    cout << endl << item << " deleted from tree ";
    getch();
}

int main()
{
    int choice, run = 0;
    float d;
    do
    {
        system("cls");
        cout << "Enter choice";
        cout << "\n1 - Create a Tree";
        cout << "\n2 - Traverse Tree";
        cout << "\n3 - Search an element in tree";
        cout << "\n4 - Insert element in tree";
        cout << "\n5 - Delete element from tree";
        cout << "\n6 - View density of tree";
        cout << "\n7 - Exit";
        if (run == 0) // Make user create Tree if running for first time
        {
            cout << "\n\n(Please create Tree first before performing any other operation)\n";
        enter_choice_again:
            scanf("%d", &choice);
            if (choice != 1 && choice != 7)
            {
                cout << "Press 1 to create Tree first!\n";
                goto enter_choice_again;
            }
            run = 1;
        }
        else
        {
            cout << "\n\n";
            scanf("%d", &choice);
        }
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            system("cls");
            if (treeEmpty() == 1)
                goto skip;
            printf("Choose type of traversal:");
            printf("\n1 - Inorder traversal");
            printf("\n2 - Preorder traversal");
            printf("\n3 - Postorder traversal");
            printf("\n4 - Level order traversal");
            printf("\n5 - Boundary traversal\n\n");
        input:
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                inorderStack(root);
                break;
            case 2:
                preorder_Stack2(root);
                break;
            case 3:
                postorder_Stack(root);
                break;
            case 4:
                levelOrder(root);
                break;
            case 5:
                boundary_traversal(root);
                break;
            default:
                printf("\nInvalid Input!\n");
                goto input;
            }
            getch();
            break;
        case 3:
            int item;
            system("cls");
            if (treeEmpty() == 1)
                goto skip;
            cout << "Enter the element you want to search: ";
            scanf("%d", &item);
            if (search(root, item) == NULL)
                cout << endl << item << " not found! ";
            else
                cout << endl << item << " found in tree! ";
            getch();
        skip:
            break;
        case 4:
            insertNode();
            break;
        case 5:
            deleteNode();
            break;
        case 6:
            int n, height;
            n = height = 0;
            system("cls");
            density(root, n, height);
            d = n / (float) height;
            cout << "Density of tree is " << d << " ";
            getch();
            break;
        case 7:
            exit(0);
        default:
            cout << "Invalid Input!";
            getch();
            break;
        }
    } while (choice);
    return 0;
}