/**
 * @FileName    :Driver_CirLinkList.c
 * @Date        :2025-03-07 20:26:12
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../CirLinkList.h"

/* Driver Code */
int main() {
    CirLinkList L = CirLinkList_Init();

    printf("%ld\n", sizeof(*L));
    printf("%ld\n", sizeof(L->length));

    printf("================================================\n");

    ElemType dataset1[] = {1, 2, 3, 4, 5};
    int length1 = sizeof(dataset1) / sizeof(dataset1[0]);
    ElemType dataset2[] = {6, 7, 8, 9, 10};
    int length2 = sizeof(dataset2) / sizeof(dataset2[0]);

    CirLinkList_CreateByTailInsert(L, dataset1, length1);
    CirLinkList_Print(L);
    CirLinkList_CreateByHeadInsert(L, dataset2, length2);
    CirLinkList_Print(L);

    printf("================================================\n");

    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->data = 666;
    node->next = NULL;
    CirLinkList_InsertDataByPosition(L, 0, 999);
    CirLinkList_InsertDataByPosition(L, 1, 999);
    CirLinkList_InsertDataByPosition(L, 6, 999);
    CirLinkList_InsertNodeByPosition(L, 13, node);
    CirLinkList_InsertDataByPosition(L, 14, 999);
    CirLinkList_InsertDataByPosition(L, 16, 999);
    CirLinkList_Print(L);

    printf("================================================\n");

    printf("Length: %d\n", CirLinkList_GetLength(L));
    if (CirLinkList_IsEmpty(L)) {
        printf("LinkList is empty!\n");
    } else {
        printf("LinkList is not empty!\n");
    }

    printf("================================================\n");

    LNode *p = NULL;
    ElemType data = 666;
    p = CirLinkList_GetNodeByData(L, data);
    if (p != NULL) {
        printf("Found Node By Data %d : %d\n", data, CirLinkList_GetData(p));
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }
    data = 100;
    p = CirLinkList_GetNodeByData(L, data);
    if (p != NULL) {
        printf("Found Node By Data %d : %d\n", data, CirLinkList_GetData(p));
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }

    printf("================================================\n");

    int position = 0;
    p = CirLinkList_GetNodeByPosition(L, position);
    if (p != NULL) {
        printf("Found Node By Position %d : %d\n", position, CirLinkList_GetData(p));
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 5;
    p = CirLinkList_GetNodeByPosition(L, position);
    if (p != NULL) {
        printf("Found Node By Position %d : %d\n", position, CirLinkList_GetData(p));
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 14;
    p = CirLinkList_GetNodeByPosition(L, position);
    if (p != NULL) {
        printf("Found Node By Position %d : %d\n", position, CirLinkList_GetData(p));
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 15;
    p = CirLinkList_GetNodeByPosition(L, position);
    if (p != NULL) {
        printf("Found Node By Position %d : %d\n", position, CirLinkList_GetData(p));
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }

    printf("================================================\n");

    int index = -1;
    index = CirLinkList_GetPositionByNode(L, node);
    if (index == -1) {
        printf("Not Found Position By Node (node) !\n");
    } else {
        printf("Found Position By Node (node) : %d\n", index);
    }

    // p = NULL;is not a valid node
    /*
    p = NULL;
    index =CirLinkList_GetPositionByNode(L, p);
    if (index == -1) {
        printf("Not Found Position By Node p !\n");
    } else {
        printf("Found Position By Node p : %d\n", index);
    }
    */

    printf("================================================\n");

    index = CirLinkList_GetPositionByData(L, 666);
    if (index == -1) {
        printf("Not Found Position By Data (666) !\n");
    } else {
        printf("Found Position By Data (666) : %d\n", index);
    }
    index = CirLinkList_GetPositionByData(L, 888);
    if (index == -1) {
        printf("Not Found Position By Data 888 !\n");
    } else {
        printf("Found Position By Data 888 : %d\n", index);
    }

    printf("================================================\n");

    // printf("Get Data By Position 0 : %d\n",CirLinkList_GetDataByPosition(L, 0));       // index out of range
    printf("Get Data By Position 1 : %d\n", CirLinkList_GetDataByPosition(L, 1));
    printf("Get Data By Position 13 : %d\n", CirLinkList_GetDataByPosition(L, 13));
    printf("Get Data By Position 14 : %d\n", CirLinkList_GetDataByPosition(L, 14));
    // printf("Get Data By Position 15 : %d\n",CirLinkList_GetDataByPosition(L, 15));     // index out of range

    printf("================================================\n");

    // printf("Deleted Node : %d\n",CirLinkList_DeleteNodeByPosition(L, 0));              // index out of range
    printf("Deleted Node : %d\n", CirLinkList_DeleteNodeByPosition(L, 1));
    printf("Deleted Node : %d\n", CirLinkList_DeleteNodeByPosition(L, 5));
    printf("Deleted Node : %d\n", CirLinkList_DeleteNodeByPosition(L, 12));
    // printf("Deleted Node : %d\n",CirLinkList_DeleteNodeByPosition(L, 12));             // index out of range
    CirLinkList_Print(L);

    printf("================================================\n");

    // printf("Deleted Node : %d\n",CirLinkList_DeleteNodeByData(L, 1234));
    printf("Deleted Node : %d\n", CirLinkList_DeleteNodeByData(L, 666));
    printf("Deleted Node : %d\n", CirLinkList_DeleteNodeByData(L, 6));

    CirLinkList_Print(L);

    printf("================================================\n");

    L = CirLinkList_Destroy(L);
    if (L == NULL) {
        printf("LinkList Destroyed!\n");
    } else {
        printf("LinkList Not Destroyed!\n");
    }
    return 0;
}