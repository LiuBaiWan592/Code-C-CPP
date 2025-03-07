/**
 * @FileName    :Driver_DoublyList.c
 * @Date        :2025-03-07 20:23:45
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../utils/DoublyList.h"

/* Driver Code */
int main() {
    DoublyList L = DoublyList_Init();

    printf("%ld\n", sizeof(*L));
    printf("%ld\n", sizeof(L->length));

    printf("================================================\n");

    ElemType dataset1[] = {1, 2, 3, 4, 5};
    int length1 = sizeof(dataset1) / sizeof(dataset1[0]);
    ElemType dataset2[] = {6, 7, 8, 9, 10};
    int length2 = sizeof(dataset2) / sizeof(dataset2[0]);

    DoublyList_CreateByTailInsert(L, dataset1, length1);
    DoublyList_Print(L);
    DoublyList_CreateByHeadInsert(L, dataset2, length2);
    DoublyList_Print(L);

    printf("================================================\n");

    DNode *node = (DNode *)malloc(sizeof(DNode));
    node->data = 666;
    node->next = NULL;
    DoublyList_InsertDataByPosition(L, 0, 999);
    DoublyList_InsertDataByPosition(L, 1, 999);
    DoublyList_InsertDataByPosition(L, 6, 999);
    DoublyList_InsertNodeByPosition(L, 13, node);
    DoublyList_InsertDataByPosition(L, 14, 999);
    DoublyList_InsertDataByPosition(L, 16, 999);
    DoublyList_Print(L);

    printf("================================================\n");

    printf("Length: %d\n", DoublyList_GetLength(L));
    if (DoublyList_IsEmpty(L)) {
        printf("LinkList is empty!\n");
    } else {
        printf("LinkList is not empty!\n");
    }

    printf("================================================\n");

    DNode *p = NULL;
    ElemType data = 666;
    ElemType returnData = 0;
    p = DoublyList_GetNodeByData(L, data);
    if (DoublyList_GetData(p, &returnData)) {
        printf("Found Node By Data %d : %d\n", data, returnData);
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }
    data = 100;
    p = DoublyList_GetNodeByData(L, data);
    if (DoublyList_GetData(p, &returnData)) {
        printf("Found Node By Data %d : %d\n", data, returnData);
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }

    printf("================================================\n");

    int position = 0;
    p = DoublyList_GetNodeByPosition(L, position);
    if (DoublyList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 5;
    p = DoublyList_GetNodeByPosition(L, position);
    if (DoublyList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 14;
    p = DoublyList_GetNodeByPosition(L, position);
    if (DoublyList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 15;
    p = DoublyList_GetNodeByPosition(L, position);
    if (DoublyList_GetData(p, &returnData)) {
        printf("Found Node By Position %d : %d\n", position, returnData);
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }

    printf("================================================\n");

    int index = -1;
    index = DoublyList_GetPositionByNode(L, node);
    if (index == 0) {
        printf("Not Found Position By Node (node) !\n");
    } else {
        printf("Found Position By Node (node) : %d\n", index);
    }
    p = NULL;
    index = DoublyList_GetPositionByNode(L, p);
    if (index == 0) {
        printf("Not Found Position By Node p !\n");
    } else {
        printf("Found Position By Node p : %d\n", index);
    }

    printf("================================================\n");

    index = DoublyList_GetPositionByData(L, 666);
    if (index == 0) {
        printf("Not Found Position By Data (666) !\n");
    } else {
        printf("Found Position By Data (666) : %d\n", index);
    }
    index = DoublyList_GetPositionByData(L, 888);
    if (index == 0) {
        printf("Not Found Position By Data 888 !\n");
    } else {
        printf("Found Position By Data 888 : %d\n", index);
    }

    printf("================================================\n");

    returnData = -1;
    DoublyList_GetDataByPosition(L, 0, &returnData);
    printf("Get Data By Position 0 : %d\n", returnData);
    returnData = -1;
    DoublyList_GetDataByPosition(L, 1, &returnData);
    printf("Get Data By Position 1 : %d\n", returnData);
    returnData = -1;
    DoublyList_GetDataByPosition(L, 13, &returnData);
    printf("Get Data By Position 13 : %d\n", returnData);
    returnData = -1;
    DoublyList_GetDataByPosition(L, 14, &returnData);
    printf("Get Data By Position 14 : %d\n", returnData);
    returnData = -1;
    DoublyList_GetDataByPosition(L, 15, &returnData);
    printf("Get Data By Position 15 : %d\n", returnData);

    printf("================================================\n");

    ElemType del = -1;
    DoublyList_DeleteNodeByPosition(L, 0, &del);
    DoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    DoublyList_DeleteNodeByPosition(L, 1, &del);
    DoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    DoublyList_DeleteNodeByPosition(L, 5, &del);
    DoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    DoublyList_DeleteNodeByPosition(L, 12, &del);
    DoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");
    del = -1;
    DoublyList_DeleteNodeByPosition(L, 12, &del);
    DoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    printf("\n");

    printf("================================================\n");

    DoublyList_DeleteNodeByData(L, 1234, &del);
    DoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    DoublyList_DeleteNodeByData(L, 666, &del);
    DoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }
    DoublyList_DeleteNodeByData(L, 6, &del);
    DoublyList_Print(L);
    if (del != -1) {
        printf("Deleted Node : %d\n", del);
    } else {
        printf("Deleted Node : NULL\n");
    }

    printf("================================================\n");

    DoublyList_Destroy(L);
    if (L->length == 0 && L->front == NULL && L->rear == NULL) {
        printf("LinkList Destroyed!\n");
        printf("Length: %d\n", DoublyList_GetLength(L));
        if (DoublyList_IsEmpty(L)) {
            printf("LinkList is empty!\n");
        } else {
            printf("LinkList is not empty!\n");
        }
    } else {
        printf("LinkList Not Destroyed!\n");
    }
    return 0;
}