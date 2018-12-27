#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node* PtrToNode;

struct Node{
    int coefficient;
    int exponent;
    PtrToNode next;
}List;

typedef PtrToNode Polynomial;

Polynomial CreatePoly(int num) {
    Polynomial head, tail;
    head = (Polynomial)malloc(sizeof(List));
    tail = head;
    size_t i;
    for (i = 0; i < num; i++) {
        Polynomial p;
        p = (Polynomial)malloc(sizeof(List));
        tail->next = p;
        p->next = NULL;
        tail = p;
    }
    return head;
}

void MakeEmpty(Polynomial head) {
    Polynomial p1, p2;
    p1 = head;
    p2 = p1->next;
    while (p2->next != NULL) {
        p1->next = p2->next;
        free(p2);
        p2 = p1->next;
    }
    p1->next = NULL;
    free(p2);
}

void InputPoly(Polynomial head) {
    Polynomial p = head->next;
    while (p != NULL) {
        scanf("%d x %d", &p->coefficient, &p->exponent);
        p = p->next;
    }
}

void OutputPoly(Polynomial head) {
    Polynomial p = head->next;
    while (p != NULL) {
        printf("%d x %d ", p->coefficient, p->exponent);
        p = p->next;
    }
    printf("\n");
}

void AddPoly(Polynomial p1, Polynomial p2, Polynomial p3) {
    Polynomial pa, pb, pc, tmp;
    pa = p1->next;
    pb = p2->next;
    pc = p3;
    while (pa != NULL && pb != NULL) {
        if (pa->exponent < pb->exponent) {
            tmp = (Polynomial)malloc(sizeof(List));
            tmp->coefficient = pa->coefficient;
            tmp->exponent = pa->exponent;
            pc->next = tmp;
            tmp->next = NULL;
            pc = tmp;
            pa = pa->next;
        }
        else if (pa->exponent > pb->exponent) {
            tmp = (Polynomial)malloc(sizeof(List));
            tmp->coefficient = pb->coefficient;
            tmp->exponent = pb->exponent;
            pc->next = tmp;
            tmp->next = NULL;
            pc = tmp;
            pb = pb->next;
        }
        else if (pa->exponent == pb->exponent) {
            if (pa->coefficient + pb->coefficient != 0) {
                tmp = (Polynomial)malloc(sizeof(List));
                tmp->coefficient = pa->coefficient + pb->coefficient;
                tmp->exponent = pa->exponent;
                pc->next = tmp;
                tmp->next = NULL;
                pc = tmp;
                pa = pa->next;
                pb = pb->next;
            }
            else if (pa->coefficient + pb->coefficient == 0) {
                pa = pa->next;
                pb = pb->next;
            }
        }
    }
    while (pa != NULL) {
        tmp = (Polynomial)malloc(sizeof(List));
        tmp->coefficient = pa->coefficient;
        tmp->exponent = pa->exponent;
        pc->next = tmp;
        tmp->next = NULL;
        pc = tmp;
        pa = pa->next;
    }
    while (pb != NULL) {
        tmp = (Polynomial)malloc(sizeof(List));
        tmp->coefficient = pb->coefficient;
        tmp->exponent = pb->exponent;
        pc->next = tmp;
        tmp->next = NULL;
        pc = tmp;
        pb = pb->next;
    }
}

void SubPoly(Polynomial p1, Polynomial p2, Polynomial p3) {
    Polynomial pa, pb, pc, tmp;
    pa = p1->next;
    pb = p2->next;
    pc = p3;
    while (pa != NULL && pb != NULL) {
        if (pa->exponent < pb->exponent) {
            tmp = (Polynomial)malloc(sizeof(List));
            tmp->coefficient = pa->coefficient;
            tmp->exponent = pa->exponent;
            pc->next = tmp;
            tmp->next = NULL;
            pc = tmp;
            pa = pa->next;
        }
        else if (pa->exponent > pb->exponent) {
            tmp = (Polynomial)malloc(sizeof(List));
            tmp->coefficient = -pb->coefficient;
            tmp->exponent = pb->exponent;
            pc->next = tmp;
            tmp->next = NULL;
            pc = tmp;
            pb = pb->next;
        }
        else if (pa->exponent == pb->exponent) {
            if (pa->coefficient != pb->coefficient) {
                tmp = (Polynomial)malloc(sizeof(List));
                tmp->coefficient = pa->coefficient - pb->coefficient;
                tmp->exponent = pa->exponent;
                pc->next = tmp;
                tmp->next = NULL;
                pc = tmp;
                pa = pa->next;
                pb = pb->next;
            }
            else if (pa->coefficient == pb->coefficient) {
                pa = pa->next;
                pb = pb->next;
            }
        }
    }
    while (pa != NULL) {
        tmp = (Polynomial)malloc(sizeof(List));
        tmp->coefficient = pa->coefficient;
        tmp->exponent = pa->exponent;
        pc->next = tmp;
        tmp->next = NULL;
        pc = tmp;
        pa = pa->next;
    }
    while (pb != NULL) {
        tmp = (Polynomial)malloc(sizeof(List));
        tmp->coefficient = -pb->coefficient;
        tmp->exponent = pb->exponent;
        pc->next = tmp;
        tmp->next = NULL;
        pc = tmp;
        pb = pb->next;
    }
}

void AscendPoly(Polynomial p1) {
    Polynomial i, j;
    int coe, exp;
    for (i = p1->next; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (j->exponent < i->exponent) {
                coe = i->coefficient;
                exp = i->exponent;
                i->coefficient = j->coefficient;
                i->exponent = j->exponent;
                j->coefficient = coe;
                j->exponent = exp;
            }
        }
    }
}

void DescendPoly(Polynomial p1) {
    Polynomial i, j;
    int coe, exp;
    for (i = p1->next; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (j->exponent > i->exponent) {
                coe = i->coefficient;
                exp = i->exponent;
                i->coefficient = j->coefficient;
                i->exponent = j->exponent;
                j->coefficient = coe;
                j->exponent = exp;
            }
        }
    }
}

void MultiPoly(Polynomial p1, Polynomial p2, Polynomial p3) {
    int max_expo, min_expo;
    Polynomial pa, pb, tail;
    size_t i;
    DescendPoly(p1);
    DescendPoly(p2);
    max_expo = p1->next->exponent + p2->next->exponent;
    AscendPoly(p1);
    AscendPoly(p2);
    min_expo = p1->next->exponent + p2->next->exponent;
    DescendPoly(p1);
    pa = p1->next;
    pb = p2->next;
    tail = p3;
    for (i = max_expo; i >= min_expo; i--) {
        pa = p1->next;
        while (pa != NULL && pa->exponent > i) {
            pa = pa->next;
        }
        while (pa != NULL && pb != NULL && pa->exponent + pb->exponent < i) {
            pb = pb->next;
        }
        while (pa != NULL && pb != NULL) {
            if (pa->exponent + pb->exponent == i) {
                if (pa->coefficient + pb->coefficient != 0) {
                    Polynomial tmp;
                    tmp = (Polynomial)malloc(sizeof(List));
                    tmp->coefficient = pa->coefficient * pb->coefficient;
                    tmp->exponent = pa->exponent + pb->exponent;
                    tail->next = tmp;
                    tmp->next = NULL;
                    tail = tmp;
                }
                pa = pa->next;
                pb = pb->next;
            }
            else if (pa->exponent + pb->exponent < i) {
                pb = pb->next;
            }
            else if (pa->exponent + pb->exponent > i) {
                pa = pa->next;
            }
        }
    }
}

int main()
{
    int m, n;
    scanf("%d %d", &m, &n);
    Polynomial p1, p2, p3;
    p1 = CreatePoly(m);
    p2 = CreatePoly(n);
    p3 = CreatePoly(0);
    InputPoly(p1);
    InputPoly(p2);
    /*
    AddPoly(p1, p2, p3);
    OutputPoly(p3);
    MakeEmpty(p3);
    SubPoly(p1, p2, p3);
    OutputPoly(p3);
    MakeEmpty(p3);
    */
    MultiPoly(p1, p2, p3);
    OutputPoly(p3);
    #if 0
    AscendPoly(p1);
    DescendPoly(p2);
    OutputPoly(p1);
    OutputPoly(p2);
    #endif // 0
    return 0;
}
