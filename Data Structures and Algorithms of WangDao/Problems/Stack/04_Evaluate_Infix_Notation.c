/**
 * @FileName    :04_Evaluate_Infix_Notation.c
 * @Date        :2025-08-06 22:23:39
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Evaluate Infix Notation
 * @Description :Using the stack data structure to evaluate infix notation
 *              :The algorithm is as follows:
 *              :1. Initialize an empty stack for operands and an empty stack for operators.
 *              :2. Read the infix expression from left to right.
 *              :3. If the current character is a digit, push it onto the operand stack.
 *              :4. If the current character is an operator, pop the top two operands from the operand stack,
 *              :   perform the operation, and push the result back onto the operand stack.
 *              :5. If the current character is an opening parenthesis, push it onto the operator stack.
 *              :6. If the current character is a closing parenthesis, pop operators from the operator stack
 *              :   and operands from the operand stack until an opening parenthesis is encountered.
 *              :7. Repeat steps 2-6 until the end of the infix expression is reached.
 *              :8. Pop any remaining operators from the operator stack and perform the operations.
 *              :9. The final result will be the top element of the operand stack.
 */

#define ElemType int

#include "common.h"

int EvaluateInfixNotation(char *infix, int length) {
    SeqStack S_operands = SeqStack_Init(length);
    SeqStack S_operators = SeqStack_Init(length);

    for (int i = 0; i < length; i++) {
        if( infix[i] >= '0' && infix[i] <= '9') {
            SeqStack_Push(S_operands, infix[i]-'0');
        } else {
            switch(infix[i]){
                case '(':
                    SeqStack_Push(S_operators, (int)infix[i]);
                    break;
                case ')':
                    while((char)SeqStack_GetTop(S_operators) != '(') {
                        int operand2 = SeqStack_Pop(S_operands);
                        int operand1 = SeqStack_Pop(S_operands);
                        char operator = (char)SeqStack_Pop(S_operators);
                        int result = 0;
                        switch(operator) {
                            case '+':
                                result = operand1 + operand2;
                                break;
                            case '-':
                                result = operand1 - operand2;
                                break;
                            case '*':
                                result = operand1 * operand2;
                                break;
                            case '/':
                                result = operand1 / operand2;
                                break;
                            default:
                                break;
                        }
                        SeqStack_Push(S_operands, result);
                    }
                    SeqStack_Pop(S_operators);
                    break;
                case '+':
                case '-':
                    while(!SeqStack_IsEmpty(S_operators) 
                           && (char)SeqStack_GetTop(S_operators) != '('){
                        int operand2 = SeqStack_Pop(S_operands);
                        int operand1 = SeqStack_Pop(S_operands);
                        char operator = (char)SeqStack_Pop(S_operators);
                        int result = 0;
                        switch(operator) {
                            case '+':
                                result = operand1 + operand2;
                                break;
                            case '-':
                                result = operand1 - operand2;
                                break;
                            case '*':
                                result = operand1 * operand2;
                                break;
                            case '/':
                                result = operand1 / operand2;
                                break;
                            default:
                                break;
                        }
                        SeqStack_Push(S_operands, result);
                    }
                    SeqStack_Push(S_operators, (int)infix[i]);
                    break;
                case '*':
                case '/':
                    while(!SeqStack_IsEmpty(S_operators) 
                           && (char)SeqStack_GetTop(S_operators) != '('
                           && (char)SeqStack_GetTop(S_operators) != '+'
                           && (char)SeqStack_GetTop(S_operators) != '-'){
                        int operand2 = SeqStack_Pop(S_operands);
                        int operand1 = SeqStack_Pop(S_operands);
                        char operator = (char)SeqStack_Pop(S_operators);
                        int result = 0;
                        switch(operator) {
                            case '*':
                                result = operand1 * operand2;
                                break;
                            case '/':
                                result = operand1 / operand2;
                                break;
                            default:
                                break;
                        }
                        SeqStack_Push(S_operands, result);
                    }
                    SeqStack_Push(S_operators, (int)infix[i]);
                    break;
            }
        }
    }
    while(!SeqStack_IsEmpty(S_operators)) {
        int operand2 = SeqStack_Pop(S_operands);
        int operand1 = SeqStack_Pop(S_operands);
        char operator = (char)SeqStack_Pop(S_operators);
        int result = 0;
        switch(operator) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                break;
        }
        SeqStack_Push(S_operands, result);
    }
    return SeqStack_Pop(S_operands);
}

int main() {
    printf("Evaluate Infix Notation:\n\n");
    printf("Infix notation\t\tResult\n");
    char Infix[4][20] = {"1+2*3-(4/1+6)*7", "1+2*3-4/1+6*7", "1+2*(3-4)-5/1", "1+2-3*4/1+6"};
    for(int i = 0; i < 4; i++) {
        printf("%s\t\t%d\n", Infix[i], EvaluateInfixNotation(Infix[i], strlen(Infix[i])));
    }

    return 0;
}

    // infix notation           postfix notation        Result
    // "1+2*3-(4/1+6)*7"        123*+41/6+7*-           -63
    // "1+2*3-4/1+6*7"          123*+41/-67*+           45
    // "1+2*(3-4)-5/1"          1234-*+51/-             -6
    // "1+2-3*4/1+6"            12+34*1/-6+             -3