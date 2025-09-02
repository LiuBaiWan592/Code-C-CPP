/**
 * @FileName    :Driver_SString.c
 * @Date        :2025-08-19 23:27:18
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :SString Driver
 * @Description :
 */

#include "../SString.h"

/* Driver code */
int main() {
    struct SString S1 = SString_Init(), S2 = SString_Init();
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

    printf("Index of T in S (Force): %d\n", SString_Index_Force(S, T));

    // KMP
    int *next = SString_GetNext(T);
    printf("Next of T: ");
    for (int i = 0; i <= SString_GetLength(T); i++) {
        printf("%d ", next[i]);
    }
    printf("\n");

    printf("Index T in S KMP: %d\n", SString_Index_KMP(S, T, next));

    int *nextval = SString_GetNextval(T);
    printf("Nextval of T: ");
    for (int i = 0; i <= SString_GetLength(T); i++) {
        printf("%d ", nextval[i]);
    }
    printf("\n");

    printf("Index T in S KMP (nextval): %d\n", SString_Index_KMP(S, T, nextval));

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