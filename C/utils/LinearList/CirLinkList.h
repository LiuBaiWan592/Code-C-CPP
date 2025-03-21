/**
 * @FileName    :CirLinkList.h
 * @Date        :2025-03-07 20:25:55
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Circular Linked List
 * @Description :Circular List With a Header node outside the list
 *              :The indexes in all functions are the order of nodes starting from 1
 *              :LNode: Linked List Node
 *              :CirLinkList: Head Node of Linked List
 *              :CirLinkList_Init: Initialize the Linked List Head Node [O(1)]
 * Get Information:
 *              :CirLinkList_GetLength: Get the length of the List(L) [O(1)]
 *              :CirLinkList_IsEmpty: Check if the List(L) is empty [O(1)]
 *              :CirLinkList_GetData: Get the Data of the Node p [O(1)]
 *              :CirLinkList_GetNodeByPosition: Get the Node of the List(L) at the position i (i start from 1) [O(n)]
 *              :CirLinkList_GetNodeByData: Get the Node of the List(L) with the Data [O(n)]
 *              :CirLinkList_GetPositionByNode: Get the position i (i start from 1) of the Node p in the List(L) [O(n)]
 *              :CirLinkList_GetPositionByData: Get the position i (i start from 1) of the Data in the List(L) [O(n)]
 *              :CirLinkList_GetDataByPosition: Get the Data of the List(L) at the position i (i start from 1) [O(n)]
 * Head Insertion:
 *              :CirLinkList_HeadInsertNode: Insert a Node at the head of the List(L) [O(1)]
 *              :CirLinkList_HeadInsertData: (Head Insertion) Insert the Data into the List(L) at the front [O(1)]
 *              :CirLinkList_CreateByHeadInsert: Create CirLinkList(L) from Array(dataset) By Head Insert [O(n)]
 * Tail Insertion:
 *              :CirLinkList_TailInsertNode: Insert the Node p into the List(L) at the rear [O(1)]
 *              :CirLinkList_TailInsertData: (Tail Insertion) Insert the Data into the List(L) at the rear [O(1)]
 *              :CirLinkList_CreateByTailInsert: Create CirLinkList(L) from Array(dataset) By Tail Insert [O(n)]
 * Insert by Position:
 *              :CirLinkList_InsertNodeByPosition: Insert the Node p into the List(L) at the position i (i start from 1) [O(n)]
 *              :CirLinkList_InsertDataByPosition: Insert the Data into the List(L) at the position i (i start from 1) [O(n)]
 * Delete and Destroy:
 *              :CirLinkList_DeleteNodeByPosition: Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]
 *              :CirLinkList_DeleteNodeByData: Delete the Node p in the List(L) with the first occurrence of Data [O(n)]
 *              :CirLinkList_Destroy: Destroy the List(L) [O(n)]
 * Print:
 *              :CirLinkList_Print: Print the List(L) [O(n)]
 */

#ifndef CIRLINKLIST_H
#define CIRLINKLIST_H

#include "../common.h"

/* Head Node of Linked List */
typedef struct {
    int length;         // Length of Linked List
    LNode *front;        // Front Node
    LNode *rear;        // Rear Node
} *CirLinkList;

/* Initialize the Linked List Head Node [O(1)] */
CirLinkList CirLinkList_Init() {
    CirLinkList L = (CirLinkList)malloc(sizeof(CirLinkList));
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int CirLinkList_GetLength(CirLinkList L) {
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool CirLinkList_IsEmpty(CirLinkList L) {
    // return L->length == 0;
    return L->front == NULL;
}

/* Get the Data of the Node p [O(1)] */
bool CirLinkList_GetData(LNode *p, ElemType *data) {
    if (p == NULL) {
        printf("Get Data Error: Node is NULL\n");
        return false;
    }
    *data = p->data;
    return true;
}

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
LNode *CirLinkList_GetNodeByPosition(CirLinkList L, int i) {
    if (i < 1 || i > L->length) {
        printf("Get Node Error: Position %d is out of range\n", i);
        return NULL;
    }
    // p: Target Node; j: Current Position
    LNode *p = L->front;
    int j = 1;
    while (j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/* Get the Node of the List(L) with the Data [O(n)] */
LNode *CirLinkList_GetNodeByData(CirLinkList L, ElemType data) {
    LNode *p = L->front;
    int j = 1;
    while (j <= L->length && p->data != data) {
        p = p->next;
        j++;
    }
    if (j > L->length) {
        printf("Get Node Error: Data %d is not in the List\n", data);
        return NULL;
    }
    return p;
}

/* Get the position i (i start from 1) of the Node p in the List(L) [O(n)] */
int CirLinkList_GetPositionByNode(CirLinkList L, LNode *p) {
    LNode *q = L->front;
    int i = 1;
    while (i <= L->length && q != p) {
        q = q->next;
        i++;
    }
    if (i > L->length) {
        printf("Get Position Error: Node is not in the List\n");
        return 0;
    }
    return i;
}

/* Get the position i (i start from 1) of the Data in the List(L) [O(n)] */
int CirLinkList_GetPositionByData(CirLinkList L, ElemType data) {
    LNode *p = L->front;
    int i = 1;
    while (p != NULL && i <= L->length && p->data != data) {
        p = p->next;
        i++;
    }
    if (p == NULL || i > L->length) {
        printf("Get Position Error: Data %d is not in the List\n", data);
        return 0;
    }
    return i;
}

/* Get the Data of the List(L) at the position i (i start from 1) [O(n)] */
bool CirLinkList_GetDataByPosition(CirLinkList L, int i, ElemType *data) {
    LNode *p = CirLinkList_GetNodeByPosition(L, i);
    return CirLinkList_GetData(p, data);
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool CirLinkList_HeadInsertNode(CirLinkList L, LNode *p) {
    if (L->front == NULL) {
        p->next = p;
        L->front = p;
        L->rear = p;
    } else {
        p->next = L->front;
        L->front = p;
        L->rear->next = p;
    }
    L->length++;
    return true;
}

/* (Head Insertion) Insert the Data into the List(L) at the front [O(1)] */
bool CirLinkList_HeadInsertData(CirLinkList L, ElemType data) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return CirLinkList_HeadInsertNode(L, p);
}

/* Create CirLinkList(L) from Array(dataset) By Head Insert [O(n)] */
bool CirLinkList_CreateByHeadInsert(CirLinkList L, ElemType dataset[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        CirLinkList_HeadInsertData(L, dataset[i]);
    }
    return true;
}

/* Insert the Node p into the List(L) at the rear [O(1)] */
bool CirLinkList_TailInsertNode(CirLinkList L, LNode *p) {
    if (L->front == NULL) {
        p->next = p;
        L->front = p;
        L->rear = p;
    } else {
        p->next = L->rear->next;
        L->rear->next = p;
        L->rear = p;
    }
    L->length++;
    return true;
}

/* (Tail Insertion) Insert the Data into the List(L) at the rear [O(1)] */
bool CirLinkList_TailInsertData(CirLinkList L, ElemType data) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return CirLinkList_TailInsertNode(L, p);
}

/* Create CirLinkList(L) from Array(dataset) By Tail Insert [O(n)] */
bool CirLinkList_CreateByTailInsert(CirLinkList L, ElemType dataset[], int length) {
    for (int i = 0; i < length; i++) {
        CirLinkList_TailInsertData(L, dataset[i]);
    }
    return true;
}

/* Insert the Node p into the List(L) at the position i (i start from 1) [O(n)] */
bool CirLinkList_InsertNodeByPosition(CirLinkList L, int i, LNode *p) {
    if (i < 1 || i > L->length + 1) {
        printf("Insert Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    if (i == 1) {
        return CirLinkList_HeadInsertNode(L, p);
    }
    if (i == L->length + 1) {
        return CirLinkList_TailInsertNode(L, p);
    } else {
        // p: Target Node; q: Node before p
        LNode *q = L->front;
        int j = 1;
        while (j < i - 1) {
            q = q->next;
            j++;
        }
        p->next = q->next;
        q->next = p;
        L->length++;
        return true;
    }
}

/* Insert the Data into the List(L) at the position i (i start from 1) [O(n)] */
bool CirLinkList_InsertDataByPosition(CirLinkList L, int i, ElemType data) {
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return CirLinkList_InsertNodeByPosition(L, i, p);
}

/* =============================================================================== */

/* Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]  */
bool CirLinkList_DeleteNodeByPosition(CirLinkList L, int i, ElemType *del) {
    if (i < 1 || i > L->length) {
        printf("Delete Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    // q: Target Node; p: Node before q
    LNode *q;
    if (i == 1) {
        q = L->front;
        L->front = q->next;
        L->rear->next = L->front;
        if (L->length == 1) {
            L->front = NULL;
            L->rear = NULL;
        }
    } else {
        LNode *p = L->front;
        int j = 1;
        while (j < i - 1) {
            p = p->next;
            j++;
        }
        q = p->next;
        p->next = q->next;
        if (i == L->length) {
            L->rear = p;
        }
    }
    L->length--;
    *del = q->data;
    free(q);
    return true;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
bool CirLinkList_DeleteNodeByData(CirLinkList L, ElemType data, ElemType *del) {
    // q: Target Node; p: Node before q
    LNode *p = NULL, *q = L->front;
    int i = 1;
    while (q != NULL && i <= L->length && q->data != data) {
        p = q;
        q = q->next;
        i++;
    }
    if (q == NULL || i > L->length) {
        *del = -1;
        printf("Delete Data Error: Data (%d) not in the list!\n", data);
        return false;
    }
    if (q == L->front) {
        L->front = q->next;
        L->rear->next = L->front;
        if (L->length == 1) {
            L->front = NULL;
            L->rear = NULL;
        }
    } else {
        p->next = q->next;
        if (i == L->length) {
            L->rear = p;
        }
    }
    L->length--;
    *del = q->data;
    free(q);
    return true;
}

/* Destroy the List(L) [O(n)] */
bool CirLinkList_Destroy(CirLinkList L) {
    LNode *p = L->front, *q = NULL;
    int i = 1;
    while (p != NULL && i <= L->length) {
        q = p;
        p = p->next;
        free(q);
        i++;
    }
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return true;
}

/* =============================================================================== */

/* Print the List(L) [O(n)] */
void CirLinkList_Print(CirLinkList L) {
    LNode *p = L->front;
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
    int i = 1;
    while (p != NULL && i <= L->length) {
        printf("%d    ", p->data);
        p = p->next;
        i++;
    }
    printf("\n");
}

void print() {
    printf("================================================\n");
}

#endif // CIRLINKLIST_H