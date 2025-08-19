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

bool Chunk_Copy(Chunk C1, Chunk C2) {
    ChunkNode *C1Node = C1->next;
    if (C2->next == NULL) {
        C2->next = Chunk_InitNode();
    }
    ChunkNode *C2Node = C2->next;
    while (C1Node != NULL) {
        for (int i = 0; i < CHUNKSIZE; i++) {
            C2Node->ch[i] = C1Node->ch[i];
        }
        C1Node = C1Node->next;
        if (C2Node->next == NULL) {
            C2Node->next = Chunk_InitNode();
            C2Node = C2Node->next;
        } else {
            C2Node = C2Node->next;
        }
    }
    C2->length = C1->length;
    return true;
}

char *Chunk_GetChar(Chunk C) {
    char *str = (char *)malloc(sizeof(char) * C->length + 1);
    ChunkNode *current = C->next;
    int i = 0;
    while (current != NULL) {
        for (int j = 0; i * CHUNKSIZE + j < C->length && j < CHUNKSIZE; j++) {
            str[i * CHUNKSIZE + j] = current->ch[j];
        }
        current = current->next;
        i++;
    }
    str[i * CHUNKSIZE] = '\0';
    return str;
}

Chunk Chunk_ConcatChar(char *str1, int len1, char *str2, int len2) {
    Chunk C = Chunk_Init();
    char *str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
    int i = 0, j = 0;
    for (i = 0; i < len1; i++) {
        str[i] = str1[i];
    }
    for (j = 0; j < len2; j++) {
        str[i + j] = str2[j];
    }
    str[i + j] = '\0';
    Chunk_Assign(C, str);
    free(str);
    return C;
}

Chunk Chunk_Concat(Chunk C1, Chunk C2) {
    char *str1 = Chunk_GetChar(C1);
    char *str2 = Chunk_GetChar(C2);
    Chunk C = Chunk_ConcatChar(str1, C1->length, str2, C2->length);
    free(str1);
    free(str2);
    return C;
}

Chunk Chunk_Substring(Chunk C, int start, int len) {
    Chunk D = Chunk_Init();
    ChunkNode *current = C->next;
    int nodeNum = start / CHUNKSIZE;
    for (int i = 0; i < nodeNum; i++) {
        current = current->next;
    }
    char *str = (char *)malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; i++) {
        str[i] = current->ch[(start + i) % CHUNKSIZE];
        if ((start + i) % CHUNKSIZE == CHUNKSIZE - 1) {
            current = current->next;
        }
    }
    str[len] = '\0';
    Chunk_Assign(D, str);
    free(str);
    return D;
}

int Chunk_Compare(Chunk C1, Chunk C2) {
    ChunkNode *C1Node = C1->next;
    ChunkNode *C2Node = C2->next;
    int i = 0;
    while (C1Node != NULL && C2Node != NULL) {
        for (int j = 0;
             j < CHUNKSIZE && i * CHUNKSIZE + j < C1->length && i * CHUNKSIZE + j < C2->length;
             j++) {
            if (C1Node->ch[j] != C2Node->ch[j]) {
                return C1Node->ch[j] - C2Node->ch[j];
            }
        }
        C1Node = C1Node->next;
        C2Node = C2Node->next;
        i++;
    }
    if (C1Node == NULL && C2Node == NULL) {
        return 0;
    } else if (C1Node == NULL) {
        return -1;
    } else {
        return 1;
    }
}

bool Chunk_Clear(Chunk C) {
    ChunkNode *current = C->next;
    while (current != NULL) {
        ChunkNode *temp = current;
        current = current->next;
        free(temp);
    }
    C->next = NULL;
    C->length = 0;
}

Chunk Chunk_Destroy(Chunk C) {
    Chunk_Clear(C);
    free(C);
    return NULL;
}

void Chunk_Print(Chunk C) {
    printf("Chunk: ");
    if (Chunk_IsEmpty(C)) {
        printf("The chunk is empty.\n");
        return;
    } else {
        printf("\n");
    }
    printf("  Index: ");
    for (int i = 0; i < C->length; i++) {
        printf("%d\t", i);
    }
    printf("\n");
    printf("  Value: ");
    ChunkNode *current = C->next;
    int i = 0;
    while (current != NULL) {
        for (int j = 0; i * CHUNKSIZE + j < C->length && j < CHUNKSIZE; j++) {
            printf("%c\t", current->ch[j]);
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

    Chunk E = Chunk_Concat(C, D);
    Chunk_Print(E);
    printf("If E is empty: %s\n", Chunk_IsEmpty(E) ? "empty" : "not empty");
    printf("Length of E: %d\n", Chunk_GetLength(E));

    D = Chunk_Substring(D, 7, 5);
    Chunk_Print(D);
    printf("If D is empty: %s\n", Chunk_IsEmpty(D) ? "empty" : "not empty");
    printf("Length of D: %d\n", Chunk_GetLength(D));

    printf("Comparison result: %d\n", Chunk_Compare(C, E));

    if (Chunk_Clear(C)) {
        printf("C is cleared.\n");
    }
    printf("If C is empty: %s\n", Chunk_IsEmpty(C) ? "empty" : "not empty");
    printf("Length of C: %d\n", Chunk_GetLength(C));

    C = Chunk_Destroy(C);
    if (C == NULL) {
        printf("C is destroyed.\n");
    }
    D = Chunk_Destroy(D);
    E = Chunk_Destroy(E);

    return 0;
}