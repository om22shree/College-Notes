#include<stdio.h>

int main () {
    int n = 0x346578;
    char b0, b1, b2, b3;
    b0 = ((char*)(&n))[0];
    b1 = ((char*)(&n))[1];
    b2 = ((char*)(&n))[2];
    b3 = ((char*)(&n))[3];
    printf("Bytes printed in 4 different characters:-\n %d, %d, %d, %d\n", b0, b1, b2, b3);
    return 0;
}