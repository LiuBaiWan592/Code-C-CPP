/**
 * @FileName    :02_Convert_Infix_Notation_to_Postfix_Notation.c
 * @Date        :2025-08-01 22:05:11
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Convert infix notation to postfix notation(Reverse Polish notation, RPN)
 * @Description :Using the stack data structure to convert infix notation to postfix notation(RPN).
 *              :The algorithm is as follows:
 *              :1. Initialize an empty stack.
 *              :2. Traverse the infix expression from left to right.
 *              :3. If the current character is an operand, add it to the output string.
 *              :4. If the current character is a left parenthesis, push it onto the stack.
 *              :5. If the current character is a right parenthesis, pop operators from the stack and add them to the output string
 *                  until the left parenthesis is encountered.
 *              :6. If the current character is an operator, pop operators from the stack and add them to the output string
 *                  until the stack is empty or the top of the stack is an operator with lower precedence or a left parenthesis.
 *                  Then push the current operator onto the stack.
 *              :7. Repeat steps 2-6 until the end of the infix expression is reached.
 *              :8. Pop any remaining operators from the stack and add them to the output string.
 *              :9. The output string is the postfix notation of the infix expression.
 */

#define Elemtype char

#include "common.h"

/**
 * @brief  Convert infix notation to postfix notation(Reverse Polish notation, RPN)
 * @param  infix  The infix expression
 * @param  postfix The postfix expression
 * @retval None
 * @note   None
 */
void InfixToPostfix(Elemtype *infix, Elemtype *postfix) {
    LinkStack S = LinkStack_Init();
    int i = 0, j = 0;               // i is the index of the infix expression, j is the index of the postfix expression
    while (infix[i] != '\0') {
        switch (infix[i]) {
        case '(':       // If the current character is a left parenthesis, push it onto the stack.
            LinkStack_Push(S, infix[i]);
            break;
        case ')':       // If the current character is a right parenthesis, pop operators from the stack and add them to the output string
            while (LinkStack_GetTop(S) != '(') {        // until the left parenthesis is encountered.
                postfix[j++] = LinkStack_Pop(S);
            }
            LinkStack_Pop(S);       // Pop the left parenthesis from the stack.
            break;
        // If the current character is an operator, pop operators from the stack and add them to the output string
        // until the stack is empty or the top of the stack is an operator with lower precedence or a left parenthesis.
        case '+':
        case '-':
            while (!LinkStack_IsEmpty(S) && LinkStack_GetTop(S) != '(') {
                postfix[j++] = LinkStack_Pop(S);
            }
            LinkStack_Push(S, infix[i]);    // Then push the current operator onto the stack.
            break;
        case '*':
        case '/':
            while (!LinkStack_IsEmpty(S) && LinkStack_GetTop(S) != '(' && LinkStack_GetTop(S) != '+' && LinkStack_GetTop(S) != '-') {
                postfix[j++] = LinkStack_Pop(S);
            }
            LinkStack_Push(S, infix[i]);    // Then push the current operator onto the stack.
            break;
        default:        // If the current character is an operand, add it to the output string.
            postfix[j++] = infix[i];
            break;
        }
        i++;
    }
    // Pop any remaining operators from the stack and add them to the output string.
    while (!LinkStack_IsEmpty(S)) {
        postfix[j++] = LinkStack_Pop(S);
    }
    postfix[j] = '\0';
    return;
}

int main() {
    printf("Infix notation to postfix notation:\n\n");
    printf("Infix notation\t\tPostfix notation\n");
    // Elemtype infix[20];
    Elemtype infix[4][20] = {"a+b*c-(d/e+f)*g", "a+b*c-d/e+f*g", "a+b*(c-d)-e/f", "a+b-c*d/e+f"};
    for(int i = 0; i < 4; i++) {
        Elemtype postfix[20];
        InfixToPostfix(infix[i], postfix);
        printf("%s\t\t%s\n", infix[i], postfix);
    }

    return 0;
}


    // "a+b*c-(d/e+f)*g"       abc*+de/f+g*-
    // "a+b*c-d/e+f*g"         abc*+de/-fg*+
    // "a+b*(c-d)-e/f"         abcd-*+ef/-
    // "a+b-c*d/e+f"           ab+cd*e/-f+