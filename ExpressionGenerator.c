#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int top = -1;
int a, b, c, d, count;
char *combinationString[30];
const int UPPER = 3, LOWER = 0;
char operator[] = {'+', '-', '/', '*'};

int isEmpty()
{
    return (top == -1);
}

void push(int *stack, int value)
{
    stack[++top] = value;
}

int pop(int *stack)
{
    return stack[top--];
}

int isOperator(char operator)
{
    if (operator== '+' || operator== '-' || operator== '*' || operator== '/')
        return 1;
    return 0;
}

int performOperation(char operator, int operand1, int operand2)
{
    switch (operator)
    {
    case '+':
        return operand1 + operand2;
    case '-':
        return operand1 - operand2;
    case '*':
        return operand1 * operand2;
    case '/':
        if (operand1 != 0)
            return operand2 / operand1;
        printf("\nDenominator cannot be zero");
        return 0;
    }
}

void evaluateExpression(char *expression, int *stack)
{
    int i, operand1, operand2, value;
    for (i = 0; i < strlen(expression); i++)
    {
        if (isOperator(expression[i]))
        {
            if (!isEmpty())
            {
                operand1 = pop(stack);
            }
            else
            {
                printf("Invalid expression");
                return;
            }
            if (!isEmpty())
            {
                operand2 = pop(stack);
            }
            else
            {
                printf("Invalid expression");
                return;
            }
            push(stack, performOperation(expression[i], operand1, operand2));
        }
        else
        {
            if (expression[i] == 'a')
                value = a;
            else if (expression[i] == 'b')
                value = b;
            else if (expression[i] == 'c')
                value = c;
            else if (expression[i] == 'd')
                value = d;
            push(stack, value);
        }
    }
}

void display(int *stack)
{
    int i;
    for (i = 0; i <= top; i++)
    {
        if (stack[i] > -1)
            printf(" %d ", stack[i]);
        else
            printf("Number is not postive integer");
    }
}

int generateNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int getIndex()
{
    return (rand() % (UPPER - LOWER + 1)) + LOWER;
}

char *getExpression(char *str, int partition)
{
    int i, j;
    char *newExpression = malloc(8 * sizeof(char *));
    if (partition == 1)
    {
        for (i = 0, j = 0; i < 2;)
        {
            newExpression[j++] = str[i++];
        }
        newExpression[j++] = operator[getIndex()];

        for (; i < 4; i++)
        {
            newExpression[j++] = str[i];
        }
        for (i = 0; i < 3 - partition; i++)
        {
            newExpression[j++] = operator[getIndex()];
        }
    }

    else if (partition == 2)
    {
        for (i = 0, j = 0; i < 3;)
        {
            newExpression[j++] = str[i++];
        }
        newExpression[j++] = operator[getIndex()];
        newExpression[j++] = operator[getIndex()];

        for (; i < 4; i++)
            newExpression[j++] = str[i];

        for (i = 0; i < 3 - partition; i++)
        {
            newExpression[j++] = operator[getIndex()];
        }
    }
    else if (partition == 3)
    {
        for (i = 0, j = 0; i < 4;)
        {
            newExpression[j++] = str[i++];
        }
        newExpression[j++] = operator[getIndex()];
        newExpression[j++] = operator[getIndex()];
        newExpression[j++] = operator[getIndex()];
    }
    return newExpression;
}

void displayNumber()
{
    printf("\na: %d \nb: %d \nc: %d \nd: %d\n", a, b, c, d);
}

void combinationUtil(char *expression, int lower, int upper)
{
    int i;

    if (lower == upper)
    {
        strcpy(combinationString[count++], expression);
    }
    else
    {
        for (i = lower; i <= upper; i++)
        {
            swap((expression + lower), (expression + i));
            combinationUtil(expression, lower + 1, upper);
            swap((expression + lower), (expression + i));
        }
    }
}

int main()
{
    int i, j, partition;
    char expression[5] = "abcd";
    char bestSolution[10];
    int bestResult = 0;

    int stack[10];
    char *postfixExpression = malloc(sizeof(char *));

    srand(time(0));
    for (i = 0; i < 38; i++)
    {
        combinationString[i] = malloc(4 * sizeof(char *));
    }

    a = generateNumber(0, 6);
    b = generateNumber(a + 1, 7);
    c = generateNumber(b + 1, 8);
    d = generateNumber(c + 1, 9);

    combinationUtil(expression, 0, strlen(expression) - 1);
    for (i = 0; i < count; i++)
    {
        for (j = 0; j < 10; j++)
        {
            stack[j] = 0;
        }
        top = -1;
        partition = getIndex();
        if (partition == 0)
            partition = 1;

        postfixExpression = getExpression(combinationString[i], partition);
        printf("Expression %s", postfixExpression);

        evaluateExpression(postfixExpression, stack);

        printf("\nResult ");
        display(stack);
        if (bestResult < stack[top])
        {
            bestResult = stack[top];
            strcpy(bestSolution, postfixExpression);
        }
        printf("\n________________________________\n");
    }

    printf("\n********BEST SOLUTION*********\n");

    displayNumber();
    printf("Suitable expression is :: %s ", bestSolution);
    printf("\nResult :: %d\n", bestResult);
}