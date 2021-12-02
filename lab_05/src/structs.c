#include "structs.h"

unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc": "=A" (d));
    return d;
}

double get_time(int t1, int t2)
{
    double r = (double)rand() / (double)RAND_MAX;
    r = (t2 - t1) * r + t1;
    return r;
}

int chance(void)
{
    int mas[10] = {0, 1, 0, 0, 0, 0, 1, 0, 0, 0};
    int ind = rand() % 10;
    return mas[ind];
}

void add_mem(struct queue_slot *slot, struct mem_slot **mem)
{
    struct mem_slot *buf = malloc(sizeof(struct mem_slot));
    buf->queue_slot = slot;
    buf->busy = 1;
    buf->next = *mem;
    *mem = buf;
}

void delete_mem(struct queue_slot *slot, struct mem_slot *mem)
{
    struct mem_slot *buf = mem;
    int f = 0;
    while (!f && buf != NULL)
    {
        if (buf->queue_slot == slot)
        {
            f = 1;
            buf->busy = 0;
        }
        buf = buf->next;
    }
}