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

void is_connected_graph(graph_struct_t *graph)
{
    int flag = 0;

    for (int i = 0; i < graph->size; i++)
        for (int j = 0; j < graph->size; j++)
            if (graph->matrix[i][j] == 0)
                flag = 1;
            

    if (!flag)
        printf("Точно связный...");
    
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

/ Функция для выполнения BFS на графике


void BFS(graph_struct_t *graph)
{

    // Посетил вектор так, чтобы

    // вершина не посещена более одного раза

    // Инициализируем вектор как false как нет

    // вершина посещается в начале

    int visited[graph->size] = 1;

    

    q.push_back(start);
    // Установить источник как посещенный

    visited[start] = true;
    int vis;

    while (!q.empty()) {

        vis = q[0];
        // Распечатать текущий узел
        cout << vis << " ";
        q.erase(q.begin());
        // Для каждой смежной вершины к текущей вершине
        for (int i = 0; i < v; i++) {
            if (adj[vis][i] == 1 && (!visited[i])) {
                // Вставляем соседний узел в очередь
                q.push_back(i);
                // Устанавливать
                visited[i] = true;

            }

        }

    }

}