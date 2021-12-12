#include "compare_structs.h"

int flag_cmp = 0;

tree_node_t *insert(tree_node_t *tree, tree_node_t *node, int *i)
{
    if (tree == NULL)
        return node;

    int cmp = strcmp(node->name, tree->name);

    if (cmp == 0)
        flag_cmp = 1;
    if (cmp < 0)
    {
        tree->left = insert(tree->left, node, i);
        (*i)++;
    }
    else if (cmp > 0)
    {
        tree->right = insert(tree->right, node, i);
        (*i)++;
    }

    return tree;
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

int insert_in_tree(tree_node_t **tree, tree_node_t **balance_tree, char *filename, hash_table_t *table)
{
    printf("\nВведите слово для вставки: ");
	clock_t start, end;
    clock_t start_balance, end_balance;

    char str[255];

    if (scanf("%s", str))
    {
        str[strlen(str)] = '\0';
        char *name = strdup(str);
        
        tree_node_t *node = create_node(name);
		tree_node_t *node_2  = create_node(name);
        
        if (!node)
            return ERROR_WITH_MEMORY;

		int i = 0;
		start = clock();
        *tree = insert(*tree, node, &i);
		end = clock();
		
        if (flag_cmp)
        {
            printf("\nДанное слово уже есть в структурах данных.\n\n");
            return EXIT_SUCCESS;
        }

        if (*balance_tree != NULL)
		{
			int i = 0;
			start_balance = clock();
			*balance_tree = insert_balance(*balance_tree, node_2, &i);
			end_balance = clock();
			printf("\nВремя добавления в балансированное дерево(в тактах): %ld\n", end_balance - start_balance);
			printf("Количество сравнений при добавлении в балансированное дерево: %d\n\n", i);	
		}

		if (insert_in_file(filename, name))
			return ERROR_FILE;		

		printf("Время добавления в исходное дерево(в тактах): %ld\n", end - start);
		printf("Количество сравнений при добавлении в исходное дерево: %d\n\n", i);	

        {
            int compare = 0;
            start = clock();
            insert_hash_node(name, table, &compare);
            end = clock();
            printf("Время добавления в хэш-таблицу(в тактах): %ld\n", end - start);
            printf("Количество сравнений при добавлении в хэш-таблицу: %d\n\n", compare);	
        }
    }
    else
    {
        printf("\nОшибка.Неверно введено слово.\n");
        return ERROR_STRING;
    }

    return EXIT_SUCCESS;
}
