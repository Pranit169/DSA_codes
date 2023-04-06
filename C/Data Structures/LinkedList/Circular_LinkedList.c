#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *tail = NULL;
void atFirst()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
}
void atLast()
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    if (tail == NULL)
    {
        tail = newNode;
        tail->next = tail;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}
void atPosition()
{
    int pos, count = 0;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d", &newNode->data);
    printf("Enter position: ");
    scanf("%d", &pos);
    struct Node *temp = tail->next;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void delFirst()
{
    if (tail==NULL)
    {
        printf("The list is empty");
        return;
    }
    struct Node *temp = tail->next;
    tail->next = temp->next;
    temp->next = NULL;
    free(temp);
}
void delLast(){
    if (tail==NULL)
    {
        printf("The list is empty");
        return;
    }
    struct Node *temp=tail;
    while (temp->next!=tail)
    {
        temp=temp->next;
    }
    temp->next=tail->next;
    free(tail);
    tail=temp;
}
void delPos(){
    if (tail==NULL)
    {
        printf("The list is empty");
        return;
    }
    int pos,count=0;
    printf("Enter the position: ");
    scanf("%d",&pos);
    if (pos==0)
    {
        delFirst();
        return;
    }
    struct Node *temp=tail->next;
    while (count<pos-1)
    {
        temp=temp->next;
        count++;
    }
    struct Node *temp1=temp->next;
    temp->next=temp1->next;
    free(temp1);
}
 void display()
{
    struct Node *temp = tail->next;
    while (temp!= tail)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d NULL\n", tail->data);
}
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
            delFirst();
            break;
        case 5:
            delLast();
            break;
        case 6:
            delPos();
            break;
        case 7:
            display();
            break;
        case 8:
            exit(0);
            break;
        }
    }
}