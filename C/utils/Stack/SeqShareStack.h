/**
 * @FileName    :SeqShareStack.h
 * @Date        :2025-03-13 21:57:06
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Sequential shared stack
 * @Description :
 *              :SeqShareStack_Init: Initialize the Sequence Stack
 *              :SeqShareStack_GetLength: Get the length of the Stack(S) [O(1)]
 *              :SeqShareStack_IsEmpty: Check if the Stack(S) is empty [O(1)]
 *              :SeqShareStack_IsFull: Check if the Stack(S) is full [O(1)]
 *              :SeqShareStack_Push: Push Element to the Stack(S) [O(1)]
 *              :SeqShareStack_Pop: Pop Element from the Stack(S) [O(1)]
 *              :SeqShareStack_GetTop: Get the top Element of the Stack(S) [O(1)]
 *              :SeqShareStack_Clear: Clear the Stack(S)
 *              :SeqShareStack_Destroy: Destroy the Stack(S)
 *              :SeqShareStack_Print: Print the Stack(S) [O(n)]
 */

#ifndef SEQSHARESTACK_H
#define SEQSHARESTACK_H

#include "../common.h"
 
 /* Sequential shared stack */
 typedef struct {
     ElemType *data;
     int top_a, top_b;
     int length_a, length_b;
 } *SeqShareStack;
 
 /* Initialize the Sequence Share Stack */
 SeqShareStack SeqShareStack_Init() {
     SeqShareStack S = (SeqShareStack)malloc(sizeof(SeqShareStack));
     S->top_a = -1;
     S->top_b = Maxsize;
     S->length_a = 0;
     S->length_b = 0;
     S->data = (ElemType *)malloc(sizeof(ElemType) * Maxsize);
     for (int i = 0; i < Maxsize; i++) {
         S->data[i] = 0;
     }
     return S;
 }
 
 /* Get the length of the Stack(S) [O(1)] */
 int SeqShareStack_GetLength(SeqShareStack S, int flag) {
     if (flag == 1) {
         // return S->length_a;
         return S->top_a + 1;
     } else {
         // return S->length_b;
         return Maxsize - S->top_b;
     }
 }
 
 /* Check if the Stack(S) is empty [O(1)] */
 bool SeqShareStack_IsEmpty(SeqShareStack S, int flag) {
     if (flag == 1) {
         // return S->top_a == -1;
         return S->length_a == 0;
     } else {
         // return S->top_b == Maxsize;
         return S->length_b == 0;
     }
 }
 
 /* Check if the Stack(S) is full [O(1)] */
 bool SeqShareStack_IsFull(SeqShareStack S) {
     // return S->length_a + S->length_b == Maxsize;
     return S->top_a + 1 == S->top_b;
 }
 
 /* Push Element to the Stack(S) [O(1)] */
 bool SeqShareStack_Push(SeqShareStack S, int flag, ElemType e) {
     if (SeqShareStack_IsFull(S)) {
         printf("Push Error: Stack is Full! Failed to Push Element %d!\n", e);
         return false;
     }
     if (flag == 1) {
         S->data[++S->top_a] = e;
         S->length_a++;
     } else {
         S->data[--S->top_b] = e;
         S->length_b++;
     }
     return true;
 }
 
 /* Pop Element from the Stack(S) [O(1)] */
 bool SeqShareStack_Pop(SeqShareStack S, int flag, ElemType *e) {
     if (SeqShareStack_IsEmpty(S, flag)) {
         printf("Pop Error: Stack is Empty! Failed to Pop Element!\n");
         return false;
     }
     if (flag == 1) {
         *e = S->data[S->top_a--];
         S->length_a--;
     } else {
         *e = S->data[S->top_b++];
         S->length_b--;
     }
     return true;
 }
 
 /* Get the top Element of the Stack(S) [O(1)] */
 bool SeqShareStack_GetTop(SeqShareStack S, int flag, ElemType *e) {
     if (SeqShareStack_IsEmpty(S, flag)) {
         printf("GetTop Error: Stack is Empty! Failed to Get Top Element!\n");
         return false;
     }
     if (flag == 1) {
         *e = S->data[S->top_a];
     } else {
         *e = S->data[S->top_b];
     }
     return true;
 }
 
 /* Clear the Stack(S) */
 bool SeqShareStack_Clear(SeqShareStack S) {
     if (S == NULL) {
         return false;
     }
     S->top_a = -1;
     S->top_b = Maxsize;
     S->length_a = 0;
     S->length_b = 0;
     return true;
 }
 
 /* Destroy the Stack(S) */
 bool SeqShareStack_Destroy(SeqShareStack S) {
     if (S == NULL) {
         return false;
     }
     free(S->data);
     free(S);
     S = NULL;
     return true;
 }
 
 /* Print the Stack(S) [O(n)] */
 void SeqShareStack_Print(SeqShareStack S) {
     printf("Sequence Share Stack: ");
     if (SeqShareStack_IsEmpty(S, 1) && SeqShareStack_IsEmpty(S, 2)) {
         printf("Empty Stack!\n");
         return;
     } else {
         printf("\n");
     }
     printf("  Index: ");
     for (int i = 0; i < Maxsize; i++) {
         printf("%d    ", i);
     }
     printf("\n");
     printf("  Value: ");
     for (int i = 0; i < S->top_a + 1; i++) {
         printf("%d    ", S->data[i]);
     }
     for(int i = S->top_a + 1; i < S->top_b; i++) {
         printf("%d    ", 0);
     }
     for(int i = S->top_b; i < Maxsize; i++) {
         printf("%d    ", S->data[i]);
     }
     printf("\n");
     return;
 }

 #endif //SEQSHARESTACK_H