/**
 * @FileName    :SString.c
 * @Date        :2025-08-19 22:43:18
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Static Sequence String
 * @Description :The Index of ch[] in SString is 1~length, not 0~length-1
 *              :the first character is ch[1], the ch[0] is not used
 *              :SString: String with Static Sequence
 *              :SString_Init: Initialize the SString [O(1)]
 *              :SString_Assign: Assign the char array to the SString [O(n)]
 *              :SString_IsEmpty: Check if the SString is empty [O(1)]
 *              :SString_GetLength: Get the length of the SString [O(1)]
 *              :SString_Copy: Copy the SString S1 to SString S2 [O(n)]
 *              :SString_Concat: Concatenate the SString S1 and S2 to S [O(n)]
 *              :SString_SubString: Get the sub string of S from pos to pos+len [O(n)]
 *              :SString_Compare: Compare the SString S1 and S2 [O(n)]
 *              :SString_Index: Get the first position of S2 in S1 [O(n)]
 *              :SString_Index_Force: Get the first position of S2 in S1 by force [O(n^2)]
 *              :SString_Clear: Clear the SString S [O(1)]
 *              :SString_Destroy: Destroy the SString S [O(1)]
 *              :SString_Print: Print the SString S [O(n)]
 */

#ifndef SSTRING_H
#define SSTRING_H

#include "../common.h"

/* Static String*/
typedef struct SString {
    char ch[Maxsize + 1];       // ch[0] is not used
    int length;                 // length of string
} *SString;

/* Initialize the SString [O(1)] */
struct SString SString_Init() {
    struct SString S;
    S.length = 0;
    return S;
}

/* Assign the char array to the SString [O(n)] */
bool SString_Assign(SString S, char *str) {
    assert(S != NULL && "ERROR: When assigning the char array to the SString, the SString is NULL!");
    assert(str != NULL && "ERROR: When assigning the char array to the SString, the char array is NULL!");
    int i = 0;
    while (str[i] != '\0' && i < Maxsize) {
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

/* Check if the SString is empty [O(1)] */
bool SString_IsEmpty(SString S) {
    assert(S != NULL && "ERROR: When checking if the SString is empty, the SString is NULL!");
    return S->length == 0;
}

/* Get the length of the SString [O(1)] */
int SString_GetLength(SString S) {
    assert(S != NULL && "ERROR: When getting the length of the SString, the SString is NULL!");
    return S->length;
}

/* Copy the SString S1 to SString S2 [O(n)] */
bool SString_Copy(SString S1, SString S2) {
    assert(S1 != NULL && "ERROR: When copying the SString, the SString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When copying the SString, the SString S2 is NULL!");
    for (int i = 1; i <= S1->length; i++) {
        S2->ch[i] = S1->ch[i];
    }
    S2->length = S1->length;
    return true;
}

/* Concatenate the SString S1 and S2 to S [O(n)] */
struct SString SString_Concat(SString S1, SString S2) {
    assert(S1 != NULL && "ERROR: When concatenating the SString, the SString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When concatenating the SString, the SString S2 is NULL!");
    struct SString S;
    for (int i = 1; i <= S1->length; i++) {
        S.ch[i] = S1->ch[i];
    }
    if (S1->length + S2->length > Maxsize) {
        printf("Warning: String is too long!\n");
        for (int i = 1; i <= S2->length && i <= Maxsize - S1->length; i++) {
            S.ch[S1->length + i] = S2->ch[i];
        }
        return S;
    } else {
        for (int i = 1; i <= S2->length; i++) {
            S.ch[S1->length + i] = S2->ch[i];
        }
        S.length = S1->length + S2->length;
        return S;
    }
}

/* Get the sub string of S from pos to pos+len [O(n)] */
struct SString SString_SubString(SString S, int pos, int len) {
    assert(S != NULL && "ERROR: When getting the sub string of the SString, the SString is NULL!");
    assert(pos >= 1 && pos <= S->length && "ERROR: When getting the sub string of the SString, the position is invalid!");
    assert(len >= 0 && len <= S->length - pos + 1 && "ERROR: When getting the sub string of the SString, the length is invalid!");
    struct SString Sub;
    for (int i = 1; i <= len; i++) {
        Sub.ch[i] = S->ch[pos + i - 1];
    }
    Sub.length = len;
    return Sub;
}

/* Compare the SString S1 and S2, if S1 > S2 return a Positive number, if S1 < S2 return a negative number, else return 0 [O(n)] */
int SString_Compare(SString S1, SString S2) {
    assert(S1 != NULL && "ERROR: When comparing the SString, the SString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When comparing the SString, the SString S2 is NULL!");
    for (int i = 1; i <= S1->length && i <= S2->length; i++) {
        if (S1->ch[i] != S2->ch[i]) {
            return S1->ch[i] - S2->ch[i];
        }
    }
    return S1->length - S2->length;
}

/* Get the index of S2 in S1, using the substring function [O(n * m)] */
int SString_Index(SString S1, SString S2) {
    assert(S1 != NULL && "ERROR: When getting the index of the SString, the SString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When getting the index of the SString, the SString S2 is NULL!");
    int i = 1, n = S1->length, m = S2->length;
    struct SString sub;
    while (i <= n - m + 1) {
        sub = SString_SubString(S1, i, m);
        if (SString_Compare(&sub, S2) != 0) {
            i++;
        } else {
            return i;
        }
    }
    return 0;
}

/* Get the index of S2 in S1, using the Force method [O(n * m)] */
int SString_Index_Force(SString S1, SString S2) {
    assert(S1 != NULL && "ERROR: When getting the index of the SString, the SString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When getting the index of the SString, the SString S2 is NULL!");
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

/* Get the next array of the SString S [O(n)] */
bool SString_GetNext(SString S, int *next) {
    assert(S != NULL && "ERROR: When getting the next of the SString, the SString is NULL!");
    next[1] = 0;
    int i = 1, j = 0;
    while (i < S->length) {
        if (j == 0 || S->ch[i] == S->ch[j]) {
            i++;
            j++;
            next[i] = j;        // next[i] = next[i - 1] + 1;
        } else {
            j = next[j];        // j = next[j - 1];
        }
    }
}

/* Get the index of S2 in S1, using the KMP method [O(n + m)] */
bool SString_Index_KMP(SString S1, SString S2, int *next) {
    assert(S1 != NULL && "ERROR: When getting the index of the SString, the SString S1 is NULL!");
    assert(S2 != NULL && "ERROR: When getting the index of the SString, the SString S2 is NULL!");
    int i = 1, j = 1;
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
    } else {
        return 0;
    }
}

/* Clear the SString S [O(1)] */
bool SString_Clear(SString S) {
    assert(S != NULL && "ERROR: When clearing the SString, the SString is NULL!");
    S->length = 0;
    return true;
}

/* Destroy the SString S [O(1)] */
SString SString_Destroy(SString S) {
    assert(S != NULL && "ERROR: When destroying the SString, the SString is NULL!");
    S->length = 0;
    return NULL;
}

/* Print the SString S [O(n)] */
void SString_Print(SString S) {
    assert(S != NULL && "ERROR: When printing the SString, the SString is NULL!");
    printf("SString: ");
    if (SString_IsEmpty(S)) {
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

#endif // SSTRING_H