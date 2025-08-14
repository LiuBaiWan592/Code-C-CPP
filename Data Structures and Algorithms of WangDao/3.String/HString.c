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

typedef struct HString {
    char *ch;
    int length;
    int capacity;
} *HString;

HString HString_Init(int capacity) {
    HString S = (HString)malloc(sizeof(struct HString));
    S->ch = (char *)malloc(sizeof(char) * (capacity + 1));
    S->length = 0;
    S->capacity = capacity;
    return S;
}

bool HString_Assign(HString S, char *str) {
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

bool HString_IsEmpty(HString S) {
    return S->length == 0;
}

int HString_GetLength(HString S) {
    return S->length;
}

bool HString_Copy(HString S, HString T) {
    for (int i = 1; i <= S->length; i++) {
        T->ch[i] = S->ch[i];
    }
    T->length = S->length;
    return true;
}

HString HString_Concat(HString S, HString T) {
    HString ST = HString_Init(S->length + T->length);
    for (int i = 1; i <= S->length; i++) {
        ST->ch[i] = S->ch[i];
    }
    for (int i = 1; i <= T->length; i++) {
        ST->ch[S->length + i] = T->ch[i];
    }
    ST->length = S->length + T->length;
    return ST;
}

HString HString_SubString(HString S, int pos, int len) {
    HString Sub = HString_Init(len);
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

int HString_Compare(HString S, HString T) {
    for (int i = 1; i <= S->length && i <= T->length; i++) {
        if (S->ch[i] != T->ch[i]) {
            return S->ch[i] - T->ch[i];
        }
    }
    return S->length - T->length;
}

int HString_Index(HString S, HString T) {
    int i = 1, n = S->length, m = T->length;
    HString Sub = HString_Init(m);
    while (i <= n - m + 1) {
        Sub = HString_SubString(S, i, m);
        if (HString_Compare(Sub, T) != 0) {
            i++;
        } else {
            return i;
        }
    }
    return 0;
}

bool HString_Clear(HString S) {
    S->length = 0;
    return true;
}

HString HString_Destroy(HString S) {
    free(S->ch);
    free(S);    
    return NULL;
}

void HString_Print(HString S) {
    printf("HString: ");
    if (HString_IsEmpty(S)) {
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
    HString S = HString_Init(10);
    HString T = HString_Init(10);
    HString_Assign(S, "Hello");
    HString_Print(S);

    printf("If S is empty: %s\n", HString_IsEmpty(S) ? "empty" : "not empty");
    printf("Length of S: %d\n", HString_GetLength(S));

    HString_Copy(S, T);
    HString_Print(T);

    HString_Assign(T, "World");
    HString_Print(T);

    HString ST = HString_Concat(S, T);
    HString_Print(S);
    HString_Print(T);
    HString_Print(ST);

    HString Sub = HString_SubString(S, 3, 3);
    HString_Print(Sub);

    printf("Compare S and ST: %d\n", HString_Compare(S, ST));

    printf("Index of T in ST: %d\n", HString_Index(ST, T));

    HString_Clear(S);
    HString_Print(S);
    printf("If S is empty: %s\n", HString_IsEmpty(S) ? "empty" : "not empty");

    S = HString_Destroy(S);
    if (S == NULL) {
        printf("S is destroyed!\n");

    } else {
        printf("S is not destroyed!\n");
    }
    T = HString_Destroy(T);
    ST = HString_Destroy(ST);
    Sub = HString_Destroy(Sub);
    return 0;
}