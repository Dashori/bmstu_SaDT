#include "graph_func.h"

int **allocate_matrix(int n, int m)
{
    int **data = malloc(n * sizeof(int*) + n * m * sizeof(int));

    if (!data)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        data[i] = (int*)((char*) data + n * sizeof(int*) + i * m * sizeof(int));
        for (int j = 0; j < m; j++)
            data[i][j] = 0;
    }

    return data;
}

void free_matrix(int *matrix)
{
    free(matrix);
}

void print_matrix(graph_struct_t graph)
{
    printf("\nМатрица смежности:\n");
    for (int i = 0; i < (graph.size); i++)
    {
        for (int j = 0; j < (graph.size); j++)
            printf("%d ", graph.matrix[i][j]);
        printf("%s", "\n");
    }
}

int create_matrix(graph_struct_t *graph)
{
    printf("Введите количество вершин в графе: ");

    if (scanf("%d", &(graph->size)) != 1 || graph->size < 1)
    {
        printf("\nНеверно введено количество вершин в графе.\n\n");
        return ERROR_SIZE;
    }
    graph->matrix = allocate_matrix(graph->size, graph->size);
    graph->reverse_matrix = allocate_matrix(graph->size, graph->size);
    int d;

    if (graph->matrix == NULL)
        return ERROR_WITH_MEMORY;
    
    for (int i = 0; i < graph->size; i++)
    {
        printf("Введите строчку %d матрицы смежности: ", i + 1);
        for (int j = 0; j < graph->size; j++)
        {
            if (scanf("%d", &d) != 1 || d < 0)
            {
                printf("Ввёден неверный элемент матрицы смежности.\n");
                return ERROR_ELEMENT;
            }
            (graph->matrix)[i][j] = d;
            (graph->reverse_matrix)[j][i] = d;
        }
    }
    return EXIT_SUCCESS;
}

void reverse(char s[])
{
    for (int i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i = 0;

    do {
        s[i++] = n % 10 + '0';   
    } while ((n /= 10) > 0);     

    s[i] = '\0';
    reverse(s);
}

int read_file(char *filename, graph_struct_t *graph)
{
    FILE *f = fopen(filename, "r");

    if (f == NULL)
        return ERROR_FILE;
    
    int d;

    for (int i = 0; i < graph->size; i++)
        for (int j = 0; j < graph->size; j++)
        {
            if (fscanf(f, "%d", &d) != 1)
                return ERROR_ELEMENT;

            (graph->matrix)[i][j] = d;
            (graph->reverse_matrix)[j][i] = d;
        }

    return EXIT_SUCCESS;
}


int read_random_matrix(graph_struct_t *graph)
{
    printf("Введите количество вершин в графе: ");
    if (scanf("%d", &(graph->size)) != 1 || graph->size < 1)
    {
        printf("\nНеверно введено количество вершин в графе.\n\n");
        return ERROR_SIZE;
    }
    graph->matrix = allocate_matrix(graph->size, graph->size);
    graph->reverse_matrix = allocate_matrix(graph->size, graph->size);

    char graph_size[10];
    itoa(graph->size, graph_size);
    
    char py_sys[] = "python3 data.py ";
    char *temp = strcat(py_sys, graph_size);
    system(temp);

    char name[] = "data_";
    temp = strcat(name, graph_size);
    
    char filename[] = "";

    strcat(temp, ".txt");
    strcpy(filename, temp);


    return read_file(filename, graph);
}

void show_graph(graph_struct_t *graph)
{
    FILE *f = fopen("graph.gv", "w");

    fprintf(f, "digraph graph_pic {\n");

    for (int i = 0; i < graph->size; ++i)
        for (int j = 0; j < graph->size; ++j)
            if (graph->matrix[i][j] != 0)
                fprintf(f, "%d -> %d [label=\"%.1d\"];\n", i, j, graph->matrix[i][j]);
    
    fprintf(f, "}\n");
    fclose(f);
}

int dfs(graph_struct_t *graph, int **matrix)
{
    int *visited = calloc(graph->size ,sizeof(int));

    if (!visited)
        return ERROR_WITH_MEMORY;

    queue_struct_t queue;
    queue.start = NULL;

    queue_node_t *temp = create_node(0);
    queue = *append_to_end(&queue, temp);
    int g =  queue.start->data;
    visited[g] = 1;

    while (queue.start)
    {    
        for (int i = 0; i < graph->size; i++)
        {
            if (i != g && matrix[g][i] && matrix[i][g] && !visited[i])
            {
                visited[i] = 1;
                queue_node_t *temp = create_node(i);
                queue = *append_to_end(&queue, temp);

            }
            if (i != g && matrix[g][i] && !visited[i])
            {
                visited[i] = 1;
                queue_node_t *temp = create_node(i);
                queue = *append_to_end(&queue, temp);
            }
        }
        
        queue = *delete_from_start(&queue);

        if (queue.start)
            g = queue.start->data;
    }

    for (int i = 0; i < graph->size; i++)
        if (visited[i] == 0)
        {
            free(visited);
            return EXIT_FAILURE;
        }

    free(visited);
                    
    return EXIT_SUCCESS;
}

int is_connected_graph(graph_struct_t *graph)
{
    int error_code = dfs(graph, graph->matrix);
    if (error_code == ERROR_WITH_MEMORY)
        return ERROR_WITH_MEMORY;

    if (!error_code)
        if (dfs(graph, graph->reverse_matrix) == 0)
        {
            printf("\nГраф  является связным.\n\n");
            return EXIT_SUCCESS;
        }
    
    printf("\nГраф не является связным.\n\n");
    return EXIT_SUCCESS;
}
