#include <stdio.h>
#include <stdlib.h>

struct QueueRecord{
    int capacity;
    int front;
    int rear;
    int size;
    int* array;
}List;

typedef struct QueueRecord* Queue;

int IsEmpty(Queue Q) {
    return Q->size == 0;
}

int IsFull(Queue Q) {
    return Q->size == Q->capacity - 1;
}

Queue CreateQueue(int max) {
    Queue Q = (Queue)malloc(sizeof(List));
    Q->capacity = max;
    size_t i;
    for (i = 0; i < Q->capacity; i++) {
        Q->array[i] = (int)malloc(sizeof(int));
    }
    return Q;
}

void DisPoseQueue(Queue Q) {
    size_t i;
    for (i = 0; i < Q->capacity; i++) {
        free((int*)Q->array[i]);
    }
    free(Q);
}

void MakeEmpty(Queue Q) {
    Q->size = 0;
    Q->front = 1;
    Q->rear = 0;
}

static int succ(int value, Queue Q) {
    if (++value == Q->capacity) {
        value = 0;
    }
    return value;
}

void Enqueue(int x, Queue Q) {
    if (IsFull(Q)) {
        printf("Full Queue!");
    }
    else{
        Q->rear = succ(Q->rear, Q);
        Q->array[Q->rear] = x;
        Q->size++;
    }
}

void Dequeue(Queue Q) {
    if (IsEmpty(Q)) {
        printf("Empty Queue!");
    }
    else {
        Q->front = succ(Q->front, Q);
        Q->size--;
    }
}

int Front(Queue Q) {
    return Q->array[Q->front];
}

int FrontAndDequeue(Queue Q) {
    Dequeue(Q);
    int tmp;
    tmp = Q->front == 0 ? Q->size - 1 : Q->front - 1;
    return Q->array[tmp];
}

int main()
{

    return 0;
}
