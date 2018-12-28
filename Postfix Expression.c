#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Node{
    char op;
    struct Node* next;
}List;

typedef struct Node* Stack;
typedef Stack PtrToNode;

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

void Push(char ch, Stack S) {
    PtrToNode tmp;
    tmp = (Stack)malloc(sizeof(List));
    tmp->op = ch;
    tmp->next = S->next;
    S->next = tmp;
}

char Top(Stack S) {
    if (!IsEmpty(S)) {
        return S->next->op;
    }
    //printf("Empty Stack!");
    return '\0';
}

void Pop(Stack S) {
    PtrToNode tmp;
    if (IsEmpty(S)) {
        //printf("Empty Stack!");
        return;
    }
    else {
        tmp = S->next;
        S->next = tmp->next;
        free(tmp);
    }
}

int main()
{
    size_t i;
    Stack Exp = CreateStack();
    char str[100];
    memset(str, 0, sizeof(str));
    gets(str);
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            continue;
        }
        else {
            if (IsEmpty(Exp)) {
                    if (isalpha(str[i])) {
                        printf("%c ", str[i]);
                    }
                    else {
                         Push(str[i], Exp);
                    }
            }
            else if (!IsEmpty(Exp)) {
                switch(str[i]) {
                case '+':
                case '-':
                    if (Top(Exp) == '(') {
                            Push(str[i], Exp);
                        }
                        else {
                            printf("%c ", str[i]);
                        }
                        break;
                case '*':
                case '/':
                    if (Top(Exp) == '+' || Top(Exp) == '-' || Top(Exp) == '(') {
                            Push(str[i], Exp);
                        }
                        else {
                            printf("%c ", str[i]);
                        }
                        break;
                case '(':
                    Push(str[i], Exp);
                    break;
                case ')':
                    while (Top(Exp) != '(') {
                            printf("%c ", Top(Exp));
                            Pop(Exp);
                           }
                           Pop(Exp);
                           break;
                default:
                    printf("%c ", str[i]);
                    break;
                }
            }
        }
        }
        while (!IsEmpty(Exp)) {
            printf("%c ", Top(Exp));
            Pop(Exp);
        }
        printf("\n");
    return 0;
}
