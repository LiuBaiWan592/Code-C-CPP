/**
 * @FileName    :Chunk.c
 * @Date        :2025-08-14 21:47:01
 * @Author      :LiuBaiWan (https://github.com/LiuBaiWan592)
 * @Version     :V1.0.0
 * @Brief       :Chunk Store String
 * @Description :
 */

#include <stdbool.h>
#include <stdio.h>

#define CHUNKSIZE 4

typedef struct Chunk {
    char ch[CHUNKSIZE];
    int length;
    struct Chunk *next;
} *Chunk;

