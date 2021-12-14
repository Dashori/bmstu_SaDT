#ifndef QUEUE_FUNC_H
#define QUEUE_FUNC_H

#include <stdio.h>
#include <stdlib.h>

typedef struct queue_node_struct queue_node_t;
struct queue_node_struct
{
    int data;
    queue_node_t *next;
};

typedef struct queue_struct queue_struct_t;
struct queue_struct
{
    queue_node_t *start;
    queue_node_t *end;
};

void create_queue(queue_struct_t *queue);

#endif