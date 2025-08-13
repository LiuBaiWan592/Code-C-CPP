/**
 * @FileName    :SeqQueue.h
 * @Date        :2025-08-07 00:06:47
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence Queue (Circular)
 * @Description :Sequential Storage Loop Queue
 *              :SeqQueue_Init: Initialize the Queue
 *              :SeqQueue_IsEmpty: Check if the Queue is empty [O(1)]
 *              :SeqQueue_IsFull: Check if the Queue is full [O(1)]
 *              :SeqQueue_GetLength: Get the length of the Queue [O(1)]
 *              :SeqQueue_Enter: Enter the element into the Queue [O(1)]
 *              :SeqQueue_Delete: Delete the element from the Queue [O(1)]
 *              :SeqQueue_GetFront: Get the front element of the Queue [O(1)]
 *              :SeqQueue_Clear: Clear the Queue
 *              :SeqQueue_Destroy: Destroy the Queue
 *              :SeqQueue_Print: Print the Queue [O(n)]
 */

#ifndef __SEQQUEUE_H_
#define __SEQQUEUE_H_

#include "../common.h"

/* Sequence Queue (Circular)*/
typedef struct SeqQueue{
    ElemType *data;
    int front;
    int rear;
    int capacity;
} *SeqQueue;

/* Initialize the Sequence Queue(Q) */
SeqQueue SeqQueue_Init(int capacity) {
    SeqQueue Q = (SeqQueue)malloc(sizeof(struct SeqQueue));
    Q->data = (ElemType *)malloc(capacity * sizeof(ElemType));
    Q->front = Q->rear = 0;
    Q->capacity = capacity;
    return Q;
}

/* Check if the Queue(Q) is empty [O(1)] */
bool SeqQueue_IsEmpty(SeqQueue Q) {
    assert(Q != NULL && "ERROR: When checking if the Queue is empty, the Queue is NULL!");
    return Q->front == Q->rear;
}

/* Check if the Queue(Q) is full [O(1)] */
bool SeqQueue_IsFull(SeqQueue Q) {
    assert(Q != NULL && "ERROR: When checking if the Queue is full, the Queue is NULL!");
    return (Q->rear + 1) % Q->capacity == Q->front;
}

/* Get the length of the Queue(Q) [O(1)] */
int SeqQueue_GetLength(SeqQueue Q) {
    assert(Q != NULL && "ERROR: When getting the length of the Queue, the Queue is NULL!");
    return (Q->rear + Q->capacity - Q->front) % Q->capacity;
}

/* Enter the element(e) into the Queue(Q) [O(1)] */
bool SeqQueue_Enter(SeqQueue Q, ElemType e) {
    assert(Q != NULL && "ERROR: When entering the element into the Queue, the Queue is NULL!");
    if (SeqQueue_IsFull(Q)) {
        printf("Queue is full!\n");
        return false;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % Q->capacity;
    return true;
}

/* Delete the element(e) from the Queue(Q) [O(1)] */
ElemType SeqQueue_Delete(SeqQueue Q) {
    assert(Q != NULL && "ERROR: When deleting the element from the Queue, the Queue is NULL!");
    assert(!SeqQueue_IsEmpty(Q) && "ERROR: When deleting the element from the Queue, the Queue is empty!");
    ElemType e = Q->data[Q->front];
    Q->front = (Q->front + 1) % Q->capacity;
    return e;
}

/* Get the front element(e) of the Queue(Q) [O(1)] */
ElemType SeqQueue_GetFront(SeqQueue Q) {
    assert(Q != NULL && "ERROR: When getting the front element of the Queue, the Queue is NULL!");
    assert(!SeqQueue_IsEmpty(Q) && "ERROR: When getting the front element of the Queue, the Queue is empty!");
    ElemType e = Q->data[Q->front];
    return e;
}

/* Clear the Queue(Q) */
bool SeqQueue_Clear(SeqQueue Q) {
    assert(Q != NULL && "ERROR: When clearing the Queue, the Queue is NULL!");
    for(int i = 0; i < Q->capacity; i++){
        Q->data[i] = (ElemType)0;
    }
    Q->front = Q->rear = 0;
    return true;
}

/* Destroy the Queue(Q) */
SeqQueue SeqQueue_Destroy(SeqQueue Q) {
    assert(Q != NULL && "ERROR: When destroying the Queue, the Queue is NULL!");
    free(Q->data);
    free(Q);
    return NULL;
}

/* Print the Queue(Q) [O(n)]*/
void SeqQueue_Print(SeqQueue Q) {
    assert(Q != NULL && "ERROR: When printing the Queue, the Queue is NULL!\n");
    printf("Sequence Queue: ");
    if (SeqQueue_IsEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    int length = SeqQueue_GetLength(Q);
    for (int i = 0; i < length; i++) {
        printf("%d    ", i);
    }
    printf("\n");
    printf("  Value: ");
    int i = Q->front;
    while (i != Q->rear) {
        printf("%d    ", Q->data[i]);
        i = (i + 1) % Q->capacity;
    }
    printf("\n");
}

#endif // __SEQQUEUE_H_