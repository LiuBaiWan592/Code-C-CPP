#include <assert.h>
#include <stdbool.h>
#include <stdio.h>


int main(){
    int a;
    int b = 1;
    
    scanf("%d", &a);
    
    // assert(b > a);
    printf("hello world\n");

    // static_assert(a != 4, "a is not 4 bytes");
    assert(a == 1 && "a is not 1");

    return 0;
}