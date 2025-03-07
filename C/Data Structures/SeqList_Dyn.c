/**
 * @FileName    :SeqList_Dyn.c
 * @Date        :2025-03-04 16:50:59
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence List of Dynamic
 * @Description :The indexes in all functions are array indices starting from 0
 *              :SeqList: Sequence List of dynamic
 *              :List_Dyn_Init: Initialize the Sequence List of dynamic [O(1)]
 *              :List_Dyn_GetLength: Get the length of the List(L) [O(1)]
 *              :List_Dyn_GetCapacity: Get the capacity of the List(L) [O(1)]
 *              :List_Dyn_IsEmpty: Check if the List(L) is empty [O(1)]
 *              :List_Dyn_GetElem: Get the element at the Index(index) of the List(L) [O(1)]
 *              :List_Dyn_LocateElem: Search the list (L) to find the index of the first element(e) [O(n)]
 *              :List_Dyn_Extend: Extend the capacity of the List(L) [O(n)]
 *              :List_Dyn_Insert: Insert Element(e) at the Index(index) of the List(L) [O(n)]
                :List_Dyn_InsertEnd: Insert Element(e) at the end of the List(L) [O(1)]
 *              :List_Dyn_Delete: Delete the Element at the Index(index) of the List(L) [O(n)]
 *              :List_Dyn_Print: Print the List(L) [O(n)]
 *              :List_Dyn_Destroy: Destory the List(L) [O(1)]
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define Maxsize 10

/* Sequence List of dynamic */
typedef struct {
    ElemType *data;
    int length;
    int capacity;
} *SeqList;

/* Initialize the Sequence List of dynamic */
SeqList List_Dyn_Init() {
    SeqList L = (SeqList)malloc(sizeof(SeqList));
    L->length = 0;
    L->capacity = Maxsize;
    L->data = (ElemType *)malloc(sizeof(ElemType) * L->capacity);
    return L;
}

/* Get the length of the List(L) [O(1)] */
int List_Dyn_GetLength(SeqList L) {
    return L->length;
}

/* Get the capacity of the List(L) [O(1)] */
int List_Dyn_GetCapacity(SeqList L) {
    return L->capacity;
}

/* Check if the List(L) is empty [O(1)] */
bool List_Dyn_IsEmpty(SeqList L) {
    return L->length == 0;
}

/* Get the element at the Index(index) of the List(L) [O(1)] */
ElemType List_Dyn_GetElem(SeqList L, int index) {
    return L->data[index];
}

/* Search the list (L) to find the index of the first element(e) [O(n)] */
int List_Dyn_LocateElem(SeqList L, ElemType e) {
    for (int i = 0; i < L->length; i++) {
        if (L->data[i] == e) {
            return i;
        }
    }
    return -1;
}

/* Extend the capacity of the List(L) [O(n)] */
bool List_Dyn_Extend(SeqList L) {
    L->data = (ElemType *)realloc(L->data, sizeof(ElemType) * (L->capacity + Maxsize));
    L->capacity += Maxsize;
    return true;
}

/* Insert Element(e) at the Index(index) of the List(L) [O(n)] */
bool List_Dyn_Insert(SeqList L, ElemType e, int index) {
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
bool List_Dyn_InsertEnd(SeqList L, ElemType e) {
    return List_Dyn_Insert(L, e, L->length);
}

/* Delete the Element at the Index(index) of the List(L) [O(n)] */
bool List_Dyn_Delete(SeqList L, int index, ElemType *e) {
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
void List_Dyn_Destroy(SeqList L) {
    free(L->data);
    L->length = 0;
}

/* Print the List(L) [O(n)] */
void List_Dyn_Print(SeqList L) {
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
    SeqList L = List_Dyn_Init();
    for (int i = 0; i < 6; i++) {
        List_Dyn_InsertEnd(L, i);
    }
    List_Dyn_Print(L);

    printf("Length: %d\n", List_Dyn_GetLength(L));

    if (List_Dyn_IsEmpty(L)) {
        printf("List is empty!\n");
    } else {
        printf("List is not empty!\n");
    }

    printf("Element at index 2: %d\n", List_Dyn_GetElem(L, 2));
    printf("Index of element 3: %d\n", List_Dyn_LocateElem(L, 3));

    printf("================================================\n");

    List_Dyn_Insert(L, 9, 0);
    List_Dyn_Insert(L, 99, 1);
    List_Dyn_Insert(L, 999, 3);
    printf("Length: %d\n", List_Dyn_GetLength(L));
    List_Dyn_Insert(L, 9999, 10);
    List_Dyn_Insert(L, 99999, 9);
    List_Dyn_Insert(L, 999999, 11);
    List_Dyn_Insert(L, 9999999, 10);
    List_Dyn_Insert(L, 99999999, 11);
    List_Dyn_Print(L);

    printf("================================================\n");

    ElemType e;
    List_Dyn_Delete(L, 0, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 1, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 7, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 8, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 9, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 10, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    printf("================================================\n");

    List_Dyn_Destroy(L);
    List_Dyn_Print(L);
    return 0;
}