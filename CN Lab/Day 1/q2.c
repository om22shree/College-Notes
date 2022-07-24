#include<stdio.h>

struct info {
    int roll;
    char name[20];
    float cgpa;
};

void display(struct info *i){
    printf("Name: %s\n", i->name);
    printf("Roll no: %d\n", i->roll);
    printf("CGPA: %f\n", i->cgpa);
}

int main() {
    struct info a = {2006077, "Om Shree", 9.3};
    display(&a);
    return 0;
}