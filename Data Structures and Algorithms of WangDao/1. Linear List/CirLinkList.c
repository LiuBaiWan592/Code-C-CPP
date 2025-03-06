/**
 * @FileName    :CirCirLinkList.c
 * @Date        :2025-03-06 19:57:39
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Circular Linked List
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *CirLinkList;

CirLinkList List_Init() {
    CirLinkList L = (CirLinkList)malloc(sizeof(LNode));
    L->next = L;
    return L;
}

CirLinkList List_Init_NoHead() {
    CirLinkList L = NULL;
    return L;
}
int List_GetLength(CirLinkList L) {
    int length = 0;
    LNode *p = L;
    while (p->next != L) {
        length++;
        p = p->next;
    }
    return length;
}

bool List_IsEmpty(CirLinkList L) {
    return L->next == L;
}

LNode *List_GetElem(CirLinkList L, int i) {
    if (i < 1) {
        return NULL;
    }
    LNode *p = L->next;
    int j = 1;
    while (p != L && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

int List_LocateElem(CirLinkList L, ElemType e) {
    LNode *p = L->next;
    int j = 1;
    while (p != L && p->data != e) {
        p = p->next;
        j++;
    }
    return p == L ? 0 : j;
}

bool List_Insert(CirLinkList L, int i, ElemType e) {
    LNode *p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == L && j < i - 1) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool List_Delete(CirLinkList L, int i, ElemType *e) {
    LNode *p = L;
    int j = 0;
    while (p->next != L && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == L || j != i - 1) {
        return false;
    }
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

void List_Print(CirLinkList L) {
    LNode *p = L;
    while (p->next != L) {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}

bool List_Destory(CirLinkList L) {
    LNode *p = L->next;
    while (p != L) {
        LNode *q = p;
        p = p->next;
        free(q);
    }
    L->next = L;
    return true;
}

bool List_HeadInsert(CirLinkList L, ElemType e) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
}

bool List_TailInsert(CirLinkList L, ElemType e) {
    LNode *p = L;
    while (p->next != L) {
        p = p->next;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L;
    p->next = s;
    return true;
}


int main() {
    CirLinkList L = List_Init();

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