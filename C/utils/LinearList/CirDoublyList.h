/**
 * @FileName    :CirDoublyList.h
 * @Date        :2025-03-07 20:27:54
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Circular Doubly Linked List
 * @Description :Circular Doubly List With a Header node outside the list
 *              :The indexes in all functions are the order of nodes starting from 1
 *              :DNode: Linked List Node
 *              :CirDoublyList: Head Node of Linked List
 *              :CirDoublyList_Init: Initialize the Linked List Head Node [O(1)]
 * Get Information:
 *              :CirDoublyList_GetLength: Get the length of the List(L) [O(1)]
 *              :CirDoublyList_IsEmpty: Check if the List(L) is empty [O(1)]
 *              :CirDoublyList_GetData: Get the Data of the Node p [O(1)]
 *              :CirDoublyList_GetNodeByPosition: Get the Node of the List(L) at the position i (i start from 1) [O(n)]
 *              :CirDoublyList_GetNodeByData: Get the Node of the List(L) with the Data [O(n)]
 *              :CirDoublyList_GetPositionByNode: Get the position i (i start from 1) of the Node p in the List(L) [O(n)]
 *              :CirDoublyList_GetPositionByData: Get the position i (i start from 1) of the Data in the List(L) [O(n)]
 *              :CirDoublyList_GetDataByPosition: Get the Data of the List(L) at the position i (i start from 1) [O(n)]
 * Head Insertion:
 *              :CirDoublyList_HeadInsertNode: Insert a Node at the head of the List(L) [O(1)]
 *              :CirDoublyList_HeadInsertData: (Head Insertion) Insert the Data into the List(L) at the front [O(1)]
 *              :CirDoublyList_CreateByHeadInsert: Create CirDoublyList(L) from Array(dataset) By Head Insert [O(n)]
 * Tail Insertion:
 *              :CirDoublyList_TailInsertNode: Insert the Node p into the List(L) at the rear [O(1)]
 *              :CirDoublyList_TailInsertData: (Tail Insertion) Insert the Data into the List(L) at the rear [O(1)]
 *              :CirDoublyList_CreateByTailInsert: Create CirDoublyList(L) from Array(dataset) By Tail Insert [O(n)]
 * Insert by Position:
 *              :CirDoublyList_InsertNodeByPosition: Insert the Node p into the List(L) at the position i (i start from 1) [O(n)]
 *              :CirDoublyList_InsertDataByPosition: Insert the Data into the List(L) at the position i (i start from 1) [O(n)]
 * Delete and Destroy:
 *              :CirDoublyList_DeleteNodeByPosition: Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]
 *              :CirDoublyList_DeleteNodeByData: Delete the Node p in the List(L) with the first occurrence of Data [O(n)]
 *              :CirDoublyList_Destroy: Destroy the List(L) [O(n)]
 * Print:
 *              :CirDoublyList_Print: Print the List(L) [O(n)]
 */

#ifndef CIRDOUBLYLIST_H
#define CIRDOUBLYLIST_H

#include "../common.h"

/* Head Node of Linked List */
typedef struct CirDoublyList {
    int length;         // Length of Linked List
    DNode *front;        // Front Node
    DNode *rear;        // Rear Node
} *CirDoublyList;

/* Initialize the Linked List Head Node [O(1)] */
CirDoublyList CirDoublyList_Init() {
    CirDoublyList L = (CirDoublyList)malloc(sizeof(struct CirDoublyList));
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int CirDoublyList_GetLength(CirDoublyList L) {
    assert(L != NULL && "ERROR: When getting the length of the List, the List is NULL");
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool CirDoublyList_IsEmpty(CirDoublyList L) {
    assert(L != NULL && "ERROR: When checking if the List is empty, the List is NULL");
    // return L->length == 0;
    return L->front == NULL;
}

/* Get the Data of the Node p [O(1)] */
ElemType CirDoublyList_GetData(DNode *p) {
    assert(p != NULL && "ERROR: When getting the Data of the Node, the Node is NULL");
    ElemType data = p->data;
    return data;
}

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
DNode *CirDoublyList_GetNodeByPosition(CirDoublyList L, int i) {
    assert(L != NULL && "ERROR: When getting the Node of the List, the List is NULL");
    // Judge whether the index is within the valid range
    if (i < 1 || i > L->length) {
        printf("Get Node Error: Position %d is out of range\n", i);
        return NULL;
    }
    // p: Target Node; j: Current Position
    DNode *p = L->front;
    int j = 1;
    while (j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/* Get the Node of the List(L) with the Data [O(n)] */
DNode *CirDoublyList_GetNodeByData(CirDoublyList L, ElemType data) {
    assert(L != NULL && "ERROR: When getting the Node of the List, the List is NULL");
    DNode *p = L->front;
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
int CirDoublyList_GetPositionByNode(CirDoublyList L, DNode *p) {
    assert(L != NULL && "ERROR: When getting the position of the Node, the List is NULL");
    assert(p != NULL && "ERROR: When getting the position of the Node, the Node is NULL");
    DNode *q = L->front;
    int i = 1;
    while (i <= L->length && q != p) {
        q = q->next;
        i++;
    }
    if (i > L->length) {
        printf("Get Position Error: Node is not in the List\n");
        return -1;
    }
    return i;
}

/* Get the position i (i start from 1) of the Data in the List(L) [O(n)] */
int CirDoublyList_GetPositionByData(CirDoublyList L, ElemType data) {
    assert(L != NULL && "ERROR: When getting the position of the Data, the List is NULL");
    DNode *p = L->front;
    int i = 1;
    while (p != NULL && i <= L->length && p->data != data) {
        p = p->next;
        i++;
    }
    if (p == NULL || i > L->length) {
        printf("Get Position Error: Data %d is not in the List\n", data);
        return -1;
    }
    return i;
}

/* Get the Data of the List(L) at the position i (i start from 1) [O(n)] */
ElemType CirDoublyList_GetDataByPosition(CirDoublyList L, int i) {
    assert(L != NULL && "ERROR: When getting the data of the List, the List is NULL!");
    assert(i >= 1 && i <= L->length && "ERROR: When getting the data of the List, the position is out of range!");
    DNode *p = CirDoublyList_GetNodeByPosition(L, i);
    return CirDoublyList_GetData(p);
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool CirDoublyList_HeadInsertNode(CirDoublyList L, DNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
    if (L->front == NULL) {
        p->next = p;
        p->prior = p;
        L->front = p;
        L->rear = p;
    } else {
        p->next = L->front;
        L->front->prior = p;
        L->front = p;
        L->rear->next = L->front;
        L->front->prior = L->rear;
    }
    L->length++;
    return true;
}

/* (Head Insertion) Insert the Data into the List(L) at the front [O(1)] */
bool CirDoublyList_HeadInsertData(CirDoublyList L, ElemType data) {
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return CirDoublyList_HeadInsertNode(L, p);
}

/* Create CirDoublyList(L) from Array(dataset) By Head Insert [O(n)] */
bool CirDoublyList_CreateByHeadInsert(CirDoublyList L, ElemType dataset[], int length) {
    assert(L != NULL && "ERROR: When creating the List, the List is NULL!");
    assert(dataset != NULL && "ERROR: When creating the List, the Dataset is NULL!");
    for (int i = length - 1; i >= 0; i--) {
        if (CirDoublyList_HeadInsertData(L, dataset[i])) {
            continue;
        } else {
            printf("Create List Error: Create Node Failed\n");
            return false;
        }
    }
    return true;
}

/* Insert the Node p into the List(L) at the rear [O(1)] */
bool CirDoublyList_TailInsertNode(CirDoublyList L, DNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
    if (L->front == NULL) {
        p->next = p;
        p->prior = p;
        L->front = p;
        L->rear = p;
    } else {
        p->prior = L->rear;
        L->rear->next = p;
        L->rear = p;
        L->rear->next = L->front;
        L->front->prior = L->rear;
    }
    L->length++;
    return true;
}

/* (Tail Insertion) Insert the Data into the List(L) at the rear [O(1)] */
bool CirDoublyList_TailInsertData(CirDoublyList L, ElemType data) {
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return CirDoublyList_TailInsertNode(L, p);
}

/* Create CirDoublyList(L) from Array(dataset) By Tail Insert [O(n)] */
bool CirDoublyList_CreateByTailInsert(CirDoublyList L, ElemType dataset[], int length) {
    assert(L != NULL && "ERROR: When creating the List, the List is NULL!");
    assert(dataset != NULL && "ERROR: When creating the List, the Dataset is NULL!");
    for (int i = 0; i < length; i++) {
        if (CirDoublyList_TailInsertData(L, dataset[i])) {
            continue;
        } else {
            printf("Create List Error: Create Node Failed\n");
            return false;
        }
    }
    return true;
}

/* Insert the Node p into the List(L) at the position i (i start from 1) [O(n)] */
bool CirDoublyList_InsertNodeByPosition(CirDoublyList L, int i, DNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
    if (i < 1 || i > L->length + 1) {
        printf("Insert Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    if (i == 1) {
        return CirDoublyList_HeadInsertNode(L, p);
    }
    if (i == L->length + 1) {
        return CirDoublyList_TailInsertNode(L, p);
    } else {
        // p: Target Node; q: Node before p
        DNode *q = L->front;
        int j = 1;
        while (j < i - 1) {
            q = q->next;
            j++;
        }
        p->next = q->next;
        q->next->prior = p;
        q->next = p;
        p->prior = q;
        L->length++;
        return true;
    }
}

/* Insert the Data into the List(L) at the position i (i start from 1) [O(n)] */
bool CirDoublyList_InsertDataByPosition(CirDoublyList L, int i, ElemType data) {
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    if (i < 1 || i > L->length + 1) {
        printf("Insert Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return CirDoublyList_InsertNodeByPosition(L, i, p);
}

/* =============================================================================== */

/* Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]  */
ElemType CirDoublyList_DeleteNodeByPosition(CirDoublyList L, int i) {
    assert(L != NULL && "ERROR: When deleting the Node, the List is NULL!");
    assert(i >= 1 && i <= L->length && "ERROR: When deleting the Node, the Index out of range!");
    // q: Target Node; p: Node before q
    DNode *q;
    if (i == 1) {
        q = L->front;
        L->front = q->next;
        L->rear->next = L->front;
        if (L->length == 1) {
            L->front = NULL;
            L->rear = NULL;
        } else {
            L->front->prior = L->rear;
        }
    } else {
        DNode *p = L->front;
        int j = 1;
        while (j < i - 1) {
            p = p->next;
            j++;
        }
        q = p->next;
        p->next = q->next;
        if (i == L->length) {
            L->rear = p;
        } else {
            q->next->prior = p;
        }
    }
    L->length--;
    ElemType del = q->data;
    free(q);
    return del;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
ElemType CirDoublyList_DeleteNodeByData(CirDoublyList L, ElemType data) {
    assert(L != NULL && "ERROR: When deleting the Node, the List is NULL!");
    // q: Target Node; p: Node before q
    DNode *p = NULL, *q = L->front;
    int i = 1;
    while (q != NULL && i <= L->length && q->data != data) {
        p = q;
        q = q->next;
        i++;
    }
    assert(q != NULL && i <= L->length && "ERROR: When deleting the Node, the Data not in the List!"); // q == NULL means the Data not in the List
    if (q == L->front) {
        L->front = q->next;
        L->rear->next = L->front;
        if (L->length == 1) {
            L->front = NULL;
            L->rear = NULL;
        } else {
            L->front->prior = L->rear;
        }
    } else {
        p->next = q->next;
        if (i == L->length) {
            L->rear = p;
        } else {
            q->next->prior = p;
        }
    }
    L->length--;
    ElemType del = q->data;
    free(q);
    return del;
}

/* Destroy the List(L) [O(n)] */
CirDoublyList CirDoublyList_Destroy(CirDoublyList L) {
    assert(L != NULL && "ERROR: When destroying the List, the List is NULL!");
    DNode *p = L->front, *q = NULL;
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
    free(L);
    return NULL;
}

/* =============================================================================== */

/* Print the List(L) [O(n)] */
void CirDoublyList_Print(CirDoublyList L) {
    assert(L != NULL && "ERROR: When Printing the List, the List is NULL!");
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
    int i = 1;
    while (p != NULL && i <= L->length) {
        printf("%d    ", p->data);
        p = p->next;
        i++;
    }
    printf("\n");
}

#endif // CIRDOUBLYLIST_H