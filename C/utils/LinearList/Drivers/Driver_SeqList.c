/**
 * @FileName    :Driver_SeqList.c
 * @Date        :2025-03-07 20:14:48
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../utils/SeqList.h"

/* Driver Code */
int main() {
    SQList List = List_Init();
    SeqList L = &List;
    for (int i = 0; i < 6; i++) {
        List_InsertEnd(L, i);
    }
    List_Print(L);

    printf("Length: %d\n", List_GetLength(L));

    if (List_IsEmpty(L)) {
        printf("List is empty!\n");
    } else {
        printf("List is not empty!\n");
    }

    printf("Element at index 2: %d\n", List_GetElem(L, 2));
    printf("Index of element 3: %d\n", List_LocateElem(L, 3));

    printf("================================================\n");

    List_Insert(L, 9, 0);
    List_Insert(L, 99, 1);
    List_Insert(L, 999, 3);
    printf("Length: %d\n", List_GetLength(L));
    List_Insert(L, 9999, 9);
    List_Insert(L, 99999, 10);
    List_Insert(L, 999999, 11);
    List_Print(L);

    printf("================================================\n");

    ElemType e;
    List_Delete(L, 0, &e);
    printf("Deleted Element: %d\n", e);
    List_Print(L);
    printf("\n");

    List_Delete(L, 1, &e);
    printf("Deleted Element: %d\n", e);
    List_Print(L);
    printf("\n");

    List_Delete(L, 7, &e);
    printf("Deleted Element: %d\n", e);
    List_Print(L);
    printf("\n");

    List_Delete(L, 8, &e);
    printf("Deleted Element: %d\n", e);
    List_Print(L);
    printf("\n");

    List_Delete(L, 10, &e);
    printf("Deleted Element: %d\n", e);
    List_Print(L);
    printf("\n");

    List_Delete(L, 11, &e);
    printf("Deleted Element: %d\n", e);
    List_Print(L);
    printf("\n");

    printf("================================================\n");

    List_Destroy(L);
    List_Print(L);
    return 0;
}