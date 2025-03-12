/**
 * @FileName    :SeqDeQueue.c
 * @Date        :2025-03-12 12:04:31
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequential Double-Ended Queue
 * @Description :
 *              :SeqDeQueue_Init: Initialize the Queue
 *              :SeqDeQueue_IsEmpty: Check if the Queue is empty [O(1)]
 *              :SeqDeQueue_IsFull: Check if the Queue is full [O(1)]
 *              :SeqDeQueue_GetLength: Get the length of the Queue [O(1)]
 *              :SeqDeQueue_EnterFront: Enter the element into the Front of the Queue [O(1)]
 *              :SeqDeQueue_EnterRear: Enter the element into the Rear of the Queue [O(1)]
 *              :SeqDeQueue_DeleteFront: Delete the element from the Front of the Queue [O(1)]
 *              :SeqDeQueue_DeleteRear: Delete the element from the Rear of the Queue [O(1)]
 *              :SeqDeQueue_GetFront: Get the element from the Front of the Queue [O(1)]
 *              :SeqDeQueue_GetRear: Get the element from the Rear of the Queue [O(1)]
 *              :SeqDeQueue_Clear: Clear the Queue
 *              :SeqDeQueue_Destroy: Destroy the Queue
 *              :SeqDeQueue_Print: Print the Queue [O(n)]
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

/* Initialize the Queue */
SeqDeQueue SeqDeQueue_Init() {
    SeqDeQueue Q = (SeqDeQueue)malloc(sizeof(SeqDeQueue));
    Q->data = (ElemType *)malloc(Maxsize * sizeof(ElemType));
    Q->front = Q->rear = 0;
    Q->length = 0;
    return Q;
}

/* Check if the Queue is empty [O(1)] */
bool SeqDeQueue_IsEmpty(SeqDeQueue Q) {
    return Q->front == Q->rear;
}

/* Check if the Queue is full [O(1)] */
bool SeqDeQueue_IsFull(SeqDeQueue Q) {
    return (Q->rear + 1) % Maxsize == Q->front;
}

/* Get the length of the Queue [O(1)] */
int SeqDeQueue_GetLength(SeqDeQueue Q) {
    return Q->length;
}

/* Enter the element into the Front of the Queue [O(1)] */
bool SeqDeQueue_EnterFront(SeqDeQueue Q, ElemType x) {
    if (SeqDeQueue_IsFull(Q)) {
        return false;
    }
    Q->front = (Q->front - 1 + Maxsize) % Maxsize;
    Q->data[Q->front] = x;
    Q->length++;
    return true;
}

/* Enter the element into the Rear of the Queue [O(1)] */
bool SeqDeQueue_EnterRear(SeqDeQueue Q, ElemType x) {
    if (SeqDeQueue_IsFull(Q)) {
        return false;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % Maxsize;
    Q->length++;
}

/* Delete the element from the Front of the Queue [O(1)] */
bool SeqDeQueue_DeleteFront(SeqDeQueue Q, ElemType *x) {
    if (SeqDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->data[Q->front];
    Q->front = (Q->front + 1) % Maxsize;
    Q->length--;
    return true;
}

/* Delete the element from the Rear of the Queue [O(1)] */
bool SeqDeQueue_DeleteRear(SeqDeQueue Q, ElemType *x) {
    if (SeqDeQueue_IsEmpty(Q)) {
        return false;
    }
    Q->rear = (Q->rear - 1 + Maxsize) % Maxsize;
    *x = Q->data[Q->rear];
    Q->length--;
    return true;
}

/* Get the element from the Front of the Queue [O(1)] */
bool SeqDeQueue_GetFront(SeqDeQueue Q, ElemType *x) {
    if (SeqDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->data[Q->front];
    return true;
}

/* Get the element from the Rear of the Queue [O(1)] */
bool SeqDeQueue_GetRear(SeqDeQueue Q, ElemType *x) {
    if (SeqDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->data[(Q->rear - 1 + Maxsize) % Maxsize];
    return true;
}

/* Clear the Queue */
void SeqDeQueue_Clear(SeqDeQueue Q) {
    Q->front = Q->rear = 0;
    Q->length = 0;
}

/* Destroy the Queue */
void SeqDeQueue_Destroy(SeqDeQueue Q) {
    free(Q->data);
    free(Q);
}

/* Print the Queue [O(n)] */
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