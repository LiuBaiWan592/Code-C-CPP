/**
 * @FileName    :Driver_SeqList_Dyn.c
 * @Date        :2025-03-07 20:18:29
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../SeqList_Dyn.h"

/* Driver Code */
int main() {
    SeqListDyn L = List_Dyn_Init();
    for (int i = 0; i < 6; i++) {
        List_Dyn_InsertEnd(L, i);
    }
    List_Dyn_Print(L);

    printf("Length: %d\n", List_Dyn_GetLength(L));

    if (List_Dyn_IsEmpty(L)) {
        printf("List is empty!\n");
    } else {
        printf("List is not empty!\n");
    }

    printf("Element at index 2: %d\n", List_Dyn_GetElem(L, 2));
    printf("Index of element 3: %d\n", List_Dyn_LocateElem(L, 3));

    printf("================================================\n");

    List_Dyn_Insert(L, 9, 0);
    List_Dyn_Insert(L, 99, 1);
    List_Dyn_Insert(L, 999, 3);
    printf("Length: %d\n", List_Dyn_GetLength(L));
    List_Dyn_Insert(L, 9999, 10);
    List_Dyn_Insert(L, 99999, 9);
    List_Dyn_Insert(L, 999999, 11);
    List_Dyn_Insert(L, 9999999, 10);
    List_Dyn_Insert(L, 99999999, 11);
    List_Dyn_Print(L);

    printf("================================================\n");

    ElemType e;
    List_Dyn_Delete(L, 0, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 1, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 7, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 8, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 9, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    List_Dyn_Delete(L, 10, &e);
    printf("Deleted Element: %d\n", e);
    List_Dyn_Print(L);
    printf("\n");

    printf("================================================\n");

    List_Dyn_Destroy(L);
    List_Dyn_Print(L);
    return 0;
}