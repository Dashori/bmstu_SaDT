#include "queue_func.h"

queue_struct_t *append_to_end(queue_struct_t *queue, queue_node_t *node)
{
    if (!queue->start)
    {
        queue->start = node;
        queue->end = node;
        return queue;
    }

    queue->end->next = node;
    queue->end = queue->end->next;

    return queue;  
}

queue_struct_t *delete_from_start(queue_struct_t *queue)
{
    queue_node_t *temp = queue->start->next;

    free(queue->start);
    queue->start = temp;

    return queue;  
}

queue_node_t *create_node(int data)
{
    queue_node_t *temp = malloc(sizeof(queue_node_t));
    
    if (!temp)
        return NULL;
    
    temp->data = data;
    temp->next = NULL;
    
    return temp;
}

void print_queue(queue_struct_t queue)
{
    while (queue.start)
    {
        printf("%d ", queue.start->data);
        queue.start = queue.start->next;
    }
}

void create_queue(queue_struct_t *queue)
{
    queue->end = queue->start;
    for (int i = 0; i < 2; i++)
    {
        queue_node_t *temp = create_node(i);
        queue = append_to_end(queue, temp);
    }
    print_queue(*queue);
    queue = delete_from_start(queue);
    print_queue(*queue);
}
