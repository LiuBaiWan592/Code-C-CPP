#include "../utils/common.h"

typedef struct Stack{
    ElemType *data;
    int top_a, top_b;
    int length_a, length_b;
    int capacity;
} *PStack;

int main()
{
    printf("Size of ElemType: %lu\n", sizeof(ElemType));
    printf("Size of int: %lu\n", sizeof(int));
    printf("Size of PStack: %lu\n", sizeof(PStack));
    printf("Size of Stack: %lu\n", sizeof(struct Stack));
    
    return 0;
}