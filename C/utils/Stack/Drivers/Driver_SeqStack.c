/**
 * @FileName    :Driver_SeqStack.c
 * @Date        :2025-03-12 14:27:36
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "../SeqStack.h"

/* Driver Code */
int main() {
    SeqStack S = SeqStack_Init();
    SeqStack_Push(S, 1);
    SeqStack_Push(S, 3);
    SeqStack_Push(S, 2);
    SeqStack_Push(S, 5);
    SeqStack_Push(S, 4);

    SeqStack_Print(S);

    ElemType top;
    SeqStack_GetTop(S, &top);
    printf("Top: %d\n", top);

    ElemType pop;
    SeqStack_Pop(S, &pop);
    printf("Pop: %d\n", pop);

    bool empty = SeqStack_IsEmpty(S);
    printf("Is Empty: %s\n", empty ? "true" : "false");
    int length = SeqStack_GetLength(S);
    printf("Length: %d\n", length);

    SeqStack_Print(S);
    SeqStack_Clear(S);
    SeqStack_Print(S);

    S = SeqStack_Destroy(S);
    return 0;
}