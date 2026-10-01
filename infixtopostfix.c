#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define M 10
void push(char s[] , char op , int *top)
{
    if(*top >= M-1)
    {
        printf("Stack is overflow \n");
        return;
    }
    else {
        s[++(*top)] = op;
        printf("%c is pushed \n" , op);
    }
}
char pop (char s[] , int *top)
{
    if (*top < 0)
    {
        printf("Stack is underflow \n");
        return '\0';
    }
    else
    {
        return s[(*top)--];
    }
}
int f(char op)
{
    if(op == '+' || op == '-')
    return 1;
    else if(op == '*' || op == '/')
    return 3;
    else if(op == '^')
    return 6;
    else if(op == '(')
    return 7;
    else if(op == ')')
    return 0;
    else
    return -1;
}
int g(char op)
{
    if(op =='+' || op == '-')
    return 2;
    else if(op == '*' || op == '/')
    return 4;
    else if(op == '^')
    return 5;
    else if(op == '(')
    return 0;
    else
    return -1;
}
void infix_to_postfix(char inf[] , char pf[] , char s[], int *top)
{
    int i = 0 , j = 0;
    char temp;
    s[++(*top)] = '(';
    for (i = 0 ; inf[i] != '\0' ; i++)
    {
         if(isalnum(inf[i]))
            pf[j++]=inf[i];
        else {
            while(f(inf[i])<g(s[*top]))
            {
                temp = pop(s,top);
                pf[j++]=temp;

            }
            if(f(inf[i])!=g(s[*top]))
                push(s, inf[i],top);
            else
                pop(s,top);
        }
    }
    pf[j]='\0';
}
int main(){
    char inf[20] , pf[20] , s[M];
    int top = -1;
    printf("Enter the infix expression : \n");
    scanf("%s" , inf);
    infix_to_postfix(inf , pf , s , &top);
    printf("The postfix expression is : %s \n" , pf);
    return 0;
}