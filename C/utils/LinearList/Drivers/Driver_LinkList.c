/**
 * @FileName    :Driver_LinkList.c
 * @Date        :2025-03-07 20:21:37
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../utils/LinkList.h"

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

    LinkList_Print(L);
    LinkList_Reverse(L);
    LinkList_Print(L);
    LinkList_Reverse(L);
    LinkList_Print(L);

    LinkList tmp = LinkList_Init();
    LinkList_Reverse(tmp);
    LinkList_HeadInsertData(tmp, 1);
    LinkList_Reverse(tmp);
    LinkList_HeadInsertData(tmp, 2);
    LinkList_HeadInsertData(tmp, 3);
    LinkList_HeadInsertData(tmp, 4);
    LinkList_HeadInsertData(tmp, 5);
    LinkList_Print(tmp);
    LinkList_Reverse(tmp);
    LinkList_Print(tmp);

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