#include "print.h"

void print_info(void)
{
    printf("\
Данная программа выполняет стандартные действия с деревьями,\n\
балансированными деревьями и хэш-таблицами.\n\
Данные генерируются скриптом data.py, который создает n неповторяющихся имен.\n\n");
}

void print_menu(void)
{
    printf("\
Работа с деревом:\n\
1 - считать дерево из файла\n\
2 - создать сбалансированное дерево\n\
3 - вывести исходное дерево\n\
4 - вывести сбалансированное дерево\n\n\
\
Работа с хэш-таблицой:\n\
5 - считать хэш-таблицу из файла\n\
6 - вывести хэш-таблицу на экран\n\
\
7 - добавить слово в деревья и в таблицу\n\n\
0 - выход из программы\n\
Выберите пункт меню: ");
}