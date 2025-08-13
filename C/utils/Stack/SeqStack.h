/**
 * @FileName    :SeqStack.h
 * @Date        :2025-03-12 14:25:59
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence Stack
 * @Description :
 *              :SeqStack_Init: Initialize the Sequence Stack
 *              :SeqStack_GetLength: Get the length of the Stack(S) [O(1)]
 *              :SeqStack_IsEmpty: Check if the Stack(S) is empty [O(1)]
 *              :SeqStack_IsFull: Check if the Stack(S) is full [O(1)]
 *              :SeqStack_Push: Push Element to the Stack(S) [O(1)]
 *              :SeqStack_Pop: Pop Element from the Stack(S) [O(1)]
 *              :SeqStack_GetTop: Get the top Element of the Stack(S) [O(1)]
 *              :SeqStack_Clear: Clear the Stack(S)
 *              :SeqStack_Destroy: Destroy the Stack(S)
 *              :SeqStack_Print: Print the Stack(S) [O(n)]
 */

#ifndef SEQSTACK_H
#define SEQSTACK_H

#include "../common.h"

/* Sequence Stack */
typedef struct SeqStack {
    ElemType *data;
    int top;
    int length;
    int capacity;
} *SeqStack;

/* Initialize the Sequence Stack */
SeqStack SeqStack_Init(int capacity) {
    SeqStack S = (SeqStack)malloc(sizeof(struct SeqStack));
    S->data = (ElemType *)malloc(sizeof(ElemType) * capacity);
    S->top = -1;
    S->length = 0;
    S->capacity = capacity;
    return S;
}

/* Get the length of the Stack(S) [O(1)] */
int SeqStack_GetLength(SeqStack S) {
    assert(S != NULL && "ERROR: When getting the length of the Stack, the Stack is NULL!\n");
    // return S->top + 1;
    return S->length;
}

/* Check if the Stack(S) is empty [O(1)] */
bool SeqStack_IsEmpty(SeqStack S) {
    assert(S != NULL && "ERROR: When checking if the Stack is empty, the Stack is NULL!\n");
    // return S->top == -1;
    return S->length == 0;
}

/* Check if the Stack(S) is full [O(1)] */
bool SeqStack_IsFull(SeqStack S) {
    assert(S != NULL && "ERROR: When checking if the Stack is full, the Stack is NULL!\n");
    return S->top == S->capacity - 1;
}

/* Push Element to the Stack(S) [O(1)] */
bool SeqStack_Push(SeqStack S, ElemType e) {
    assert(S != NULL && "ERROR: When pushing an element to the Stack, the Stack is NULL!\n");
    assert(!SeqStack_IsFull(S) && "ERROR: When pushing an element to the Stack, the Stack is Full!\n");
    S->data[++S->top] = e;
    S->length++;
    return true;
}

/* Pop Element from the Stack(S) [O(1)] */
ElemType SeqStack_Pop(SeqStack S) {
    assert(S != NULL && "ERROR: When popping an element from the Stack, the Stack is NULL!\n");
    assert(!SeqStack_IsEmpty(S) && "ERROR: When popping an element from the Stack, the Stack is Empty!\n");
    ElemType e = S->data[S->top--];
    S->length--;
    return e;
}

/* Get the top Element of the Stack(S) [O(1)] */
ElemType SeqStack_GetTop(SeqStack S) {
    assert(S != NULL && "ERROR: When getting the top element from the Stack, the Stack is NULL!\n");
    assert(!SeqStack_IsEmpty(S) && "ERROR: When getting the top element from the Stack, the Stack is Empty!\n");
    ElemType e = S->data[S->top];
    return e;
}

/* Clear the Stack(S) */
bool SeqStack_Clear(SeqStack S) {
    assert(S != NULL && "ERROR: When clearing the Stack, the Stack is NULL!\n");
    for(int i = 0; i < S->capacity; i++){
        S->data[i] = (ElemType)0;
    }
    S->top = -1;
    S->length = 0;
    return true;
}

/* Destroy the Stack(S) */
SeqStack SeqStack_Destroy(SeqStack S) {
    assert(S != NULL && "ERROR: When destroying the Stack, the Stack is NULL!\n");
    free(S->data);
    free(S);
    return NULL;
}

/* Print the Stack(S) [O(n)] */
void SeqStack_Print(SeqStack S) {
    printf("Sequence Stack: ");
    if (S->length == 0) {
        printf("Empty Stack!\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 0; i < S->length; i++) {
        printf("%d    ", i);
    }
    printf("\n");
    printf("  Value: ");
    for (int i = 0; i < S->length; i++) {
        printf("%d    ", S->data[i]);
    }
    printf("\n");
    return;
}

#endif // SEQSTACK_H