#include<stdio.h>
#include<stdlib.h>

struct DynArrStack {
    int top;
    int capacity;
    int *array;
};

struct DynArrStack *createStack() {
    struct DynArrStack *S = malloc(sizeof(struct DynArrStack));
    if(!S) {
        return NULL;
    }
    S->capacity = 1;
    S->top = -1;
    S->array = malloc(S->capacity * sizeof(int));
    if(!S->array) {
        return NULL;
    }
    return S;
}

int isFull(struct DynArrStack *S) {
    return (S->top == S->capacity - 1);
}

void doubleStack(struct DynArrStack *S) {
    S->capacity *= 2;
    S->array = realloc(S->array, S->capacity * sizeof(int));
}

void push(struct DynArrStack *S, int x) {
    if(isFull(S)) {
        doubleStack(S);
    }
    S->array[++S->top] = x;
}

int isEmpty(struct DynArrStack *S) {
    return S->top == -1;
}

int top(struct DynArrStack *S) {
    if(isEmpty(S)) {
        return -1;
    }
    return S->array[S->top];
}

int pop(struct DynArrStack *S) {
    if(isEmpty(S)) {
        return -1;
    }
    return S->array[S->top--];
}

void deleteStack(struct DynArrStack *S) {
    if(S) {
        if(S->array) {
            free(S->array);
        }
        free(S);
    }
}

