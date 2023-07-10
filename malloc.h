#ifndef MALLOC_FT
#define MALLOC_FT

#include <unistd.h>
#include <string.h>
#include <stdatomic.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Block{
    size_t size;
    struct Block* NEXT;
    int free;
} Block;

#define BLOCK_SIZE sizeof(Block)
#define DEFAULT_CHUNK_SIZE 4096

void    BestFit(int BlockSize[], int block, int ProcessSize[], int processes);

void    *ft_malloc(size_t size);

void    ft_free(void* ptr);

#endif