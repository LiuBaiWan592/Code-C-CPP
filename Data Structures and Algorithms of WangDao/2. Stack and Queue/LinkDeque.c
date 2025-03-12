/**
 * @FileName    :LinkDeque.c
 * @Date        :2025-03-12 12:10:24
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Linked Double-Ended Queue
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct DNode {
    ElemType data;      // Data
    struct DNode *prior, *next; // Prior Node and Next Node
} DNode;

typedef struct {
    int length; // Length
    DNode *front, *rear; // Front Node and Rear Node
} *LinkDeQueue;

LinkDeQueue LinkDeQueue_Init() {
    LinkDeQueue Q = (LinkDeQueue)malloc(sizeof(LinkDeQueue));
    Q->front = Q->rear = 0;
    Q->length = 0;
    return Q;
}

bool LinkDeQueue_IsEmpty(LinkDeQueue Q) {
    return Q->length == 0;
}

int LinkDeQueue_GetLength(LinkDeQueue Q) {
    return Q->length;
}

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

bool LinkDeQueue_GetFront(LinkDeQueue Q, ElemType *x) {
    if (LinkDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->front->data;
    return true;
}

bool LinkDeQueue_GetRear(LinkDeQueue Q, ElemType *x) {
    if (LinkDeQueue_IsEmpty(Q)) {
        return false;
    }
    *x = Q->rear->data;
    return true;
}

void LinkDeQueue_Clear(LinkDeQueue Q) {
    while (!LinkDeQueue_IsEmpty(Q)) {
        ElemType x;
        LinkDeQueue_DeleteFront(Q, &x);
    }
}

void LinkDeQueue_Destroy(LinkDeQueue Q) {
    while (!LinkDeQueue_IsEmpty(Q)) {
        ElemType x;
        LinkDeQueue_DeleteFront(Q, &x);
    }
    free(Q);
}

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

int main() {
    LinkDeQueue Q = LinkDeQueue_Init();
    LinkDeQueue_Print(Q);
    LinkDeQueue_EnterFront(Q, 1);
    LinkDeQueue_EnterFront(Q, 2);
    LinkDeQueue_EnterFront(Q, 3);
    LinkDeQueue_Print(Q);
    LinkDeQueue_EnterRear(Q, 4);
    LinkDeQueue_EnterRear(Q, 5);
    LinkDeQueue_Print(Q);

    printf("Length: %d\n", LinkDeQueue_GetLength(Q));
    printf("Is empty: %d\n", LinkDeQueue_IsEmpty(Q));

    ElemType x;
    LinkDeQueue_DeleteFront(Q, &x);
    printf("Delete front: %d\n", x);
    LinkDeQueue_DeleteRear(Q, &x);
    printf("Delete rear: %d\n", x);

    LinkDeQueue_GetFront(Q, &x);
    printf("Front: %d\n", x);
    LinkDeQueue_GetRear(Q, &x);
    printf("Rear: %d\n", x);
    
    LinkDeQueue_Clear(Q);
    LinkDeQueue_Print(Q);

    LinkDeQueue_Destroy(Q);
    return 0;
}