/**
 * @FileName    :LinkDeQueue.h
 * @Date        :2025-08-12 23:19:47
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Linked Double-Ended Queue
 * @Description :
 *              :LinkDeQueue_Init: Initialize the Queue
 *              :LinkDeQueue_IsEmpty: Check if the Queue is empty [O(1)]
 *              :LinkDeQueue_GetLength: Get the length of the Queue [O(1)]
 *              :LinkDeQueue_EnterFront: Enter the element into the Front of the Queue [O(1)]
 *              :LinkDeQueue_EnterRear: Enter the element into the Rear of the Queue [O(1)]
 *              :LinkDeQueue_DeleteFront: Delete the element from the Front of the Queue [O(1)]
 *              :LinkDeQueue_DeleteRear: Delete the element from the Rear of the Queue [O(1)]
 *              :LinkDeQueue_GetFront: Get the element from the Front of the Queue [O(1)]
 *              :LinkDeQueue_GetRear: Get the element from the Rear of the Queue [O(1)]
 *              :LinkDeQueue_Clear: Clear the Queue [O(n)]
 *              :LinkDeQueue_Destroy: Destroy the Queue [O(n)]
 *              :LinkDeQueue_Print: Print the Queue [O(n)]
 */

#ifndef LINKDEQUEUE_H
#define LINKDEQUEUE_H

#include "../common.h"

typedef struct LinkDeQueue{
    int length; // Length
    DNode *front, *rear; // Front Node and Rear Node
} *LinkDeQueue;

/* Initialize the Queue */
LinkDeQueue LinkDeQueue_Init() {
    LinkDeQueue Q = (LinkDeQueue)malloc(sizeof(struct LinkDeQueue));
    Q->length = 0;
    Q->front = Q->rear = NULL;
    return Q;
}

/* Check if the Queue is empty [O(1)] */
bool LinkDeQueue_IsEmpty(LinkDeQueue Q) {
    assert(Q != NULL && "ERROR: When checking if the Queue is empty, the Queue is NULL!");
    return Q->length == 0;
}

/* Get the length of the Queue [O(1)] */
int LinkDeQueue_GetLength(LinkDeQueue Q) {
    assert(Q != NULL && "ERROR: When getting the length of the Queue, the Queue is NULL!");
    return Q->length;
}

/* Enter the element into the Front of the Queue [O(1)] */
bool LinkDeQueue_EnterFront(LinkDeQueue Q, ElemType x) {
    assert(Q != NULL && "ERROR: When entering the element into the Front of the Queue, the Queue is NULL!");
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = x;
    if(LinkDeQueue_IsEmpty(Q)) {
        Q->front = Q->rear = newNode;
    }else{
        newNode->next = Q->front;
        Q->front->prior = newNode;
        Q->front = newNode;
    }
    Q->length++;
    return true;
}

/* Enter the element into the Rear of the Queue [O(1)] */
bool LinkDeQueue_EnterRear(LinkDeQueue Q, ElemType x) {
    assert(Q != NULL && "ERROR: When entering the element into the Rear of the Queue, the Queue is NULL!");
    DNode *newNode = (DNode *)malloc(sizeof(DNode));
    newNode->data = x;
    if(LinkDeQueue_IsEmpty(Q)) {
        Q->front = Q->rear = newNode;
    }else{
        Q->rear->next = newNode;
        newNode->prior = Q->rear;
        Q->rear = newNode;
    }
    Q->length++;
    return true;
}

/* Delete the element from the Front of the Queue [O(1)] */
ElemType LinkDeQueue_DeleteFront(LinkDeQueue Q) {
    assert(Q != NULL && "ERROR: When deleting the element from the Front of the Queue, the Queue is NULL!");
    assert(!LinkDeQueue_IsEmpty(Q) && "ERROR: When deleting the element from the Front of the Queue, the Queue is empty!");
    DNode *delNode = Q->front;
    ElemType e = delNode->data;
    Q->front = delNode->next;
    if(Q->front == NULL){
        Q->rear = NULL;
    }else{
        Q->front->prior = NULL;
    }
    free(delNode);
    Q->length--;
    return e;
}

/* Delete the element from the Rear of the Queue [O(1)] */
ElemType LinkDeQueue_DeleteRear(LinkDeQueue Q) {
    assert(Q != NULL && "ERROR: When deleting the element from the Rear of the Queue, the Queue is NULL!");
    assert(!LinkDeQueue_IsEmpty(Q) && "ERROR: When deleting the element from the Rear of the Queue, the Queue is empty!");
    DNode *delNode = Q->rear;
    ElemType e = delNode->data;
    Q->rear = delNode->prior;
    if(Q->rear == NULL){
        Q->front = NULL;
    }else{
        Q->rear->next = NULL;
    }
    free(delNode);
    Q->length--;
    return e;
}

/* Get the element from the Front of the Queue [O(1)] */
ElemType LinkDeQueue_GetFront(LinkDeQueue Q) {
    assert(Q != NULL && "ERROR: When getting the element from the Front of the Queue, the Queue is NULL!");
    assert(!LinkDeQueue_IsEmpty(Q) && "ERROR: When getting the element from the Front of the Queue, the Queue is empty!");
    ElemType e = Q->front->data;
    return e;
}

/* Get the element from the Rear of the Queue [O(1)] */
ElemType LinkDeQueue_GetRear(LinkDeQueue Q) {
    assert(Q != NULL && "ERROR: When getting the element from the Rear of the Queue, the Queue is NULL!");
    assert(!LinkDeQueue_IsEmpty(Q) && "ERROR: When getting the element from the Rear of the Queue, the Queue is empty!");
    ElemType e = Q->rear->data;
    return e;
}

/* Clear the Queue [O(n)] */
bool LinkDeQueue_Clear(LinkDeQueue Q) {
    assert(Q != NULL && "ERROR: When clearing the Queue, the Queue is NULL!");
    if (LinkDeQueue_IsEmpty(Q)) {
        return true;
    }
    while (!LinkDeQueue_IsEmpty(Q)) {
        LinkDeQueue_DeleteFront(Q);
    }
    return true;
}

/* Destroy the Queue [O(n)] */
bool LinkDeQueue_Destroy(LinkDeQueue Q) {
    LinkDeQueue_Clear(Q);
    return true;
}

/* Print the Queue [O(n)] */
void LinkDeQueue_Print(LinkDeQueue Q) {
    printf("Linked Double-Ended Queue: ");
    if (LinkDeQueue_IsEmpty(Q)) {
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
    DNode *p = Q->front;
    while (p != NULL) {
        printf("%d    ", p->data);
        p = p->next;
    }
    printf("\n");
}

#endif // LINKDEQUEUE_H