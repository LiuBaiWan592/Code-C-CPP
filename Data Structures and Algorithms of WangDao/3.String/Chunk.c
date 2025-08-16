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

typedef struct ChunkNode {
    char ch[CHUNKSIZE];
    struct ChunkNode *next;
}ChunkNode;

typedef struct Chunk {
    int length;
    struct ChunkNode *next;
} *Chunk;

Chunk Chunk_Init() {
    Chunk C = (Chunk)malloc(sizeof(struct Chunk));
    C->length = 0;
    C->next = NULL;
    return C;
}

bool Chunk_Assign(Chunk C, char *str) {
}