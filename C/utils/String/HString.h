/**
 * @FileName    :HString.h
 * @Date        :2025-08-19 23:18:56
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :The Index of *ch in HString is 1~length, not 0~length-1
 *              :the first character is ch[1], the ch[0] is not used
 *              :HString: String with dynamic memory allocation
 *              :HString_Assign: Assign the char array to the HString [O(n)]
 *              :HString_IsEmpty: Check if the HString is empty [O(1)]
 *              :HString_GetLength: Get the length of the HString [O(1)]
 *              :HString_Copy: Copy the HString S1 to HString S2 [O(n)]
 *              :HString_Concat: Concatenate the HString S1 and S2 to S [O(n)]
 *              :HString_SubString: Get the sub string of S from pos to pos+len [O(n)]
 *              :HString_Compare: Compare the HString S1 and S2 [O(n)]
 *              :HString_Index: Get the first position of S2 in S1 [O(n)]
 *              :HString_Index_Force: Get the first position of S2 in S1 by force [O(n^2)]
 *              :HString_Clear: Clear the HString S [O(1)]
 *              :HString_Destroy: Destroy the HString S [O(1)]
 *              :HString_Print: Print the HString S [O(n)]
 */

#ifndef HSTRING_H
#define HSTRING_H

#include "../common.h"

/* Heap String */
typedef struct HString {
    char *ch;               // ch[0] is not used
    int length;             // length of HString
    int capacity;           // capacity of HString
} *HString;

/* Initialize the Heap String [O(1)] */
HString HString_Init(int capacity) {
    HString S = (HString)malloc(sizeof(struct HString));
    S->ch = (char *)malloc(sizeof(char) * (capacity + 1));
    S->length = 0;
    S->capacity = capacity;
    return S;
}

/* Assign the char array to the HString [O(n)] */
bool HString_Assign(HString S, char *str) {
    assert(S != NULL && "ERROR: When assigning the char array to the HString, the HString is NULL!");
    assert(str != NULL && "ERROR: When assigning the char array to the HString, the char array is NULL!");
    int i = 0;
    while (str[i] != '\0' && i < S->capacity) {
        S->ch[i + 1] = str[i];
        i++;
    }
    S->length = i;
    if (str[i] != '\0') {
        printf("Warning: String is too long!\n");
        return false;
    }
    return true;
}

/* Check if the HString is empty [O(1)] */
bool HString_IsEmpty(HString S) {
    assert(S != NULL && "ERROR: When checking if the HString is empty, the HString is NULL!");
    return S->length == 0;
}

/* Get the length of the HString [O(1)] */
int HString_GetLength(HString S) {
    assert(S != NULL && "ERROR: When getting the length of the HString, the HString is NULL!");
    return S->length;
}

/* Copy the HString S1 to HString S2 [O(n)] */
bool HString_Copy(HString S1, HString S2) {
    assert(S1 != NULL && "ERROR: When copying the HString, the HString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When copying the HString, the HString S2 is NULL!");
    for (int i = 1; i <= S1->length; i++) {
        S2->ch[i] = S1->ch[i];
    }
    S2->length = S1->length;
    return true;
}

/* Concatenate the HString S1 and S2 to S [O(n)] */
HString HString_Concat(HString S1, HString S2) {
    assert(S1 != NULL && "ERROR: When concatenating the HString, the HString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When concatenating the HString, the HString S2 is NULL!");
    HString S = HString_Init(S1->length + S2->length);
    for (int i = 1; i <= S1->length; i++) {
        S->ch[i] = S1->ch[i];
    }
    for (int i = 1; i <= S2->length; i++) {
        S->ch[S1->length + i] = S2->ch[i];
    }
    S->length = S1->length + S2->length;
    return S;
}

/* Get the sub string of S from pos to pos+len [O(n)] */
HString HString_SubString(HString S, int pos, int len) {
    assert(S != NULL && "ERROR: When getting the sub string of the HString, the HString is NULL!");
    assert(pos >= 1 && pos <= S->length && "ERROR: When getting the sub string of the HString, the position is invalid!");
    assert(len >= 0 && len <= S->length - pos + 1 && "ERROR: When getting the sub string of the HString, the length is invalid!");
    HString Sub = HString_Init(len);
    for (int i = 1; i <= len; i++) {
        Sub->ch[i] = S->ch[pos + i - 1];
    }
    Sub->length = len;
    return Sub;
}

/* Compare the HString S1 and S2, if S1 > S2 return a Positive number, if S1 < S2 return a negative number, else return 0 [O(n)] */
int HString_Compare(HString S1, HString S2) {
    assert(S1 != NULL && "ERROR: When comparing the HString, the HString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When comparing the HString, the HString S2 is NULL!");
    for (int i = 1; i <= S1->length && i <= S2->length; i++) {
        if (S1->ch[i] != S2->ch[i]) {
            return S1->ch[i] - S2->ch[i];
        }
    }
    return S1->length - S2->length;
}

/* Get the index of S2 in S1, using the substring function [O(n * m)] */
int HString_Index(HString S1, HString S2) {
    assert(S1 != NULL && "ERROR: When getting the index of the HString, the HString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When getting the index of the HString, the HString S2 is NULL!");
    int i = 1, n = S1->length, m = S2->length;
    HString Sub = HString_Init(m);
    while (i <= n - m + 1) {
        Sub = HString_SubString(S1, i, m);
        if (HString_Compare(Sub, S2) != 0) {
            i++;
        } else {
            return i;
        }
    }
    return 0;
}

/* Get the index of S2 in S1, using the Force method [O(n * m)] */
int HString_Index_Force(HString S1, HString S2) {
    assert(S1 != NULL && "ERROR: When getting the index of the HString, the HString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When getting the index of the HString, the HString S2 is NULL!");
    int i = 1, j = 1;
    while (i <= S1->length && j <= S2->length) {
        if (S1->ch[i] == S2->ch[j]) {
            i++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > S2->length) {
        return i - S2->length;
    } else {
        return 0;
    }
}

/* Get the next array of the HString S [O(n)] */
int* HString_GetNextArray(HString S) {
    assert(S != NULL && "ERROR: When getting the next array of the HString, the HString is NULL!");
    int* next = (int*)malloc(sizeof(int) * (S->length + 1));
    next[1] = 0;
    int i = 1, j = 0;
    while (i < S->length) {
        if (j == 0 || S->ch[i] == S->ch[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

/* Get the index of S2 in S1, using the KMP method [O(n + m)] */
int HString_Index_KMP(HString S1, HString S2) {
    assert(S1 != NULL && "ERROR: When getting the index of the HString, the HString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When getting the index of the HString, the HString S2 is NULL!");
    int i = 1, j = 1;
    int* next = HString_GetNextArray(S2);
    while (i <= S1->length && j <= S2->length) {
        if (j == 0 || S1->ch[i] == S2->ch[j]) {
            i++;
            j++;
        } else {
            j = next[j];
        }
    }
    if (j > S2->length) {
        return i - S2->length;
    }else {
        return 0;
    }
}

/* Clear the HString S [O(1)] */
bool HString_Clear(HString S) {
    assert(S != NULL && "ERROR: When clearing the HString, the HString is NULL!");
    S->length = 0;
    return true;
}

/* Destroy the HString S [O(1)] */
HString HString_Destroy(HString S) {
    assert(S != NULL && "ERROR: When destroying the HString, the HString is NULL!");
    free(S->ch);
    free(S);    
    return NULL;
}

/* Print the HString S [O(n)] */
void HString_Print(HString S) {
    assert(S != NULL && "ERROR: When printing the HString, the HString is NULL!");
    printf("HString: ");
    if (HString_IsEmpty(S)) {
        printf("Empty String!\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 1; i <= S->length; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    printf("  Value: ");
    for (int i = 1; i <= S->length; i++) {
        printf("%c\t", S->ch[i]);
    }
    printf("\n");
}

#endif // HSTRING_H