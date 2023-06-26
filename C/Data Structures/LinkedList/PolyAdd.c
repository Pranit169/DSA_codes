#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int coeff;
    int expt;
    struct Node *next;
};
typedef struct Node Polynomial;
Polynomial *createTerm(int coeff, int expt)
{
    Polynomial *newTerm = (Polynomial *)malloc(sizeof(Polynomial));
    newTerm->coeff = coeff;
    newTerm->expt = expt;
    newTerm->next = NULL;
    return newTerm;
}
void addTerm(Polynomial **poly, int coeff, int expt)
{
    Polynomial *newTerm = createTerm(coeff, expt);
    if (*poly == NULL)
    {
        *poly = newTerm;
    }
    else
    {
        Polynomial *temp = *poly;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}
Polynomial *addPolynomials(Polynomial *poly1, Polynomial *poly2)
{
    Polynomial *result = NULL;
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->expt > poly2->expt)
        {
            addTerm(&result, poly1->coeff, poly1->expt);
            poly1 = poly1->next;
        }
        else if (poly1->expt < poly2->expt)
        {
            addTerm(&result, poly1->coeff, poly2->coeff);
            poly2 = poly2->next;
        }
        else
        {
            int sum = poly1->coeff + poly2->coeff;
            if (sum != 0)
            {
                addTerm(&result, sum, poly1->expt);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }
    while (poly1 != NULL)
    {
        addTerm(&result, poly1->coeff, poly1->expt);
        poly1 = poly1->next;
    }
    while (poly2 != NULL)
    {
        addTerm(&result, poly2->coeff, poly2->expt);
        poly2 = poly2->next;
    }
    return result;
}
void displayPoly(Polynomial *poly)
{
    if (poly == NULL)
    {
        printf("Polynomial is empty.\n");
        return;
    }
    Polynomial *current = poly;
    while (current != NULL)
    {
        printf("%dx^%d ", current->coeff, current->expt);
        current = current->next;
        if (current != NULL)
        {
            printf("+ ");
        }
    }
    printf("\n");
}
int main()
{
    Polynomial *poly1 = NULL;
    Polynomial *poly2 = NULL;
    Polynomial *poly3 = NULL;
    addTerm(&poly1, 3, 4);
    addTerm(&poly1, 2, 3);
    addTerm(&poly1, 1, 2);
    addTerm(&poly2, 1, 3);
    addTerm(&poly2, 2, 1);
    addTerm(&poly2, 1, 0);
    Polynomial *result = addPolynomials(poly1, poly2);
    printf("First Polynomial: ");
    displayPoly(poly1);
    printf("Second Polynomial: ");
    displayPoly(poly2);
    printf("Sum: ");
    displayPoly(result);
}
