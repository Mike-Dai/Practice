#include <stdio.h>
#include <stdlib.h>

struct Node{
    int element;
    struct Node* left;
    struct Node* right;
}TreeNode;

typedef struct Node* Position;
typedef struct Node* SearchTree;

SearchTree MakeEmpty(SearchTree T) {
    if (T != NULL)
    {
        MakeEmpty(T->left);
        MakeEmpty(T->right);
        free(T);
    }
    return NULL;
}

Position Find(int x, SearchTree T) {
    if (T == NULL) {
        return NULL;
    }
    else {
        if (x < T->element) {
            return Find(x, T->left);
        }
        else if (x > T->element) {
            return Find(x, T->right);
        }
        else {
            return T;
        }
    }
}

Position FindMin(SearchTree T) {
    if (T == NULL) {
        return NULL;
    }
    else {
        if (T->left == NULL) {
        return T;
        }
        else {
            return FindMin(T->left);
        }
    }
}

Position FindMax(SearchTree T) {
    if (T == NULL) {
        return NULL;
    }
    else {
        if (T->right == NULL) {
            return T;
        }
        else {
            return FindMax(T->right);
        }
    }
}

SearchTree Insert(int x, SearchTree T) {
    if (T == NULL) {
        T = (Position)malloc(sizeof(TreeNode));
        if (T == NULL) {
            printf("Out of space!\n");
        }
        else {
            T->element = x;
            T->left = T->right = NULL;
        }
    }
    else {
        if (x < T->element) {
            T->left = Insert(x, T->left);
        }
        else if (x > T->element) {
            T->right = Insert(x, T->right);
        }
    }
    return T;
}

SearchTree Delete(int x, SearchTree T) {
    Position TmpCell;
    if (T == NULL) {
        printf("Element not found!\n");
    }
    else {
        if (T->left && T->right) {
            if (x < T->element) {
                T->left = Delete(x, T->left);
            }
            else if (x > T->element) {
                T->right = Delete(x, T->right);
            }
            else {
                TmpCell = FindMin(T->right);
                T->element = TmpCell->element;
                T->right = Delete(T->element, T->right);
            }
        }
        else {
            TmpCell = T;
            if (T->right == NULL) {
                T = T->left;
            }
            else if (T->left == NULL) {
                T = T->right;
            }
            free(TmpCell);
        }
    }
    return T;
}

int main()
{

    return 0;
}
