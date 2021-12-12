#define _GNU_SOURCE

#ifndef HASH_FUNC_H
#define HASH_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exceptions.h"
#include "tree_func.h"

typedef struct node node_t;
struct node
{
    char *name;
    node_t *list;
};

typedef struct node_table node_table_t;
struct node_table
{
    char *name;
    node_table_t *next;
};

typedef struct hash_table hash_table_t;
struct hash_table
{
    int cur_size;
    int max_size;

    node_table_t *array; //массив на элементы
};

int read_filename(char *filename, int *max_size, int *cur_size);
int create_hash(char *filename, hash_table_t **table);
void print_hash(hash_table_t table, int cur_size);
void insert_hash_node(char *name, hash_table_t *table, int *compare);

#endif
