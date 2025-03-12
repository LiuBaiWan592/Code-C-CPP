/**
 * @FileName    :LinkQueue.c
 * @Date        :2025-03-11 15:49:59
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Linked List Queue
 * @Description :
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
    LNode *front;       // Front Node
    LNode *rear;        // Rear Node
} *LinkQueue;

LinkQueue LinkQueue_Init() {
    LinkQueue Q = (LinkQueue)malloc(sizeof(LinkQueue));
    Q->front = Q->rear = (LNode *)malloc(sizeof(LNode));
    Q->front->next = NULL;
    return Q;
}

bool LinkQueue_IsEmpty(LinkQueue Q) {
    if (Q->front == Q->rear)
        return true;
    else
        return false;
}

void LinkQueue_EnQueue(LinkQueue Q, ElemType e) {
    LNode *s = (LNode *)malloc(sizeof(LNode));
    s->data = e;
    s->next = NULL;
    Q->rear->next = s;
    Q->rear = s;
}

bool LinkQueue_DeQueue(LinkQueue Q, ElemType *e) {
    if (Q->front == Q->rear)
        return false;
    LNode *p = Q->front->next;
    *e = p->data;
    Q->front->next = p->next;
    if (Q->rear == p)
        Q->rear = Q->front;
    free(p);
    return true;
}

int main() {
    LinkQueue Q = LinkQueue_Init();
    if (LinkQueue_IsEmpty(Q))
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
    LinkQueue_EnQueue(Q, 1);
    LinkQueue_EnQueue(Q, 2);
    LinkQueue_EnQueue(Q, 3);
    ElemType e;
    LinkQueue_DeQueue(Q, &e);
    printf("DeQueue: %d\n", e);
    if (LinkQueue_IsEmpty(Q))
        printf("Queue is empty.\n");
    else
        printf("Queue is not empty.\n");
    free(Q->front);
    free(Q);

    return 0;
}