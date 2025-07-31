/**
 * @FileName    :LinkStack.h
 * @Date        :2025-07-28 18:26:04
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :Linked List Stack With Head Node
 * @Description :
 *              :LinkStack_Init: Initialize the Linked List Stack
 *              :LinkStack_GetLength: Get the length of the Stack(S) [O(1)]
 *              :LinkStack_IsEmpty: Check if the Stack(S) is empty [O(1)]
 *              :LinkStack_Push: Push Element to the Stack(S) [O(1)]
 *              :LinkStack_Pop: Pop Element from the Stack(S) [O(1)]
 *              :LinkStack_GetTop: Get the top Element of the Stack(S) [O(1)]
 *              :LinkStack_Clear: Clear the Stack(S)
 *              :LinkStack_Destroy: Destroy the Stack(S)
 *              :LinkStack_Print: Print the Stack(S) [O(n)]
 *              :LinkStack_Reverse: Reverse the Stack(S) [O(n)]
 */

#ifndef LINKSTACK_H
#define LINKSTACK_H

#include "../common.h"

/* Head Node of Linked List Stack */
typedef struct LinkStack{
    int length;
    LNode *next;
} *LinkStack;

/* Initialize Linked List Stack */
LinkStack LinkStack_Init() {
    LinkStack S = (LinkStack)malloc(sizeof(struct LinkStack));
    S->length = 0;
    S->next = NULL;
    return S;
}

/* Get the length of the Stack(S) [O(1)] */
int LinkStack_GetLength(LinkStack S) {
    return S->length;
}

/* Check if Linked List Stack is Empty [O(1)] */
bool LinkStack_IsEmpty(LinkStack S) {
    return S->next == NULL;
}

/* Push Element(x) to Linked List Stack [O(1)] */
bool LinkStack_Push(LinkStack S, ElemType x) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = S->next;
    S->next = s;
    S->length++;
    return true;
}

/* Pop Element(x) from Linked List Stack [O(1)] */
bool LinkStack_Pop(LinkStack S, ElemType *x) {
    if (S->next == NULL) {
        printf("Pop Error: Stack is Empty! Failed to Pop Element!\n");
        return false;
    }
    LNode *s = S->next;
    *x = s->data;
    S->next = s->next;
    free(s);
    S->length--;
    return true;
}

/* Get Top Element(x) from Linked List Stack [O(1)] */
bool LinkStack_GetTop(LinkStack S, ElemType *x) {
    if (S->next == NULL) {
        printf("GetTop Error: Stack is Empty! Failed to Get Top Element!\n");
        return false;
    }
    *x = S->next->data;
    return true;
}

/* Clear Linked List Stack */
bool LinkStack_Clear(LinkStack S) {
    ElemType tmp;
    while (!LinkStack_IsEmpty(S)) {
        LinkStack_Pop(S, &tmp);
    }
    S->length = 0;
    return true;
}

/* Destroy Linked List Stack */
void LinkStack_Destroy(LinkStack S) {
    if (S == NULL) {
        return;
    }
    LNode *p = S->next;
    while (p != NULL) {
        LNode *q = p->next;
        free(p);
        p = q;
    }
    S->length = 0;
    return;
}

/* Print Linked List Stack */
void LinkStack_Print(LinkStack S) {
    printf("Linked Stack: ");
    if (LinkStack_IsEmpty(S)) {
        printf("Empty Linked Stack!\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 1; i <= S->length; i++) {
        printf("%d    ", i);
    }
    printf("\n");
    printf("  Value: ");
    LNode *p = S->next;
    while (p != NULL) {
        printf("%d    ", p->data);
        p = p->next;
    }
    printf("\n");
}

/* Reverse the List(L) [O(n)] */
bool LinkStack_Reverse(LinkStack S) {
    LNode *p = S->next, *q = NULL;
    LNode *rear = p;
    while (p != NULL) {
        q = p->next;
        p->next = S->next;
        S->next = p;
        p = q;
    }
    rear->next = NULL;
    return true;
}

#endif // LINKSTACK_H