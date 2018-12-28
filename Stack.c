#include <stdio.h>
#include <stdlib.h>

struct Node{
    int value;
    struct Node* next;
}List;

typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S) {
    return S->next == NULL;
}

Stack CreateStack() {
    Stack head;
    head = (Stack)malloc(sizeof(List));
    if (head == NULL) {
        printf("Out of space!");
    }
    head->next = NULL;
    return head;
}

void Push(int x, Stack S) {
    PtrToNode tmp;
    tmp = (Stack)malloc(sizeof(List));
    tmp->value = x;
    S->next = tmp;
    tmp->next = NULL;
}

int Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->next->value;
    }
    printf("Empty Stack!");
    return 0;
}

void Pop(Stack S) {
    PtrToNode tmp;
    if (IsEmpty(S)) {
        printf("Empty Stack!");
    }
    else {
        tmp = S->next;
        S->next = tmp->next;
        free(tmp);
    }
}

void MakeEmpty(Stack S) {
    if (S == NULL) {
        printf("Must use CreateStack first!");
    }
    while (!IsEmpty(S)) {
        Pop(S);
    }
}
int main()
{

    return 0;
}
