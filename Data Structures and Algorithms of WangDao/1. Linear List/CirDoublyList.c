/**
 * @FileName    :CirDoublyList.c
 * @Date        :2025-03-06 19:57:58
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Circular Doubly Linked List
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *CirDoublyList;

CirDoublyList List_Init() {
    CirDoublyList L = (CirDoublyList)malloc(sizeof(DNode));
    L->prior = L;
    L->next = L;
    return L;
}

CirDoublyList List_Init_NoHead() {
    CirDoublyList L = NULL;
    return L;
}
int List_GetLength(CirDoublyList L) {
    int length = 0;
    DNode *p = L;
    while (p->next != L) {
        length++;
        p = p->next;
    }
    return length;
}

bool List_IsEmpty(CirDoublyList L) {
    return L->next == L;
}

DNode *List_GetElem(CirDoublyList L, int i) {
    if (i < 1) {
        return NULL;
    }
    DNode *p = L->next;
    int j = 1;
    while (p != L && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

int List_LocateElem(CirDoublyList L, ElemType e) {
    DNode *p = L->next;
    int j = 1;
    while (p != L && p->data != e) {
        p = p->next;
        j++;
    }
    return p == L ? 0 : j;
}

bool List_Insert(CirDoublyList L, int i, ElemType e) {
    DNode *p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == L && j < i - 1) {
        return false;
    }
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    p->next->prior = s;
    s->prior = p;
    p->next = s;
    return true;
}

bool List_Delete(CirDoublyList L, int i, ElemType *e) {
    DNode *p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == L || j != i - 1) {
        return false;
    }
    DNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    q->next->prior = p;
    free(q);
    return true;
}

void List_Print(CirDoublyList L) {
    DNode *p = L;
    while (p->next != L) {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}

bool List_Destory(CirDoublyList L) {
    DNode *p = L->next;
    while (p != L) {
        DNode *q = p;
        p = p->next;
        free(q);
    }
    L->next = L;
    L->prior = L;
    return true;
}

bool List_HeadInsert(CirDoublyList L, ElemType e) {
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = L->next;
    L->next->prior = s;
    s->prior = L;
    L->next = s;
    return true;
}

bool List_TailInsert(CirDoublyList L, ElemType e) {
    DNode *p = L;
    while (p->next != L) {
        p = p->next;
    }
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = L;
    s->prior = p;
    p->next = s;
    return true;
}

int main() {
    CirDoublyList L = List_Init();

    for (int i = 0; i < 5; i++) {
        List_TailInsert(L, i);
    }
    List_Print(L);
    for (int i = 0; i < 5; i++) {
        List_HeadInsert(L, i);
    }
    List_Print(L);

    printf("List_IsEmpty: %d\n", List_IsEmpty(L));
    printf("List_GetLength: %d\n", List_GetLength(L));
    printf("List_LocateElem: %d\n", List_LocateElem(L, 3));
    printf("List_GetElem: %d\n", (List_GetElem(L, 2)) == NULL ? 0 : List_GetElem(L, 2)->data);

    ElemType e;
    List_Delete(L, 2, &e);
    List_Print(L);

    List_Insert(L, 1, 100);
    List_Print(L);

    List_Destory(L);
    List_Print(L);
    return 0;
}