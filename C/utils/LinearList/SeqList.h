/**
 * @FileName    :SeqList.h
 * @Date        :2025-03-07 20:10:54
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
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
 *              :SeqList_Destroy: Destory the List(L) [O(1)]
 *              :SeqList_Print: Print the List(L) [O(n)]
 */

#ifndef SEQLIST_H
#define SEQLIST_H

#include "../common.h"

/* Sequence List */
typedef struct SeqList {
    ElemType data[Maxsize];
    int length;
} *SeqList;

/* Initialize the Sequence List */
struct SeqList SeqList_Init() {
    struct SeqList L;
    L.length = 0;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int SeqList_GetLength(SeqList L) {
    assert(L != NULL && "ERROR: When getting the length of the List, the List is NULL!");
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool SeqList_IsEmpty(SeqList L) {
    assert(L != NULL && "ERROR: When checking if the List is empty, the List is NULL!");
    return L->length == 0;
}

/* Get the element at the Index(index) of the List(L) [O(1)] */
ElemType SeqList_GetElem(SeqList L, int index) {
    assert(L != NULL && "ERROR: When getting the element of the List, the List is NULL!");
    assert(index >= 0 && index < L->length && "ERROR: When getting the element of the List, Index out of range!");
    return L->data[index];
}

/* Search the list (L) to find the index of the first element(e) [O(n)] */
int SeqList_LocateElem(SeqList L, ElemType e) {
    assert(L != NULL && "ERROR: When locating the element of the List, the List is NULL!");
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }
    return -1;
}

/* Insert Element(e) at the Index(index) of the List(L) [O(n)] */
bool SeqList_Insert(SeqList L, ElemType e, int index) {
    assert(L != NULL && "ERROR: When inserting the element of the List, the List is NULL!");
    // Judge whether the index is within the valid range
    assert(index >= 0 && index <= L->length && "ERROR: When inserting the element of the List, Index out of range!");
    // Judge whether the List is full
    if (L->length >= Maxsize) {
        printf("ERROR: When inserting the element of the List, List is full!\n");
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
    assert(L != NULL && "ERROR: When inserting the element of the List at the end, the List is NULL!");
    return SeqList_Insert(L, e, L->length);
}

/* Delete the Element at the Index(index) of the List(L) [O(n)] */
ElemType SeqList_Delete(SeqList L, int index) {
    assert(L != NULL && "ERROR: When deleting the element of the List, the List is NULL!");
    // Judge whether the index is within the valid range
    assert(index >= 0 && index < L->length && "ERROR: When deleting the element of the List, Index out of range!");
    // Delete the element
    ElemType e = L->data[index];
    // Move the elements after the index to the left
    for (int i = index; i < L->length; i++) {
        L->data[i] = L->data[i + 1];
    }
    L->length--;
    return e;
}

/* Destory the List(L) [O(1)] */
void SeqList_Destroy(SeqList L) {
    assert(L != NULL && "ERROR: When destroying the List, the List is NULL!");
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