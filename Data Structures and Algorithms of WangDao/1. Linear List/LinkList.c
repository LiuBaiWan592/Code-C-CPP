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
 * Get Node or Position:
 *              :LinkList_GetNodeByPosition: Get the Node of the List(L) at the position i (i start from 1) [O(n)]
 *              :LinkList_GetNodeByData: Get the Node of the List(L) with the Data [O(n)]
 *              :LinkList_GetPositionByNode: Get the position i (i start from 1) of the Node p in the List(L) [O(n)]
 *              :LinkList_GetPositionByData: Get the position i (i start from 1) of the Data in the List(L) [O(n)]
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
    LNode *next;        // Next Node
    LNode *rear;        // Rear Node
} *LinkList;

/* Initialize the Linked List Head Node [O(1)] */
LinkList LinkList_Init() {
    LinkList L = (LinkList)malloc(sizeof(LinkList));
    L->length = 0;
    L->next = NULL;
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
    return L->next == NULL;
}

/* Get the Data of the Node p [O(1)] */
bool LinkList_GetData(LNode *p, ElemType *data) {
    if (p == NULL) {
        return false;
    }
    *data = p->data;
    return true;
}

/* =============================================================================== */

/* Get the Node of the List(L) at the position i (i start from 1) [O(n)] */
LNode *LinkList_GetNodeByPosition(LinkList L, int i) {
    if (i < 1 || i > L->length) {
        return NULL;
    }
    LNode *p = L->next;
    while (p != NULL && --i) {
        p = p->next;
    }
    return p;
}

/* Get the Node of the List(L) with the Data [O(n)] */
LNode *LinkList_GetNodeByData(LinkList L, ElemType data) {
    LNode *p = L->next;
    while (p != NULL && p->data != data) {
        p = p->next;
    }
    return p;
}

/* Get the position i (i start from 1) of the Node p in the List(L) [O(n)] */
int LinkList_GetPositionByNode(LinkList L, LNode *p) {
    LNode *q = L->next;
    int i = 1;
    while (q != p) {
        q = q->next;
        i++;
    }
    if (q == NULL) {
        return -1;
    }
    return i;
}

/* Get the position i (i start from 1) of the Data in the List(L) [O(n)] */
int LinkList_GetPositionByData(LinkList L, ElemType data) {
    LNode *p = L->next;
    int i = 1;
    while (p != NULL && p->data != data) {
        p = p->next;
        i++;
    }
    if (p == NULL) {
        return -1;
    }
    return i;
}

/* =============================================================================== */

/* Insert the Node p into the List(L) at the front [O(1)] */
bool LinkList_HeadInsertNode(LinkList L, LNode *p) {
    if (L->next == NULL) {
        p->next = L->next;
        L->next = p;
        L->rear = p;
    } else {
        p->next = L->next;
        L->next = p;
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
    if (L->next == NULL) {
        p->next = L->next;
        L->next = p;
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
        return false;
    }
    if (i == 1) {
        return LinkList_HeadInsertNode(L, p);
    }
    if (i == L->length + 1) {
        return LinkList_TailInsertNode(L, p);
    } else {
        LNode *q = L->next;
        i--;
        while (q != NULL && --i) {
            q = q->next;
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
bool LinkList_DeleteNodeByPosition(LinkList L, int i, LNode *del) {
    if (i < 1 || i > L->length) {
        return false;
    }
    LNode *p = NULL;
    if (i == 1) {
        p = L->next;
        L->next = p->next;
        if (L->next == NULL) {
            L->rear = NULL;
        }
    } else {
        LNode *q = L->next;
        i--;
        while (q != NULL && --i) {
            q = q->next;
        }
        p = q->next;
        q->next = p->next;
        if (q->next == NULL) {
            L->rear = q;
        }
    }
    L->length--;
    *del = *p;
    free(p);
    return true;
}

/* Delete the Node p in the List(L) with the first occurrence of Data [O(n)] */
bool LinkList_DeleteNodeByData(LinkList L, ElemType data, LNode *del) {
    LNode *q = NULL, *p = L->next;
    while (p != NULL && p->data != data) {
        q = p;
        p = p->next;
    }
    if (p == NULL) {
        return false;
    }
    if (p == L->next) {
        L->next = p->next;
        if (L->next == NULL) {
            L->rear = NULL;
        }
    }
    q->next = p->next;
    if (q->next == NULL) {
        L->rear = q;
    }
    L->length--;
    *del = *p;
    free(p);
    return true;
}

/* Destroy the List(L) [O(n)] */
bool LinkList_Destroy(LinkList L) {
    LNode *p = L->next, *q = NULL;
    while (p != NULL) {
        q = p;
        p = p->next;
        free(q);
    }
    L->length = 0;
    L->next = NULL;
    L->rear = NULL;
    return true;
}

/* =============================================================================== */

/* Print the List(L) [O(n)] */
void LinkList_Print(LinkList L) {
    LNode *p = L->next;
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

void print() {
    printf("================================================\n");
}

/* Driver Code */
int main() {
    LinkList L = LinkList_Init();

    printf("%d\n", sizeof(*L));
    printf("%d\n", sizeof(L->length));

    print();

    ElemType dataset1[] = {1, 2, 3, 4, 5};
    int length1 = sizeof(dataset1) / sizeof(dataset1[0]);
    ElemType dataset2[] = {6, 7, 8, 9, 10};
    int length2 = sizeof(dataset2) / sizeof(dataset2[0]);

    LinkList_CreateByTailInsert(L, dataset2, length1);
    LinkList_Print(L);
    LinkList_CreateByHeadInsert(L, dataset1, length1);
    LinkList_Print(L);

    print();

    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = 50;
    node->next = NULL;
    LinkList_InsertNodeByPosition(L, 3, node);
    LinkList_Print(L);

    LinkList_InsertDataByPosition(L, 5, 99);
    LinkList_Print(L);

    print();

    printf("Length: %d\n", LinkList_GetLength(L));
    if (LinkList_IsEmpty(L)) {
        printf("LinkList is empty!\n");
    } else {
        printf("LinkList is not empty!\n");
    }

    print();

    LNode *p = NULL;
    ElemType data = 3;
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

    print();

    int position = 5;
    p = LinkList_GetNodeByPosition(L, position);
    if (LinkList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 100;
    p = LinkList_GetNodeByPosition(L, position);
    if (LinkList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }

    print();

    int index = -1;
    index = LinkList_GetPositionByNode(L, node);
    if (index == -1) {
        printf("Not Found Position By Node (node) !\n");
    } else {
        printf("Found Position By Node (node) : %d\n", index);
    }
    p = NULL;
    index = LinkList_GetPositionByNode(L, p);
    if (index == -1) {
        printf("Not Found Position By Node p !\n");
    } else {
        printf("Found Position By Node p : %d\n", index);
    }

    print();

    LNode del = {0, NULL};
    LinkList_DeleteNodeByPosition(L, 5, &del);
    LinkList_Print(L);
    if (LinkList_GetData(&del, &returnData)) {
        printf("Deleted Node : %d\n", returnData);
    } else {
        printf("Deleted Node : NULL\n");
    }

    print();

    LinkList_DeleteNodeByData(L, 50, &del);
    LinkList_Print(L);
    if (LinkList_GetData(&del, &returnData)) {
        printf("Deleted Node : %d\n", returnData);
    } else {
        printf("Deleted Node : NULL\n");
    }

    print();

    LinkList_Destroy(L);
    if (L->length == 0 && L->next == NULL && L->rear == NULL) {
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