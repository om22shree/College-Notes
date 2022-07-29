/*
Q5: Write a C program to check whether the host machine is little endian or
big endian. Enter a number, print the content of each byte location and convert 
the endianness of the same i.e. little to big endian and vice versa.
*/

#include <stdio.h>

int main () {
    unsigned int x = 0x76543210;
    char *c = (char*) &x;
 
    printf ("*c is: 0x%x\n", *c);
    if (*c == 0x10) {
        printf ("little endian. \n");
    } else {
        printf ("big endian. \n");
    }
 
    return 0;
}

