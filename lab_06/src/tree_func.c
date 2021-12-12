#include "tree_func.h"

tree_node_t *create_node(const char *name_node)
{
    tree_node_t *node = malloc(sizeof(tree_node_t));
    
    if (node)
    {
        node->name = name_node;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}


void node_print(tree_node_t *node, void *param)
{
    const char *fmt = param;

    printf(fmt, node->name);
}


int read_tree(char *filename, tree_node_t **root)
{
    FILE *f;

    if (!(f = fopen(filename, "r")))
    {
        printf("\nОшибка. Невозможно открыть файл %s.\n", filename);
        return ERROR_FILE;
    }

    char str[255];
    int flag = 1;

    while (fgets(str, 255, f))
    {
        flag = 0;
        str[strlen(str) - 1] = '\0';
        char *name = strdup(str);
        tree_node_t *node = create_node(name);
        
        if (!node)
        {
            fclose(f);
            return ERROR_WITH_MEMORY;
        }
        int i = 0;

        *root = insert(*root, node, &i);
    }

    fclose(f);

    if (flag)
    {
        printf("\nОшибка.Файл %s пустой.\n", filename);
        return ERROR_EMPTY_FILE;
    }

    return EXIT_SUCCESS;
}

void btree_apply_pre(tree_node_t *tree, ptr_action_t f, void *arg)
{
    if (tree == NULL)
        return;

    f(tree, arg);
    btree_apply_pre(tree->left, f, arg);
    btree_apply_pre(tree->right, f, arg);
}


void node_to_dot(tree_node_t *tree, void *param)
{
    FILE *f = param;

    if (tree->left)
        fprintf(f, "%s -> %s;\n", tree->name, tree->left->name);

    if (tree->right)
        fprintf(f, "%s -> %s;\n", tree->name, tree->right->name);
}


void btree_export_to_dot(char *filename, const char *tree_name, tree_node_t *tree)
{
    FILE *f;
    f = fopen(filename, "w");

    fprintf(f, "digraph %s {\n", tree_name);

    btree_apply_pre(tree, node_to_dot, f);

    fprintf(f, "}\n");

    fclose(f);
}
