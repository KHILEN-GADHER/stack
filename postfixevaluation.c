#include <stdio.h>
#include <ctype.h>
#include <math.h>

#define M 20

// Mentor-style push function
void push(int s[], int op, int *top)
{
    if (*top >= M - 1)
    {
        printf("Stack is overflow \n");
        return;
    }
    else
    {
        s[++(*top)] = op;
    }
}

// Mentor-style pop function (returns int for numeric calculation)
int pop(int s[], int *top)
{
    if (*top < 0)
    {
        printf("Stack is underflow \n");
        return 0;
    }
    else
    {
        return s[(*top)--];
    }
}

// Postfix evaluation using the mentor's stack functions
int evaluatePostfix(char *exp)
{
    int s[M];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(s, exp[i] - '0', &top);
        }
        else
        {
            int val2 = pop(s, &top); 
            int val1 = pop(s, &top);

            if (exp[i] == '+')
            {
                push(s, val1 + val2, &top);
            }
            else if (exp[i] == '-')
            {
                push(s, val1 - val2, &top);
            }
            else if (exp[i] == '*')
            {
                push(s, val1 * val2, &top);
            }
            else if (exp[i] == '/')
            {
                push(s, val1 / val2, &top);
            }
            else if (exp[i] == '^')
            {
                push(s, (int)pow(val1, val2), &top);
            }
        }
    }
    return pop(s, &top);
}

int main()
{
    char exp[] = "231*+9-"; // Calculation: (2 + (3 * 1)) - 9 = 5 - 9 = -4
    printf("Result: %d\n", evaluatePostfix(exp));
    return 0;
}