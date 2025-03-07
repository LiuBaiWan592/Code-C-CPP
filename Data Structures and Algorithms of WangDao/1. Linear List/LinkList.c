/**
 * @FileName    :LinkList.c
 * @Date        :2025-03-06 17:27:31
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Linked List
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

LinkList List_Init() {
    LinkList L = (LinkList)malloc(sizeof(LNode));
    L->next = NULL;
    return L;
}

LinkList List_Init_NoHead() {
    LinkList L = NULL;
    return L;
}
int List_GetLength(LinkList L) {
    int length = 0;
    LNode *p = L;
    while (p->next != NULL) {
        length++;
        p = p->next;
    }
    return length;
}

bool List_IsEmpty(LinkList L) {
    return L->next == NULL;
}

LNode *List_GetElem(LinkList L, int i) {
    if (i < 1) {
        return NULL;
    }
    LNode *p = L->next;
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

int List_LocateElem(LinkList L, ElemType e) {
    LNode *p = L->next;
    int j = 1;
    while (p != NULL && p->data != e) {
        p = p->next;
        j++;
    }
    return p == NULL ? 0 : j;
}

bool List_Insert(LinkList L, int i, ElemType e) {
    LNode *p = L;
    int j = 0;
    while (p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p == NULL) {
        return false;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool List_Delete(LinkList L, int i, ElemType *e) {
    LNode *p = L;
    int j = 0;
    while (p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if (p->next == NULL || j != i - 1) {
        return false;
    }
    LNode *q = p->next;
    *e = q->data;
    p->next = q->next;
    free(q);
    return true;
}

void List_Print(LinkList L) {
    LNode *p = L;
    while (p != NULL && p->next != NULL) {
        p = p->next;
        printf("%d ", p->data);
    }
    printf("\n");
}

bool List_Destory(LinkList L) {
    LNode *p = L->next;
    while (p != NULL) {
        LNode *q = p;
        p = p->next;
        free(q);
    }
    L->next = NULL;
    return true;
}

bool List_HeadInsert(LinkList L, ElemType e) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = L->next;
    L->next = s;
    return true;
}

bool List_TailInsert(LinkList L, ElemType e) {
    LNode *p = L;
    while (p->next != NULL) {
        p = p->next;
    }
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;
    p->next = s;
    return true;
}

int main() {
    LinkList L = List_Init();

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