#ifndef GRAPH_FUNC_H
#define GRAPH_FUNC_H

#include <stdio.h>
#include <stdlib.h>

#include "exceptions.h"

typedef struct graph_struct graph_struct_t;

struct graph_struct
{
    int size;

    int **matrix;
};

int create_matrix(graph_struct_t *graph);
void print_matrix(graph_struct_t graph);
void free_matrix(int *matrix);
void show_graph(graph_struct_t *graph);
void is_connected_graph(graph_struct_t *graph);

#endif