/**
 * @FileName    :SeqListDyn_Dyn.h
 * @Date        :2025-03-07 20:16:20
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :Sequence List of Dynamic
 * @Description :The indexes in all functions are array indices starting from 0
 *              :SeqListDyn: Sequence List of dynamic
 *              :SeqListDyn_Init: Initialize the Sequence List of dynamic [O(1)]
 *              :SeqListDyn_GetLength: Get the length of the List(L) [O(1)]
 *              :SeqListDyn_GetCapacity: Get the capacity of the List(L) [O(1)]
 *              :SeqListDyn_IsEmpty: Check if the List(L) is empty [O(1)]
 *              :SeqListDyn_GetElem: Get the element at the Index(index) of the List(L) [O(1)]
 *              :SeqListDyn_LocateElem: Search the list (L) to find the index of the first element(e) [O(n)]
 *              :SeqListDyn_Extend: Extend the capacity of the List(L) [O(n)]
 *              :SeqListDyn_Insert: Insert Element(e) at the Index(index) of the List(L) [O(n)]
 *              :SeqListDyn_InsertEnd: Insert Element(e) at the end of the List(L) [O(1)]
 *              :SeqListDyn_Delete: Delete the Element at the Index(index) of the List(L) [O(n)]
 *              :SeqListDyn_Print: Print the List(L) [O(n)]
 *              :SeqListDyn_Destroy: Destory the List(L) [O(1)]
 */

#ifndef SEQLISTDYN_H
#define SEQLISTDYN_H

#include "../common.h"

/* Sequence List of dynamic */
typedef struct SeqListDyn{
    ElemType *data;
    int length;
    int capacity;
} *SeqListDyn;

/* Initialize the Sequence List of dynamic */
SeqListDyn SeqListDyn_Init(int capacity) {
    SeqListDyn L = (SeqListDyn)malloc(sizeof(struct SeqListDyn));
    L->length = 0;
    L->capacity = capacity;
    L->data = (ElemType *)malloc(sizeof(ElemType) * L->capacity);
    for (int i = 0; i < L->capacity; i++) {
        L->data[i] = 0;
    }
    return L;
}

/* Get the length of the List(L) [O(1)] */
int SeqListDyn_GetLength(SeqListDyn L) {
    return L->length;
}

/* Get the capacity of the List(L) [O(1)] */
int SeqListDyn_GetCapacity(SeqListDyn L) {
    return L->capacity;
}

/* Check if the List(L) is empty [O(1)] */
bool SeqListDyn_IsEmpty(SeqListDyn L) {
    return L->length == 0;
}

/* Get the element at the Index(index) of the List(L) [O(1)] */
ElemType SeqListDyn_GetElem(SeqListDyn L, int index) {
    return L->data[index];
}

/* Search the list (L) to find the index of the first element(e) [O(n)] */
int SeqListDyn_LocateElem(SeqListDyn L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }
    return -1;
}

/* Extend the capacity of the List(L) [O(n)] */
bool SeqListDyn_Extend(SeqListDyn L, int extend) {
    if(!L){
        printf("ERROR: The List is NULL!\n");
        return false;
    }
    L->data = (ElemType *)realloc(L->data, sizeof(ElemType) * (L->capacity + extend));
    L->capacity += extend;
    return true;
}

/* Insert Element(e) at the Index(index) of the List(L) [O(n)] */
bool SeqListDyn_Insert(SeqListDyn L, ElemType e, int index) {
    // Judge whether the index is within the valid range
    if (index < 0 || index > L->length) {
        printf("ERROR: Index (%d) out of range!\n", index);
        return false;
    }
    // Judge whether the List is full
    if (L->length >= L->capacity) {
        printf("WARRING: The List is full, will extend the capacity of the List\n");
        SeqListDyn_Extend(L, L->capacity);
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
bool SeqListDyn_InsertEnd(SeqListDyn L, ElemType e) {
    return SeqListDyn_Insert(L, e, L->length);
}

/* Delete the Element at the Index(index) of the List(L) [O(n)] */
bool SeqListDyn_Delete(SeqListDyn L, int index, ElemType *e) {
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
void SeqListDyn_Destroy(SeqListDyn L) {
    free(L->data);
    L->length = 0;
    L->capacity = 0;
    return;
}

/* Print the List(L) [O(n)] */
void SeqListDyn_Print(SeqListDyn L) {
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

#endif // SEQLISTDYN_H