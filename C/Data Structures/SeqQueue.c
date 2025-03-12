/**
 * @FileName    :SeqQueue.c
 * @Date        :2025-03-11 15:50:31
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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define Maxsize 4
#define ElemType int

/* Sequence Queue (Circular)*/
typedef struct {
    ElemType *data;
    int front;
    int rear;
} *SeqQueue;

/* Initialize the Sequence Queue(Q) */
SeqQueue SeqQueue_Init() {
    SeqQueue Q = (SeqQueue)malloc(sizeof(SeqQueue));
    Q->data = (ElemType *)malloc(Maxsize * sizeof(ElemType));
    Q->front = Q->rear = 0;
    return Q;
}

/* Check if the Queue(Q) is empty [O(1)] */
bool SeqQueue_IsEmpty(SeqQueue Q) {
    return Q->front == Q->rear;
}

/* Check if the Queue(Q) is full [O(1)] */
bool SeqQueue_IsFull(SeqQueue Q) {
    return (Q->rear + 1) % Maxsize == Q->front;
}

/* Get the length of the Queue(Q) [O(1)] */
int SeqQueue_GetLength(SeqQueue Q) {
    return (Q->rear + Maxsize - Q->front) % Maxsize;
}

/* Enter the element(e) into the Queue(Q) [O(1)] */
bool SeqQueue_Enter(SeqQueue Q, ElemType e) {
    if (SeqQueue_IsFull(Q)) {
        printf("Queue is full!\n");
        return false;
    }
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % Maxsize;
    return true;
}

/* Delete the element(e) from the Queue(Q) [O(1)] */
bool SeqQueue_Delete(SeqQueue Q, ElemType *e) {
    if (SeqQueue_IsEmpty(Q)) {
        printf("Queue is empty!\n");
        return false;
    }
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % Maxsize;
    return true;
}

/* Get the front element(e) of the Queue(Q) [O(1)] */
bool SeqQueue_GetFront(SeqQueue Q, ElemType *e) {
    if (SeqQueue_IsEmpty(Q)) {
        printf("Queue is empty!\n");
        return false;
    }
    *e = Q->data[Q->front];
    return true;
}

/* Clear the Queue(Q) */
void SeqQueue_Clear(SeqQueue Q) {
    Q->front = Q->rear = 0;
}

/* Destroy the Queue(Q) */
void SeqQueue_Destroy(SeqQueue Q) {
    free(Q->data);
    free(Q);
}

/* Print the Queue(Q) [O(n)]*/
void SeqQueue_Print(SeqQueue Q) {
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
        i = (i + 1) % Maxsize;
    }
    printf("\n");
}

/* Driver Code */
int main() {
    SeqQueue Q = SeqQueue_Init();
    SeqQueue_Enter(Q, 1);
    SeqQueue_Enter(Q, 2);
    SeqQueue_Enter(Q, 3);
    SeqQueue_Enter(Q, 4);
    SeqQueue_Enter(Q, 5);
    SeqQueue_Print(Q);
    ElemType e;
    SeqQueue_Delete(Q, &e);
    printf("Delete: %d\n", e);
    SeqQueue_Delete(Q, &e);
    printf("Delete: %d\n", e);
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