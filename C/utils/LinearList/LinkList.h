/**
 * @FileName    :LinkList.h
 * @Date        :2025-03-07 20:19:51
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Linked List
 * @Description :List With Header node
 *              :The indexes in all functions are the order of nodes starting from 1
 *              :LNode: Linked List Node
 *              :LinkList: Head Node of Linked List
 *              :LinkList_Init: Initialize the Linked List Head Node [O(1)]
 * Get Information:
 *              :LinkList_GetLength: Get the length of the List(L) [O(1)]
 *              :LinkList_IsEmpty: Check if the List(L) is empty [O(1)]
 *              :LinkList_GetData: Get the Data of the Node p [O(1)]
 *              :LinkList_GetNodeByPosition: Get the Node of the List(L) at the position i (i start from 1) [O(n)]
 *              :LinkList_GetNodeByData: Get the Node of the List(L) with the Data [O(n)]
 *              :LinkList_GetPositionByNode: Get the position i (i start from 1) of the Node p in the List(L) [O(n)]
 *              :LinkList_GetPositionByData: Get the position i (i start from 1) of the Data in the List(L) [O(n)]
 *              :LinkList_GetDataByPosition: Get the Data of the List(L) at the position i (i start from 1) [O(n)]
 * Head Insertion:
 *              :LinkList_HeadInsertNode: Insert a Node at the head of the List(L) [O(1)]
 *              :LinkList_HeadInsertData: (Head Insertion) Insert the Data into the List(L) at the front [O(1)]
 *              :LinkList_CreateByHeadInsert: Create LinkList(L) from Array(dataset) By Head Insert [O(n)]
 * Tail Insertion:
 *              :LinkList_TailInsertNode: Insert the Node p into the List(L) at the rear [O(1)]
 *              :LinkList_TailInsertData: (Tail Insertion) Insert the Data into the List(L) at the rear [O(1)]
 *              :LinkList_CreateByTailInsert: Create LinkList(L) from Array(dataset) By Tail Insert [O(n)]
 * Insert by Position:
 *              :LinkList_InsertNodeByPosition: Insert the Node p into the List(L) at the position i (i start from 1) [O(n)]
 *              :LinkList_InsertDataByPosition: Insert the Data into the List(L) at the position i (i start from 1) [O(n)]
 * Reverse:
 *              :LinkList_Reverse: Reverse the List(L) [O(n)]
 * Delete and Destroy:
 *              :LinkList_DeleteNodeByPosition: Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]
 *              :LinkList_DeleteNodeByData: Delete the Node p in the List(L) with the first occurrence of Data [O(n)]
 *              :LinkList_Destroy: Destroy the List(L) [O(n)]
 * Print:
 *              :LinkList_Print: Print the List(L) [O(n)]
 */

#ifndef LINKLIST_H
#define LINKLIST_H

#include "../common.h"

/* Head Node of Linked List */
typedef struct LinkList {
    int length;         // Length of Linked List
    LNode *front;        // Front Node
    LNode *rear;        // Rear Node
} *LinkList;

/* Initialize the Linked List Head Node [O(1)] */
LinkList LinkList_Init() {
    LinkList L = (LinkList)malloc(sizeof(struct LinkList));
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int LinkList_GetLength(LinkList L) {
    assert(L != NULL && "ERROR: When getting the length of the List, the List is NULL!");
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool LinkList_IsEmpty(LinkList L) {
    assert(L != NULL && "ERROR: When checking if the List is empty, the List is NULL!");
    // return L->length == 0;
    return L->front == NULL;
}

/* Get the Data of the Node p [O(1)] */
ElemType LinkList_GetData(LNode *p) {
    assert(p != NULL && "ERROR: When getting the Data of the Node, the Node is NULL!");
    ElemType data = p->data;
    return data;
}

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
LNode *LinkList_GetNodeByPosition(LinkList L, int i) {
    assert(L != NULL && "ERROR: When getting the Node of the List, the List is NULL!");
    // Judge whether the index is within the valid range
    if (i < 1 || i > L->length) {
        printf("Get Node Error: Position %d is out of range\n", i);
        return NULL;
    }
    // p: Target Node; j: Current Position
    LNode *p = L->front;
    int j = 1;
    while (p != NULL && j < i) {
        p = p->next;
        j++;
    }
    return p;
}

/* Get the Node of the List(L) with the Data [O(n)] */
LNode *LinkList_GetNodeByData(LinkList L, ElemType data) {
    assert(L != NULL && "ERROR: When getting the Node of the List, the List is NULL!");
    LNode *p = L->front;
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
int LinkList_GetPositionByNode(LinkList L, LNode *p) {
    assert(L != NULL && "ERROR: When getting the position of the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When getting the position of the Node, the Node is NULL!");
    LNode *q = L->front;
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
int LinkList_GetPositionByData(LinkList L, ElemType data) {
    assert(L != NULL && "ERROR: When getting the position of the Data, the List is NULL!");
    LNode *p = L->front;
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
ElemType LinkList_GetDataByPosition(LinkList L, int i) {
    assert(L != NULL && "ERROR: When getting the data of the List, the List is NULL!");
    assert(i >= 1 && i <= L->length && "ERROR: When getting the data of the List, the position is out of range!");
    LNode *p = LinkList_GetNodeByPosition(L, i);
    return LinkList_GetData(p);
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool LinkList_HeadInsertNode(LinkList L, LNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
    if (L->front == NULL) {
        p->next = L->front;
        L->front = p;
        L->rear = p;
    } else {
        p->next = L->front;
        L->front = p;
    }
    L->length++;
    return true;
}

/* (Head Insertion) Insert the Data into the List(L) at the front [O(1)] */
bool LinkList_HeadInsertData(LinkList L, ElemType data) {
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return LinkList_HeadInsertNode(L, p);
}

/* Create LinkList(L) from Array(dataset) By Head Insert [O(n)] */
bool LinkList_CreateByHeadInsert(LinkList L, ElemType dataset[], int length) {
    assert(L != NULL && "ERROR: When creating the List, the List is NULL!");
    assert(dataset != NULL && "ERROR: When creating the List, the Dataset is NULL!");
    for (int i = length - 1; i >= 0; i--) {
        if (LinkList_HeadInsertData(L, dataset[i])) {
            continue;
        } else {
            printf("Create List Error: Insert Data %d failed\n", dataset[i]);
            return false;
        }
    }
    return true;
}

/* Insert the Node p into the List(L) at the rear [O(1)] */
bool LinkList_TailInsertNode(LinkList L, LNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
    if (L->front == NULL) {
        p->next = L->front;
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
bool LinkList_TailInsertData(LinkList L, ElemType data) {
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return LinkList_TailInsertNode(L, p);
}

/* Create LinkList(L) from Array(dataset) By Tail Insert [O(n)] */
bool LinkList_CreateByTailInsert(LinkList L, ElemType dataset[], int length) {
    assert(L != NULL && "ERROR: When creating the List, the List is NULL!");
    assert(dataset != NULL && "ERROR: When creating the List, the Dataset is NULL!");
    for (int i = 0; i < length; i++) {
        if (LinkList_TailInsertData(L, dataset[i])) {
            continue;
        } else {
            printf("Create List Error: Insert Data %d failed\n", dataset[i]);
            return false;
        }
    }
    return true;
}

/* Insert the Node p into the List(L) at the position i (i start from 1) [O(n)] */
bool LinkList_InsertNodeByPosition(LinkList L, int i, LNode *p) {
    assert(L != NULL && "ERROR: When inserting the Node, the List is NULL!");
    assert(p != NULL && "ERROR: When inserting the Node, the Node is NULL!");
    if (i < 1 || i > L->length + 1) {
        printf("Insert Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    if (i == 1) {
        return LinkList_HeadInsertNode(L, p);
    }
    if (i == L->length + 1) {
        return LinkList_TailInsertNode(L, p);
    } else {
        // p: Target Node; q: Node before p
        LNode *q = L->front;
        int j = 1;
        while (q != NULL && j < i - 1) {
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
bool LinkList_InsertDataByPosition(LinkList L, int i, ElemType data) {
    assert(L != NULL && "ERROR: When inserting the Data, the List is NULL!");
    if (i < 1 || i > L->length + 1) {
        printf("Insert Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return LinkList_InsertNodeByPosition(L, i, p);
}

/* =============================================================================== */

/* Reverse the List(L) [O(n)] */
bool LinkList_Reverse(LinkList L) {
    assert(L != NULL && "ERROR: When reversing the List, the List is NULL!");
    if (L->front == NULL) {
        printf("Reverse Warring: Empty List!\n");
        return false;
    }
    if (L->front == L->rear) {
        printf("Reverse Warring: Only One Node in the List!\n");
        return false;
    }

    LNode *p = L->front, *q = NULL;
    L->rear = p;
    while (p != NULL) {
        q = p->next;
        p->next = L->front;
        L->front = p;
        p = q;
    }
    L->rear->next = NULL;
    return true;
}

/* =============================================================================== */

/* Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]  */
ElemType LinkList_DeleteNodeByPosition(LinkList L, int i) {
    assert(L != NULL && "ERROR: When deleting the Node, the List is NULL!");
    assert(i >= 1 && i <= L->length && "ERROR: When deleting the Node, the Index out of range!");
    // q: Target Node; p: Node before q
    LNode *q;
    if (i == 1) {
        q = L->front;
        L->front = q->next;
        if (L->front == NULL) {
            L->rear = NULL;
        }
    } else {
        LNode *p = L->front;
        int j = 1;
        while (p->next != NULL && j < i - 1) {
            p = p->next;
            j++;
        }
        q = p->next;
        p->next = q->next;
        if (p->next == NULL) {
            L->rear = p;
        }
    }
    L->length--;
    ElemType del = q->data;
    free(q);
    return del;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
ElemType LinkList_DeleteNodeByData(LinkList L, ElemType data) {
    assert(L != NULL && "ERROR: When deleting the Node, the List is NULL!");
    // q: Target Node; p: Node before q
    LNode *p = NULL, *q = L->front;
    while (q != NULL && q->data != data) {
        p = q;
        q = q->next;
    }
    assert(q != NULL && "ERROR: When deleting the Node, the Data not in the List!"); // q == NULL means the Data not in the List
    if (q == L->front) {
        L->front = q->next;
        if (L->front == NULL) {
            L->rear = NULL;
        }
    } else {
        p->next = q->next;
        if (p->next == NULL) {
            L->rear = p;
        }
    }
    L->length--;
    ElemType del = q->data;
    free(q);
    return del;
}

/* Destroy the List(L) [O(n)] */
LinkList LinkList_Destroy(LinkList L) {
    assert(L != NULL && "ERROR: When destroying the List, the List is NULL!");
    LNode *p = L->front, *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    free(L);
    return NULL;
}

/* =============================================================================== */

/* Print the List(L) [O(n)] */
void LinkList_Print(LinkList L) {
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
    while (p != NULL) {
        printf("%d    ", p->data);
        p = p->next;
    }
    printf("\n");
}

#endif // LINKLIST_H