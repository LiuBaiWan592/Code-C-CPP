/**
 * @FileName    :01_Stack_Bracket_Match.c
 * @Date        :2025-07-28 22:09:32
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Stack to match brackets
 * @Description :
 */

#define ElemType char

#include "common.h"

bool Bracket_Match(char *str){
    if(str == NULL){
        return false;
    }
    int len = strlen(str);
    SeqStack S = SeqStack_Init(len);
    for(int i = 0; i < len; i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            SeqStack_Push(S, str[i]);           // if the current character is an opening bracket, push it into the stack
        }else{
            if(SeqStack_IsEmpty(S)){
                return false;                   // when the current character is a closing bracket, if the stack is empty, return false
            }

            char topElem;
            SeqStack_Pop(S, &topElem);       // pop the top element
            if(str[i] == ')' && topElem != '(')
                SeqStack_Clear(S);
                return false;
            if(str[i] == ']' && topElem != '[')
                SeqStack_Clear(S);
                return false;
            if(str[i] == '}' && topElem != '{')
                SeqStack_Clear(S);
                return false;
        }
    }
    return SeqStack_IsEmpty(S);                 // if the stack is empty, return true
}

int main(){
    char input[100];
    scanf("%s", input);
    bool flag = Bracket_Match(input);
    printf("flag = %s\n", flag ? "true" : "false");
    return 0;
}

// {[()()]()}           true
// {[()([))]()}         false
// {[()()]()            false
// ({[()()]()})[        false