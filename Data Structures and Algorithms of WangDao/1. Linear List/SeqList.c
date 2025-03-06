/**
 * @FileName    :SeqList.c
 * @Date        :2025-03-06 17:07:05
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence List
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MaxSize 50
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;

typedef struct {
    ElemType *data;
    int length;
} SeqList;

void List_Init(SqList *L) {
    L->length = 0;
}

void List_Init_D(SeqList *L) {
    L->data = (ElemType *)malloc(sizeof(ElemType) * MaxSize);
    L->length = 0;
}

int List_GetLength(SqList L) {
    return L.length;
}

bool List_IsEmpty(SqList L) {
    return L.length == 0;
}

ElemType List_GetElem(SqList L, int i) {
    return L.data[i - 1];
}

int List_LocateElem(SqList L, ElemType e) {
    for (int i = 0; i < L.length; i++) {
        if (L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}

bool List_Insert(SqList *L, int i, ElemType e) {
    if (i < 1 || i > L->length + 1) {
        return false;
    }
    if (L->length >= MaxSize) {
        return false;
    }
    for (int j = L->length; j >= i; j--) {
        L->data[j] = L->data[j - 1];
    }
    L->data[i - 1] = e;
    L->length++;
    return true;
}

bool List_Delete(SqList *L, int i, ElemType *e) {
    if (i < 1 || i > L->length) {
        return false;
    }
    *e = L->data[i - 1];
    for (int j = i; j < L->length; j++) {
        L->data[j - 1] = L->data[j];
    }
    L->length--;
    return true;
}

void List_Print(SqList L) {
    for (int i = 0; i < L.length; i++) {
        printf("%d ", L.data[i]);
    }
    printf("\n");
}

bool List_Destory(SqList *L) {
    L->length = 0;
    return true;
}

int main() {
    SqList L;
    List_Init(&L);
    List_Insert(&L, 1, 1);
    List_Insert(&L, 2, 2);
    List_Insert(&L, 3, 3);
    List_Print(L);

    printf("List_IsEmpty: %d\n", List_IsEmpty(L));
    printf("List_GetLength: %d\n", List_GetLength(L));
    printf("List_LocateElem: %d\n", List_LocateElem(L, 3));
    printf("List_GetElem: %d\n", List_GetElem(L, 2));

    ElemType e;
    List_Delete(&L, 2, &e);
    List_Print(L);

    List_Destory(&L);
    List_Print(L);
    return 0;
}