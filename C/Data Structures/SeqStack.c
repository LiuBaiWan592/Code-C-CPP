/**
 * @FileName    :SeqStack.c
 * @Date        :2025-03-10 11:54:57
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 4
#define ElemType int

/* Sequence Stack */
typedef struct {
    ElemType *data;
    int top;
    int length;
} *SeqStack;

/* Initialize the Sequence Stack */
SeqStack SeqStack_Init() {
    SeqStack S = (SeqStack)malloc(sizeof(SeqStack));
    S->top = -1;
    S->length = 0;
    S->data = (ElemType *)malloc(sizeof(ElemType) * Maxsize);
    for (int i = 0; i < Maxsize; i++) {
        S->data[i] = 0;
    }
    return S;
}

/* Get the length of the Stack(S) [O(1)] */
int SeqStack_GetLength(SeqStack S) {
    // return S->top + 1;
    return S->length;
}

/* Check if the Stack(S) is empty [O(1)] */
bool SeqStack_IsEmpty(SeqStack S) {
    // return S->top == -1;
    return S->length == 0;
}

/* Check if the Stack(S) is full [O(1)] */
bool SeqStack_IsFull(SeqStack S) {
    return S->top == Maxsize - 1;
}

/* Push Element to the Stack(S) [O(1)] */
bool SeqStack_Push(SeqStack S, ElemType e) {
    if (SeqStack_IsFull(S)) {
        printf("Push Error: Stack is Full! Failed to Push Element %d!\n", e);
        return false;
    }
    S->data[++S->top] = e;
    S->length++;
    return true;
}

/* Pop Element from the Stack(S) [O(1)] */
bool SeqStack_Pop(SeqStack S, ElemType *e) {
    if (SeqStack_IsEmpty(S)) {
        printf("Pop Error: Stack is Empty! Failed to Pop Element!\n");
        return false;
    }
    *e = S->data[S->top--];
    S->length--;
    return true;
}

/* Get the top Element of the Stack(S) [O(1)] */
bool SeqStack_GetTop(SeqStack S, ElemType *e) {
    if (SeqStack_IsEmpty(S)) {
        printf("GetTop Error: Stack is Empty! Failed to Get Top Element!\n");
        return false;
    }
    *e = S->data[S->top];
    return true;
}

/* Clear the Stack(S) */
bool SeqStack_Clear(SeqStack S) {
    S->top = -1;
    S->length = 0;
    return true;
}

/* Destroy the Stack(S) */
bool SeqStack_Destroy(SeqStack S) {
    free(S->data);
    free(S);
    return true;
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

/* Driver Code */
int main() {
    SeqStack S = SeqStack_Init();
    SeqStack_Push(S, 1);
    SeqStack_Push(S, 3);
    SeqStack_Push(S, 2);
    SeqStack_Push(S, 5);
    SeqStack_Push(S, 4);

    SeqStack_Print(S);

    ElemType top;
    SeqStack_GetTop(S, &top);
    printf("Top: %d\n", top);

    ElemType pop;
    SeqStack_Pop(S, &pop);
    printf("Pop: %d\n", pop);

    bool empty = SeqStack_IsEmpty(S);
    printf("Is Empty: %s\n", empty ? "true" : "false");
    int length = SeqStack_GetLength(S);
    printf("Length: %d\n", length);

    SeqStack_Print(S);
    SeqStack_Clear(S);
    SeqStack_Print(S);

    SeqStack_Destroy(S);
    return 0;
}