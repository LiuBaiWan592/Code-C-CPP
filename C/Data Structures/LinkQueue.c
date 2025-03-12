/**
 * @FileName    :LinkQueue.c
 * @Date        :2025-03-12 10:38:20
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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

/* Linked List Node*/
typedef struct LNode {
    ElemType data;      // Data
    struct LNode *next; // Next Node
} LNode;

/* Head Node of Linked List Queue */
typedef struct {
    int length;         // Length
    LNode *front;       // Front Node
    LNode *rear;        // Rear Node
} *LinkQueue;

/* Initialize the Linked List Queue(Q) */
LinkQueue LinkQueue_Init() {
    LinkQueue Q = (LinkQueue)malloc(sizeof(LinkQueue));
    Q->front = Q->rear = NULL;
    Q->length = 0;
    return Q;
}

/* Check if the Queue(Q) is empty [O(1)] */
bool LinkQueue_IsEmpty(LinkQueue Q) {
    return Q->front == NULL;
}

/* Get the length of the Queue(Q) [O(1)] */
int LinkQueue_GetLength(LinkQueue Q) {
    return Q->length;
}

/* Enter the element(e) into the Queue(Q) [O(1)] */
bool LinkQueue_Enter(LinkQueue Q, ElemType e) {
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
bool LinkQueue_Delete(LinkQueue Q, ElemType *e) {
    if (LinkQueue_IsEmpty(Q)) {
        printf("Delete Error: Queue is Empty! Failed to Delete Element!\n");
        return false;
    }
    *e = Q->front->data;
    LNode *temp = Q->front;
    Q->front = Q->front->next;
    if (Q->front == NULL) {
        Q->rear = NULL;
    }
    free(temp);
    Q->length--;
    return true;
}

/* Get the front element(e) of the Queue(Q) [O(1)] */
bool LinkQueue_GetFront(LinkQueue Q, ElemType *e) {
    if (LinkQueue_IsEmpty(Q)) {
        printf("GetFront Error: Queue is Empty! Failed to Get Front Element!\n");
        return false;
    }
    *e = Q->front->data;
    return true;
}

/* Clear the Queue(Q) */
void LinkQueue_Clear(LinkQueue Q) {
    Q->front = Q->rear = 0;
    Q->length = 0;
    while (Q->front != NULL) {
        LNode *temp = Q->front;
        Q->front = Q->front->next;
        free(temp);
    }
}

/* Destroy the Queue(Q) */
void LinkQueue_Destroy(LinkQueue Q) {
    LinkQueue_Clear(Q);
    free(Q);
}

/* Print the Queue(Q) [O(n)]*/
void LinkQueue_Print(LinkQueue Q) {
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

/* Driver Code */
int main() {
    LinkQueue Q = LinkQueue_Init();
    LinkQueue_Enter(Q, 1);
    LinkQueue_Enter(Q, 2);
    LinkQueue_Enter(Q, 3);
    LinkQueue_Enter(Q, 4);
    LinkQueue_Enter(Q, 5);
    LinkQueue_Print(Q);
    ElemType e;
    LinkQueue_Delete(Q, &e);
    printf("Delete: %d\n", e);
    LinkQueue_Delete(Q, &e);
    printf("Delete: %d\n", e);
    LinkQueue_Enter(Q, 4);
    LinkQueue_Enter(Q, 5);
    LinkQueue_Print(Q);
    LinkQueue_GetFront(Q, &e);
    printf("Front: %d\n", e);
    LinkQueue_Print(Q);
    printf("Length: %d\n", LinkQueue_GetLength(Q));
    printf("Is Empty: %d\n", LinkQueue_IsEmpty(Q));
    LinkQueue_Clear(Q);
    printf("Is Empty: %d\n", LinkQueue_IsEmpty(Q));
    LinkQueue_Print(Q);
    LinkQueue_Destroy(Q);
    return 0;
}