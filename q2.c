/*
Name: Garnet McLaren
Date: 15/10/18
Assignment Number: 2
Student ID: 1022927
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node node;       //struct stores drigits
struct node{
    double n;
    node* next;
};

#define empty(s) (!(s))

void push(node** top, double n)   //add a next digit to the stack
{
    node* new = malloc(sizeof(node));
    if (!new)
    {
        exit(-1);
    }
    new->n = n;
    new->next = *top;
    *top = new;
}

double pop(node** top)      //remove a digit from the stack
{
    double n;
    node *temp;
    if (empty(*top))
    {
        return 0;
    }
    temp = *top;
    *top = temp->next;
    n = temp->n;
    free(temp);
    return n;
}

double do_calculation(double a, double b, char operation)   //does a different calculation depending on the operation char
{
    if (operation == '+')
    {
        return a + b;
    }
    else if (operation == '-')
    {
        return a - b;
    }
    else if (operation == '*')
    {
        return a * b;
    }
    else if (operation == '/')
    {
        return a / b;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    if (argc == 2)     //verifies that a single line of input is entered
    {
        node* s = NULL;
        int count;
        for (count = 0; count < strlen(argv[1]); count ++)   //loops through the input
        {
            if ((argv[1][count] != '+') && (argv[1][count] != '-') && (argv[1][count] != '*') && (argv[1][count] != '/'))
            {
                push(&s, (double)argv[1][count]-48);        //digits are added to the stack
            }
            else
            {
                push(&s, do_calculation(pop(&s), pop(&s), argv[1][count]));   //if an operator is encountered,
            }

        }
        printf("%.2lf\n", pop(&s));      //the stack will have one digit, the result which gets printed
    }
    else
    {
        printf("invalid input\n");
    }
    return 0;
}
