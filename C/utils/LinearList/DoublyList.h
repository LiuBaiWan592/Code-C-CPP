/**
 * @FileName    :DoublyList.h
 * @Date        :2025-03-07 20:23:41
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Doubly Linked List
 * @Description :Doubly List With Header node
 *              :The indexes in all functions are the order of nodes starting from 1
 *              :DNode: Doubly Linked List Node
 *              :DoublyList: Head Node of Doubly Linked List
 *              :DoublyList_Init: Initialize the Linked List Head Node [O(1)]
 * Get Information:
 *              :DoublyList_GetLength: Get the length of the DoublyList(L) [O(1)]
 *              :DoublyList_IsEmpty: Check if the DoublyList(L) is empty [O(1)]
 *              :DoublyList_GetData: Get the Data of the Node p [O(1)]
 *              :DoublyList_GetNodeByPosition: Get the Node of the DoublyList(L) at the position i (i start from 1) [O(n)]
 *              :DoublyList_GetNodeByData: Get the Node of the DoublyList(L) with the Data [O(n)]
 *              :DoublyList_GetPositionByNode: Get the position i (i start from 1) of the Node p in the DoublyList(L) [O(n)]
 *              :DoublyList_GetPositionByData: Get the position i (i start from 1) of the Data in the DoublyList(L) [O(n)]
 *              :DoublyList_GetDataByPosition: Get the Data of the DoublyList(L) at the position i (i start from 1) [O(n)]
 * Head Insertion:
 *              :DoublyList_HeadInsertNode: Insert a Node at the head of the DoublyList(L) [O(1)]
 *              :DoublyList_HeadInsertData: (Head Insertion) Insert the Data into the DoublyList(L) at the front [O(1)]
 *              :DoublyList_CreateByHeadInsert: Create DoublyList(L) from Array(dataset) By Head Insert [O(n)]
 * Tail Insertion:
 *              :DoublyList_TailInsertNode: Insert the Node p into the DoublyList(L) at the rear [O(1)]
 *              :DoublyList_TailInsertData: (Tail Insertion) Insert the Data into the DoublyList(L) at the rear [O(1)]
 *              :DoublyList_CreateByTailInsert: Create DoublyList(L) from Array(dataset) By Tail Insert [O(n)]
 * Insert by Position:
 *              :DoublyList_InsertNodeByPosition: Insert the Node p into the DoublyList(L) at the position i (i start from 1) [O(n)]
 *              :DoublyList_InsertDataByPosition: Insert the Data into the DoublyList(L) at the position i (i start from 1) [O(n)]
 * Delete and Destroy:
 *              :DoublyList_DeleteNodeByPosition: Delete the Node p in the DoublyList(L) at the position i (i start from 1) [O(n)]
 *              :DoublyList_DeleteNodeByData: Delete the Node p in the DoublyList(L) with the first occurrence of Data [O(n)]
 *              :DoublyList_Destroy: Destroy the DoublyList(L) [O(n)]
 * Print:
 *              :DoublyList_Print: Print the DoublyList(L) [O(n)]
 */

#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include "../common.h"

/* Head Node of Linked List */
typedef struct {
    int length;         // Length of Linked List
    DNode *front;        // Front Node
    DNode *rear;        // Rear Node
} *DoublyList;

/* Initialize the Linked List Head Node [O(1)] */
DoublyList DoublyList_Init() {
    DoublyList L = (DoublyList)malloc(sizeof(DoublyList));
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int DoublyList_GetLength(DoublyList L) {
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool DoublyList_IsEmpty(DoublyList L) {
    // return L->length == 0;
    return L->front == NULL;
}

/* Get the Data of the Node p [O(1)] */
bool DoublyList_GetData(DNode *p, ElemType *data) {
    if (p == NULL) {
        printf("Get Data Error: Node is NULL\n");
        return false;
    }
    *data = p->data;
    return true;
}

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
DNode *DoublyList_GetNodeByPosition(DoublyList L, int i) {
    if (i < 1 || i > L->length) {
        printf("Get Node Error: Position %d is out of range\n", i);
        return NULL;
    }
    // p: Target Node; j: Current Position
    DNode *p = L->front;
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/* Get the Node of the List(L) with the Data [O(n)] */
DNode *DoublyList_GetNodeByData(DoublyList L, ElemType data) {
    DNode *p = L->front;
    while (p != NULL && p->data != data) {
        p = p->next;
    }
    if (p == NULL) {
        printf("Get Node Error: Data %d is not in the List\n", data);
        return NULL;
    }
    return p;
}

/* Get the position i (i start from 1) of the Node p in the List(L) [O(n)] */
int DoublyList_GetPositionByNode(DoublyList L, DNode *p) {
    DNode *q = L->front;
    int i = 1;
    while (q != NULL && q != p) {
        q = q->next;
        i++;
    }
    if (q == NULL) {
        printf("Get Position Error: Node is not in the List\n");
        return 0;
    }
    return i;
}

/* Get the position i (i start from 1) of the Data in the List(L) [O(n)] */
int DoublyList_GetPositionByData(DoublyList L, ElemType data) {
    DNode *p = L->front;
    int i = 1;
    while (p != NULL && p->data != data) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Get Position Error: Data %d is not in the List\n", data);
        return 0;
    }
    return i;
}

/* Get the Data of the List(L) at the position i (i start from 1) [O(n)] */
bool DoublyList_GetDataByPosition(DoublyList L, int i, ElemType *data) {
    DNode *p = DoublyList_GetNodeByPosition(L, i);
    return DoublyList_GetData(p, data);
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool DoublyList_HeadInsertNode(DoublyList L, DNode *p) {
    if (L->front == NULL) {
        p->next = L->front;
        p->prior = NULL;
        L->front = p;
        L->rear = p;
    } else {
        p->next = L->front;
        L->front->prior = p;
        p->prior = NULL;
        L->front = p;
    }
    L->length++;
    return true;
}

/* (Head Insertion) Insert the Data into the List(L) at the front [O(1)] */
bool DoublyList_HeadInsertData(DoublyList L, ElemType data) {
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return DoublyList_HeadInsertNode(L, p);
}

/* Create DoublyList(L) from Array(dataset) By Head Insert [O(n)] */
bool DoublyList_CreateByHeadInsert(DoublyList L, ElemType dataset[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        DoublyList_HeadInsertData(L, dataset[i]);
    }
    return true;
}

/* Insert the Node p into the List(L) at the rear [O(1)] */
bool DoublyList_TailInsertNode(DoublyList L, DNode *p) {
    if (L->front == NULL) {
        p->next = L->front;
        p->prior = NULL;
        L->front = p;
        L->rear = p;
    } else {
        p->next = L->rear->next;
        p->prior = L->rear;
        L->rear->next = p;
        L->rear = p;
    }
    L->length++;
    return true;
}

/* (Tail Insertion) Insert the Data into the List(L) at the rear [O(1)] */
bool DoublyList_TailInsertData(DoublyList L, ElemType data) {
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return DoublyList_TailInsertNode(L, p);
}

/* Create DoublyList(L) from Array(dataset) By Tail Insert [O(n)] */
bool DoublyList_CreateByTailInsert(DoublyList L, ElemType dataset[], int length) {
    for (int i = 0; i < length; i++) {
        DoublyList_TailInsertData(L, dataset[i]);
    }
    return true;
}

/* Insert the Node p into the List(L) at the position i (i start from 1) [O(n)] */
bool DoublyList_InsertNodeByPosition(DoublyList L, int i, DNode *p) {
    if (i < 1 || i > L->length + 1) {
        printf("Insert Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    if (i == 1) {
        return DoublyList_HeadInsertNode(L, p);
    }
    if (i == L->length + 1) {
        return DoublyList_TailInsertNode(L, p);
    } else {
        // p: Target Node; q: Node before p
        DNode *q = L->front;
        int j = 1;
        while (q != NULL && j < i - 1) {
            q = q->next;
            j++;
        }
        p->next = q->next;
        p->prior = q;
        q->next->prior = p;
        q->next = p;
        L->length++;
        return true;
    }
}

/* Insert the Data into the List(L) at the position i (i start from 1) [O(n)] */
bool DoublyList_InsertDataByPosition(DoublyList L, int i, ElemType data) {
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return DoublyList_InsertNodeByPosition(L, i, p);
}

/* =============================================================================== */

/* Reverse the List(L) [O(n)] */
bool DoublyList_Reverse(DoublyList L) {
    if (L->front == NULL || L->front == L->rear) {
        printf("Reverse Warring: Empty List or Only One Node in the List!\n");
        return false;
    }
    DNode *p = L->front;
    DNode *q = L->rear;
    while (p != q && q->next != p) {
        ElemType temp = p->data;
        p->data = q->data;
        q->data = temp;
        p = p->next;
        q = q->prior;
    }
    return true;
}

/* Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]  */
bool DoublyList_DeleteNodeByPosition(DoublyList L, int i, ElemType *del) {
    if (i < 1 || i > L->length) {
        *del = -1;
        printf("Delete Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    // q: Target Node; p: Node before q
    DNode *q;
    if (i == 1) {
        q = L->front;
        L->front = q->next;
        if (L->front == NULL) {
            L->rear = NULL;
        } else {
            L->front->prior = NULL;
        }
    } else {
        DNode *p = L->front;
        int j = 1;
        while (p != NULL && j < i - 1) {
            p = p->next;
            j++;
        }
        q = p->next;
        p->next = q->next;
        if (p->next == NULL) {
            L->rear = p;
        } else {
            p->next->prior = p;
        }
    }
    L->length--;
    *del = q->data;
    free(q);
    return true;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
bool DoublyList_DeleteNodeByData(DoublyList L, ElemType data, ElemType *del) {
    // q: Target Node; p: Node before q
    DNode *p = NULL, *q = L->front;
    while (q != NULL && q->data != data) {
        p = q;
        q = q->next;
    }
    if (q == NULL) {
        *del = -1;
        printf("Delete Data Error: Data (%d) not in the list!\n", data);
        return false;
    }
    if (q == L->front) {
        L->front = q->next;
        if (L->front == NULL) {
            L->rear = NULL;
        } else {
            L->front->prior = NULL;
        }
    } else {
        p->next = q->next;
        if (p->next == NULL) {
            L->rear = p;
        } else {
            p->next->prior = p;
        }
    }
    L->length--;
    *del = q->data;
    free(q);
    return true;
}

/* Destroy the List(L) [O(n)] */
bool DoublyList_Destroy(DoublyList L) {
    DNode *p = L->front, *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return true;
}

/* =============================================================================== */

/* Print the List(L) [O(n)] */
void DoublyList_Print(DoublyList L) {
    DNode *p = L->front;
    printf("Linked List: ");
    if (p == NULL) {
        printf("Empty List!\n");
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 1; i <= L->length; i++) {
        printf("%d    ", i);
    }
    printf("\n");
    printf("  Value: ");
    while (p != NULL) {
        printf("%d    ", p->data);
        p = p->next;
    }
    printf("\n");
}

#endif // DOUBLYLIST_H