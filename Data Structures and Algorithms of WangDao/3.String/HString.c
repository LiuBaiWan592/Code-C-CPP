/**
 * @FileName    :HString.c
 * @Date        :2025-08-14 21:02:59
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Heap Sequence String
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>

typedef struct SString {
    char *ch;
    int length;
    int capacity;
} *SString;

SString SString_Init(int capacity) {
    SString S = (SString)malloc(sizeof(struct SString));
    S->ch = (char *)malloc(sizeof(char) * (capacity + 1));
    S->length = 0;
    S->capacity = capacity;
    return S;
}

bool SString_Assign(SString S, char *str) {
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

SString SString_Concat(SString S, SString T) {
    SString ST = SString_Init(S->length + T->length);
    for (int i = 1; i <= S->length; i++) {
        ST->ch[i] = S->ch[i];
    }
    for (int i = 1; i <= T->length; i++) {
        ST->ch[S->length + i] = T->ch[i];
    }
    ST->length = S->length + T->length;
    return ST;
}

SString SString_SubString(SString S, int pos, int len) {
    SString Sub = SString_Init(len);
    if (pos < 1 || pos > S->length || len < 0 || len > S->length - pos + 1) {
        printf("Warning: Invalid position or length!\n");
        return Sub;
    }
    for (int i = 1; i <= len; i++) {
        Sub->ch[i] = S->ch[pos + i - 1];
    }
    Sub->length = len;
    return Sub;
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
    SString Sub = SString_Init(m);
    while (i <= n - m + 1) {
        Sub = SString_SubString(S, i, m);
        if (SString_Compare(Sub, T) != 0) {
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
    free(S->ch);
    free(S);    
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
    SString S = SString_Init(10);
    SString T = SString_Init(10);
    SString_Assign(S, "Hello");
    SString_Print(S);

    printf("If S is empty: %s\n", SString_IsEmpty(S) ? "empty" : "not empty");
    printf("Length of S: %d\n", SString_GetLength(S));

    SString_Copy(S, T);
    SString_Print(T);

    SString_Assign(T, "World");
    SString_Print(T);

    SString ST = SString_Concat(S, T);
    SString_Print(S);
    SString_Print(T);
    SString_Print(ST);

    SString Sub = SString_SubString(S, 3, 3);
    SString_Print(Sub);

    printf("Compare S and ST: %d\n", SString_Compare(S, ST));

    printf("Index of T in ST: %d\n", SString_Index(ST, T));

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
    ST = SString_Destroy(ST);
    Sub = SString_Destroy(Sub);
    return 0;
}