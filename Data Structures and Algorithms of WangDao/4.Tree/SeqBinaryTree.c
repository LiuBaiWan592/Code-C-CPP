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
#include <string.h>

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
    TreeNode *data = (TreeNode *)malloc(sizeof(TreeNode) * length + 1);
    for (int i = 0; i < length; i++) {
        data[i + 1].data = arr[i];
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
    for (int i = 1; i <= tree->length; i++) {
        if (tree->data[i].data != INT_MIN) {
            printf("%d ", tree->data[i].data);
        } else {
            printf("NULL ");
        }
    }
    printf("\n");
}

typedef struct Trunk {
    struct Trunk *prev;
    char *str;
} Trunk;

Trunk *newTrunk(Trunk *prev, char *str) {
    Trunk *trunk = (Trunk *)malloc(sizeof(Trunk));
    trunk->prev = prev;
    trunk->str = (char *)malloc(sizeof(char) * 10);
    strcpy(trunk->str, str);
    return trunk;
}

void showTrunks(Trunk *trunk) {
    if (trunk == NULL) {
        return;
    }
    showTrunks(trunk->prev);
    printf("%s", trunk->str);
}

void SeqBinaryTree_PrintTreeHelper(SeqBinaryTree tree, int i, Trunk *prev, bool isRight) {
    if (tree->data[i].data == INT_MIN || i > tree->length) {
        return;
    }
    char *prev_str = "    ";
    Trunk *trunk = newTrunk(prev, prev_str);
    SeqBinaryTree_PrintTreeHelper(tree, 2 * i + 1, trunk, true);
    if (prev == NULL) {
        trunk->str = "———";
    } else if (isRight) {
        trunk->str = "/———";
        prev_str = "   |";
    } else {
        trunk->str = "\\———";
        prev->str = prev_str;
    }
    showTrunks(trunk);
    printf("%d\n", tree->data[i].data);

    if (prev != NULL) {
        prev->str = prev_str;
    }
    trunk->str = "   |";
    SeqBinaryTree_PrintTreeHelper(tree, 2 * i, trunk, false);
}

int main() {
    ElemType arr[] = {1, 2, 3, 4, INT_MIN, 6, 7, 8, 9, INT_MIN, INT_MIN, 12, INT_MIN, INT_MIN, 15};
    int length = sizeof(arr) / sizeof(ElemType);
    int capacity = length + 1;
    TreeNode *data = SeqBinaryTree_InitTreeNode(arr, length);
    SeqBinaryTree tree = SeqBinaryTree_Init(capacity, data, length);
    SeqBinaryTree_PrintData(tree);
    SeqBinaryTree_PrintTreeHelper(tree, 1, NULL, false);
    SeqBinaryTree_Destroy(tree);
    return 0;
}