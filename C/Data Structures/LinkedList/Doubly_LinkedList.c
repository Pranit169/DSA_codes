#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head, *tail;
void addAtFirst()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        newNode->next = NULL;
        return;
    }
    newNode->prev = NULL;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void addAtLast()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        newNode->next = NULL;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->prev = temp;
    temp->next = newNode;
    newNode->next = NULL;
}
void addAtPos()
{
    int pos;
    printf("Enter the position and data: ");
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d %d", &pos, &newNode->data);
    struct Node *temp = head;
    int count = 0;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}
void delAtFirst()
{
    struct Node *temp;
    if (head == NULL)
    {
        printf("The list is empty.");
        return;
    }
    temp = head;
    head = temp->next;
    head->prev = NULL;
    free(temp);
}
void delAtLast()
{
    struct Node *temp1, *temp2;
    if (head == NULL)
    {
        printf("The list is empty.");
        return;
    }
    temp1 = head;
    temp2 = head->next;
    while (temp2->next != NULL)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    temp1->next = NULL;
    free(temp2);
}
void delAtPos()
{
    struct Node *temp1, *temp2;
    temp1 = head;
    temp2 = head->next;
    int pos, count = 0;
    printf("Enter the position: ");
    scanf("%d", &pos);

    while (count < pos -1)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
        count++;
    }
    temp2->next->prev = temp1;
    temp1->next = temp2->next;

    free(temp2);
}
void search()
{
    int el, pos = 0;
    printf("Enter the element: ");
    scanf("%d", &el);
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == el)
        {
            printf("The element is found at address %p\n",temp);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("The element is not present in the list.\n");
}
void display()
{
    struct Node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        tail = temp;
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayRev()
{
    printf("Printing in reverse: ");
    struct Node *temp = tail;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1) Insert at first.\n2) Insert at last.\n3) Insert at position.\n4) Delete at first.\n5) Delete at last.\n6) Delete at position.\n7) Display.\n8) Display in reverse.\n9)Search.\n10)Exit.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            addAtFirst();
            break;
        case 2:
            addAtLast();
            break;
        case 3:
            addAtPos();
            break;
        case 4:
            delAtFirst();
            break;
        case 5:
            delAtLast();
            break;
        case 6:
            delAtPos();
            break;
        case 7:
            display();
            break;
        case 8:
            displayRev();
            break;
        case 9:
            search();
            break;
        case 10:
            exit(0);
            break;
        }
    }
    
}