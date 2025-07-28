/**
 * @FileName    :SeqListDyn_Dyn.h
 * @Date        :2025-03-07 20:16:20
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence List of Dynamic
 * @Description :The indexes in all functions are array indices starting from 0
 *              :SeqListDyn: Sequence List of dynamic
 *              :List_Dyn_Init: Initialize the Sequence List of dynamic [O(1)]
 *              :List_Dyn_GetLength: Get the length of the List(L) [O(1)]
 *              :List_Dyn_GetCapacity: Get the capacity of the List(L) [O(1)]
 *              :List_Dyn_IsEmpty: Check if the List(L) is empty [O(1)]
 *              :List_Dyn_GetElem: Get the element at the Index(index) of the List(L) [O(1)]
 *              :List_Dyn_LocateElem: Search the list (L) to find the index of the first element(e) [O(n)]
 *              :List_Dyn_Extend: Extend the capacity of the List(L) [O(n)]
 *              :List_Dyn_Insert: Insert Element(e) at the Index(index) of the List(L) [O(n)]
 *              :List_Dyn_InsertEnd: Insert Element(e) at the end of the List(L) [O(1)]
 *              :List_Dyn_Delete: Delete the Element at the Index(index) of the List(L) [O(n)]
 *              :List_Dyn_Print: Print the List(L) [O(n)]
 *              :List_Dyn_Destroy: Destory the List(L) [O(1)]
 */

#ifndef SEQLIST_DYN_H
#define SEQLIST_DYN_H

#include "../common.h"

/* Sequence List of dynamic */
typedef struct {
    ElemType *data;
    int length;
    int capacity;
} *SeqListDyn;

/* Initialize the Sequence List of dynamic */
SeqListDyn List_Dyn_Init() {
    SeqListDyn L = (SeqListDyn)malloc(sizeof(SeqListDyn));
    L->length = 0;
    L->capacity = Maxsize;
    L->data = (ElemType *)malloc(sizeof(ElemType) * L->capacity);
    return L;
}

/* Get the length of the List(L) [O(1)] */
int List_Dyn_GetLength(SeqListDyn L) {
    return L->length;
}

/* Get the capacity of the List(L) [O(1)] */
int List_Dyn_GetCapacity(SeqListDyn L) {
    return L->capacity;
}

/* Check if the List(L) is empty [O(1)] */
bool List_Dyn_IsEmpty(SeqListDyn L) {
    return L->length == 0;
}

/* Get the element at the Index(index) of the List(L) [O(1)] */
ElemType List_Dyn_GetElem(SeqListDyn L, int index) {
    return L->data[index];
}

/* Search the list (L) to find the index of the first element(e) [O(n)] */
int List_Dyn_LocateElem(SeqListDyn L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }
    return -1;
}

/* Extend the capacity of the List(L) [O(n)] */
bool List_Dyn_Extend(SeqListDyn L) {
    L->data = (ElemType *)realloc(L->data, sizeof(ElemType) * (L->capacity + Maxsize));
    L->capacity += Maxsize;
    return true;
}

/* Insert Element(e) at the Index(index) of the List(L) [O(n)] */
bool List_Dyn_Insert(SeqListDyn L, ElemType e, int index) {
    // Judge whether the index is within the valid range
    if (index < 0 || index > L->length) {
        printf("ERROR: Index (%d) out of range!\n", index);
        return false;
    }
    // Judge whether the List is full
    if (L->length >= L->capacity) {
        printf("WARRING: The List is full, will extend the capacity of the List\n");
        List_Dyn_Extend(L);
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
bool List_Dyn_InsertEnd(SeqListDyn L, ElemType e) {
    return List_Dyn_Insert(L, e, L->length);
}

/* Delete the Element at the Index(index) of the List(L) [O(n)] */
bool List_Dyn_Delete(SeqListDyn L, int index, ElemType *e) {
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
void List_Dyn_Destroy(SeqListDyn L) {
    free(L->data);
    L->length = 0;
}

/* Print the List(L) [O(n)] */
void List_Dyn_Print(SeqListDyn L) {
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

#endif // SEQ_LIST_DYN_H