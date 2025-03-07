/**
 * @FileName    :LinkList.c
 * @Date        :2025-03-04 13:27:10
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
 * Delete and Destroy:
 *              :LinkList_DeleteNodeByPosition: Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]
 *              :LinkList_DeleteNodeByData: Delete the Node p in the List(L) with the first occurrence of Data [O(n)]
 *              :LinkList_Destroy: Destroy the List(L) [O(n)]
 * Print:
 *              :LinkList_Print: Print the List(L) [O(n)]
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

/* Head Node of Linked List */
typedef struct {
    int length;         // Length of Linked List
    LNode *front;        // Front Node
    LNode *rear;        // Rear Node
} *LinkList;

/* Initialize the Linked List Head Node [O(1)] */
LinkList LinkList_Init() {
    LinkList L = (LinkList)malloc(sizeof(LinkList));
    L->length = 0;
    L->front = NULL;
    L->rear = NULL;
    return L;
}

/* Get the length of the List(L) [O(1)] */
int LinkList_GetLength(LinkList L) {
    return L->length;
}

/* Check if the List(L) is empty [O(1)] */
bool LinkList_IsEmpty(LinkList L) {
    // return L->length == 0;
    return L->front == NULL;
}

/* Get the Data of the Node p [O(1)] */
bool LinkList_GetData(LNode *p, ElemType *data) {
    if (p == NULL) {
        printf("Get Data Error: Node is NULL\n");
        return false;
    }
    *data = p->data;
    return true;
}

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
LNode *LinkList_GetNodeByPosition(LinkList L, int i) {
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
    LNode *q = L->front;
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
int LinkList_GetPositionByData(LinkList L, ElemType data) {
    LNode *p = L->front;
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

/* Get the data of the List(L) at the position i (i start from 1) [O(n)] */
bool LinkList_GetDataByPosition(LinkList L, int i, ElemType *data) {
    LNode *p = LinkList_GetNodeByPosition(L, i);
    return LinkList_GetData(p, data);
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool LinkList_HeadInsertNode(LinkList L, LNode *p) {
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
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return LinkList_HeadInsertNode(L, p);
}

/* Create LinkList(L) from Array(dataset) By Head Insert [O(n)] */
bool LinkList_CreateByHeadInsert(LinkList L, ElemType dataset[], int length) {
    for (int i = length - 1; i >= 0; i--) {
        LinkList_HeadInsertData(L, dataset[i]);
    }
    return true;
}

/* Insert the Node p into the List(L) at the rear [O(1)] */
bool LinkList_TailInsertNode(LinkList L, LNode *p) {
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
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return LinkList_TailInsertNode(L, p);
}

/* Create LinkList(L) from Array(dataset) By Tail Insert [O(n)] */
bool LinkList_CreateByTailInsert(LinkList L, ElemType dataset[], int length) {
    for (int i = 0; i < length; i++) {
        LinkList_TailInsertData(L, dataset[i]);
    }
    return true;
}

/* Insert the Node p into the List(L) at the position i (i start from 1) [O(n)] */
bool LinkList_InsertNodeByPosition(LinkList L, int i, LNode *p) {
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
    LNode *p = (LNode *)malloc(sizeof(LNode));
    p->data = data;
    return LinkList_InsertNodeByPosition(L, i, p);
}

/* =============================================================================== */

/* Delete the Node p in the List(L) at the position i (i start from 1) [O(n)]  */
bool LinkList_DeleteNodeByPosition(LinkList L, int i, ElemType *del) {
    if (i < 1 || i > L->length) {
        *del = -1;
        printf("Delete Position Error: Index (%d) out of range!\n", i);
        return false;
    }
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
    *del = q->data;
    free(q);
    return true;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
bool LinkList_DeleteNodeByData(LinkList L, ElemType data, ElemType *del) {
    // q: Target Node; p: Node before q
    LNode *p = NULL, *q = L->front;
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
        }
    } else {
        p->next = q->next;
        if (p->next == NULL) {
            L->rear = p;
        }
    }
    L->length--;
    *del = q->data;
    free(q);
    return true;
}

/* Destroy the List(L) [O(n)] */
bool LinkList_Destroy(LinkList L) {
    LNode *p = L->front, *q = NULL;
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
void LinkList_Print(LinkList L) {
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

/* Driver Code */
int main() {
    LinkList L = LinkList_Init();

    printf("%ld\n", sizeof(*L));
    printf("%ld\n", sizeof(L->length));

    printf("================================================\n");

    ElemType dataset1[] = {1, 2, 3, 4, 5};
    int length1 = sizeof(dataset1) / sizeof(dataset1[0]);
    ElemType dataset2[] = {6, 7, 8, 9, 10};
    int length2 = sizeof(dataset2) / sizeof(dataset2[0]);

    LinkList_CreateByTailInsert(L, dataset1, length1);
    LinkList_Print(L);
    LinkList_CreateByHeadInsert(L, dataset2, length2);
    LinkList_Print(L);

    printf("================================================\n");

    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = 666;
    node->next = NULL;
    LinkList_InsertDataByPosition(L, 0, 999);
    LinkList_InsertDataByPosition(L, 1, 999);
    LinkList_InsertDataByPosition(L, 6, 999);
    LinkList_InsertNodeByPosition(L, 13, node);
    LinkList_InsertDataByPosition(L, 14, 999);
    LinkList_InsertDataByPosition(L, 16, 999);
    LinkList_Print(L);

    printf("================================================\n");

    printf("Length: %d\n", LinkList_GetLength(L));
    if (LinkList_IsEmpty(L)) {
        printf("LinkList is empty!\n");
    } else {
        printf("LinkList is not empty!\n");
    }

    printf("================================================\n");

    LNode *p = NULL;
    ElemType data = 666;
    ElemType returnData = 0;
    p = LinkList_GetNodeByData(L, data);
    if (LinkList_GetData(p, &returnData)) {
        printf("Found Node By Data %d : %d\n", data, returnData);
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }
    data = 100;
    p = LinkList_GetNodeByData(L, data);
    if (LinkList_GetData(p, &returnData)) {
        printf("Found Node By Data %d : %d\n", data, returnData);
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }

    printf("================================================\n");

    int position = 0;
    p = LinkList_GetNodeByPosition(L, position);
    if (LinkList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 5;
    p = LinkList_GetNodeByPosition(L, position);
    if (LinkList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 14;
    p = LinkList_GetNodeByPosition(L, position);
    if (LinkList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 15;
    p = LinkList_GetNodeByPosition(L, position);
    if (LinkList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }

    printf("================================================\n");

    int index = -1;
    index = LinkList_GetPositionByNode(L, node);
    if (index == 0) {
        printf("Not Found Position By Node (node) !\n");
    } else {
        printf("Found Position By Node (node) : %d\n", index);
    }
    p = NULL;
    index = LinkList_GetPositionByNode(L, p);
    if (index == 0) {
        printf("Not Found Position By Node p !\n");
    } else {
        printf("Found Position By Node p : %d\n", index);
    }

    printf("================================================\n");

    index = LinkList_GetPositionByData(L, 666);
    if (index == 0) {
        printf("Not Found Position By Data (666) !\n");
    } else {
        printf("Found Position By Data (666) : %d\n", index);
    }
    index = LinkList_GetPositionByData(L, 888);
    if (index == 0) {
        printf("Not Found Position By Data 888 !\n");
    } else {
        printf("Found Position By Data 888 : %d\n", index);
    }

    printf("================================================\n");

    returnData = -1;
    LinkList_GetDataByPosition(L, 0, &returnData);
    printf("Get Data By Position 0 : %d\n", returnData);
    returnData = -1;
    LinkList_GetDataByPosition(L, 1, &returnData);
    printf("Get Data By Position 1 : %d\n", returnData);
    returnData = -1;
    LinkList_GetDataByPosition(L, 13, &returnData);
    printf("Get Data By Position 13 : %d\n", returnData);
    returnData = -1;
    LinkList_GetDataByPosition(L, 14, &returnData);
    printf("Get Data By Position 14 : %d\n", returnData);
    returnData = -1;
    LinkList_GetDataByPosition(L, 15, &returnData);
    printf("Get Data By Position 15 : %d\n", returnData);

    printf("================================================\n");

    ElemType del = -1;
    LinkList_DeleteNodeByPosition(L, 0, &del);
    LinkList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    LinkList_DeleteNodeByPosition(L, 1, &del);
    LinkList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    LinkList_DeleteNodeByPosition(L, 5, &del);
    LinkList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    LinkList_DeleteNodeByPosition(L, 12, &del);
    LinkList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    LinkList_DeleteNodeByPosition(L, 12, &del);
    LinkList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");

    printf("================================================\n");

    LinkList_DeleteNodeByData(L, 1234, &del);
    LinkList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    LinkList_DeleteNodeByData(L, 666, &del);
    LinkList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    LinkList_DeleteNodeByData(L, 6, &del);
    LinkList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }

    printf("================================================\n");

    LinkList_Destroy(L);
    if (L->length == 0 && L->front == NULL && L->rear == NULL) {
        printf("LinkList Destroyed!\n");
        printf("Length: %d\n", LinkList_GetLength(L));
        if (LinkList_IsEmpty(L)) {
            printf("LinkList is empty!\n");
        } else {
            printf("LinkList is not empty!\n");
        }
    } else {
        printf("LinkList Not Destroyed!\n");
    }
    return 0;
}