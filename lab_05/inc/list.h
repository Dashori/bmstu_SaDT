#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structs.h"
#include "array.h"

unsigned long simulate_service(struct mem_slot **mem, int *mem_used);
void new_req(double *total_time, struct queue *queue, struct machine *machine, struct mem_slot **mem);
int processing(struct machine *machine, struct queue *queue, struct mem_slot **mem);
void queue_compare(struct mem_slot **mem);
void show_mem(struct mem_slot **mem);

#endif