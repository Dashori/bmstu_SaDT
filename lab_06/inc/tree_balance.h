#include "tree_func.h"

#ifndef TREE_BALANCE_H
#define TREE_BALANCE_H

#include "tree_struct.h"
#include <time.h>

tree_node_t *copy(tree_node_t *root);
tree_node_t *balance(tree_node_t *node, int *rotate);
tree_node_t *btree_balance_post(tree_node_t *tree, ptr_action_2_t f, int *rotate);
int insert_in_tree(tree_node_t **tree, tree_node_t **balance_tree);
tree_node_t *insert_balance(tree_node_t *tree, tree_node_t *node) ;

#endif