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
    printf("%c%c%c%c", n.c1, n.c2[0], n.c2[1], n.c3);
    return 0;
}