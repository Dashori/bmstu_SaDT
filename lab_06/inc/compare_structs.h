#define _GNU_SOURCE

#ifndef COMPARE_STRUCTS_H
#define COMPARE_STRUCTS_H

#include "exceptions.h"
#include "tree_balance.h"
#include "tree_func.h"
#include "hash_func.h"

int insert_in_tree(tree_node_t **tree, tree_node_t **balance_tree, char *filename, hash_table_t *table);
tree_node_t *insert(tree_node_t *tree, tree_node_t *node, int *i);

#endif