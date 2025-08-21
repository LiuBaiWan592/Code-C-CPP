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
    struct SeqList List = SeqList_Init();
    SeqList L = &List;
    int capacity = 10;
    SeqListDyn seqlistdyn = SeqListDyn_Init(capacity);
    LinkList linklist = LinkList_Init();
    DoublyList doublylist = DoublyList_Init();
    CirLinkList cirlinklist = CirLinkList_Init();
    CirDoublyList cirdoublylist = CirDoublyList_Init();

    SeqStack seqstack = SeqStack_Init(capacity);
    SeqShareStack seqsharestack = SeqShareStack_Init(capacity);
    LinkStack linkstack = LinkStack_Init();

    SeqQueue seqqueue = SeqQueue_Init(capacity);
    SeqDeQueue seqdequeue = SeqDeQueue_Init(capacity);
    LinkQueue linkqueue = LinkQueue_Init();
    LinkDeQueue linkdeque = LinkDeQueue_Init();

    struct SString sstring = SString_Init();
    SString S = &sstring;
    HString hstring = HString_Init(capacity);

    UT_hash_table * hashtable = (UT_hash_table *)malloc(sizeof(UT_hash_table));
    printf("Test common success!\n");
    return 0;
}