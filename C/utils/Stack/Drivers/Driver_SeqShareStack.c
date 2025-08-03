/**
 * @FileName    :Driver_SeqShareStack.c
 * @Date        :2025-03-13 21:57:55
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :
 * @Description :
 */

#include "../SeqShareStack.h"

 /* Driver Code */
int main() {
    int capacity = 10;
    SeqShareStack S = SeqShareStack_Init(capacity);
    SeqShareStack_Push(S, 1, 1);
    SeqShareStack_Push(S, 1, 2);
    SeqShareStack_Push(S, 1, 3);
    SeqShareStack_Push(S, 2, 4);
    SeqShareStack_Push(S, 2, 5);
    SeqShareStack_Push(S, 2, 6);
    SeqShareStack_Push(S, 2, 7);
    SeqShareStack_Push(S, 2, 8);
    SeqShareStack_Push(S, 2, 9);
    SeqShareStack_Push(S, 2, 10);
    // SeqShareStack_Push(S, 2, 11);        // The stack is full, so this line will cause an error

    SeqShareStack_Print(S);

    printf("Top: %d\n", SeqShareStack_GetTop(S, 2));

    printf("Pop: %d\n", SeqShareStack_Pop(S, 2));

    bool empty = SeqShareStack_IsEmpty(S, 2);
    printf("Is Empty: %s\n", empty ? "true" : "false");
    int length = SeqShareStack_GetLength(S, 2);
    printf("Length: %d\n", length);

    SeqShareStack_Print(S);

    SeqShareStack_Clear(S);
    SeqShareStack_Print(S);

    SeqShareStack_Destroy(S);
    return 0;
}