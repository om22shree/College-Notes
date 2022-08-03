/*
Q4: Write a C program to enter a number and store the number across a following
structure and print the content of each member of the structure then aggregate
each member of the structure to form the original number and print the same.
*/

#include<stdio.h>
struct num {
    char c1;
    char c2[2];
    char c3;
};

int main() {
    struct num n;
    n.c1 = 1+'0';
    n.c2[0] = 2+'0';
    n.c2[1] = 3+'0';
    n.c3 = 4+'0';
    printf("%c%c%c%c\n", n.c1, n.c2[0], n.c2[1], n.c3);
    return 0;
}