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
 *              :List_InsertEnd: Insert Element(e) at the end of the List(L) [O(1)]
 *              :List_Delete: Delete the Element at the Index(index) of the List(L) [O(n)]
 *              :List_Print: Print the List(L) [O(n)]
 *              :List_Destroy: Destory the List(L) [O(1)]
 */

#include <stdbool.h>
#include <stdio.h>

#define ElemType int
#define Maxsize 10

/* Sequence List */
typedef struct SQList {
    ElemType data[Maxsize];
    int length;
}SQList, *SeqList;

/* Initialize the Sequence List */
SQList List_Init() {
    SQList L;
    L.length = 0;
    for(int i = 0; i < Maxsize; i++) {
        L.data[i] = 0;
    }
    return L;
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
        printf("Index out of range!\n");
        return false;
    }
    // Judge whether the List is full
    if (L->length >= Maxsize) {
        printf("List is full!\n");
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
bool List_InsertEnd(SeqList L, ElemType e) {
    return List_Insert(L, e, L->length);
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

/* Destory the List(L) [O(1)] */
void List_Destroy(SeqList L) {
    L->length = 0;
}

/* Print the List(L) [O(n)] */
void List_Print(SeqList L) {
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

/* Driver Code */
int main() {
    SQList List = List_Init();
    SeqList L = &List;
    for (int i = 0; i < 6; i++) {
        List_InsertEnd(L, i);
    }
    List_Print(L);

    printf("Length: %d\n", List_GetLength(L));

    if (List_IsEmpty(L)) {
        printf("List is empty!\n");
    } else {
        printf("List is not empty!\n");
    }

    printf("Element at index 2: %d\n", List_GetElem(L, 2));

    printf("Index of element 3: %d\n", List_LocateElem(L, 3));

    List_Insert(L, 100, 5);
    List_Print(L);

    ElemType e;
    List_Delete(L, 3, &e);
    printf("Deleted Element: %d\n", e);
    List_Print(L);

    List_Destroy(L);
    List_Print(L);
    return 0;
}