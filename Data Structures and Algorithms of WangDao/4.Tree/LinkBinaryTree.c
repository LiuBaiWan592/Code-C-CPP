/**
 * @FileName    :LinkBinaryTree.c
 * @Date        :2025-09-10 22:40:36
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Binary tree with linked storage
 * @Description :
 */

#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define ElemType int

typedef struct BiTNode {
    ElemType data;                   // data
    int depth;                       // node's depth
    int height;                      // node's height
    struct BiTNode *lchild, *rchild; // left child and right child
}BiTNode, *BiTree;

BiTNode *BiTree_NewTreeNode(ElemType data) {
    BiTNode *newNode = (BiTNode *)malloc(sizeof(BiTNode));
    newNode->data = data;
    newNode->depth = 0;
    newNode->height = 0;
    newNode->lchild = newNode->rchild = NULL;
    return newNode;
}

BiTree BiTree_ArrayToBiTreeDFS(ElemType *arr, int length, int index) {
    if (index < 0 || index >= length || arr[index] == INT_MIN) {
        return NULL;
    }
    BiTNode *Node = BiTree_NewTreeNode(arr[index]);
    Node->lchild = BiTree_ArrayToBiTreeDFS(arr, length, 2 * index + 1);
    Node->rchild = BiTree_ArrayToBiTreeDFS(arr, length, 2 * index + 2);
    return Node;
}

BiTree BiTree_ArrayToBiTree(ElemType *arr, int length) {
    return BiTree_ArrayToBiTreeDFS(arr, length, 0);
}