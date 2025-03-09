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
    S->top = -1; // Initialize the top of the stack to -1
}

bool SeqStack_IsEmpty(SeqStack S) {
    return S.top == -1; // If the top of the stack is -1, the stack is empty
}

bool Push(SeqStack *S, ElemType e) {
    if (S->top == MAXSIZE - 1) {
        return false; // If the stack is full, return false
    }
    S->data[++S->top] = e;
    return true;
}

bool Pop(SeqStack *S, ElemType *e) {
    if (S->top == -1) {
        return false; // If the stack is empty, return false
    }
    *e = S->data[S->top--];
    return true;
}

bool GetTop(SeqStack S, ElemType *e) {
    if (S.top == -1) {
        return false; // If the stack is empty, return false
    }
    *e = S.data[S.top];
    return true;
}

bool SeqStack_Destroy(SeqStack *S) {
    S->top = -1;
    return true;
}

int main() {
    SeqStack S;
    SeqStack_Init(&S);
    Push(&S, 1);
    Push(&S, 2);
    Push(&S, 3);
    ElemType e;
    Pop(&S, &e);
    printf("%d\n", e);
    GetTop(S, &e);
    printf("%d\n", e);
}