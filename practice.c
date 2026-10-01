#include <stdio.h>
#define MAX 3
int stack[MAX];
int top = -1;

void push(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", val);
        return;
    }
    stack[++top] = val;
    printf("%d pushed to stack\n", val);
}
void pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop from empty stack\n");
        return;
    }
    printf("%d popped from stack\n", stack[top--]);
}   

int main() {
    push(10);
    push(20);
    push(30);
    push(40); // This will cause stack overflow
    pop();  
    pop();
    pop();
    pop(); // This will cause stack underflow
    return 0;
}