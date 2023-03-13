#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head;
void addAtFirst(){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    if (head==NULL)
    {
        newNode->prev=NULL;
        head=newNode;
        newNode->next=NULL;
        return;
    }
    newNode->prev=NULL;
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
void addAtLast(){
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    if (head==NULL)
    {
        newNode->prev=NULL;
        head=newNode;
        newNode->next=NULL;
        return;
    }
    struct Node *temp=head;
    while (temp->next!=NULL)
    {
        temp=temp->next;
    }
    newNode->prev=temp;
    temp->next=newNode;
    newNode->next=NULL;
}
void addAtPos(){
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
    newNode->next=temp->next;
    temp->next->prev=newNode;
    temp->next=newNode;
    newNode->prev=temp;
}
void delAtFirst(){
    struct Node *temp;
    if (head == NULL)
    {
        printf("The list is empty.");
        return;
    }
    temp=head;
    head=temp->next;
    head->prev=NULL;
    free(temp);
}
void delAtLast(){
   struct Node *temp1,*temp2;
    if (head == NULL)
    {
        printf("The list is empty.");
        return;
    }
    temp1=head;
    temp2=head->next;
    while (temp2->next!=NULL)
    {
        temp1=temp1->next;
        temp2=temp2->next;
    }
    
    

}
void display(){
    struct Node *temp;
    temp = head;
    struct Node *last=NULL;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        last=temp;
        temp = temp->next;
    }
    printf("NULL\n");

    printf("Printing in reverse: ");
    while (last!=NULL)
    {
        printf("%d->", last->data);
        last=last->prev;
    }
    printf("NULL\n");
}
int main(){
    
    addAtFirst();
    addAtLast();
    addAtPos();
    display();
    delAtFirst();
    display();
}