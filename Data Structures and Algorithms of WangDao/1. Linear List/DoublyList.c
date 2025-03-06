/**
 * @FileName    :DoublyList.c
 * @Date        :2025-03-06 19:24:24
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Doubly Linked List
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct DNode {
    ElemType data;
    struct DNode *prior, *next;
} DNode, *DoublyList;

DoublyList List_Init() {
    DoublyList L = (DoublyList)malloc(sizeof(DNode));
    L->prior = NULL;
    L->next = NULL;
    return L;
}

DoublyList List_Init_NoHead() {
    DoublyList L = NULL;
    return L;
}
int List_GetLength(DoublyList L) {
    int length = 0;
    DNode *p = L;
    while (p->next != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

bool List_IsEmpty(DoublyList L) {
    return L->next == NULL;
}

DNode *List_GetElem(DoublyList L, int i) {
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

int List_LocateElem(DoublyList L, ElemType e) {
    DNode *p = L->next;
    int j = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        j++;
    }
    return p == NULL ? 0 : j;
}

bool List_Insert(DoublyList L, int i, ElemType e) {
    DNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = p->next;
    if (p->next != NULL) {
        p->next->prior = s;
    }
    s->prior = p;
    p->next = s;
    return true;
}

bool List_Delete(DoublyList L, int i, ElemType *e) {
    DNode *p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j != i - 1) {
        return false;
    }
    DNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    if (q->next != NULL) {
        q->next->prior = p;
    }
    free(q);
    return true;
}

void List_Print(DoublyList L) {
    DNode *p = L;
    while (p != NULL && p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}

bool List_Destory(DoublyList L) {
    DNode *p = L->next;
    while (p != NULL) {
        DNode *q = p;
        p = p->next;
        free(q);
    }
    L->next = NULL;
    return true;
}

bool List_HeadInsert(DoublyList L, ElemType e) {
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = L->next;
    if (L->next != NULL) {
        L->next->prior = s;
    }
    s->prior = L;
    L->next = s;
    return true;
}

bool List_TailInsert(DoublyList L, ElemType e) {
    DNode *p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    DNode *s = (DNode *)malloc(sizeof(DNode));
    s->data = e;
    s->next = NULL;
    s->prior = p;
    p->next = s;
    return true;
}


int main() {
    DoublyList L = List_Init();

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