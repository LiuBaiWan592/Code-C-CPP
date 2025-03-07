/**
 * @FileName    :CirDoublyList.c
 * @Date        :2025-03-07 11:50:53
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Circular Linked List
 * @Description :Circular List With a Header node outside the list
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

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define ElemType int
/* Linked List Node*/
typedef struct DNode {
    ElemType data;      // Data
    struct DNode *prior, *next; // Prior Node and Next Node
} DNode;

/* Head Node of Linked List */
typedef struct {
    int length;         // Length of Linked List
    DNode *front;        // Front Node
    DNode *rear;        // Rear Node
} *CirDoublyList;

/* Initialize the Linked List Head Node [O(1)] */
CirDoublyList CirDoublyList_Init() {
    CirDoublyList L = (CirDoublyList)malloc(sizeof(CirDoublyList));
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int CirDoublyList_GetLength(CirDoublyList L) {
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool CirDoublyList_IsEmpty(CirDoublyList L) {
    // return L->length == 0;
    return L->front == NULL;
}

/* Get the Data of the Node p [O(1)] */
bool CirDoublyList_GetData(DNode *p, ElemType *data) {
    if (p == NULL) {
        printf("Get Data Error: Node is NULL\n");
        return false;
    }
    *data = p->data;
    return true;
}

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
DNode *CirDoublyList_GetNodeByPosition(CirDoublyList L, int i) {
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
    DNode *q = L->front;
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
int CirDoublyList_GetPositionByData(CirDoublyList L, ElemType data) {
    DNode *p = L->front;
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
bool CirDoublyList_GetDataByPosition(CirDoublyList L, int i, ElemType *data) {
    DNode *p = CirDoublyList_GetNodeByPosition(L, i);
    return CirDoublyList_GetData(p, data);
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool CirDoublyList_HeadInsertNode(CirDoublyList L, DNode *p) {
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
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return CirDoublyList_HeadInsertNode(L, p);
}

/* Create CirDoublyList(L) from Array(dataset) By Head Insert [O(n)] */
bool CirDoublyList_CreateByHeadInsert(CirDoublyList L, ElemType dataset[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        CirDoublyList_HeadInsertData(L, dataset[i]);
    }
    return true;
}

/* Insert the Node p into the List(L) at the rear [O(1)] */
bool CirDoublyList_TailInsertNode(CirDoublyList L, DNode *p) {
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
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return CirDoublyList_TailInsertNode(L, p);
}

/* Create CirDoublyList(L) from Array(dataset) By Tail Insert [O(n)] */
bool CirDoublyList_CreateByTailInsert(CirDoublyList L, ElemType dataset[], int length) {
    for (int i = 0; i < length; i++) {
        CirDoublyList_TailInsertData(L, dataset[i]);
    }
    return true;
}

/* Insert the Node p into the List(L) at the position i (i start from 1) [O(n)] */
bool CirDoublyList_InsertNodeByPosition(CirDoublyList L, int i, DNode *p) {
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
    DNode *p = (DNode *)malloc(sizeof(DNode));
    p->data = data;
    return CirDoublyList_InsertNodeByPosition(L, i, p);
}

/* =============================================================================== */

/* Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]  */
bool CirDoublyList_DeleteNodeByPosition(CirDoublyList L, int i, ElemType *del) {
    if (i < 1 || i > L->length) {
        printf("Delete Position Error: Index (%d) out of range!\n", i);
        return false;
    }
    // q: Target Node; p: Node before q
    DNode *q;
    if (i == 1) {
        q = L->front;
        L->front = q->next;
        L->rear->next = L->front;
        if (L->length == 1) {
            L->front = NULL;
            L->rear = NULL;
        }else{
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
        }else {
            q->next->prior = p;
        }
    }
    L->length--;
    *del = q->data;
    free(q);
    return true;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
bool CirDoublyList_DeleteNodeByData(CirDoublyList L, ElemType data, ElemType *del) {
    // q: Target Node; p: Node before q
    DNode *p = NULL, *q = L->front;
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
        }else {
            L->front->prior = L->rear;
        }
    } else {
        p->next = q->next;
        if (i == L->length) {
            L->rear = p;
        }else {
            q->next->prior = p;
        }
    }
    L->length--;
    *del = q->data;
    free(q);
    return true;
}

/* Destroy the List(L) [O(n)] */
bool CirDoublyList_Destroy(CirDoublyList L) {
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
    return true;
}

/* =============================================================================== */

/* Print the List(L) [O(n)] */
void CirDoublyList_Print(CirDoublyList L) {
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

void print() {
    printf("================================================\n");
}

/* Driver Code */
int main() {
    CirDoublyList L = CirDoublyList_Init();

    printf("%ld\n", sizeof(*L));
    printf("%ld\n", sizeof(L->length));

    printf("================================================\n");

    ElemType dataset1[] = {1, 2, 3, 4, 5};
    int length1 = sizeof(dataset1) / sizeof(dataset1[0]);
    ElemType dataset2[] = {6, 7, 8, 9, 10};
    int length2 = sizeof(dataset2) / sizeof(dataset2[0]);

    CirDoublyList_CreateByTailInsert(L, dataset1, length1);
    CirDoublyList_Print(L);
    CirDoublyList_CreateByHeadInsert(L, dataset2, length2);
    CirDoublyList_Print(L);

    printf("================================================\n");

    DNode *node = (DNode *)malloc(sizeof(DNode));
    node->data = 666;
    node->next = NULL;
    CirDoublyList_InsertDataByPosition(L, 0, 999);
    CirDoublyList_InsertDataByPosition(L, 1, 999);
    CirDoublyList_InsertDataByPosition(L, 6, 999);
    CirDoublyList_InsertNodeByPosition(L, 13, node);
    CirDoublyList_InsertDataByPosition(L, 14, 999);
    CirDoublyList_InsertDataByPosition(L, 16, 999);
    CirDoublyList_Print(L);

    printf("================================================\n");

    printf("Length: %d\n", CirDoublyList_GetLength(L));
    if (CirDoublyList_IsEmpty(L)) {
        printf("LinkList is empty!\n");
    } else {
        printf("LinkList is not empty!\n");
    }

    printf("================================================\n");

    DNode *p = NULL;
    ElemType data = 666;
    ElemType returnData = 0;
    p = CirDoublyList_GetNodeByData(L, data);
    if (CirDoublyList_GetData(p, &returnData)) {
        printf("Found Node By Data %d : %d\n", data, returnData);
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }
    data = 100;
    p = CirDoublyList_GetNodeByData(L, data);
    if (CirDoublyList_GetData(p, &returnData)) {
        printf("Found Node By Data %d : %d\n", data, returnData);
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }

    printf("================================================\n");

    int position = 0;
    p = CirDoublyList_GetNodeByPosition(L, position);
    if (CirDoublyList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 5;
    p = CirDoublyList_GetNodeByPosition(L, position);
    if (CirDoublyList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 14;
    p = CirDoublyList_GetNodeByPosition(L, position);
    if (CirDoublyList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 15;
    p = CirDoublyList_GetNodeByPosition(L, position);
    if (CirDoublyList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }

    printf("================================================\n");

    int index = -1;
    index = CirDoublyList_GetPositionByNode(L, node);
    if (index == 0) {
        printf("Not Found Position By Node (node) !\n");
    } else {
        printf("Found Position By Node (node) : %d\n", index);
    }
    p = NULL;
    index = CirDoublyList_GetPositionByNode(L, p);
    if (index == 0) {
        printf("Not Found Position By Node p !\n");
    } else {
        printf("Found Position By Node p : %d\n", index);
    }

    printf("================================================\n");

    index = CirDoublyList_GetPositionByData(L, 666);
    if (index == 0) {
        printf("Not Found Position By Data (666) !\n");
    } else {
        printf("Found Position By Data (666) : %d\n", index);
    }
    index = CirDoublyList_GetPositionByData(L, 888);
    if (index == 0) {
        printf("Not Found Position By Data 888 !\n");
    } else {
        printf("Found Position By Data 888 : %d\n", index);
    }

    printf("================================================\n");

    returnData = -1;
    CirDoublyList_GetDataByPosition(L, 0, &returnData);
    printf("Get Data By Position 0 : %d\n", returnData);
    returnData = -1;
    CirDoublyList_GetDataByPosition(L, 1, &returnData);
    printf("Get Data By Position 1 : %d\n", returnData);
    returnData = -1;
    CirDoublyList_GetDataByPosition(L, 13, &returnData);
    printf("Get Data By Position 13 : %d\n", returnData);
    returnData = -1;
    CirDoublyList_GetDataByPosition(L, 14, &returnData);
    printf("Get Data By Position 14 : %d\n", returnData);
    returnData = -1;
    CirDoublyList_GetDataByPosition(L, 15, &returnData);
    printf("Get Data By Position 15 : %d\n", returnData);

    printf("================================================\n");

    ElemType del = -1;
    CirDoublyList_DeleteNodeByPosition(L, 0, &del);
    CirDoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    CirDoublyList_DeleteNodeByPosition(L, 1, &del);
    CirDoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    CirDoublyList_DeleteNodeByPosition(L, 5, &del);
    CirDoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    CirDoublyList_DeleteNodeByPosition(L, 12, &del);
    CirDoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    CirDoublyList_DeleteNodeByPosition(L, 12, &del);
    CirDoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");

    printf("================================================\n");

    CirDoublyList_DeleteNodeByData(L, 1234, &del);
    CirDoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    CirDoublyList_DeleteNodeByData(L, 666, &del);
    CirDoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    CirDoublyList_DeleteNodeByData(L, 6, &del);
    CirDoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }

    printf("================================================\n");

    CirDoublyList_Destroy(L);
    if (L->length == 0 && L->front == NULL && L->rear == NULL) {
        printf("LinkList Destroyed!\n");
        printf("Length: %d\n", CirDoublyList_GetLength(L));
        if (CirDoublyList_IsEmpty(L)) {
            printf("LinkList is empty!\n");
        } else {
            printf("LinkList is not empty!\n");
        }
    } else {
        printf("LinkList Not Destroyed!\n");
    }
    return 0;
}