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

tree_node_t *insert_balance(tree_node_t *tree, tree_node_t *node, int *i) 
{
	int rotate = 0;

	if (tree == NULL)
        return node;

    int cmp = strcmp(node->name, tree->name);

    if (cmp == 0)
        printf("\nДанное слово не может быть добавлено, так как уже есть в дереве.\n\n");

    if (cmp < 0)
	{
		(*i)++;
        tree->left = insert_balance(tree->left, node, i);
	}
    else if (cmp > 0)
	{
        tree->right = insert_balance(tree->right, node, i);
		(*i)++;
	}

    // return tree;
	return balance(tree, &rotate);
} 

int insert_in_file(char *filename, char *name)
{
	clock_t start, end;

	FILE *f = fopen(filename, "r+");
	if (!f)
	{
		printf("\nОшибка. Невозможно открыть файл %s.\n", filename);
		return ERROR_FILE;
	}
	char str[255];
	int count = 0;
	int flag = 1;

	while (fgets(str, 255, f))
	{
		str[strlen(str) - 1] = '\0';
		if (!strcmp(str, name))
		{
			printf("\nДанное слово не может быть добавлено, так как уже есть в дереве.\n\n");
			flag = 0;
			break;
		}
		count++;
	}
	
	if (flag)
	{
		start = clock();
		fprintf(f, "%s\n", name);
		end = clock();

		printf("Время добавления в файл(в тактах): %ld\n", end - start);
	}

	printf("Количество сравнений для вставки в файл: %d\n\n", count);

	fclose(f);
	return EXIT_SUCCESS;
}

int insert_in_tree(tree_node_t **tree, tree_node_t **balance_tree, char *filename)
{
    char str[255];
    printf("\nВведите слово для вставки в дерево: ");

	clock_t start, end;
    clock_t start_balance, end_balance;

    if (scanf("%s", str))
    {
        char *name = strdup(str);
        tree_node_t *node = create_node(name);
		tree_node_t *node_2  = create_node(name);
        
        if (!node)
            return ERROR_WITH_MEMORY;
		
		int i = 0;

		start = clock();
        *tree = insert(*tree, node, &i);
		end = clock();
		
        if (*balance_tree != NULL)
		{
			int i = 0;
			start_balance = clock();
			*balance_tree = insert_balance(*balance_tree, node_2, &i);
			end_balance = clock();
			printf("\nВремя добавления в балансированное дерево(в тактах): %ld\n", end_balance - start_balance);
			printf("Количество сравнений при добавлении в балансированное дерево: %d\n\n", i);	
		}
		else
			printf("Слово добавлено только в исходное дерево, так как сбаласированное не создано.\n\n");

		if (insert_in_file(filename, name))
			return ERROR_FILE;		

		printf("Время добавления в исходное дерево(в тактах): %ld\n", end - start);
		printf("Количество сравнений при добавлении в исходное дерево: %d\n\n", i);	
		
    }
    else
    {
        printf("\nОшибка.Неверно введено слово.\n");
        return ERROR_STRING;
    }

    return EXIT_SUCCESS;
}
