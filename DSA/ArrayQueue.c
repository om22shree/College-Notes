#include<stdio.h>
#include<stdlib.h>

struct ArrayQueue {
    int front, rear, capacity;
    int *arr;
};

struct ArrayQueue *Queue(int size) {
    struct ArrayQueue *Q = malloc(sizeof(struct ArrayQueue));
    if(!Q) {
        return NULL;
    }
    Q->capacity = size;
    Q->front = Q->rear = -1;
    Q->arr = malloc(Q->capacity * sizeof(int));
    if(!Q->arr) {
        return NULL;
    }
    return Q;
}

int isEmpty(struct ArrayQueue *Q) {
    return Q->front == -1;
}

int isFull(struct ArrayQueue *Q) {
    return ((Q->rear + 1) % Q->capacity == Q->front);
}

int size(struct ArrayQueue *Q) {
    return ((Q->capacity - Q->front + Q->rear + 1) % Q->capacity);
}

void enQueue(struct ArrayQueue *Q, int data) {
    if(isFull(Q)) {
        printf("Memory Overflow");
    } else {
        Q->rear = (Q->rear + 1) % Q->capacity;
        Q->arr[Q->rear] = data;
        if(Q->front == -1) {
            Q->front = Q->rear;
        }
    }
}

int deQueue(struct ArrayQueue *Q) {
    int data = 0;
    if(isEmpty(Q)) {
        printf("Memory underflow");
        return -1;
    } else {
        data = Q->arr[Q->front];
        if(Q->front == Q->rear) {
            Q->front = Q->rear = -1;
        } else {
            Q->front = (Q->front + 1) % Q->capacity;
        }
        return data;
    }
}

void deleteQueue(struct ArrayQueue *Q) {
    if(Q) {
        if(Q->arr) {
            free(Q->arr);
        }
        free(Q);
    }  
}
