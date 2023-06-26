#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};
struct Node *createNode(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *node, int el)
{
    if (node == NULL)
        return createNode(el);
    if (node->data < el)
    {
        node->right = insert(node->right, el);
    }
    else
    {
        node->left = insert(node->left, el);
    }
    return node;
}
struct Node *delete(struct Node *node, int data)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->left == NULL && node->right == NULL)
    {
        free(node);
        return NULL;
    }

    if (node->data > data)
    {
        node->left = delete (node->left, data);
    }
    else if (node->data < data)
    {
        node->right = delete (node->right, data);
    }
    else
    {

        struct Node *temp = node->right;
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        node->data = temp->data;
        node->right = delete (node->right, data);
    }
    return node;
}
struct Node *search(struct Node *node, int el)
{
    if (node == NULL || node->data == el)
        return node;

    if (node->data < el)
    {
        return search(node->right, el);
    }
    else
    {
        return search(node->left, el);
    }
}
void inOrder(struct Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int main()
{
    struct Node *root = NULL;
    root = insert(root, 5);
    insert(root, 6);
    insert(root, 3);
    insert(root, 1);
    insert(root, 4);
    printf("Inorder traversel: ");
    inOrder(root);
    printf("\n");
    printf("Is 5 present in the tree or not: \n");
    if (search(root, 5) != NULL)
    {
        printf("The element is present in the tree\n");
    }
    else
    {
        printf("\nThe element is not present in the tree\n");
    }
    printf("Before deletion: ");
    inOrder(root);
    root = delete (root, 4);
    printf("\nAfter deletion: ");
    inOrder(root);
}