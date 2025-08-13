/**
 * @FileName    :Driver_SeqDeQueue.c
 * @Date        :2025-08-11 23:21:00
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../SeqDeQueue.h"

/* Driver Code */
int main() {
    int capacity = 10;
    SeqDeQueue Q = SeqDeQueue_Init(capacity);
    SeqDeQueue_Print(Q);
    SeqDeQueue_EnterFront(Q, 1);
    SeqDeQueue_EnterFront(Q, 2);
    SeqDeQueue_EnterFront(Q, 3);
    SeqDeQueue_Print(Q);
    SeqDeQueue_EnterRear(Q, 4);
    SeqDeQueue_EnterRear(Q, 5);
    SeqDeQueue_Print(Q);

    printf("Length: %d\n", SeqDeQueue_GetLength(Q));
    printf("Is empty: %d\n", SeqDeQueue_IsEmpty(Q));
    printf("Is full: %d\n", SeqDeQueue_IsFull(Q));

    printf("Delete front: %d\n", SeqDeQueue_DeleteFront(Q));
    printf("Delete rear: %d\n", SeqDeQueue_DeleteRear(Q));

    printf("Front: %d\n", SeqDeQueue_GetFront(Q));
    printf("Rear: %d\n", SeqDeQueue_GetRear(Q));

    SeqDeQueue_Clear(Q);
    SeqDeQueue_Print(Q);

    Q = SeqDeQueue_Destroy(Q);
    if (Q == NULL) {
        printf("SeqDeQueue Destroyed!\n");
    } else {
        printf("SeqDeQueue Not Destroyed!\n");
    }
    return 0;
}