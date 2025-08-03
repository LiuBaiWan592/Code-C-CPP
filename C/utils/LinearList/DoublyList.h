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
 * Reverse:
 *              :LinkList_Reverse: Reverse the List(L) [O(n)]
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
typedef struct DoublyList {
    int length;         // Length of Linked List
    DNode *front;        // Front Node
    DNode *rear;        // Rear Node
} *DoublyList;

/* Initialize the Linked List Head Node [O(1)] */
DoublyList DoublyList_Init() {
    DoublyList L = (DoublyList)malloc(sizeof(struct DoublyList));
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int DoublyList_GetLength(DoublyList L) {
    assert(L != NULL && "ERROR: When getting the length of the List, the List is NULL");
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool DoublyList_IsEmpty(DoublyList L) {
    assert(L != NULL && "ERROR: When checking if the List is empty, the List is NULL");
    // return L->length == 0;
    return L->front == NULL;
}

/* Get the Data of the Node p [O(1)] */
ElemType DoublyList_GetData(DNode *p) {
    assert(p != NULL && "ERROR: When getting the Data of the Node, the Node is NULL");
    ElemType data = p->data;
    return data;
}

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
DNode *DoublyList_GetNodeByPosition(DoublyList L, int i) {
    assert(L != NULL && "ERROR: When getting the Node of the List, the List is NULL");
    // Judge whether the index is within the valid range
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
    assert(L != NULL && "ERROR: When getting the Node of the List, the List is NULL");
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
    assert(L != NULL && "ERROR: When getting the position of the Node, the List is NULL");
    assert(p != NULL && "ERROR: When getting the position of the Node, the Node is NULL");
    DNode *q = L->front;
    int i = 1;
    while (q != NULL && q != p) {
        q = q->next;
        i++;
    }
    if (q == NULL) {
        printf("Get Position Error: Node is not in the List\n");
        return -1;
    }
    return i;
}

/* Get the position i (i start from 1) of the Data in the List(L) [O(n)] */
int DoublyList_GetPositionByData(DoublyList L, ElemType data) {
    assert(L != NULL && "ERROR: When getting the position of the Data, the List is NULL");
    DNode *p = L->front;
    int i = 1;
    while (p != NULL && p->data != data) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Get Position Error: Data %d is not in the List\n", data);
        return -1;
    }
    return i;
}

/* Get the data of the List(L) at the position i (i start from 1) [O(n)] */
ElemType DoublyList_GetDataByPosition(DoublyList L, int i) {
    assert(L != NULL && "ERROR: When getting the data of the List, the List is NULL!");
    assert(i >= 1 && i <= L->length && "ERROR: When getting the data of the List, the position is out of range!");
    DNode *p = DoublyList_GetNodeByPosition(L, i);
    return DoublyList_GetData(p);
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool DoublyList_HeadInsertNode(DoublyList L, DNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
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
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return DoublyList_HeadInsertNode(L, p);
}

/* Create DoublyList(L) from Array(dataset) By Head Insert [O(n)] */
bool DoublyList_CreateByHeadInsert(DoublyList L, ElemType dataset[], int length) {
    assert(L != NULL && "ERROR: When creating the List, the List is NULL!");
    assert(dataset != NULL && "ERROR: When creating the List, the Dataset is NULL!");
    for (int i = length - 1; i >= 0; i--) {
        if (DoublyList_HeadInsertData(L, dataset[i])) {
            continue;
        } else {
            printf("Create List Error: Insert Data %d failed\n", dataset[i]);
            return false;
        }
    }
    return true;
}

/* Insert the Node p into the List(L) at the rear [O(1)] */
bool DoublyList_TailInsertNode(DoublyList L, DNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
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
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return DoublyList_TailInsertNode(L, p);
}

/* Create DoublyList(L) from Array(dataset) By Tail Insert [O(n)] */
bool DoublyList_CreateByTailInsert(DoublyList L, ElemType dataset[], int length) {
    assert(L != NULL && "ERROR: When creating the List, the List is NULL!");
    assert(dataset != NULL && "ERROR: When creating the List, the Dataset is NULL!");
    for (int i = 0; i < length; i++) {
        if (DoublyList_TailInsertData(L, dataset[i])) {
            continue;
        } else {
            printf("Create List Error: Insert Data %d failed\n", dataset[i]);
            return false;
        }
    }
    return true;
}

/* Insert the Node p into the List(L) at the position i (i start from 1) [O(n)] */
bool DoublyList_InsertNodeByPosition(DoublyList L, int i, DNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
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
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    if (i < 1 || i > L->length + 1) {
        printf("Insert Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return DoublyList_InsertNodeByPosition(L, i, p);
}

/* =============================================================================== */

/* Reverse the List(L) [O(n)] */
bool DoublyList_Reverse(DoublyList L) {
    assert(L != NULL && "ERROR: When reversing the List, the List is NULL!");
    if (L->front == NULL) {
        printf("Reverse Warring: Empty List!\n");
        return false;
    }
    if (L->front == L->rear) {
        printf("Reverse Warring: Only One Node in the List!\n");
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

/* =============================================================================== */

/* Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]  */
ElemType DoublyList_DeleteNodeByPosition(DoublyList L, int i) {
    assert(L != NULL && "ERROR: When deleting the Node, the List is NULL!");
    assert(i >= 1 && i <= L->length && "ERROR: When deleting the Node, the Index out of range!");
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
    ElemType del = q->data;
    free(q);
    return del;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
ElemType DoublyList_DeleteNodeByData(DoublyList L, ElemType data) {
    assert(L != NULL && "ERROR: When deleting the Node, the List is NULL!");
    // q: Target Node; p: Node before q
    DNode *p = NULL, *q = L->front;
    while (q != NULL && q->data != data) {
        p = q;
        q = q->next;
    }
    assert(q != NULL && "ERROR: When deleting the Node, the Data not found!");      // q == NULL means the Data not found
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
    ElemType del = q->data;
    free(q);
    return del;
}

/* Destroy the List(L) [O(n)] */
bool DoublyList_Destroy(DoublyList L) {
    assert(L != NULL && "ERROR: When destroying the List, the List is NULL!");
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