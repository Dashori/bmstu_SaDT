#ifndef ARRAY_H
#define ARRAY_H

#include "structs.h"

unsigned long simulate_service_arr(int *mem_used);
void new_req_arr(double *total_time, struct machine *machine, struct queue *queue, struct queue_slot *array, int mass_len);
int processing_arr(struct machine *machine, struct queue *queue, struct queue_slot *arr, int arr_len);

#endif