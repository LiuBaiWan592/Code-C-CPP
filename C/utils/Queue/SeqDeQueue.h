/**
 * @FileName    :SeqDeQueue.h
 * @Date        :2025-08-11 23:12:19
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

#ifndef SEQDEQUEUE_H
#define SEQDEQUEUE_H

#include "../common.h"

typedef struct SeqDeQueue{
    ElemType *data;
    int front, rear;
    int length;
    int capacity;
} *SeqDeQueue;

/* Initialize the Queue */
SeqDeQueue SeqDeQueue_Init(int capacity) {
    SeqDeQueue Q = (SeqDeQueue)malloc(sizeof(struct SeqDeQueue));
    Q->data = (ElemType *)malloc(capacity * sizeof(ElemType));
    Q->front = Q->rear = 0;
    Q->length = 0;
    Q->capacity = capacity;
    return Q;
}

/* Check if the Queue is empty [O(1)] */
bool SeqDeQueue_IsEmpty(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When checking if the Queue is empty, the Queue is NULL!");
    return Q->front == Q->rear;
}

/* Check if the Queue is full [O(1)] */
bool SeqDeQueue_IsFull(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When checking if the Queue is full, the Queue is NULL!");
    return (Q->rear + 1) % Q->capacity == Q->front;
}

/* Get the length of the Queue [O(1)] */
int SeqDeQueue_GetLength(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When getting the length of the Queue, the Queue is NULL!");
    return Q->length;
}

/* Enter the element into the Front of the Queue [O(1)] */
bool SeqDeQueue_EnterFront(SeqDeQueue Q, ElemType x) {
    assert(Q != NULL && "ERROR: When entering the element into the Front of the Queue, the Queue is NULL!");
    if (SeqDeQueue_IsFull(Q)) {
        printf("Queue is full!\n");
        return false;
    }
    Q->front = (Q->front - 1 + Q->capacity) % Q->capacity;
    Q->data[Q->front] = x;
    Q->length++;
    return true;
}

/* Enter the element into the Rear of the Queue [O(1)] */
bool SeqDeQueue_EnterRear(SeqDeQueue Q, ElemType x) {
    assert(Q != NULL && "ERROR: When entering the element into the Rear of the Queue, the Queue is NULL!");
    if (SeqDeQueue_IsFull(Q)) {
        printf("Queue is full!\n");
        return false;
    }
    Q->data[Q->rear] = x;
    Q->rear = (Q->rear + 1) % Q->capacity;
    Q->length++;
}

/* Delete the element from the Front of the Queue [O(1)] */
ElemType SeqDeQueue_DeleteFront(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When deleting the element from the Front of the Queue, the Queue is NULL!");
    assert(!SeqDeQueue_IsEmpty(Q) && "ERROR: When deleting the element from the Front of the Queue, the Queue is empty!");
    ElemType e = Q->data[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    Q->length--;
    return e;
}

/* Delete the element from the Rear of the Queue [O(1)] */
ElemType SeqDeQueue_DeleteRear(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When deleting the element from the Rear of the Queue, the Queue is NULL!");
    assert(!SeqDeQueue_IsEmpty(Q) && "ERROR: When deleting the element from the Rear of the Queue, the Queue is empty!");
    Q->rear = (Q->rear - 1 + Q->capacity) % Q->capacity;
    ElemType e = Q->data[Q->rear];
    Q->length--;
    return e;
}

/* Get the element from the Front of the Queue [O(1)] */
ElemType SeqDeQueue_GetFront(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When getting the element from the Front of the Queue, the Queue is NULL!");
    assert(!SeqDeQueue_IsEmpty(Q) && "ERROR: When getting the element from the Front of the Queue, the Queue is empty!");
    ElemType e = Q->data[Q->front];
    return e;
}

/* Get the element from the Rear of the Queue [O(1)] */
ElemType SeqDeQueue_GetRear(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When getting the element from the Rear of the Queue, the Queue is NULL!");
    assert(!SeqDeQueue_IsEmpty(Q) && "ERROR: When getting the element from the Rear of the Queue, the Queue is empty!");
    ElemType e = Q->data[(Q->rear - 1 + Q->capacity) % Q->capacity];
    return e;
}

/* Clear the Queue */
bool SeqDeQueue_Clear(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When clearing the Queue, the Queue is NULL!");
    if(Q == NULL){
        return false;
    }
    Q->front = Q->rear = 0;
    Q->length = 0;
    return true;
}

/* Destroy the Queue */
bool SeqDeQueue_Destroy(SeqDeQueue Q) {
    assert(Q != NULL && "ERROR: When destroying the Queue, the Queue is NULL!");
    if(Q == NULL){
        return false;
    }
    free(Q->data);
    Q->front = Q->rear = 0;
    Q->length = 0;
    Q->capacity = 0;
    return true;
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
    for (int i = Q->front; i != Q->rear; i = (i + 1) % Q->capacity) {
        printf("%d    ", Q->data[i]);
    }
    printf("\n");
}


#endif // SEQDEQUEUE_H