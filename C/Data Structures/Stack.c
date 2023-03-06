#include <stdio.h>
#include <stdlib.h>
int a[50], n;
int top = -1;

void push();
void pop();
void display();
int main()
{
    int c, choice = 1;
    printf("Enter the length of array: ");
    scanf("%d", &n);
    while (1)
    {
        printf("\nEnter 1 to push: \nEnter 2 to pop: \nEnter 3 to display: \nEnter 4 to exit: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            exit(0);
            break;
        }
    }
}
void push()
{
    int el;
    if (top == n - 1)
    {
        printf("Overflow");
        return;
    }
    printf("Enter the element you want to enter: ");
    scanf("%d", &el);
    top = top + 1;
    a[top] = el;
}
void pop()
{
    if (top == -1)
    {
        printf("The stack is empty.");
        return;
    }
    printf("The element poped is %d", a[top]);
    top = top - 1;
}
void display()
{
    if (top == -1)
    {
        printf("The stack is empty");
        return;
    }
    int temp = top;
    while (temp >= 0)
    {
        printf("%d ", a[temp]);
        temp--;
    }
}