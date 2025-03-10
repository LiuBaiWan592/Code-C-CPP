/**
 * @FileName    :SeqStack.c
 * @Date        :2025-03-09 21:56:35
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence Stack
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 10
#define ElemType int

typedef struct {
    ElemType data[MAXSIZE];
    int top;
} SeqStack;

void SeqStack_Init(SeqStack *S) {
    S->top = -1;
}

bool SeqStack_IsEmpty(SeqStack S) {
    return S.top == -1;
}

bool SeqStack_Push(SeqStack *S, ElemType e) {
    if (S->top == MAXSIZE - 1) {
        return false;
    }
    S->data[++S->top] = e;
    return true;
}

bool SeqStack_Pop(SeqStack *S, ElemType *e) {
    if (S->top == -1) {
        return false;
    }
    *e = S->data[S->top--];
    return true;
}

bool SeqStack_GetTop(SeqStack S, ElemType *e) {
    if (S.top == -1) {
        return false;
    }
    *e = S.data[S.top];
    return true;
}

bool SeqStack_Destroy(SeqStack *S) {
    S->top = -1;
    return true;
}

void SeqStack_Print(SeqStack S) {
    for (int i = 0; i <= S.top; i++) {
        printf("%d ", S.data[i]);
    }
    printf("\n");
}

int main() {
    SeqStack S;
    SeqStack_Init(&S);
    SeqStack_Push(&S, 1);
    SeqStack_Push(&S, 3);
    SeqStack_Push(&S, 2);
    SeqStack_Push(&S, 5);
    SeqStack_Push(&S, 4);

    SeqStack_Print(S);

    ElemType top;
    SeqStack_GetTop(S, &top);
    printf("Top: %d\n", top);

    ElemType pop;
    SeqStack_Pop(&S, &pop);
    printf("Pop: %d\n", pop);

    bool empty = SeqStack_IsEmpty(S);
    printf("Is Empty: %s\n", empty ? "true" : "false");

    SeqStack_Print(S);

    SeqStack_Destroy(&S);
    return 0;
}