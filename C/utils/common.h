/**
 * @FileName    :common.h
 * @Date        :2025-03-07 20:13:57
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :
 * @Description :
 */

#ifndef COMMON_H
#define COMMON_H

#ifndef ElemType
#define ElemType int
#endif // ElemType

#ifndef Maxsize
#define Maxsize 10
#endif // Maxsize

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "Node.h"

#include "./LinearList/CirDoublyList.h"
#include "./LinearList/CirLinkList.h"
#include "./LinearList/DoublyList.h"
#include "./LinearList/LinkList.h"
#include "./LinearList/SeqList.h"
#include "./LinearList/SeqListDyn.h"

#include "./Stack/SeqStack.h"
#include "./Stack/SeqShareStack.h"
#include "./Stack/LinkStack.h"


#include "./uthash/src/uthash.h" // uthash库

#endif // COMMON_H