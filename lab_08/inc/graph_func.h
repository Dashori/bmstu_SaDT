#ifndef GRAPH_FUNC_H
#define GRAPH_FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "exceptions.h"
#include "queue_func.h"

typedef struct graph_struct graph_struct_t;

struct graph_struct
{
    int size;

    int **matrix;
    int **reverse_matrix;
};

int create_matrix(graph_struct_t *graph);
int read_random_matrix(graph_struct_t *graph);
void print_matrix(graph_struct_t graph);
void free_matrix(int *matrix);
void show_graph(graph_struct_t *graph);
int is_connected_graph(graph_struct_t *graph);


#endif