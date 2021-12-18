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

queue_node_t *create_node(int data);
queue_struct_t *append_to_end(queue_struct_t *queue, queue_node_t *node);
queue_struct_t *delete_from_start(queue_struct_t *queue);
void create_queue(queue_struct_t *queue);
void print_queue(queue_struct_t queue);

#endif