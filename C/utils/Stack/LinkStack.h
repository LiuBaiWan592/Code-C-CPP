/**
 * @FileName    :LinkStack.h
 * @Date        :2025-07-28 18:26:04
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
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
typedef struct LinkStack {
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
    assert(S != NULL && "ERROR: When getting the length of the Stack, the Stack is NULL!\n");
    return S->length;
}

/* Check if Linked List Stack is Empty [O(1)] */
bool LinkStack_IsEmpty(LinkStack S) {
    assert(S != NULL && "ERROR: When checking if the Stack is empty, the Stack is NULL!\n");
    return S->next == NULL;
}

/* Push Element(x) to Linked List Stack [O(1)] */
bool LinkStack_Push(LinkStack S, ElemType x) {
    assert(S != NULL && "ERROR: When pushing an element to the Stack, the Stack is NULL!\n");
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = x;
    s->next = S->next;
    S->next = s;
    S->length++;
    return true;
}

/* Pop Element(x) from Linked List Stack [O(1)] */
ElemType LinkStack_Pop(LinkStack S) {
    assert(S != NULL && "ERROR: When popping an element from the Stack, the Stack is NULL!\n");
    assert(!LinkStack_IsEmpty(S) && "ERROR: When popping an element from the Stack, the Stack is Empty!\n");
    LNode *s = S->next;
    ElemType e = s->data;
    S->next = s->next;
    free(s);
    S->length--;
    return e;
}

/* Get Top Element(x) from Linked List Stack [O(1)] */
ElemType LinkStack_GetTop(LinkStack S) {
    assert(S != NULL && "ERROR: When popping an element from the Stack, the Stack is NULL!\n");
    assert(!LinkStack_IsEmpty(S) && "ERROR: When popping an element from the Stack, the Stack is Empty!\n");
    ElemType e = S->next->data;
    return e;
}

/* Clear Linked List Stack */
bool LinkStack_Clear(LinkStack S) {
    assert(S != NULL && "ERROR: When clearing the Stack, the Stack is NULL!\n");
    while (!LinkStack_IsEmpty(S)) {
        LinkStack_Pop(S);
    }
    S->length = 0;
    return true;
}

/* Destroy Linked List Stack */
LinkStack LinkStack_Destroy(LinkStack S) {
    assert(S != NULL && "ERROR: When destroying the Stack, the Stack is NULL!\n");
    LNode *p = S->next;
    while (p != NULL) {
        LNode *q = p->next;
        free(p);
        p = q;
    }
    free(S);
    return NULL;
}

/* Print Linked List Stack */
void LinkStack_Print(LinkStack S) {
    assert(S != NULL && "ERROR: When printing the Stack, the Stack is NULL!\n");
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