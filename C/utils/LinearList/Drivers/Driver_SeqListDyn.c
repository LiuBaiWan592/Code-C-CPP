/**
 * @FileName    :Driver_SeqListDyn.c
 * @Date        :2025-03-07 20:18:29
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :
 * @Description :
 */

#include "../SeqListDyn.h"

/* Driver Code */
int main() {
    int capatity = 10;
    SeqListDyn L = SeqListDyn_Init(capatity);
    for (int i = 0; i < 6; i++) {
        SeqListDyn_InsertEnd(L, i);
    }

    printf("Length: %d\n", SeqListDyn_GetLength(L));

    SeqListDyn_Print(L);


    if (SeqListDyn_IsEmpty(L)) {
        printf("List is empty!\n");
    } else {
        printf("List is not empty!\n");
    }

    printf("Element at index 2: %d\n", SeqListDyn_GetElem(L, 2));
    printf("Index of element 3: %d\n", SeqListDyn_LocateElem(L, 3));

    printf("================================================\n");

    SeqListDyn_Insert(L, 9, 0);
    SeqListDyn_Insert(L, 99, 1);
    SeqListDyn_Insert(L, 999, 3);
    printf("Length: %d\n", SeqListDyn_GetLength(L));
    SeqListDyn_Insert(L, 9999, 9);
    SeqListDyn_Insert(L, 99999, 10);
    SeqListDyn_Insert(L, 999999, 11);
    SeqListDyn_Print(L);

    printf("================================================\n");

    ElemType e;
    SeqListDyn_Delete(L, 0, &e);
    printf("Deleted Element: %d\n", e);
    SeqListDyn_Print(L);
    printf("\n");

    SeqListDyn_Delete(L, 1, &e);
    printf("Deleted Element: %d\n", e);
    SeqListDyn_Print(L);
    printf("\n");

    SeqListDyn_Delete(L, 7, &e);
    printf("Deleted Element: %d\n", e);
    SeqListDyn_Print(L);
    printf("\n");

    SeqListDyn_Delete(L, 8, &e);
    printf("Deleted Element: %d\n", e);
    SeqListDyn_Print(L);
    printf("\n");

    SeqListDyn_Delete(L, 10, &e);
    printf("Deleted Element: %d\n", e);
    SeqListDyn_Print(L);
    printf("\n");

    SeqListDyn_Delete(L, 11, &e);
    printf("Deleted Element: %d\n", e);
    SeqListDyn_Print(L);
    printf("\n");

    printf("================================================\n");

    SeqListDyn_Destroy(L);
    SeqListDyn_Print(L);
    return 0;
}