/**
 * @FileName    :05_Fibonacci_Sequence.c
 * @Date        :2025-08-06 23:52:59
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Fibonacci sequence
 * @Description :Using Stack and Recursive Computation to Calculate Fibonacci Sequence
 * 
 *              :Using Stack to Calculate Fibonacci Sequence:
 *              :1. Create a stack and push 0 and 1 into the stack
 *              :2. Pop the top two elements from the stack and push the sum of them into the stack
 *              :3. Repeat step 2 until the desired Fibonacci number is obtained
 * 
 *              :Using Recursive Computation to Calculate Fibonacci Sequence:
 *              :1. Define a recursive function that calculates the Fibonacci number
 *              :2. Call the recursive function with the desired Fibonacci number as the argument
 *              :3. Return the result of the recursive function
 */


#define ElemType int

#include "common.h"


// Using Stack to Calculate Fibonacci Sequence
int Fibonacci_Stack(int n) {
    LinkStack S = LinkStack_Init();
    LinkStack_Push(S, 0);
    LinkStack_Push(S, 1);
    for (int i = 2; i <= n; i++) {
        int x = LinkStack_Pop(S);
        int y = LinkStack_Pop(S);
        LinkStack_Push(S, x);
        LinkStack_Push(S, x + y);
    }
    return LinkStack_Pop(S);
}

// Using Recursive Computation to Calculate Fibonacci Sequence
int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main() {
    int n = 10;
    printf("Using Stack to Calculate Fibonacci Sequence:\n");
    printf("Fibonacci(%d) = %d\n", n, Fibonacci_Stack(n));
    printf("Using Recursive Computation to Calculate Fibonacci Sequence:\n");
    printf("Fibonacci(%d) = %d\n", n, Fibonacci(n));
    return 0;
}