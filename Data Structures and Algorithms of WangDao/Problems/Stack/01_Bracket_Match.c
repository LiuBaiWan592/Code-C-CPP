/**
 * @FileName    :01_Bracket_Match.c
 * @Date        :2025-07-28 22:09:32
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V2.0.0
 * @Brief       :Stack to match brackets
 * @Description :Using the stack data structure to check whether the brackets in the string are matched.
 *              :if the brackets are matched, return true, otherwise return false.
 *              :The algorithm is as follows:
 *              :1. Initialize a stack.
 *              :2. Traverse the string from left to right.
 *              :3. If the current character is an opening bracket, push it into the stack.
 *              :4. If the current character is a closing bracket, pop the top element from the stack.
 *              :5. If the stack is empty, return false.
 *              :6. If the stack is not empty, continue to traverse the string.
 *              :7. If the stack is empty after traversing the string, return true.
 *              :8. If the stack is not empty after traversing the string, return false.
 *              :9. If the stack is empty, return true.
 *              :10. If the stack is not empty, return false.
 */

#define ElemType char

#include "common.h"

bool Bracket_Match(char *str, int length){
    SeqStack S = SeqStack_Init(length);         // Initialize a stack.
    for(int i = 0; i < length; i++){            // Traverse the string from left to right.
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){    
            SeqStack_Push(S, str[i]);           // if the current character is an opening bracket, push it into the stack
        }else{
            if(SeqStack_IsEmpty(S)){
                return false;                   // when the current character is a closing bracket, if the stack is empty, return false
            }

            char topElem = SeqStack_Pop(S);     // pop the top element, If the stack is not empty after traversing the string, return false.
            if(str[i] == ')' && topElem != '(')
                return false;
            if(str[i] == ']' && topElem != '[')
                return false;
            if(str[i] == '}' && topElem != '{')
                return false;
        }
    }
    return SeqStack_IsEmpty(S);                 // if the stack is empty, return true
}

int main(){
    char input[100];
    scanf("%s", input);
    int length = strlen(input);
    bool flag = Bracket_Match(input, length);
    printf("flag = %s\n", flag ? "true" : "false");
    return 0;
}

// {[()()]()}           true
// {[()([))]()}         false
// {[()()]()            false
// ({[()()]()})[        false
// ({[()()]()})[]       true
