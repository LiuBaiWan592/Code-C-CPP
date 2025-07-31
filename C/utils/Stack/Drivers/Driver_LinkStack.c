/**
 * @FileName    :Driver_LinkStack.c
 * @Date        :2025-07-28 18:22:10
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :
 * @Description :
 */

#include "../LinkStack.h"

/* Drive Code */
int main() {
    LinkStack S = LinkStack_Init();

    LinkStack_Push(S, 1);
    LinkStack_Push(S, 3);
    LinkStack_Push(S, 2);
    LinkStack_Push(S, 5);
    LinkStack_Push(S, 4);

    LinkStack_Print(S);

    ElemType top;
    LinkStack_GetTop(S, &top);
    printf("Top: %d\n", top);

    ElemType pop;
    LinkStack_Pop(S, &pop);
    printf("Pop: %d\n", pop);

    bool empty = LinkStack_IsEmpty(S);
    printf("Is Empty: %s\n", empty ? "true" : "false");

    LinkStack_Reverse(S);
    LinkStack_Print(S);
    LinkStack_Clear(S);
    LinkStack_Print(S);

    LinkStack_Destroy(S);
    return 0;
}