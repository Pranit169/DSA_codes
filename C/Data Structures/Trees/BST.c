#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *left, *right;
};

struct Node *create(int data)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
struct Node *insert(struct Node *node)
{
    int el;
    printf("Enter the data: ");
    scanf("%d", &el);
    if (node == NULL)
        return create(el);
    if (node->data < el)
    {
        node->right = insert(node->right);
    }
    else
    {
        node->left = insert(node->left);
    }
    return node;
}
struct Node *search(struct Node *node)
{
    int el;
    printf("Enter the element: ");
    scanf("%d", &el);
    if ( node ==NULL|| node->data == el)
        return node;

    if (node->data < el)
    {
        return search(node->right);
    }
    return search(node->left);
}
void inOrder(struct Node *root){
    if (root!=NULL)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }   
}
int main(){
      struct Node *root=insert(root);
      insert(root);
      insert(root);
      insert(root);
      inOrder(root);
}