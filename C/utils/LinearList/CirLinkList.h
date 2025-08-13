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
typedef struct CirLinkList {
    int length;         // Length of Linked List
    LNode *front;        // Front Node
    LNode *rear;        // Rear Node
} *CirLinkList;

/* Initialize the Linked List Head Node [O(1)] */
CirLinkList CirLinkList_Init() {
    CirLinkList L = (CirLinkList)malloc(sizeof(struct CirLinkList));
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int CirLinkList_GetLength(CirLinkList L) {
    assert(L != NULL && "ERROR: When getting the length of the List, the List is NULL!");
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool CirLinkList_IsEmpty(CirLinkList L) {
    assert(L != NULL && "ERROR: When checking if the List is empty, the List is NULL!");
    // return L->length == 0;
    return L->front == NULL;
}

/* Get the Data of the Node p [O(1)] */
ElemType CirLinkList_GetData(LNode *p) {
    assert(p != NULL && "ERROR: When getting the Data of the Node, the Node is NULL!");
    ElemType data = p->data;
    return data;
}

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
LNode *CirLinkList_GetNodeByPosition(CirLinkList L, int i) {
    assert(L != NULL && "ERROR: When getting the Node of the List, the List is NULL!");
    // Judge whether the index is within the valid range
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
    assert(L != NULL && "ERROR: When getting the Node of the List, the List is NULL!");
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
    assert(L != NULL && "ERROR: When getting the position of the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When getting the position of the Node, the Node is NULL!");
    LNode *q = L->front;
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
int CirLinkList_GetPositionByData(CirLinkList L, ElemType data) {
    assert(L != NULL && "ERROR: When getting the position of the Data, the List is NULL!");
    LNode *p = L->front;
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
ElemType CirLinkList_GetDataByPosition(CirLinkList L, int i) {
    assert(L != NULL && "ERROR: When getting the data of the List, the List is NULL!");
    assert(i >= 1 && i <= L->length && "ERROR: When getting the data of the List, the position is out of range!");
    LNode *p = CirLinkList_GetNodeByPosition(L, i);
    return CirLinkList_GetData(p);
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool CirLinkList_HeadInsertNode(CirLinkList L, LNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node into the List, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node into the List, the Node is NULL!");
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
    assert(L != NULL && "ERROR: When inserting the Data into the List, the List is NULL!");
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return CirLinkList_HeadInsertNode(L, p);
}

/* Create CirLinkList(L) from Array(dataset) By Head Insert [O(n)] */
bool CirLinkList_CreateByHeadInsert(CirLinkList L, ElemType dataset[], int length) {
    assert(L != NULL && "ERROR: When creating the List, the List is NULL!");
    assert(dataset != NULL && "ERROR: When creating the List, the dataset is NULL!");
    for (int i = length - 1; i >= 0; i--) {
        if (CirLinkList_HeadInsertData(L, dataset[i])) {
            continue;
        } else {
            printf("Create List Error: Create Node %d failed\n", i);
            return false;
        }
    }
    return true;
}

/* Insert the Node p into the List(L) at the rear [O(1)] */
bool CirLinkList_TailInsertNode(CirLinkList L, LNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node into the List, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node into the List, the Node is NULL!");
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
    assert(L != NULL && "ERROR: When inserting the Data into the List, the List is NULL!");
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return CirLinkList_TailInsertNode(L, p);
}

/* Create CirLinkList(L) from Array(dataset) By Tail Insert [O(n)] */
bool CirLinkList_CreateByTailInsert(CirLinkList L, ElemType dataset[], int length) {
    assert(L != NULL && "ERROR: When creating the List, the List is NULL!");
    assert(dataset != NULL && "ERROR: When creating the List, the dataset is NULL!");
    for (int i = 0; i < length; i++) {
        if (CirLinkList_TailInsertData(L, dataset[i])) {
            continue;
        } else {
            printf("Create List Error: Create Node %d failed\n", i);
            return false;
        }
    }
    return true;
}

/* Insert the Node p into the List(L) at the position i (i start from 1) [O(n)] */
bool CirLinkList_InsertNodeByPosition(CirLinkList L, int i, LNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node into the List, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node into the List, the Node is NULL!");
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
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    if (i < 1 || i > L->length + 1) {
        printf("Insert Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return CirLinkList_InsertNodeByPosition(L, i, p);
}

/* =============================================================================== */

/* Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]  */
ElemType CirLinkList_DeleteNodeByPosition(CirLinkList L, int i) {
    assert(L != NULL && "ERROR: When deleting the Node from the List, the List is NULL!");
    assert(i >= 1 && i <= L->length && "ERROR: When deleting the Node from the List, the index is out of range!");
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
    ElemType del = q->data;
    free(q);
    return del;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
ElemType CirLinkList_DeleteNodeByData(CirLinkList L, ElemType data) {
    assert(L != NULL && "ERROR: When deleting the Node from the List, the List is NULL!");
    // q: Target Node; p: Node before q
    LNode *p = NULL, *q = L->front;
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
        }
    } else {
        p->next = q->next;
        if (i == L->length) {
            L->rear = p;
        }
    }
    L->length--;
    ElemType del = q->data;
    free(q);
    return del;
}

/* Destroy the List(L) [O(n)] */
CirLinkList CirLinkList_Destroy(CirLinkList L) {
    assert(L != NULL && "ERROR: When destroying the List, the List is NULL!");
    LNode *p = L->front, *q = NULL;
    int i = 1;
    while (p != NULL && i <= L->length) {
        q = p;
        p = p->next;
        free(q);
        i++;
    }
    free(L);
    return NULL;
}

/* =============================================================================== */

/* Print the List(L) [O(n)] */
void CirLinkList_Print(CirLinkList L) {
    assert(L != NULL && "ERROR: When Printing the List, the List is NULL!");
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

#endif // CIRLINKLIST_H