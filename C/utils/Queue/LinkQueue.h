/**
 * @FileName    :LinkQueue.h
 * @Date        :2025-08-09 22:10:24
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Linked List Queue
 * @Description :
 *              :LinkQueue_Init: Initialize the Queue
 *              :LinkQueue_IsEmpty: Check if the Queue is empty [O(1)]
 *              :LinkQueue_GetLength: Get the length of the Queue [O(1)]
 *              :LinkQueue_Enter: Enter the element into the Queue [O(1)]
 *              :LinkQueue_Delete: Delete the element from the Queue [O(1)]
 *              :LinkQueue_GetFront: Get the front element of the Queue [O(1)]
 *              :LinkQueue_Clear: Clear the Queue
 *              :LinkQueue_Destroy: Destroy the Queue
 *              :LinkQueue_Print: Print the Queue [O(n)]
 */

#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include "../common.h"

/* Head Node of Linked List Queue */
typedef struct LinkQueue {
    int length;         // Length
    LNode *front;       // Front Node
    LNode *rear;        // Rear Node
} *LinkQueue;

/* Initialize the Linked List Queue(Q) */
LinkQueue LinkQueue_Init() {
    LinkQueue Q = (LinkQueue)malloc(sizeof(struct LinkQueue));
    Q->length = 0;
    Q->front = Q->rear = NULL;
    return Q;
}

/* Check if the Queue(Q) is empty [O(1)] */
bool LinkQueue_IsEmpty(LinkQueue Q) {
    assert(Q != NULL && "ERROR: When checking if the Queue is empty, the Queue is NULL!");
    return Q->front == NULL;
}

/* Get the length of the Queue(Q) [O(1)] */
int LinkQueue_GetLength(LinkQueue Q) {
    assert(Q != NULL && "ERROR: When getting the length of the Queue, the Queue is NULL!");
    return Q->length;
}

/* Enter the element(e) into the Queue(Q) [O(1)] */
bool LinkQueue_Enter(LinkQueue Q, ElemType e) {
    assert(Q != NULL && "ERROR: When entering the element into the Queue, the Queue is NULL!");
    LNode *newNode = (LNode *)malloc(sizeof(LNode));
    newNode->data = e;
    newNode->next = NULL;
    if (LinkQueue_IsEmpty(Q)) {
        Q->front = Q->rear = newNode;
    } else {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }
    Q->length++;
    return true;
}

/* Delete the element(e) from the Queue(Q) [O(1)] */
ElemType LinkQueue_Delete(LinkQueue Q) {
    assert(Q != NULL && "ERROR: When deleting the element from the Queue, the Queue is NULL!");
    assert(!LinkQueue_IsEmpty(Q) && "ERROR: When deleting the element from the Queue, the Queue is empty!");
    ElemType e = Q->front->data;
    LNode *delNode = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(delNode);
    Q->length--;
    return e;
}

/* Get the front element(e) of the Queue(Q) [O(1)] */
ElemType LinkQueue_GetFront(LinkQueue Q) {
    assert(Q != NULL && "ERROR: When getting the front element of the Queue, the Queue is NULL!");
    assert(!LinkQueue_IsEmpty(Q) && "ERROR: When getting the front element of the Queue, the Queue is empty!");
    ElemType e = Q->front->data;
    return e;
}

/* Clear the Queue(Q) */
bool LinkQueue_Clear(LinkQueue Q) {
    assert(Q != NULL && "ERROR: When clearing the Queue, the Queue is NULL!");
    if (LinkQueue_IsEmpty(Q)) {
        return true;
    }
    while (!LinkQueue_IsEmpty(Q)) {
        LinkQueue_Delete(Q);
    }
    return true;
}

/* Destroy the Queue(Q) */
LinkQueue LinkQueue_Destroy(LinkQueue Q) {
    assert(Q != NULL && "ERROR: When destroying the Queue, the Queue is NULL!");
    LinkQueue_Clear(Q);
    free(Q);
    return NULL;
}

/* Print the Queue(Q) [O(n)]*/
void LinkQueue_Print(LinkQueue Q) {
    assert(Q != NULL && "ERROR: When printing the Queue, the Queue is NULL!\n");
    printf("Linked List Queue: ");
    if (LinkQueue_IsEmpty(Q)) {
        printf("Queue is empty!\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 1; i <= Q->length; i++) {
        printf("%d    ", i);
    }
    printf("\n");
    printf("  Value: ");
    for (LNode *p = Q->front; p != NULL; p = p->next) {
        printf("%d    ", p->data);
    }
    printf("\n");
}

#endif // LINKQUEUE_H