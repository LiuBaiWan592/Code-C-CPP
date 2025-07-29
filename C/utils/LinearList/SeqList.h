/**
 * @FileName    :SeqList.h
 * @Date        :2025-03-07 20:10:54
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :Sequence List
 * @Description :The indexes in all functions are array indices starting from 0
 *              :SeqList: Sequence List
 *              :SeqList_Init: Initialize the Sequence List [O(1)]
 *              :SeqList_GetLength: Get the length of the List(L) [O(1)]
 *              :SeqList_IsEmpty: Check if the List(L) is empty [O(1)]
 *              :SeqList_GetElem: Get the element at the Index(index) of the List(L) [O(1)]
 *              :SeqList_LocateElem: Search the list (L) to find the index of the first element(e) [O(n)]
 *              :SeqList_Insert: Insert Element(e) at the Index(index) of the List(L) [O(n)]
 *              :SeqList_InsertEnd: Insert Element(e) at the end of the List(L) [O(1)]
 *              :SeqList_Delete: Delete the Element at the Index(index) of the List(L) [O(n)]
 *              :SeqList_Print: Print the List(L) [O(n)]
 *              :SeqList_Destroy: Destory the List(L) [O(1)]
 */

#ifndef SEQLIST_H
#define SEQLIST_H

#include "../common.h"

/* Sequence List */
typedef struct {
    ElemType data[Maxsize];
    int length;
} SQList, *SeqList;

/* Initialize the Sequence List */
SQList SeqList_Init() {
    SQList L;
    L.length = 0;
    for (int i = 0; i < Maxsize; i++) {
        L.data[i] = 0;
    }
    return L;
}

/* Get the length of the List(L) [O(1)] */
int SeqList_GetLength(SeqList L) {
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool SeqList_IsEmpty(SeqList L) {
    return L->length == 0;
}

/* Get the element at the Index(index) of the List(L) [O(1)] */
ElemType SeqList_GetElem(SeqList L, int index) {
    return L->data[index];
}

/* Search the list (L) to find the index of the first element(e) [O(n)] */
int SeqList_LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }
    return -1;
}

/* Insert Element(e) at the Index(index) of the List(L) [O(n)] */
bool SeqList_Insert(SeqList L, ElemType e, int index) {
    // Judge whether the index is within the valid range
    if (index < 0 || index > L->length) {
        printf("ERROR: Index (%d) out of range!\n", index);
        return false;
    }
    // Judge whether the List is full
    if (L->length >= Maxsize) {
        printf("ERROR: List is full!\n");
        return false;
    }
    // Move the elements after the index to the right
    for (int i = L->length; i > index; i--) {
        L->data[i] = L->data[i - 1];
    }
    // Insert the element
    L->data[index] = e;
    L->length++;
    return true;
}

/* Insert Element(e) at the end of the List(L) */
bool SeqList_InsertEnd(SeqList L, ElemType e) {
    return SeqList_Insert(L, e, L->length);
}

/* Delete the Element at the Index(index) of the List(L) [O(n)] */
bool SeqList_Delete(SeqList L, int index, ElemType *e) {
    // Judge whether the index is within the valid range
    if (index < 0 || index >= L->length) {
        printf("ERROR: Index (%d) out of range!\n", index);
        return false;
    }
    // Delete the element
    *e = L->data[index];
    // Move the elements after the index to the left
    for (int i = index; i < L->length; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return true;
}

/* Destory the List(L) [O(1)] */
void SeqList_Destroy(SeqList L) {
    for (int i = 0; i < Maxsize; i++) {
        L->data[i] = 0;
    }
    L->length = 0;
    return;
}

/* Print the List(L) [O(n)] */
void SeqList_Print(SeqList L) {
    printf("Sequence List: ");
    if (L->length == 0) {
        printf("Empty List!\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 0; i < L->length; i++) {
        printf("%d    ", i);
    }
    printf("\n");
    printf("  Value: ");
    for (int i = 0; i < L->length; i++) {
        printf("%d    ", L->data[i]);
    }
    printf("\n");
}

#endif // SEQLIST_H