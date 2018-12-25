#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    int value;
    struct Node* next;
}
typedef struct Node* PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List MakeEmpty(List L);
int isEmpty(List L);
int isLast(Position P, List L);
Position Find(int x, List L);
void Delete(int x, List L);
Position FindPrevious(int x, List L);
void Insert(int x, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
int Retrieve(Position P);

int main() {
    
    return 0;
}

List MakeEmpty(List L) {
    L->next = NULL;
    return L;
}

int isEmpty(List L) {
    return L->next == NULL;
}

int isLast(Position P, List L) {
    return P->next == NULL;
}

Position Find(int x, List L) {
    Position P = L->next;
    while (P != NULL && P->value != x)
        P = P->next;
    return P;
}

void Delete(int x, List L) {
    Position P, TmpCell;
    P = FindPrevious(x, L);
    while (!isLast(P)) {
        TmpCell = P->next;
        P->next = TmpCell->next;
        free(TmpCell);
    }
}

Position FindPrevious(int x, List L) {
    Position P = L;
    while (P->next != NULL && P->next->value != x) {
        P = P->next;
    }
    return P;
}

void Insert(int x, List L, Position P) {
    Position TmpCell;
    TmpCell = (PtrToNode)malloc(sizeof(struct Node));
    if (TmpCell == NULL)
        printf("Out of space!");
    TmpCell->value = x;
    TmpCell->next = P->next;
    P->next = TmpCell;
}

void DeleteList(List L) {
    Position P, TmpCell;
    P = L->next;
    L->next = NULL;
    while (P != NULL) {
        TmpCell = P->next;
        free(P);
        P = TmpCell;
    }
}
