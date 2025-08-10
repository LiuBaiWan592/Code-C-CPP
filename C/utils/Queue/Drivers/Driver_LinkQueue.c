/**
 * @FileName    :Driver_LinkQueue.c
 * @Date        :2025-08-10 22:25:45
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../LinkQueue.h"

/* Driver Code */
int main() {
    LinkQueue Q = LinkQueue_Init();
    LinkQueue_Enter(Q, 1);
    LinkQueue_Enter(Q, 2);
    LinkQueue_Enter(Q, 3);
    LinkQueue_Enter(Q, 4);
    LinkQueue_Enter(Q, 5);
    LinkQueue_Print(Q);
    
    printf("Delete: %d\n", LinkQueue_Delete(Q));
    printf("Delete: %d\n", LinkQueue_Delete(Q));

    LinkQueue_Enter(Q, 4);
    LinkQueue_Enter(Q, 5);
    LinkQueue_Print(Q);

    printf("Front: %d\n", LinkQueue_GetFront(Q));
    LinkQueue_Print(Q);
    printf("Length: %d\n", LinkQueue_GetLength(Q));
    printf("Is Empty: %d\n", LinkQueue_IsEmpty(Q));
    LinkQueue_Clear(Q);
    printf("Is Empty: %d\n", LinkQueue_IsEmpty(Q));
    LinkQueue_Print(Q);
    LinkQueue_Destroy(Q);
    return 0;
}