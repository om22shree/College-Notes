#include<stdio.h>

struct num {
    char c1;
    char c2[2];
    char c3;
};

int main() {
    struct num n = {1+'0', 23+'0', 4+'0'};
    printf("%c%s%c", n.c1, n.c2, n.c3);
    return 0;
}