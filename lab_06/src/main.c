#include "print.h"
#include "tree_func.h"
#include "tree_balance.h"
#include "hash_func.h"
#include "exceptions.h"

int main(void)
{
    setbuf(stdout, NULL);
    print_info();
    tree_node_t *root = NULL;
    tree_node_t *root_balance = NULL;
    hash_table_t *table = NULL;

    int key = 1, error_code = 0;
    int max_size = 0, cur_size = 0;
    int flag_file = 1;
    char filename[20] = "";
    char filename_dot[] = "tree.gv";
    char filename_dot_balance[] = "balance_tree.gv";

    while (key)
    {
        print_menu();
        if (scanf("%d", &key) != 1 || key < 0 || key > 8)
        {
            printf("Введён неверный ключ.\n");
            return ERROR_KEY;
        }
        switch(key)
        {
            case(0):
            {
                printf("Программа успешно завершена по вашему желанию.\n");
                return EXIT_SUCCESS;
            }
            case(1):
            {
                if (flag_file)
                {
                    if ((error_code = read_filename(filename, &max_size, &cur_size)))
                        return error_code;
                    flag_file = 0;
                }

                if ((error_code = read_tree(filename, &root)))
                    return error_code;
                
                printf("\nДерево успешно считано из файла.\n\n");

                break;
            }
            case(2):
            {
                if (root == NULL)
                {
                    printf("\nДля балансировки необходимо выполнить пункт 1.\n\n");
                    break;
                }

                int rotate = 0;
                root_balance = copy(root);

                do
                root_balance = btree_balance_post(root_balance, balance, &rotate);
                while (rotate);

                printf("\nДерево успешно сбалансировано.\n\n");

                break;
            }
            case(3):
            {
                if (root == NULL)
                {
                    printf("\nДля вставки ногово слова необходимо выполнить пункт 1.\n\n");
                    break;
                }

                if (max_size <= cur_size)
                {
                    printf("\nНевозможно добавить элемент в структуры, так как они полностью заполнены.\n\n");
                    break;
                }

                if ((error_code = insert_in_tree(&root, &root_balance, filename)))
                    return error_code;
                
                cur_size++;

                break;
            }
            case(4):
            {
                if (root == NULL)
                {
                    printf("\nДля вывода дерева необходимо его считать в пункте 1.\n\n");
                    break;                    
                }

                btree_export_to_dot(filename_dot, "tree", root);
                system("dot -Tpng tree.gv -otree.png");
                system("xdg-open tree.png");
                
                break;
            }
            case(5):
            {
                if (root_balance == NULL)
                {
                    printf("\nДля вывода балансированного дерева необходимо\n");
                    printf("его считать в пункте 1 и сбалансировать в пункте 2.\n\n");
                    break;                    
                }

                btree_export_to_dot(filename_dot_balance, "balance_tree", root_balance);
                system("dot -Tpng balance_tree.gv -obalance_tree.png");
                system("xdg-open balance_tree.png");
                
                break;
            }
            case(6):
            {
                if (flag_file)
                {
                    if ((error_code = read_filename(filename, &max_size, &cur_size)))
                        return error_code;
                    flag_file = 0;
                }
                table = malloc(sizeof(hash_table_t));
                table->array = malloc(max_size * sizeof(node_table_t));

                if (!(table->array))
                    return ERROR_WITH_MEMORY;
                    
                table->cur_size = cur_size;
                table->max_size = max_size;

                create_hash(filename, &table);
                
                break;
            } 
            case(7):
            {
                if (table != NULL)
                {
                    print_hash(table, cur_size);
                }
                break;
            }
            default:
                return error_code;
        }
    }
    
    
   	return error_code;
}