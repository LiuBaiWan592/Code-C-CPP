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
} ChunkNode;

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

ChunkNode *Chunk_InitNode() {
    ChunkNode *newNode = (ChunkNode *)malloc(sizeof(struct ChunkNode));
    newNode->next = NULL;
    return newNode;
}

bool Chunk_Assign(Chunk C, char *str) {
    ChunkNode *current = C->next;
    if (current == NULL) {
        current = Chunk_InitNode();
        C->next = current;
    }
    int i = 0;
    while (str[i] != '\0') {
        if (i % CHUNKSIZE == 0 && i != 0) {
            if (current->next == NULL) {
                current->next = Chunk_InitNode();
            }
            current = current->next;
        }
        current->ch[i % CHUNKSIZE] = str[i];
        i++;
    }
    if (i % CHUNKSIZE != 0) {
        for (int j = i % CHUNKSIZE; j < CHUNKSIZE; j++) {
            current->ch[j] = '#';
        }
    }
    C->length = i;
    return true;
}

bool Chunk_IsEmpty(Chunk C) {
    return C->length == 0;
}

int Chunk_GetLength(Chunk C) {
    return C->length;
}

bool Chunk_Copy(Chunk C, Chunk D) {
}

void Chunk_Print(Chunk C) {
    ChunkNode *current = C->next;
    int i = 0;
    while (current != NULL) {
        for (int j = 0; i * CHUNKSIZE + j < C->length && j < CHUNKSIZE; j++) {
            printf("%c", current->ch[j]);
        }
        current = current->next;
        i++;
    }
    printf("\n");
}

int main() {
    Chunk C = Chunk_Init();
    char str[] = "Hello, World!";
    Chunk_Assign(C, str);
    Chunk_Print(C);

    printf("If C is empty: %s\n", Chunk_IsEmpty(C) ? "empty" : "not empty");
    printf("Length of C: %d\n", Chunk_GetLength(C));
    return 0;
}