/**
 * @FileName    :Test_common.c
 * @Date        :2025-03-07 20:29:46
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#include "common.h"

int main() {
    SQList List = List_Init();
    SeqList seqlist = &List;
    SeqListDyn seqlistdyn = List_Dyn_Init();
    LinkList linklist = LinkList_Init();
    DoublyList doublylist = DoublyList_Init();
    CirLinkList cirlinklist = CirLinkList_Init();
    CirDoublyList cirdoublylist = CirDoublyList_Init();
    SeqStack seqstack = SeqStack_Init();
    SeqShareStack seqsharestack = SeqShareStack_Init();
    LinkStack linkstack = LinkStack_Init();
    UT_hash_table * hashtable = (UT_hash_table *)malloc(sizeof(UT_hash_table));
    printf("Test common success!\n");
    return 0;
}