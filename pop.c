#include <stdio.h>
#define M 10
void push(char s[] , char op , int *top)
{
    if (*top >= M-1)
    {
        printf("stack is overflow \n");
        return;
    }
    else {
        s[++(*top)] = op;
        printf("%c is pushed \n" , op);
    }  
}
char pop(char s[] , int *top)
{
    if (*top < 0){
        printf("stack is underflow \n");
        return '\0';
    }
    return s[(*top)--];
}
int main () {
    char s[M] ;
    int top = -1;
    push(s , 'A' , &top);   
    push(s , 'B' , &top);
    push(s , 'C' , &top);
    printf("\nPopping from stack:\n");
    printf("Popped value: %c (new top = %d)\n", pop(s, &top), top);
    printf("Popped value: %c (new top = %d)\n", pop(s, &top), top);
    printf("Popped value: %c (new top = %d)\n", pop(s, &top), top);
    printf("\nAttempting 4th pop:\n");
    pop(s , &top);
    return 0;
}
