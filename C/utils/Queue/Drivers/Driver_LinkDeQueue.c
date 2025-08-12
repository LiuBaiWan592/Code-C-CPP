/**
 * @FileName    :Driver_LinkDeQueue.c
 * @Date        :2025-08-12 23:20:11
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../LinkDeQueue.h"

/* Driver Code */
int main() {
    LinkDeQueue Q = LinkDeQueue_Init();
    LinkDeQueue_Print(Q);
    LinkDeQueue_EnterFront(Q, 1);
    LinkDeQueue_EnterFront(Q, 2);
    LinkDeQueue_EnterFront(Q, 3);
    LinkDeQueue_Print(Q);
    LinkDeQueue_EnterRear(Q, 4);
    LinkDeQueue_EnterRear(Q, 5);
    LinkDeQueue_Print(Q);

    printf("Length: %d\n", LinkDeQueue_GetLength(Q));
    printf("Is empty: %d\n", LinkDeQueue_IsEmpty(Q));

    ElemType x;
    LinkDeQueue_DeleteFront(Q, &x);
    printf("Delete front: %d\n", x);
    LinkDeQueue_DeleteRear(Q, &x);
    printf("Delete rear: %d\n", x);

    LinkDeQueue_GetFront(Q, &x);
    printf("Front: %d\n", x);
    LinkDeQueue_GetRear(Q, &x);
    printf("Rear: %d\n", x);
    
    LinkDeQueue_Clear(Q);
    LinkDeQueue_Print(Q);

    LinkDeQueue_Destroy(Q);
    return 0;
}