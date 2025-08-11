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

    ElemType x;
    SeqDeQueue_DeleteFront(Q, &x);
    printf("Delete front: %d\n", x);
    SeqDeQueue_DeleteRear(Q, &x);
    printf("Delete rear: %d\n", x);

    SeqDeQueue_GetFront(Q, &x);
    printf("Front: %d\n", x);
    SeqDeQueue_GetRear(Q, &x);
    printf("Rear: %d\n", x);

    SeqDeQueue_Clear(Q);
    SeqDeQueue_Print(Q);

    SeqDeQueue_Destroy(Q);
    return 0;
}