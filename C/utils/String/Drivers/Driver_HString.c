/**
 * @FileName    :Driver_HString.c
 * @Date        :2025-08-19 23:24:24
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :HString Driver
 * @Description :
 */

#include "../HString.h"

/* Driver code */
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
    printf("Index of T in ST (Force): %d\n", HString_Index_Force(ST, T));

    printf("Index of T in ST KMP: %d\n", HString_Index_KMP(ST, T, HString_GetNext(T)));
    printf("Index of T in ST KMP (nextval): %d\n", HString_Index_KMP(ST, T, HString_GetNextval(T)));

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