/*
Q3: Write a C program to extract bytes of a number into characters and print
thier contents.
*/

#include<stdio.h>

int main () {
    unsigned char bytes[4];
    unsigned long n = 983475;

    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;
    printf("%x %x %x %x\n", bytes[0], bytes[1], bytes[2], bytes[3]);

    return 0;
}