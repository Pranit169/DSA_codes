#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
struct Node *createNode()
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->left = NULL;
    newNode->right = NULL;
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if (newNode->data == -1)
    {
        return NULL;
    }
    printf("Enter left data for %d\n", newNode->data);
    newNode->left = createNode();

    printf("Enter right data for %d\n", newNode->data);
    newNode->right = createNode();
    return newNode;
}
void preOrder(struct Node *root)
{
    // Follows:-  N->L->R (L=left, R=Right, N=Print node)
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void postOrder(struct Node *root)
{
    // Follows:- L->R->N
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
void inOrder(struct Node *root)
{
    // Follows:- L->N->R
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
int main()
{
    struct Node *root = createNode();
    preOrder(root);
    printf("\n");
    postOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
}