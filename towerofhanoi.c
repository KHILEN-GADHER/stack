#include<stdio.h>

void toh(int n , char s , char i , char d)

{

    if (n == 1)

    {

        printf("Move disk 1 from %c to % c\n", s ,d);

        return;

    }

    toh(n-1 , s , d , i);

    printf("move disk %d from %c to %c \n", n , s , d);

    toh(n-1 , i , s ,d);

}

int main() {

    int n = 3;

    printf("Tower of Hanoi sequence for %d disks:\n", n);

    toh(n , 'A' , 'B' , 'C');

    return 0;

}