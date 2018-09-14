#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int top = -1;
int a, b, c, d;
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

int evaluate(char operator, int operand1, int operand2)
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
        return operand2 / operand1;
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
            push(stack, evaluate(expression[i], operand1, operand2));
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
        printf(" %d ", stack[i]);
    }
}

int generateNumber(int lower, int upper)
{
    return (rand() % (upper - lower + 1)) + lower;
}

int main()
{
    srand(time(0));
    int *stack = malloc(4 * sizeof(int));

    a = generateNumber(0, 6);
    b = generateNumber(a + 1, 7);
    c = generateNumber(b + 1, 8);
    d = generateNumber(c + 1, 9);

    printf("\na %d\nb %d\nc %d\nd %d", a, b, c, d);

    char *expression = "abc-*d+";
    evaluateExpression(expression, stack);
    display(stack);
}