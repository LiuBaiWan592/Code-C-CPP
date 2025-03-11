/**
 * @FileName    :LinkStack.c
 * @Date        :2025-03-11 10:45:06
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :Linked List Stack With Head Node
 * @Description :
 *              :LinkStack_Init: Initialize the Linked List Stack
 *              :LinkStack_GetLength: Get the length of the Stack(S) [O(1)]
 *              :LinkStack_IsEmpty: Check if the Stack(S) is empty [O(1)]
 *              :LinkStack_IsFull: Check if the Stack(S) is full [O(1)]
 *              :LinkStack_Push: Push Element to the Stack(S) [O(1)]
 *              :LinkStack_Pop: Pop Element from the Stack(S) [O(1)]
 *              :LinkStack_GetTop: Get the top Element of the Stack(S) [O(1)]
 *              :LinkStack_Clear: Clear the Stack(S)
 *              :LinkStack_Destroy: Destroy the Stack(S)
 *              :LinkStack_Print: Print the Stack(S) [O(n)]
 *              :LinkStack_Reverse: Reverse the Stack(S) [O(n)]
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

/* Linked List Stack Node */
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkStack;

/* Initialize Linked List Stack */
LinkStack LinkStack_Init() {
    LinkStack S = (LinkStack)malloc(sizeof(LinkStack));
    S->data = 0;
    S->next = NULL;
    return S;
}

/* Get the length of the Stack(S) [O(1)] */
int LinkStack_GetLength(LinkStack S) {
    int len = 0;
    LNode *p = S->next;
    while (p != NULL) {
        len++;
        p = p->next;
    }
    return len;
}

/* Check if Linked List Stack is Empty [O(1)] */
bool LinkStack_IsEmpty(LinkStack S) {
    return S->next == NULL;
}

/* Push Element(x) to Linked List Stack [O(1)] */
bool LinkStack_Push(LinkStack S, ElemType x) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    if (s == NULL)
        return false;
    s->data = x;
    s->next = S->next;
    S->next = s;
    return true;
}

/* Pop Element(x) from Linked List Stack [O(1)] */
bool LinkStack_Pop(LinkStack S, ElemType *x) {
    if (S->next == NULL)
        return false;
    LNode *s = S->next;
    *x = s->data;
    S->next = s->next;
    free(s);
    return true;
}

/* Get Top Element(x) from Linked List Stack [O(1)] */
bool LinkStack_GetTop(LinkStack S, ElemType *x) {
    if (S->next == NULL)
        return false;
    *x = S->next->data;
    return true;
}

/* Clear Linked List Stack */
bool LinkStack_Clear(LinkStack S) {
    ElemType tmp;
    while (!LinkStack_IsEmpty(S)) {
        LinkStack_Pop(S, &tmp);
    }
    return true;
}

/* Destroy Linked List Stack */
bool LinkStack_Destroy(LinkStack S) {
    LNode *p = S;
    while (p != NULL) {
        LNode *q = p->next;
        free(p);
        p = q;
    }
    return true;
}

/* Print Linked List Stack */
void LinkStack_Print(LinkStack S) {
    if (LinkStack_IsEmpty(S)) {
        printf("Empty Linked Stack!\n");
        return;
    }
    LNode *p = S->next;
    while (p != NULL) {
        printf("%d ", p->data);
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

/* Drive Code */
int main() {
    LinkStack S = LinkStack_Init();

    LinkStack_Push(S, 1);
    LinkStack_Push(S, 3);
    LinkStack_Push(S, 2);
    LinkStack_Push(S, 5);
    LinkStack_Push(S, 4);

    LinkStack_Print(S);

    ElemType top;
    LinkStack_GetTop(S, &top);
    printf("Top: %d\n", top);

    ElemType pop;
    LinkStack_Pop(S, &pop);
    printf("Pop: %d\n", pop);

    bool empty = LinkStack_IsEmpty(S);
    printf("Is Empty: %s\n", empty ? "true" : "false");

    LinkStack_Reverse(S);
    LinkStack_Print(S);
    LinkStack_Clear(S);
    LinkStack_Print(S);

    LinkStack_Destroy(S);
    return 0;
}