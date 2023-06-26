#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    false,
    true
} boolean;
struct node
{
    struct node *left;
    boolean lthread;
    int data;
    boolean rthread;
    struct node *right;
};
struct node *insert(struct node *root, int key)
{
    struct node *tmp, *par, *ptr;
    int found = 0;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (key == ptr->data)
        {
            found = 1;
            break;
        }
        par = ptr;
        if (key < ptr->data)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (found)
        printf("\nDuplicate key");
    else
    {
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = key;
        tmp->lthread = true;
        tmp->rthread = true;
        if (par == NULL)
        {
            root = tmp;
            tmp->left = NULL;
            tmp->right = NULL;
        }
        else if (key < par->data)
        {
            tmp->left = par->left;
            tmp->right = par;
            par->lthread = false;
            par->left = tmp;
        }
        else
        {
            tmp->left = par;
            tmp->right = par->right;
            par->rthread = false;
            par->right = tmp;
        }
    }
    return root;
}
struct node *in_succ(struct node *ptr)
{
    if (ptr->rthread == true)
        return ptr->right;
    else
    {
        ptr = ptr->right;
        while (ptr->lthread == false)
            ptr = ptr->left;
        return ptr;
    }
}
struct node *in_pred(struct node *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;
    else
    {
        ptr = ptr->left;
        while (ptr->rthread == false)
            ptr = ptr->right;
        return ptr;
    }
}
void inorder(struct node *root)
{
    struct node *ptr;
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr = root;
    while (ptr->lthread == false)
        ptr = ptr->left;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = in_succ(ptr);
    }
}
void preorder(struct node *root)
{
    struct node *ptr;
    if (root == NULL)
    {
        printf("Tree is empty");
        return;
    }
    ptr = root;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        if (ptr->lthread == false)
            ptr = ptr->left;
        else if (ptr->rthread == false)
            ptr = ptr->right;
        else
        {
            while (ptr != NULL && ptr->rthread == true)
                ptr = ptr->right;
            if (ptr != NULL)
                ptr = ptr->right;
        }
    }
}
int main()
{

    int choice, num;
    struct node *root = NULL;
    while (1)
    {
        printf("\n1.Insert\n");
        printf("2.Traversal\n");
        printf("3.Quit\n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number to be inserted : ");
            scanf("%d", &num);
            root = insert(root, num);
            break;
        case 2:
            printf("Inorder Traversell: ");
            inorder(root);
            printf("\nPreorder Traversel: ");
            preorder(root);
            break;
        case 3:
            exit(0);

        default:
            printf("invalid Output\n");
        }
    }
    return 0;
}
