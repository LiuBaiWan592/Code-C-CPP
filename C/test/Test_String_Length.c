#include "common.h"

int main()
{
    char postfix[5][20] = {"123+*", "123*+45/-67*-", "123*+45/-67*+", "1234-*+56/-", "12+34*5/-6+"};
    printf("%d\n", strlen(postfix[1]));

    return 0;
}