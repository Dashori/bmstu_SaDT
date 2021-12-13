#include "tree_func.h"

#ifndef HASH_FUNC_H
#define HASH_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exceptions.h"

typedef struct node_table node_table_t;
struct node_table
{
    char *name;
    node_table_t *next;
};

typedef struct hash_table hash_table_t;
struct hash_table
{
    int max_size;

    node_table_t *array; 
};

int read_filename(char *filename, int *max_size, int *cur_size);
int create_hash(char *filename, hash_table_t **table, int cur_size);
void print_hash(hash_table_t table, int cur_size);
void insert_hash_node(char *name, hash_table_t *table, int *compare);

#endif
