/**
 * @FileName    :03_Evaluate_Postfix_Notation.c
 * @Date        :2025-08-05 21:45:56
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Evaluate Postfix Notation
 * @Description :Using the stack data structure to evaluate postfix notation
 *              :The algorithm is as follows:
 *              :1. Initialize an empty stack.
 *              :2. Traverse the postfix expression from left to right.
 *              :3. If the current character is a digit, push it onto the stack.
 *              :4. If the current character is an operator, pop the top two elements from the stack.
 *              :   Perform the operation and push the result back onto the stack.
 *              :5. After traversing the entire expression, the stack should contain only one element, which is the result of the evaluation.
 *              :6. Pop the final result from the stack and return it.
 */

#define ElemType int

#include "common.h"

int EvaluatePostfixNotation(char *str, int length) {
    SeqStack S = SeqStack_Init(length);         // Initialize the stack
    for (int i = 0; str[i] != '\0'; i++) {          // Traverse the postfix expression
        if (str[i] >= '0' && str[i] <= '9') {
            SeqStack_Push(S, str[i] - '0');     // If the current character is a digit, push it onto the stack.
        } else {                                // If the current character is an operator
            int num2 = SeqStack_Pop(S);
            int num1 = SeqStack_Pop(S);         // Pop the top two elements from the stack.
            switch (str[i]) {                   // Perform the operation and push the result back onto the stack.
                case '+':
                    SeqStack_Push(S, num1 + num2);
                    break;
                case '-':
                    SeqStack_Push(S, num1 - num2);
                    break;
                case '*':
                    SeqStack_Push(S, num1 * num2);
                    break;
                case '/':
                    SeqStack_Push(S, num1 / num2);
                    break;
                default:
                    break;
            }
        }
    }
     // After traversing the entire expression, the stack should contain only one element, which is the result of the evaluation.
    return SeqStack_Pop(S);                    //Pop the final result from the stack and return it.
}

int main() {
    printf("Evaluate Postfix Notation:\n\n");
    printf("Postfix notation\t\tResult\n");
    char postfix[4][20] = {"123*+41/6+7*-", "123*+41/-67*+", "1234-*+51/-", "12+34*1/-6+"};
    for(int i = 0; i < 4; i++) {
        printf("%s\t\t%d\n", postfix[i], EvaluatePostfixNotation(postfix[i], strlen(postfix[i])));
    }

    return 0;
}

    // infix notation           postfix notation        Result
    // "1+2*3-(4/1+6)*7"        123*+41/6+7*-           -63
    // "1+2*3-4/1+6*7"          123*+41/-67*+           45
    // "1+2*(3-4)-5/1"          1234-*+51/-             -6
    // "1+2-3*4/1+6"            12+34*1/-6+             -3