/**
 * @FileName    :Driver_SeqList.c
 * @Date        :2025-03-07 20:14:48
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../SeqList.h"

/* Driver Code */
int main() {
    struct SeqList List = SeqList_Init();
    SeqList L = &List;
    for (int i = 0; i < 6; i++) {
        SeqList_InsertEnd(L, i);
    }

    if (SeqList_IsEmpty(L)) {
        printf("List is empty!\n");
    } else {
        printf("List is not empty!\n");
    }

    printf("Length: %d\n", SeqList_GetLength(L));

    SeqList_Print(L);

    printf("Element at index 2: %d\n", SeqList_GetElem(L, 2));
    printf("Index of element 3: %d\n", SeqList_LocateElem(L, 3));

    printf("================================================\n");

    SeqList_Insert(L, 9, 0);
    SeqList_Insert(L, 99, 1);
    SeqList_Insert(L, 999, 3);
    printf("Length: %d\n", SeqList_GetLength(L));
    SeqList_Insert(L, 9999, 9);
    SeqList_Insert(L, 99999, 10);
    // SeqList_Insert(L, 999999, 11);  // Out of range
    SeqList_Print(L);

    printf("================================================\n");

    printf("Deleted Element: %d\n", SeqList_Delete(L, 0));
    SeqList_Print(L);
    printf("\n");

    printf("Deleted Element: %d\n", SeqList_Delete(L, 1));
    SeqList_Print(L);
    printf("\n");

    printf("Deleted Element: %d\n", SeqList_Delete(L, 7));
    SeqList_Print(L);
    printf("\n");

    // Out of Range
    /*
    printf("Deleted Element: %d\n", SeqList_Delete(L, 8));
    SeqList_Print(L);
    printf("\n");

    printf("Deleted Element: %d\n", SeqList_Delete(L, 10));
    SeqList_Print(L);
    printf("\n");

    printf("Deleted Element: %d\n", SeqList_Delete(L, 11));
    SeqList_Print(L);
    printf("\n");
    */

    printf("================================================\n");

    SeqList_Destroy(L);
    SeqList_Print(L);
    return 0;
}