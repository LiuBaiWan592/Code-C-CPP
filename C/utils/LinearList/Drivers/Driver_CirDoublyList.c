/**
 * @FileName    :Driver_CirDoublyList.c
 * @Date        :2025-03-07 20:28:07
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :
 * @Description :
 */

#include "../CirDoublyList.h"

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
        printf("DoublyList is empty!\n");
    } else {
        printf("DoublyList is not empty!\n");
    }

    printf("================================================\n");

    DNode *p = NULL;
    ElemType data = 666;
    p = CirDoublyList_GetNodeByData(L, data);
    if (p != NULL) {
        printf("Found Node By Data %d : %d\n", data, CirDoublyList_GetData(p));
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }
    data = 100;
    p = CirDoublyList_GetNodeByData(L, data);
    if (p != NULL) {
        printf("Found Node By Data %d : %d\n", data, CirDoublyList_GetData(p));
    } else {
        printf("Not Found Node By Data %d !\n", data);
    }

    printf("================================================\n");

    int position = 0;
    p = CirDoublyList_GetNodeByPosition(L, position);
    if (p != NULL) {
        printf("Found Node By Position %d : %d\n", position, CirDoublyList_GetData(p));
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 5;
    p = CirDoublyList_GetNodeByPosition(L, position);
    if (p != NULL) {
        printf("Found Node By Position %d : %d\n", position, CirDoublyList_GetData(p));
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 14;
    p = CirDoublyList_GetNodeByPosition(L, position);
    if (p != NULL) {
        printf("Found Node By Position %d : %d\n", position, CirDoublyList_GetData(p));
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }
    position = 15;
    p = CirDoublyList_GetNodeByPosition(L, position);
    if (p != NULL) {
        printf("Found Node By Position %d : %d\n", position, CirDoublyList_GetData(p));
    } else {
        printf("Not Found Node By Position %d !\n", position);
    }

    printf("================================================\n");

    int index = -1;
    index = CirDoublyList_GetPositionByNode(L, node);
    if (index == -1) {
        printf("Not Found Position By Node (node) !\n");
    } else {
        printf("Found Position By Node (node) : %d\n", index);
    }

    // p = NULL;is not a valid node
    /*
    p = NULL;
    index = CirDoublyList_GetPositionByNode(L, p);
    if (index == -1) {
        printf("Not Found Position By Node p !\n");
    } else {
        printf("Found Position By Node p : %d\n", index);
    }
    */

    printf("================================================\n");

    index = CirDoublyList_GetPositionByData(L, 666);
    if (index == -1) {
        printf("Not Found Position By Data (666) !\n");
    } else {
        printf("Found Position By Data (666) : %d\n", index);
    }
    index = CirDoublyList_GetPositionByData(L, 888);
    if (index == -1) {
        printf("Not Found Position By Data 888 !\n");
    } else {
        printf("Found Position By Data 888 : %d\n", index);
    }

    printf("================================================\n");

    // printf("Get Data By Position 0 : %d\n", CirDoublyList_GetDataByPosition(L, 0));       // index out of range
    printf("Get Data By Position 1 : %d\n", CirDoublyList_GetDataByPosition(L, 1));
    printf("Get Data By Position 13 : %d\n", CirDoublyList_GetDataByPosition(L, 13));
    printf("Get Data By Position 14 : %d\n", CirDoublyList_GetDataByPosition(L, 14));
    // printf("Get Data By Position 15 : %d\n", CirDoublyList_GetDataByPosition(L, 15));     // index out of range

    printf("================================================\n");

    // printf("Deleted Node : %d\n", CirDoublyList_DeleteNodeByPosition(L, 0));              // index out of range
    printf("Deleted Node : %d\n", CirDoublyList_DeleteNodeByPosition(L, 1));
    printf("Deleted Node : %d\n", CirDoublyList_DeleteNodeByPosition(L, 5));
    printf("Deleted Node : %d\n", CirDoublyList_DeleteNodeByPosition(L, 12));
    // printf("Deleted Node : %d\n", CirDoublyList_DeleteNodeByPosition(L, 12));             // index out of range
    CirDoublyList_Print(L);

    printf("================================================\n");

    // printf("Deleted Node : %d\n", CirDoublyList_DeleteNodeByData(L, 1234));
    printf("Deleted Node : %d\n", CirDoublyList_DeleteNodeByData(L, 666));
    printf("Deleted Node : %d\n", CirDoublyList_DeleteNodeByData(L, 6));

    CirDoublyList_Print(L);

    printf("================================================\n");

    L = CirDoublyList_Destroy(L);
    if (L == NULL) {
        printf("DoublyList Destroyed!\n");
    } else {
        printf("DoublyList Not Destroyed!\n");
    }
    return 0;
}