/**
 * @FileName    :Driver_SeqQueue.c
 * @Date        :2025-08-08 21:52:41
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../SeqQueue.h"

/* Driver Code */
int main() {
    int capacity = 4;
    SeqQueue Q = SeqQueue_Init(capacity);
    SeqQueue_Enter(Q, 1);
    SeqQueue_Enter(Q, 2);
    SeqQueue_Enter(Q, 3);
    SeqQueue_Enter(Q, 4);
    SeqQueue_Enter(Q, 5);
    SeqQueue_Print(Q);

    printf("Delete: %d\n", SeqQueue_Delete(Q));
    printf("Delete: %d\n", SeqQueue_Delete(Q));

    SeqQueue_Enter(Q, 4);
    SeqQueue_Enter(Q, 5);
    SeqQueue_Print(Q);
    
    printf("Front: %d\n", SeqQueue_GetFront(Q));
    SeqQueue_Print(Q);
    printf("Length: %d\n", SeqQueue_GetLength(Q));
    printf("Is Empty: %d\n", SeqQueue_IsEmpty(Q));
    printf("Is Full: %d\n", SeqQueue_IsFull(Q));
    SeqQueue_Clear(Q);
    printf("Is Empty: %d\n", SeqQueue_IsEmpty(Q));
    SeqQueue_Print(Q);
    Q = SeqQueue_Destroy(Q);
    if (Q == NULL) {
        printf("SeqQueue Destroyed!\n");
    } else {
        printf("SeqQueue Not Destroyed!\n");
    }
    return 0;
}