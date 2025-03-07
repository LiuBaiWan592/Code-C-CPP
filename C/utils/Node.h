/**
 * @FileName    :Node.h
 * @Date        :2025-03-07 20:43:20
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :
 * @Description :
 */

#ifndef NODE_H
#define NODE_H

#include "common.h"

/* Linked List Node*/
typedef struct LNode {
    ElemType data;      // Data
    struct LNode *next; // Next Node
} LNode;

typedef struct DNode {
    ElemType data;      // Data
    struct DNode *prior, *next; // Prior Node and Next Node
} DNode;

#endif // NODE_H