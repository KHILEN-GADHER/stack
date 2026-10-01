#include <stdio.h>
#define M 5
void push (int s[] , int op , int *top)
{
    if (*top >= M - 1)
    {
        printf("Stack overflow \n");
        return;
    }
    else
    {
         s[++(*top)] = op;
        printf("%c is pushed \n" , op);
    }
}
int main(){
    int s[M] ;
    int top = -1;
    push(s , 10 , &top);
    push(s , 20 , &top);
    push(s , 30 , &top);
    printf("\n Stack from top to bottom is : \n");
    for (int i = top ; i >= 0 ; i--)
    {
        printf ("%d \n" , s[i]);
    }
    return 0;
}