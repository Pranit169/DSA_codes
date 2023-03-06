#include <stdio.h>
#include <stdlib.h>
int queue[50], n, front = -1, rear = -1;
void insert();
void delete();
void display();
int main()
{
    int choice;
    printf("Enter the length of array: ");
    scanf("%d", &n);
    while (1)
    {
        printf("\n1)Insert an element.\n2)Delete an element.\n3)Display.\n4)Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            delete ();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("INVALID INPUT");
            break;
        }
    }
}
void insert()
{
    int el;
    printf("Enter the element: ");
    scanf("%d", &el);
    if (rear == n - 1)
    {
        printf("OVERFLOW");
        return;
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = el;
    printf("The element is inserted.\n");
}
void delete()
{
    int el;
    if (front == -1 || front > rear)
    {
        printf("UNDERFLOW");
        return;
    }
    front++;
    printf("Deleted the element.\n");
}
void display()
{
    if (front == -1)
    {
        printf("The queue is empty.");
        return;
    }
    printf("The elements are: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}