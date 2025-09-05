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