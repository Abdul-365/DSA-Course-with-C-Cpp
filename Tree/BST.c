#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int i, n;

struct node
{
    int info;
    struct node *left;
    struct node *right;
} *p, *root = NULL;

void create()
{
    struct node *node;
    system("cls");
    printf("Enter number of elements for Tree: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    root = malloc(sizeof(struct node));
    p = root;
    scanf("%d", &p->info);
    p->left = NULL;
    p->right = NULL;
    for (i = 1; i < n; i++)
    {
        node = malloc(sizeof(struct node));
        scanf("%d", &node->info);
        while (p->left != NULL || p->right != NULL)
        {
            if (node->info >= p->info)
            {
                if (p->right != NULL)
                    p = p->right;
                else break;
            }
            else
            {
                if (p->left != NULL)
                    p = p->left;
                else break;
            }
        }
        if (node->info >= p->info)
            p->right = node;
        else
            p->left = node;
        node->left = NULL;
        node->right = NULL;
        p = root;
    }
    printf("\nAll elements have been entered... ");
    getch();
}

void preorder(struct node *p)
{
    if (p == NULL)
        return;
    printf("%d ", p->info);
    preorder(p->left);
    preorder(p->right);
}

void inorder(struct node *p)
{
    if (p == NULL)
        return;
    inorder(p->left);
    printf("%d ", p->info);
    inorder(p->right);
}

void postorder(struct node *p)
{
    if (p == NULL)
        return;
    postorder(p->left);
    postorder(p->right);
    printf("%d ", p->info);
}

int height(struct node *p)
{
    if (p == NULL)
        return 0;
    int leftHeight = height(p->left); 
    int rightHeight = height(p->right);
    if (leftHeight > rightHeight)
        return leftHeight + 1; 
    else return rightHeight + 1;
}   

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

void levelOrder(struct node *p)
{
    for(int i = 1; i <= height(root); i++)
    {
        printf("\n");
        printCurrentLevel(p, i);
    }
}

void insert()
{
    struct node *new;
    system("cls");
    printf("Enter element you want to insert into tree: ");
    new = malloc(sizeof(struct node));
    scanf("%d", &new->info);
    new->left = NULL;
    new->right = NULL;
    if (root == NULL)
    {
        root = new;
        goto root_skip;
    }
    p = root;
    while (p->left != NULL || p->right != NULL)
    {
        if (new->info >= p->info)
        {
            if (p->right != NULL)
                p = p->right;
            else
                break;
        }
        else
        {
            if (p->left != NULL)
                p = p->left;
            else
                break;
        }
    }
    if (new->info >= p->info)
        p->right = new;
    else
        p->left = new;
root_skip:
    printf("\n%d has been inserted into the tree ", new->info);
    getch();
}

int check_tree_empty()
{
    if (root == NULL)
    {
        printf("Tree is empty! ");
        getch();
        return 1;
    }
    else
        return 0;
}

struct node *search(int item)
{
    p = root;
    while (p != NULL)
    {
        if (item > p->info)
            p = p->right;
        else if (item < p->info)
            p = p->left;
        else
            return p;
    }
    return NULL;
}

struct node *search_Parent(struct node *delete)
{
    p = root;
    while (p->left != delete &&p->right != delete)
    {
        if (delete->info > p->info)
            p = p->right;
        else if (delete->info < p->info)
            p = p->left;
    }
    return p;
}

struct node *inorder_successor_Parent(struct node *p)
{
    p = p->right;
    if (p->left == NULL)
        return root;
    while (p->left->left != NULL)
        p = p->left;
    return p;
}

void delete ()
{
    system("cls");
    if (check_tree_empty() == 1)
        return;
    int item;
    struct node *delete;
    printf("Enter element you want to delete: ");
    scanf("%d", &item);
    delete = search(item); //"delete" is the element we are intending to delete
    if (delete == NULL)
    {
        printf("\nItem not found in tree! ");
        getch();
        return;
    }
    else if (delete->left == NULL && delete->right == NULL)
    {
        if (delete == root)
        {
            free(root);
            root = NULL;
        }
        else
        {
            struct node *parent = search_Parent(delete);
            if (parent->left == delete)
                parent->left = NULL;
            else
                parent->right = NULL;
        }
    }
    else if (delete->left != NULL && delete->right != NULL)
    {
        if (inorder_successor_Parent(delete) != delete)
        {
            struct node *inorder_successor_Parent_ = inorder_successor_Parent(delete);
            struct node *inorder_successor = inorder_successor_Parent_->left;
            delete->info = inorder_successor->info;
            inorder_successor_Parent_->left = inorder_successor->right;
            free(inorder_successor);
        }
        else
        {
            struct node *inorder_successor = delete->right;
            delete->info = inorder_successor->info;
            delete->right = inorder_successor->right;
            free(inorder_successor);
        }
    }
    else
    {
        struct node *child;
        if (delete->left != NULL)
            child = delete->left;
        else
            child = delete->right;
        delete->info = child->info;
        delete->left = child->left;
        delete->right = child->right;
        free(child);
    }
    printf("\n%d has been deleted from tree ", item);
    getch();
}

void main()
{
    int choice, run = 0;
    do
    {
        system("cls");
        printf("Enter choice");
        printf("\n1 - Create a Tree");
        printf("\n2 - Traverse Tree");
        printf("\n3 - Search for element in tree");
        printf("\n4 - Insert element in tree");
        printf("\n5 - Delete element from tree");
        printf("\n6 - View height of tree");
        printf("\n7 - Exit");
        if (run == 0) // Make user create Tree if running for first time
        {
            printf("\n\n(Please create Tree first before performing any other operation)\n");
        enter_choice_again:
            scanf("%d", &choice);
            if (choice != 1 && choice != 7)
            {
                printf("Press 1 to create Tree first!\n");
                goto enter_choice_again;
            }
            run = 1;
        }
        else
        {
            printf("\n\n");
            scanf("%d", &choice);
        }
        switch (choice)
        {
        case 1:
            create();
            break;
        case 2:
            system("cls");
            if (check_tree_empty() == 1)
                goto skip;
            printf("Choose type of traversal:");
            printf("\n1 - Inorder traversal");
            printf("\n2 - Preorder traversal");
            printf("\n3 - Postorder traversal");
            printf("\n4 - Level order traversal\n\n");
        input:
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                inorder(root);
                break;
            case 2:
                preorder(root);
                break;
            case 3:
                postorder(root);
                break;
            case 4:
                levelOrder(root);
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
            if (check_tree_empty() == 1)
                goto skip;
            printf("Enter the element you want to search: ");
            scanf("%d", &item);
            if (search(item) == NULL)
                printf("\nItem not found! ");
            else
                printf("\n%d found in tree! ", item);
            getch();
        skip:
            break;
        case 4:
            insert();
            break;
        case 5:
            delete();
            break;
        case 6:
            system("cls");
            printf("Height of the tree is %d ", height(root));
            getch();
            break;
        case 7:
            exit(0);
        default:
            printf("Invalid Input!");
            getch();
            break;
        }
    } while (choice);
}