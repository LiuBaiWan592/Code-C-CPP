/**
 * @FileName    :SeqDeQueue.c
 * @Date        :2025-03-12 11:42:46
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequential Double-Ended Queue
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 10
#define ElemType int

typedef struct {
    ElemType *data;
    int front, rear;
    int length;
} *SeqDeQueue;

SeqDeQueue SeqDeQueue_Init() {
    SeqDeQueue Q = (SeqDeQueue)malloc(sizeof(SeqDeQueue));
    Q->data = (ElemType *)malloc(Maxsize * sizeof(ElemType));
    Q->front = Q->rear = 0;
    Q->length = 0;
    return Q;
}

bool SeqDeQueue_IsEmpty(SeqDeQueue Q) {
    return Q->front == Q->rear;
}

bool SeqDeQueue_IsFull(SeqDeQueue Q) {
    return (Q->rear + 1) % Maxsize == Q->front;
}

int SeqDeQueue_GetLength(SeqDeQueue Q) {
    return Q->length;
}

bool SeqDeQueue_EnterFront(SeqDeQueue Q, ElemType x) {
    if (SeqDeQueue_IsFull(Q)) {
        return false;
    }
    Q->front = (Q->front - 1 + Maxsize) % Maxsize;
    Q->data[Q->front] = x;
    Q->length++;
    return true;
}

bool SeqDeQueue_EnterRear(SeqDeQueue Q, ElemType x) {
    if (SeqDeQueue_IsFull(Q)) {
        return false;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % Maxsize;
    Q->length++;
}

bool SeqDeQueue_DeleteFront(SeqDeQueue Q, ElemType *x) {
    if (SeqDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % Maxsize;
    Q->length--;
    return true;
}

bool SeqDeQueue_DeleteRear(SeqDeQueue Q, ElemType *x) {
    if (SeqDeQueue_IsEmpty(Q)) {
        return false;
    }
    Q->rear = (Q->rear - 1 + Maxsize) % Maxsize;
    *x = Q->data[Q->rear];
    Q->length--;
    return true;
}

bool SeqDeQueue_GetFront(SeqDeQueue Q, ElemType *x) {
    if (SeqDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->data[Q->front];
    return true;
}

bool SeqDeQueue_GetRear(SeqDeQueue Q, ElemType *x) {
    if (SeqDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->data[(Q->rear - 1 + Maxsize) % Maxsize];
    return true;
}

void SeqDeQueue_Clear(SeqDeQueue Q) {
    Q->front = Q->rear = 0;
    Q->length = 0;
}

void SeqDeQueue_Destroy(SeqDeQueue Q) {
    free(Q->data);
    free(Q);
}

void SeqDeQueue_Print(SeqDeQueue Q) {
    printf("Sequential Double-Ended Queue: ");
    if (SeqDeQueue_IsEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 0; i < Q->length; i++) {
        printf("%d    ", i);
    }
    printf("\n");
    printf("  Value: ");
    for (int i = Q->front; i != Q->rear; i = (i + 1) % Maxsize) {
        printf("%d    ", Q->data[i]);
    }
    printf("\n");
}

int main() {
    SeqDeQueue Q = SeqDeQueue_Init();
    SeqDeQueue_Print(Q);
    SeqDeQueue_EnterFront(Q, 1);
    SeqDeQueue_EnterFront(Q, 2);
    SeqDeQueue_EnterFront(Q, 3);
    SeqDeQueue_Print(Q);
    SeqDeQueue_EnterRear(Q, 4);
    SeqDeQueue_EnterRear(Q, 5);
    SeqDeQueue_Print(Q);

    printf("Length: %d\n", SeqDeQueue_GetLength(Q));
    printf("Is empty: %d\n", SeqDeQueue_IsEmpty(Q));
    printf("Is full: %d\n", SeqDeQueue_IsFull(Q));

    ElemType x;
    SeqDeQueue_DeleteFront(Q, &x);
    printf("Delete front: %d\n", x);
    SeqDeQueue_DeleteRear(Q, &x);
    printf("Delete rear: %d\n", x);

    SeqDeQueue_GetFront(Q, &x);
    printf("Front: %d\n", x);
    SeqDeQueue_GetRear(Q, &x);
    printf("Rear: %d\n", x);
    
    SeqDeQueue_Clear(Q);
    SeqDeQueue_Print(Q);

    SeqDeQueue_Destroy(Q);
    return 0;
}