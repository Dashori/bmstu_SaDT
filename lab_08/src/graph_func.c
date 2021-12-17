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
    if (scanf("%d", &(graph->size)) != 1 || graph->size < 2)
    {
        printf("\nНеверно введено количество вершин в графе.\n\n");
        return ERROR_SIZE;
    }
    graph->matrix = allocate_matrix(graph->size, graph->size);

    if (graph->matrix == NULL)
        return ERROR_WITH_MEMORY;
    
    for (int i = 0; i < graph->size; i++)
    {
        printf("Введите строчку %d матрицы смежности: ", i + 1);
        for (int j = 0; j < graph->size; j++)
        {
            if (scanf("%d", &(graph->matrix)[i][j]) != 1 || (graph->matrix)[i][j] < 0)
            {
                printf("Ввёден неверный элемент матрицы смежности.\n");
                return ERROR_ELEMENT;
            }
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

    for (int i = 0; i < graph->size; i++)
        for (int j = 0; j < graph->size; j++)
            if (fscanf(f, "%d", &(graph->matrix[i][j])) != 1)
                return ERROR_ELEMENT;

    return EXIT_SUCCESS;
}


int read_random_matrix(graph_struct_t *graph)
{
    printf("Введите количество вершин в графе: ");
    if (scanf("%d", &(graph->size)) != 1 || graph->size < 2)
    {
        printf("\nНеверно введено количество вершин в графе.\n\n");
        return ERROR_SIZE;
    }
    graph->matrix = allocate_matrix(graph->size, graph->size);

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

// int dfs(int u, int visited[])
// {
//     int visitedVertices = 1
//     visited[u] = 1;                           // помечаем вершину как пройденную
//     for v: uv ∈ E                               // проходим по смежным с u вершинам
//         if not visited[v]                       // проверяем, не находились ли мы ранее в выбранной вершине
//             visitedVertices += dfs(v, visited)
//     return visitedVertices
// }

int dfs(graph_struct_t *graph)
{
    int *visited = calloc(graph->size ,sizeof(int));
    if (!visited)
        return ERROR_WITH_MEMORY;

    queue_struct_t queue;
    queue.start = NULL;
    

    // for (int i = 0; i < graph->size; i++)
    // 
    queue_node_t *temp = create_node(0);
    queue = *append_to_end(&queue, temp);
    // }
    print_queue(queue);

    // int n = queue.start->data;
    int g =  queue.start->data;
    visited[g] = 1;
    // int n = 2;
    while (queue.start)
    {    
        printf(" g = %d \n", g);

        for (int i = 0; i < graph->size; i++)
        {
            if (i != g && graph->matrix[g][i] && graph->matrix[i][g] && !visited[i])
            {
                printf(" f ");
                visited[i] = 1;
                queue_node_t *temp = create_node(i);
                queue = *append_to_end(&queue, temp);
            }
        } 
        
        queue = *delete_from_start(&queue);
        if (queue.start)
        {
            g = queue.start->data;
            // printf("\n QUEUE ");
            // print_queue(queue);
            // printf("END \n");
        }
        // n--;
    }

    for (int i = 0; i < graph->size; i++)
        if (visited[i] == 0)
            printf("%d  NOOOO \n", i);
                    
    return EXIT_SUCCESS;

}

void is_connected_graph(graph_struct_t *graph)
{
    int flag = 0;
    // int visited[graph->size] = 0;
    for (int i = 0; i < graph->size; i++)
    {
        for (int j = 0; j < graph->size; j++)
        {
            if (graph->matrix[i][j] == 0 && i != j)
                flag = 1;
        }
    }

    if (!flag)
        printf("Точно связный...");

    dfs(graph);
}




// queue <int> turn;//Это наша очередь, хранящая номера вершин
// int used[1000];//массив, хранящий состояние вершины("сгорела","не сгорела")
// int matrix[1000][1000];//матрица, хранящая информацию о смежности вершин
// void bfs () //собственно сама функция
// {
//       while ( !turn.empty() ) //проверяем, пуста ли очередь
//       {
//             int ind=turn.front();//берем из очереди крайний элемент
//             turn.pop();//удаляем его
//             for ( int i=0; i<1000; i++ )//смотрим, с какими вершинами смежна вершина ind
//             {
//                   if ( matrix[ind][i]==1 )
//                   {
//                         turn.push(i);//добавляем в очередь вершину i
//                   }
//             }
//        }
// }

// / Функция для выполнения BFS на графике


// void BFS(graph_struct_t *graph)
// {

    // Посетил вектор так, чтобы

    // вершина не посещена более одного раза

    // Инициализируем вектор как false как нет

    // вершина посещается в начале

    // int visited[graph->size] = 1;
    // q.push_back(start);
    // Установить источник как посещенный

//     visited[start] = true;
//     int vis;

//     while (!q.empty()) {

//         vis = q[0];
//         // Распечатать текущий узел
//         cout << vis << " ";
//         q.erase(q.begin());
//         // Для каждой смежной вершины к текущей вершине
//         for (int i = 0; i < v; i++) {
//             if (adj[vis][i] == 1 && (!visited[i])) {
//                 // Вставляем соседний узел в очередь
//                 q.push_back(i);
//                 // Устанавливать
//                 visited[i] = true;

//             }

//         }

//     }

// }