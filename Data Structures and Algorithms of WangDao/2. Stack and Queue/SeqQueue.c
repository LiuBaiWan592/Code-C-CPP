/**
 * @FileName    :SeqQueue.c
 * @Date        :2025-03-11 11:58:07
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence Queue (Circular)
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 4
#define ElemType int

typedef struct {
    ElemType *data;
    int front;
    int rear;
} *SeqQueue;

SeqQueue SeqQueue_Init() {
    SeqQueue Q = (SeqQueue)malloc(sizeof(SeqQueue));
    Q->data = (ElemType *)malloc(Maxsize * sizeof(ElemType));
    Q->front = Q->rear = 0;
    return Q;
}

bool SeqQueue_IsEmpty(SeqQueue Q) {
    return Q->front == Q->rear;
}

bool SeqQueue_IsFull(SeqQueue Q) {
    return (Q->rear + 1) % Maxsize == Q->front;
}

int SeqQueue_GetLength(SeqQueue Q) {
    return (Q->rear + Maxsize - Q->front) % Maxsize;
}

bool SeqQueue_Enter(SeqQueue Q, ElemType e) {
    if (SeqQueue_IsFull(Q)) {
        printf("Queue is full!\n");
        return false;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % Maxsize;
    return true;
}

bool SeqQueue_Leave(SeqQueue Q, ElemType *e) {
    if (SeqQueue_IsEmpty(Q)) {
        printf("Queue is empty!\n");
        return false;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % Maxsize;
    return true;
}

bool SeqQueue_GetFront(SeqQueue Q, ElemType *e) {
    if (SeqQueue_IsEmpty(Q)) {
        printf("Queue is empty!\n");
        return false;
    }
    *e = Q->data[Q->front];
    return true;
}

void SeqQueue_Clear(SeqQueue Q) {
    Q->front = Q->rear = 0;
}

void SeqQueue_Destroy(SeqQueue Q) {
    free(Q->data);
    free(Q);
}

void SeqQueue_Print(SeqQueue Q) {
    if (SeqQueue_IsEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    }
    int i = Q->front;
    while (i != Q->rear) {
        printf("%d ", Q->data[i]);
        i = (i + 1) % Maxsize;
    }
    printf("\n");
}

int main() {
    SeqQueue Q = SeqQueue_Init();
    SeqQueue_Enter(Q, 1);
    SeqQueue_Enter(Q, 2);
    SeqQueue_Enter(Q, 3);
    SeqQueue_Enter(Q, 4);
    SeqQueue_Enter(Q, 5);
    SeqQueue_Print(Q);
    ElemType e;
    SeqQueue_Leave(Q, &e);
    printf("Leave: %d\n", e);
    SeqQueue_Leave(Q, &e);
    printf("Leave: %d\n", e);
    SeqQueue_Enter(Q, 4);
    SeqQueue_Enter(Q, 5);
    SeqQueue_Print(Q);
    SeqQueue_GetFront(Q, &e);
    printf("Front: %d\n", e);
    SeqQueue_Print(Q);
    printf("Length: %d\n", SeqQueue_GetLength(Q));
    printf("Is Empty: %d\n", SeqQueue_IsEmpty(Q));
    printf("Is Full: %d\n", SeqQueue_IsFull(Q));
    SeqQueue_Clear(Q);
    printf("Is Empty: %d\n", SeqQueue_IsEmpty(Q));
    SeqQueue_Print(Q);
    SeqQueue_Destroy(Q);
    return 0;
}