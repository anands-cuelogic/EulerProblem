#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

const int UPPER = 3, LOWER = 0;
char operator[] = {'+', '-', '/', '*'};

typedef struct expressionTree
{
    char num;
} ET;

int getIndex()
{
    return (rand() % (UPPER - LOWER + 1)) + LOWER;
}

void createExpression(int *numArray, int size)
{
    int i = 0, result = 0;
    for (i = 0; i < 4; i++)
    {
        printf("a %c b %c c %c d\n", operator[getIndex()], operator[getIndex()], operator[getIndex()]);
    }
}

int isOperator(char operator)
{
    if (operator== '+' || operator== '-' || operator== '*' || operator== '/')
        return 1;
    return 0;
}

int evaluate(char operator, char operand1, char operand2)
{
    switch (operator)
    {
    case '+':
        return (operand1 - '0') + (operand2 - '0');
    case '-':
        return (operand1 - '0') - (operand2 - '0');
    case '*':
        return (operand1 - '0') * (operand2 - '0');
    case '/':
        return (operand1 - '0') / (operand2 - '0');
    }
}

void createExpressionTree(ET **expTree, char *experssion)
{
    int i, num, result;
    ET *temp = NULL;
    for (i = 0; i < strlen(experssion); i++)
    {
        if (isOperator(experssion[i]))
        {
            if (*expTree == NULL)
            {
                printf("Invalid expression");
                return;
            }
            num = (*expTree)->num;
            temp = *expTree;
            if ((*expTree)->next != NULL)
            {
                *expTree = (*expTree)->next;
                result = evaluate(experssion[i], num, (*expTree)->num);
                temp->next = NULL;
                free(temp);
                printf("RESULT IS %d \n", result);
                (*expTree)->num = result + '0';
            }
            else
            {
                printf("Expression is not valid");
                return;
            }
        }
        else
        {
            if (*expTree == NULL)
            {
                *expTree = malloc(sizeof(struct expressionTree));
                (*expTree)->num = experssion[i];
                (*expTree)->next = NULL;
            }
            else
            {
                temp = malloc(sizeof(struct expressionTree));
                temp->num = experssion[i];
                temp->next = *expTree;
                *expTree = temp;
            }
        }
    }
}

void display(ET *stack)
{
    while (stack != NULL)
    {
        printf(" %d ", stack->num);
        stack = stack->next;
    }
}

int main()
{
    ET *expTree1 = NULL;
    srand(time(0));
    int numArray[] = {1, 2, 3, 4};
    char *exp1 = "243++5+";
    createExpressionTree(&expTree1, exp1);
    display(expTree1);
}