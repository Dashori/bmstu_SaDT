#include "list.h"

unsigned long simulate_service(struct mem_slot **mem, int *mem_used)
{
    struct queue queue;
    queue.pin = queue.pout = NULL;
    queue.len = queue.in_num = queue.state = queue.max = 0;
    queue.total_stay_time = 0;
    struct machine machine;
    machine.time = machine.downtime = 0;
    machine.processed_count = machine.triggering = 0;
    double total_time = 0;
    int f = 0;
    printf("\nРеализация списком:\n\n");
    unsigned long time = tick(), t_buf1 = 0, t_buf2 = 0;
    while (machine.processed_count < TOTAL_NEED)
    {
        while (queue.len == 0 || machine.time > total_time)
        {
            new_req(&total_time, &queue, &machine, mem);
        }
        f = processing(&machine, &queue, mem);
        t_buf1 = tick();
        if (f && machine.processed_count % INTER_NEED == 0)
        {
            printf("Количетсво заявок: %d\n", machine.processed_count);
            printf("Текущая длина очереди: %d\n", queue.len);
            printf("Средняя длина очереди: %.2f\n\n", (float)(queue.state / machine.triggering));
        }
        t_buf2 += tick() - t_buf1;
        if (f)
            f = 0;
    }
    time = tick() - time - t_buf2;
    double model = 0;

    if ((COMING_END + COMING_START) < (PROCESSING_END + PROCESSING_START))
        model = (double)(COMING_END + COMING_START) / 2 * TOTAL_NEED;
    else
        model = (double)(PROCESSING_END + PROCESSING_START) / 2 * TOTAL_NEED * (1 / 0.2);
    
    *mem_used = queue.max * sizeof(struct queue_slot);
    
    printf("Ожидаемое время моделирования: %.2f\n", model);
    printf("Полученное время моделирования: %.2f\n", machine.time);
    printf("Погрешность: ~%.2f%%\n\n", fabs((machine.time - model) / model * 100));
    printf("Количество вошедших заявок: %d\n", queue.in_num);
    printf("Количество вышедших заявок: %d\n", machine.processed_count);
    printf("Среднее время в очереди: %.2f\n", queue.total_stay_time / machine.processed_count);
    printf("Время простоя аппарата: %.2f\n", machine.downtime);
    printf("Количество срабатывания аппарата: %d\n\n", machine.triggering);
    return time;
}

void new_req(double *total_time, struct queue *queue, struct machine *machine, struct mem_slot **mem)
{
    double time = get_time(COMING_START, COMING_END);
    *total_time += time;
    if (queue->len == 0 && *total_time > machine->time)
    {
        machine->downtime += *total_time - machine->time;
        machine->time = *total_time;
    }
    struct queue_slot *buf = malloc(sizeof(struct queue_slot));
    if (queue->pin != NULL)
        queue->pin->next = buf;
    buf->next = NULL;
    buf->arrival_time = *total_time;
    queue->pin = buf;
    if (queue->len == 0)
        queue->pout = buf;
    queue->len++;
    queue->in_num++;
    add_mem(buf, mem);
}

int processing(struct machine *machine, struct queue *queue, struct mem_slot **mem)
{
    int f = 0;
    queue->state += queue->len;
    if (queue->len > queue->max)
        queue->max = queue->len;
    machine->triggering++;
    machine->time += get_time(PROCESSING_START, PROCESSING_END);
    struct queue_slot *buf = queue->pout;
    if (queue->len > 1)
        queue->pout = buf->next;
    if (!chance())
    {
        queue->pin->next = buf;
        queue->pin = buf;
        buf->next = NULL;
    }
    else
    {
        if (queue->len == 1)
            queue->pin = queue->pout = NULL;
        queue->total_stay_time += machine->time - buf->arrival_time;
        machine->processed_count++;
        queue->len--;
        free(buf);
        delete_mem(buf, *mem);
        f = 1;
    }
    return f;
}

void show_mem(struct mem_slot **mem)
{
    struct mem_slot *buf = *mem, *buf1;
    if (buf == NULL)
        printf("\nДля данного пункта нужно смоделировать очередь списком.\n\n");
    else
    {
        printf("Использование памяти:\
        + - память используется\
        - - память не используется\n");
        int flag = 0;
        while (buf != NULL && flag != 80)
        {
            printf("%p ", (void*)buf->queue_slot);
            if (buf->busy == 1)
                printf("+\n");
            else
                printf("-\n");
            buf1 = buf;
            buf = buf->next;
            free(buf1);
            flag++;
        }
        *mem = NULL;
    }
}

void queue_compare(struct mem_slot **mem)
{
    int mem1 = 0, mem2 = 0;
    unsigned long t1 = simulate_service(mem, &mem1);
    unsigned long t2 = simulate_service_arr(&mem2);
 
    struct mem_slot *buf = *mem;
    while (buf)
    {
        *mem = buf->next;
        free(buf);
        buf = *mem;
    }
    printf("Время для списка(в тиках): %lu\n", t1);
    printf("Время для массива(в тиках): %lu\n", t2);
    printf("Память для списка(в байтах): %d\n", mem1);
    printf("Память для массива(в байтах): %d\n", mem2);
}
