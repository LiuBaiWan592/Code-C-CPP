/**
 * @FileName    :SeqList.c
 * @Date        :2025-03-04 13:27:05
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence List
 * @Description :The indexes in all functions are array indices starting from 0
 *              :SeqList: Sequence List
 *              :List_Init: Initialize the Sequence List [O(1)]
 *              :List_GetLength: Get the length of the List(L) [O(1)]
 *              :List_IsEmpty: Check if the List(L) is empty [O(1)]
 *              :List_GetElem: Get the element at the Index(index) of the List(L) [O(1)]
 *              :List_LocateElem: Search the list (L) to find the index of the first element(e) [O(n)]
 *              :List_Insert: Insert Element(e) at the Index(index) of the List(L) [O(n)]
 *              :List_Delete: Delete the Element at the Index(index) of the List(L) [O(n)]
 *              :List_Print: Print the List(L) [O(n)]
 *              :List_Destroy: Destory the List(L) [O(n)]
 */

#include <stdbool.h>
#include <stdio.h>

#define ElemType int
#define Maxsize 50

/* Sequence List */
typedef struct SeqList {
    ElemType data[Maxsize];
    int length;
} *SeqList;

/* Initialize the Sequence List */
void List_Init(SeqList L) {
    L->length = 0;
}

/* Get the length of the List(L) [O(1)] */
int List_GetLength(SeqList L) {
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool List_IsEmpty(SeqList L) {
    return L->length == 0;
}

/* Get the element at the Index(index) of the List(L) [O(1)] */
ElemType List_GetElem(SeqList L, int index) {
    return L->data[index];
}

/* Search the list (L) to find the index of the first element(e) [O(n)] */
int List_LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }
    return -1;
}

/* Insert Element(e) at the Index(index) of the List(L) [O(n)] */
bool List_Insert(SeqList L, ElemType e, int index) {
    // Judge whether the index is within the valid range
    if (index < 0 || index > L->length) {
        return false;
    }
    // Judge whether the List is full
    if (L->length > Maxsize) {
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

/* Delete the Element at the Index(index) of the List(L) [O(n)] */
bool List_Delete(SeqList L, int index, ElemType *e) {
    // Judge whether the index is within the valid range
    if (index < 0 || index >= L->length) {
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

/* Print the List(L) [O(n)] */
void List_Print(SeqList L) {
    for (int i = 0; i < L->length; i++) {
        printf("%d    ", L->data[i]);
    }
    printf("\n");
}

/* Destory the List(L) [O(1)] */
void List_Destroy(SeqList L) {
    L->length = 0;
}

int main() {
    return 0;
}