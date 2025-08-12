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

typedef struct {
    int length; // Length
    DNode *front, *rear; // Front Node and Rear Node
} *LinkDeQueue;

/* Initialize the Queue */
LinkDeQueue LinkDeQueue_Init() {
    LinkDeQueue Q = (LinkDeQueue)malloc(sizeof(LinkDeQueue));
    Q->front = Q->rear = 0;
    Q->length = 0;
    return Q;
}

/* Check if the Queue is empty [O(1)] */
bool LinkDeQueue_IsEmpty(LinkDeQueue Q) {
    return Q->length == 0;
}

/* Get the length of the Queue [O(1)] */
int LinkDeQueue_GetLength(LinkDeQueue Q) {
    return Q->length;
}

/* Enter the element into the Front of the Queue [O(1)] */
bool LinkDeQueue_EnterFront(LinkDeQueue Q, ElemType x) {
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = x;
    if(LinkDeQueue_IsEmpty(Q)) {
        Q->front = Q->rear = p;
    }else{
        p->next = Q->front;
        Q->front->prior = p;
        Q->front = p;
    }
    Q->length++;
    return true;
}

/* Enter the element into the Rear of the Queue [O(1)] */
bool LinkDeQueue_EnterRear(LinkDeQueue Q, ElemType x) {
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = x;
    if(LinkDeQueue_IsEmpty(Q)) {
        Q->front = Q->rear = p;
    }else{
        Q->rear->next = p;
        p->prior = Q->rear;
        Q->rear = p;
    }
    Q->length++;
    return true;
}

/* Delete the element from the Front of the Queue [O(1)] */
bool LinkDeQueue_DeleteFront(LinkDeQueue Q, ElemType *x) {
    if (LinkDeQueue_IsEmpty(Q)) {
        return false;
    }
    DNode *p = Q->front;
    *x = p->data;
    Q->front = p->next;
    if(Q->front == NULL){
        Q->rear = NULL;
    }else{
        Q->front->prior = NULL;
    }
    free(p);
    Q->length--;
    return true;
}

/* Delete the element from the Rear of the Queue [O(1)] */
bool LinkDeQueue_DeleteRear(LinkDeQueue Q, ElemType *x) {
    if (LinkDeQueue_IsEmpty(Q)) {
        return false;
    }
    DNode *p = Q->rear;
    *x = p->data;
    Q->rear = p->prior;
    if(Q->rear == NULL){
        Q->front = NULL;
    }else{
        Q->rear->next = NULL;
    }
    free(p);
    Q->length--;
    return true;
}

/* Get the element from the Front of the Queue [O(1)] */
bool LinkDeQueue_GetFront(LinkDeQueue Q, ElemType *x) {
    if (LinkDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->front->data;
    return true;
}

/* Get the element from the Rear of the Queue [O(1)] */
bool LinkDeQueue_GetRear(LinkDeQueue Q, ElemType *x) {
    if (LinkDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->rear->data;
    return true;
}

/* Clear the Queue [O(n)] */
void LinkDeQueue_Clear(LinkDeQueue Q) {
    while (!LinkDeQueue_IsEmpty(Q)) {
        ElemType x;
        LinkDeQueue_DeleteFront(Q, &x);
    }
}

/* Destroy the Queue [O(n)] */
void LinkDeQueue_Destroy(LinkDeQueue Q) {
    while (!LinkDeQueue_IsEmpty(Q)) {
        ElemType x;
        LinkDeQueue_DeleteFront(Q, &x);
    }
    free(Q);
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