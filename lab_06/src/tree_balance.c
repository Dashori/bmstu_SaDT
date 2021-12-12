#include "tree_balance.h"

unsigned char height(tree_node_t *node)
{
	return node ? node->height : 0;
}

int bfactor(tree_node_t *node)
{
	return height(node->right) - height(node->left);
}

void fixheight(tree_node_t *node)
{
	unsigned char height_l = height(node->left);
	unsigned char height_r = height(node->right);
	node->height = (height_l > height_r ? height_l : height_r) + 1;
}

tree_node_t *rotateright(tree_node_t *p) // правый поворот вокруг p
{
	tree_node_t *q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);

	return q;
}

tree_node_t *rotateleft(tree_node_t *q) // левый поворот вокруг q
{
	tree_node_t *p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);

	return p;
}

tree_node_t *balance(tree_node_t *node, int *rotate) // балансировка узла p
{
	fixheight(node);

	if (bfactor(node) >= 2)
	{   
		*rotate += 1;
		if (bfactor(node->right) < 0)
			node->right = rotateright(node->right);

		return rotateleft(node);
	}

	if (bfactor(node) <= -2)
	{
		*rotate += 1;
		if (bfactor(node->left) > 0)
			node->left = rotateleft(node->left);

		return rotateright(node);
	}

	return node; // балансировка не нужна
}

tree_node_t *btree_balance_post(tree_node_t *tree, ptr_action_2_t f, int *rotate)
{
	*rotate = 0;

    if (tree == NULL)
        return NULL;	

    tree->left = btree_balance_post(tree->left, f, rotate);
    tree->right = btree_balance_post(tree->right, f, rotate);
    tree = f(tree, rotate);

    return tree;
}

tree_node_t *copy(tree_node_t *root)
{
    if (root == NULL)
        return NULL;
    
    char *temp = strdup(root->name);
    tree_node_t *new_root = create_node(temp);

    new_root->left = copy(root->left);
    new_root->right = copy(root->right);

    return new_root;
}

