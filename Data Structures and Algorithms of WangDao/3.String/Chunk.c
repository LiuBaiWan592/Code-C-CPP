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
#include <stdlib.h>

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

bool Chunk_ClearTail(ChunkNode *current) {
    current = current->next;
    while (current != NULL) {
        ChunkNode *temp = current;
        current = current->next;
        free(temp);
    }
    return true;
}

bool Chunk_Assign(Chunk C, char *str) {
    if (C->next == NULL) {
        C->next = Chunk_InitNode();
    }
    ChunkNode *current = C->next;
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
    if (current->next != NULL) {
        Chunk_ClearTail(current);
    }
    return true;
}

bool Chunk_IsEmpty(Chunk C) {
    return C->length == 0;
}

int Chunk_GetLength(Chunk C) {
    return C->length;
}

bool Chunk_Copy(Chunk C, Chunk D) {
    ChunkNode *CNode = C->next;
    if (D->next == NULL) {
        D->next = Chunk_InitNode();
    }
    ChunkNode *DNode = D->next;
    while (CNode != NULL) {
        for (int i = 0; i < CHUNKSIZE; i++) {
            DNode->ch[i] = CNode->ch[i];
        }
        CNode = CNode->next;
        if (DNode->next == NULL) {
            DNode->next = Chunk_InitNode();
            DNode = DNode->next;
        } else {
            DNode = DNode->next;
        }
    }
    D->length = C->length;
    return true;
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

    Chunk D = Chunk_Init();
    Chunk_Copy(C, D);
    Chunk_Print(D);
    printf("If D is empty: %s\n", Chunk_IsEmpty(D) ? "empty" : "not empty");
    printf("Length of D: %d\n", Chunk_GetLength(D));
    return 0;
}