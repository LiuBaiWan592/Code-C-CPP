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
    tree->data = data;
    tree->length = length;
    tree->capacity = capacity;
    return tree;
}

SeqBinaryTree SeqBinaryTree_Destroy(SeqBinaryTree tree) {
    free(tree->data);
    free(tree);
    return NULL;
}

void SeqBinaryTree_PrintData(SeqBinaryTree tree) {
    for (int i = 0; i < tree->length; i++) {
        if(tree->data[i].data != INT_MIN){
            printf("%d ", tree->data[i].data);
        }else{
            printf("NULL ");
        }
    }
    printf("\n");
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, INT_MIN, 6, 7, 8, 9, INT_MIN, INT_MIN, 12, INT_MIN, INT_MIN, 15};
    TreeNode *data = SeqBinaryTree_InitTreeNode(arr, sizeof(arr) / sizeof(ElemType));
    SeqBinaryTree tree = SeqBinaryTree_Init(15, data, sizeof(arr) / sizeof(ElemType));
    SeqBinaryTree_PrintData(tree);
    SeqBinaryTree_Destroy(tree);
    return 0;
}