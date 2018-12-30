#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct BinaryTreeNode{
    int key;
    int height;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
}node;

typedef struct BinaryTreeNode avlnode;
typedef struct BinaryTreeNode avltree;

int maxh(int ha, int hb) {
    return ha > hb ? ha : hb;
}

int height(avltree* tree) {
    if (NULL == tree) {
        return 0;
    }
    return tree->height;
}

avlnode* singleRightRotate(avlnode* aNode) {
    avlnode* bNode = aNode->left;
    aNode->left = bNode->right;
    bNode->right = aNode;
    aNode->height = maxh(height(aNode->left), height(aNode->right)) + 1;
    bNode->height = maxh(height(bNode->left), height(bNode->right)) + 1;
    return bNode;
}

avlnode* singleLeftRotate(avlnode* aNode) {
    avlnode* bNode = aNode->right;
    aNode->right = bNode->left;
    bNode->left = aNode;
    aNode->height = maxh(height(aNode->left), height(aNode->right)) + 1;
    bNode->height = maxh(height(bNode->left), height(bNode->right)) + 1;
    return bNode;
}

avlnode* leftRightRotate(avlnode* aNode) {
    aNode->left = singleLeftRotate(aNode->left);
    return singleRightRotate(aNode);
}

avlnode* rightLeftNode(avlnode* aNode) {
    aNode->right = singleRightRotate(aNode->right);
    return singleLeftRotate(aNode);
}

avlnode* avl_insert(avltree* tree, int key) {
    if (NULL == tree) {
        tree = (avlnode*)malloc(sizeof(avlnode));
        tree->key = key;
        tree->height = 1;
        tree->left = NULL;
        tree->right = NULL;
    }
    else if (key > tree->key) {
        tree->right = avl_insert(tree->right, key);
        int BalanceFactor = height(tree->right) - height(tree->left);
        if (BalanceFactor == 2) {
            if (key > tree->right->key) {
                tree = singleLeftRotate(tree);
            }
            else {
                tree = rightLeftNode(tree);
            }
        }
    }
    else if (key < tree->key){
        tree->left = avl_insert(tree->left, key);
        int BalanceFactor = height(tree->left) - height(tree->right);
        if (BalanceFactor == 2) {
            if (key < tree->left->key) {
                tree = singleRightRotate(tree);
            }
            else {
                tree = leftRightRotate(tree);
            }
        }
    }
    tree->height = maxh(height(tree->left), height(tree->right)) + 1;
    return tree;
}

avlnode* avl_delete(avltree* tree, int key) {
    if (NULL == tree) {
        return NULL;
    }
    else {
        if (key < tree->key) {
            tree->left = avl_delete(tree->left, key);
        }
        else if (key > tree->key) {
            tree->right = avl_delete(tree->right, key);
        }
        else {
            if (NULL != tree->left) {
                avlnode* dn;
                for (dn = tree->left; NULL != dn->right; dn = dn->right) {

                }
                tree->key = dn->key;
                tree->left = avl_delete(tree->left, dn->key);
            }
            else if (NULL != tree->right) {
                avlnode* dn;
                for (dn = tree->right; NULL != dn->left; dn = dn->left) {

                }
                tree->key = dn->key;
                tree->right = avl_delete(tree->right, dn->key);
            }
            else {
                free(tree);
                return NULL;
            }
        }
    }
    if (height(tree->left) - height(tree->right) == 2) {
        if (height(tree->left->left) - height(tree->left->right) == 1) {
            tree = singleRightRotate(tree);
        }
        else {
            tree = leftRightRotate(tree);
        }
    }
    else if (height(tree->left) - height(tree->right) == -2) {
        if (height(tree->right->right) - height(tree->right->left) == 1) {
            tree = singleLeftRotate(tree);
        }
        else {
            tree = rightLeftNode(tree);
        }
    }
    tree->height = maxh(height(tree->left), height(tree->right));
    return tree;
}
int main()
{
    return 0;
}
