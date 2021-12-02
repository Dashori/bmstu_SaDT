#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdlib.h>
#include <stdio.h>
#include "math.h"

#define TOTAL_NEED 1000
#define INTER_NEED 100
#define COMING_START 0
#define COMING_END 6
#define PROCESSING_START 0
#define PROCESSING_END 2

struct queue_slot
{
    double arrival_time; //время прихода в очередб
    struct queue_slot *next; //указатель на след элемент
};

struct queue
{
    struct queue_slot *pin; //указатель на начало очереди
    struct queue_slot *pout; //указатель на конец очереди
    int len; //длина очереди
    int in_num; //число вошедших в очередь заявок
    int state; //переменная для вычисления средней длины
    int max; // переменная для подсчета очереди в списке
    double total_stay_time; //время нахождения заявок в очереди
};

struct machine
{
    double time; //текущее время состояния аппарата 
    double downtime; // время простоя аппарата
    int triggering; // количесво срабатывания аппарата
    int processed_count; //кол-во обработанных из очереди заявок
};

struct mem_slot
{
    struct queue_slot *queue_slot; //указатель на участок памяти
    int busy; // состояние участка 1(занят) или 0
    struct mem_slot *next; //указатель на след элемент очереди
};

unsigned long long tick(void);
double get_time(int t1, int t2);
int chance(void);
void add_mem(struct queue_slot *slot, struct mem_slot **mem);
void delete_mem(struct queue_slot *slot, struct mem_slot *mem);

#endif