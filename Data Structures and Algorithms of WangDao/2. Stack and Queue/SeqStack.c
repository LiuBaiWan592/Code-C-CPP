/**
 * @FileName    :SeqStack.c
 * @Date        :2025-03-09 21:56:35
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequence Stack
 * @Description :
 */

#define MAXSIZE 10
#define ElemType int

typedef struct {
    ElemType data[MAXSIZE];
    int top;
}SeqStack;

