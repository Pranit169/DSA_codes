#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head;
void atFirst();
void atLast();
void atPosition();
void deleteAtFirst();
void deleteAtLast();
void deleteAtPosition();
void print();
int main()
{
    int choice;
    while (1)
    {
        printf("\n1) Insert at first.\n2) Insert at last.\n3) Insert at position.\n4) Delete at first.\n5) Delete at last.\n6) Delete at position.\n7) Display.\n8) Exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            atFirst();
            break;
        case 2:
            atLast();
            break;
        case 3:
            atPosition();
            break;
        case 4:
            deleteAtFirst();
            break;
        case 5:
            deleteAtLast();
            break;
        case 6:
            deleteAtPosition();
            break;
        case 7:
            print();
            break;
        case 8:
            exit(0);
            break;
        }
    }
}

void print()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
void atFirst()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int n;
    printf("Enter data: ");
    scanf("%d", &n);
    newNode->data = n;
    newNode->next = head;
    head = newNode;
}
void atLast()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    int n;
    printf("Enter data: ");
    scanf("%d", &n);
    newNode->data = n;
    if (head == NULL)
    {
        newNode->next = NULL;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = NULL;
}
void atPosition()
{
    int n, pos;
    printf("Enter the position and data: ");
    scanf("%d %d", &pos, &n);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int count = 0;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->data = n;
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteAtFirst()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("The list is empty.");
        return;
    }
    temp = head;
    head = temp->next;
    free(temp);
}
void deleteAtLast()
{
    struct Node *temp, *temp2;
    if (head == NULL)
    {
        printf("The list is empty.");
        return;
    }
    temp = head;
    temp2 = head->next;
    while (temp2->next != NULL)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = NULL;
    free(temp2);
}
void deleteAtPosition()
{
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    int count = 0;
    struct Node *temp, *temp2;
    temp = head;
    temp2 = head->next;
    for (int i = 0; i < pos - 1; i++)
    {
        temp = temp->next;
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    free(temp2);
}