#ifndef TREE_STRUCT_H
#define TREE_STRUCT_H

#include <stdlib.h>
#include <stdio.h>


typedef struct tree_node tree_node_t;

struct tree_node
{
    const char *name;
    unsigned char height; 
    // меньшие
    struct tree_node *left;
    // большие
    struct tree_node *right;
};

typedef void (*ptr_action_t) (tree_node_t*, void*);
typedef tree_node_t *(*ptr_action_2_t)(tree_node_t *, int *rotate);


#endif