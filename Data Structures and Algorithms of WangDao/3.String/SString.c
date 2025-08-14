/**
 * @FileName    :SString.c
 * @Date        :2025-08-13 23:05:29
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Static Sequence String
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>

#define MAXSIZE 10

typedef struct SString {
    char ch[MAXSIZE + 1];
    int length;
} *SString;

bool SString_Assign(SString S, char *str) {
    int i = 0;
    while (str[i] != '\0' && i < MAXSIZE) {
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

bool SString_IsEmpty(SString S) {
    return S->length == 0;
}

int SString_GetLength(SString S) {
    return S->length;
}

bool SString_Copy(SString S, SString T) {
    for (int i = 1; i <= S->length; i++) {
        T->ch[i] = S->ch[i];
    }
    T->length = S->length;
    return true;
}

struct SString SString_Concat(SString S1, SString S2) {
    struct SString S;
    for (int i = 1; i <= S1->length; i++) {
        S.ch[i] = S1->ch[i];
    }
    if (S1->length + S2->length > MAXSIZE) {
        printf("Warning: String is too long!\n");
        for (int i = 1; i <= S2->length && i <= MAXSIZE - S1->length; i++) {
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

struct SString SString_SubString(SString S, int pos, int len) {
    struct SString T;
    if (pos < 1 || pos > S->length || len < 0 || len > S->length - pos + 1) {
        printf("Warning: Invalid position or length!\n");
        return T;
    }
    for (int i = 1; i <= len; i++) {
        T.ch[i] = S->ch[pos + i - 1];
    }
    T.length = len;
    return T;
}

int SString_Compare(SString S, SString T) {
    for (int i = 1; i <= S->length && i <= T->length; i++) {
        if (S->ch[i] != T->ch[i]) {
            return S->ch[i] - T->ch[i];
        }
    }
    return S->length - T->length;
}

int SString_Index(SString S, SString T) {
    int i = 1, n = S->length, m = T->length;
    struct SString sub;
    while (i <= n - m + 1) {
        sub = SString_SubString(S, i, m);
        if (SString_Compare(&sub, T) != 0) {
            i++;
        } else {
            return i;
        }
    }
    return 0;
}

bool SString_Clear(SString S) {
    S->length = 0;
    return true;
}

SString SString_Destroy(SString S) {
    S->length = 0;
    return NULL;
}
void SString_Print(SString S) {
    printf("SString: ");
    if (SString_IsEmpty(S)) {
        printf("Empty String!\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 1; i <= S->length; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("  Value: ");
    for (int i = 1; i <= S->length; i++) {
        printf("%c ", S->ch[i]);
    }
    printf("\n");
}

int main() {
    struct SString S1, S2;
    SString S = &S1, T = &S2;
    SString_Assign(S, "Hello");
    SString_Print(S);

    printf("If S is empty: %s\n", SString_IsEmpty(S) ? "empty" : "not empty");
    printf("Length of S: %d\n", SString_GetLength(S));

    SString_Copy(S, T);
    SString_Print(T);

    SString_Assign(T, "World");
    SString_Print(T);

    S1 = SString_Concat(S, T);
    SString_Print(&S1);
    SString_Print(S);

    S2 = SString_SubString(S, 3, 3);
    SString_Print(&S2);
    SString_Print(T);

    S2 = SString_SubString(S, 1, 8);
    SString_Print(&S2);
    printf("Compare S and T: %d\n", SString_Compare(S, T));

    S2 = SString_SubString(S, 3, 3);
    printf("Index of T in S: %d\n", SString_Index(S, T));

    SString_Clear(S);
    SString_Print(S);
    printf("If S is empty: %s\n", SString_IsEmpty(S) ? "empty" : "not empty");

    S = SString_Destroy(S);
    if (S == NULL) {
        printf("S is destroyed!\n");

    } else {
        printf("S is not destroyed!\n");
    }
    T = SString_Destroy(T);

    return 0;
}