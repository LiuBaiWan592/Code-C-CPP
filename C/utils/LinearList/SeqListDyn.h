/**
 * @FileName    :SeqListDyn_Dyn.h
 * @Date        :2025-03-07 20:16:20
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
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
 *              :SeqListDyn_Destroy: Destory the List(L) [O(1)]
 *              :SeqListDyn_Print: Print the List(L) [O(n)]
 */

#ifndef SEQLISTDYN_H
#define SEQLISTDYN_H

#include "../common.h"

/* Sequence List of dynamic */
typedef struct SeqListDyn {
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
    return L;
}

/* Get the length of the List(L) [O(1)] */
int SeqListDyn_GetLength(SeqListDyn L) {
    assert(L != NULL && "ERROR: When getting the length of the List, the List is NULL!");
    return L->length;
}

/* Get the capacity of the List(L) [O(1)] */
int SeqListDyn_GetCapacity(SeqListDyn L) {
    assert(L != NULL && "ERROR: When getting the capacity of the List, the List is NULL!");
    return L->capacity;
}

/* Check if the List(L) is empty [O(1)] */
bool SeqListDyn_IsEmpty(SeqListDyn L) {
    assert(L != NULL && "ERROR: When checking if the List is empty, the List is NULL!");
    return L->length == 0;
}

/* Get the element at the Index(index) of the List(L) [O(1)] */
ElemType SeqListDyn_GetElem(SeqListDyn L, int index) {
    assert(L != NULL && "ERROR: When getting the element of the List, the List is NULL!");
    assert(index >= 0 && index < L->length && "ERROR: When getting the element of the List, Index out of range!");
    return L->data[index];
}

/* Search the list (L) to find the index of the first element(e) [O(n)] */
int SeqListDyn_LocateElem(SeqListDyn L, ElemType e) {
    assert(L != NULL && "ERROR: When searching the List to locate the element, the List is NULL!");
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }
    return -1;
}

/* Extend the capacity of the List(L) [O(n)] */
bool SeqListDyn_Extend(SeqListDyn L, int extend) {
    assert(L != NULL && "ERROR: When extending the capacity of the List, the List is NULL!");
    // If the extend is less than or equal to 0, print an error message and exit
    assert(extend > 0 && "ERROR: When extending the capacity of the List, Extend must be greater than 0!");
    L->data = (ElemType *)realloc(L->data, sizeof(ElemType) * (L->capacity + extend));
    L->capacity += extend;
    return true;
}

/* Insert Element(e) at the Index(index) of the List(L) [O(n)] */
bool SeqListDyn_Insert(SeqListDyn L, ElemType e, int index) {
    assert(L != NULL && "ERROR: When inserting the element of the List, the List is NULL!");
    // Judge whether the index is within the valid range
    assert(index >= 0 && index <= L->length && "ERROR: When inserting the element of the List, Index out of range!");
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
    assert(L != NULL && "ERROR: When inserting the element of the List at the end, the List is NULL!");
    return SeqListDyn_Insert(L, e, L->length);
}

/* Delete the Element at the Index(index) of the List(L) [O(n)] */
ElemType SeqListDyn_Delete(SeqListDyn L, int index) {
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
SeqListDyn SeqListDyn_Destroy(SeqListDyn L) {
    assert(L != NULL && "ERROR: When destorying the List, the List is NULL!");
    free(L->data);
    L->length = 0;
    L->capacity = 0;
    free(L);
    return NULL;
}

/* Print the List(L) [O(n)] */
void SeqListDyn_Print(SeqListDyn L) {
    assert(L != NULL && "ERROR: When Printing the List, the List is NULL!");
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