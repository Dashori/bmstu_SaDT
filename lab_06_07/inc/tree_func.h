#define _GNU_SOURCE

#ifndef TREE_FUNC_H
#define TREE_FUNC_H

#include "tree_struct.h"
#include "exceptions.h"
#include "compare_structs.h"
#include <string.h>

tree_node_t *create_node(const char *name_node);
int read_tree(char *filename, tree_node_t **root);
void btree_export_to_dot(char *filename, const char *tree_name, tree_node_t *tree);
void node_print(tree_node_t *node, void *param);
void btree_apply_pre(tree_node_t *tree, ptr_action_t f, void *arg);


#endif