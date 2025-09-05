/**
 * @FileName    :SeqBinaryTree.c
 * @Date        :2025-09-08 13:47:35
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequential binary tree with dynamic memory allocation
 * @Description :
 */

#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct TreeNode {
    ElemType data;
} TreeNode;

typedef struct SeqBinaryTree {
    TreeNode *data;
    int length;
    int capacity;
} *SeqBinaryTree;

TreeNode *SeqBinaryTree_InitTreeNode(ElemType *arr, int length) {
    TreeNode *data = (TreeNode *)malloc(sizeof(TreeNode) * length);
    for (int i = 0; i < length; i++) {
        data[i].data = arr[i];
    }
    return data;
}

SeqBinaryTree SeqBinaryTree_Init(int capacity, TreeNode *data, int length) {
    SeqBinaryTree tree = (SeqBinaryTree)malloc(sizeof(struct SeqBinaryTree));
    tree->data = (TreeNode *)malloc(sizeof(TreeNode) * capacity);
    tree->length = length;
    for (int i = 0; i < length; i++) {
        tree->data[i] = data[i];
    }
    tree->capacity = capacity;
    free(data);
    return tree;
}
