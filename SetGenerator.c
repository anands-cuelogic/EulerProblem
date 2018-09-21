#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *combinationString[30], *operatorCombinationString[64];
char operator[] = {'+', '-', '*', '/'};
int a, b, c, d, operatorCombinationCount, count, resultArray[100] = {0}, resultArrayCount = 0;
const int UPPER = 3, LOWER = 0;
int top = -1;

void appendOperator(int upper, char *newExpression, char *operatorStr)
{
    int i, j = strlen(newExpression);
    for (i = 0; i < upper; i++)
    {
        newExpression[j++] = operatorStr[i];
    }
}

void appendOperand(int lower, int upper, int j, char *str, char *newExpression)
{
    int i;
    for (i = lower; i < upper; i++)
    {
        newExpression[j++] = str[i];
    }
    newExpression[j] = '\0';
}

char *getExpression(char *combString, char *operatorStr, int partition)
{
    int i;
    char *newExpression = malloc(8 * sizeof(char *));
    if (partition == 1)
    {
        appendOperand(0, 2, 0, combString, newExpression);
        appendOperator(1, newExpression, operatorStr);

        appendOperand(2, 4, 3, combString, newExpression);
        appendOperator(3 - partition, newExpression, operatorStr);
    }

    else if (partition == 2)
    {
        appendOperand(0, 3, 0, combString, newExpression);
        appendOperator(2, newExpression, operatorStr);

        appendOperand(3, 4, 5, combString, newExpression);
        appendOperator(3 - partition, newExpression, operatorStr);
    }
    else if (partition == 3)
    {
        appendOperand(0, 4, 0, combString, newExpression);
        appendOperator(3, newExpression, operatorStr);
    }
    return newExpression;
}

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
        if (stack[i] >= 1)
            printf(" %d ", stack[i]);
    }
}

int isFound(int value)
{
    int i;
    for (i = 0; i < resultArrayCount; i++)
    {
        if (value == resultArray[i])
            return 1;
    }
    return 0;
}

void operatorCombinationUtil(int i, int j, int k)
{
    char *postfixExpression = malloc(sizeof(char *));
    int stack[10];
    int outer, inner, jj;
    if (i < 4)
    {
        if (j < 4)
        {
            if (k < 4)
            {
                //Store the operator in operatorCombinationString
                operatorCombinationString[operatorCombinationCount][0] = operator[i];
                operatorCombinationString[operatorCombinationCount][1] = operator[j];
                operatorCombinationString[operatorCombinationCount][2] = operator[k];
                for (outer = 0; outer < count; outer++)
                {
                    for (inner = 0; inner < 3; inner++)
                    {
                        for (jj = 0; jj < 10; jj++)
                        {
                            stack[jj] = 0;
                        }
                        top = -1;

                        postfixExpression = getExpression(combinationString[outer], operatorCombinationString[operatorCombinationCount], (inner + 1));
                        evaluateExpression(postfixExpression, stack);

                        if (stack[top] > 0 && !isFound(stack[top]))
                        {
                            resultArray[resultArrayCount++] = stack[top];
                            printf("Expression %s", postfixExpression);
                            printf("\nResult ");
                            display(stack);
                        }
                    }
                }
                operatorCombinationCount += 1;

                //Recursive call to operatorCombinationUtil
                operatorCombinationUtil(i, j, k + 1);
            }
            else
            {
                //Recursive call to operatorCombinationUtil
                operatorCombinationUtil(i, j + 1, 0);
            }
        }
        else
        {
            //Recursive call to operatorCombinationUtil
            operatorCombinationUtil(i + 1, 0, 0);
        }
    }
}

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//Generate the combination of operand
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

    int i, j, k;
    char expression[5] = "abcd";

    //Allocate the memory for combination of operand
    for (i = 0; i < 38; i++)
    {
        combinationString[i] = malloc(4 * sizeof(char *));
    }

    //Allocate the memory for combination of operator
    for (i = 0; i < 64; i++)
    {
        operatorCombinationString[i] = malloc(4 * sizeof(char *));
    }

    combinationUtil(expression, 0, strlen(expression) - 1);

    //To print all operand combination
    printf("\nExpression combination string is :\n");
    for (i = 0; i < count; i++)
    {
        printf("\n%s ", combinationString[i]);
    }

    //To genrate all operator combination
    a = 1;
    b = 2;
    c = 5;
    d = 8;
    operatorCombinationUtil(0, 0, 0);

    //To print all operator combination
    // printf("\nExpression combination string is :\n");
    // for (i = 0; i < operatorCombinationCount; i++)
    // {
    //     printf("\n%s ", operatorCombinationString[i]);
    // }

    printf("\nCount %d", operatorCombinationCount);
}