#include "array.h"

unsigned long simulate_service_arr(int *mem_used)
{
    int all = TOTAL_NEED;
    struct queue_slot *arr = malloc(all * sizeof(struct queue_slot));
    struct queue queue;
    queue.pin = queue.pout = arr;
    queue.len = queue.in_num = queue.state = 0;
    queue.total_stay_time = 0;
    struct machine machine;
    machine.time = machine.downtime = 0;
    machine.processed_count = machine.triggering = 0;
    double total_time = 0;
    int f = 0;
    printf("\nРеализация массивом:\n\n");

    unsigned long time = tick(), t_buf1 = 0, t_buf2 = 0;
    while (f != 2 && machine.processed_count < TOTAL_NEED)
    {
        while (queue.len == 0 || machine.time > total_time)
        {
            new_req_arr(&total_time, &machine, &queue, arr, all);
            if (queue.len != 0 && queue.len != 1 && queue.pout == queue.pin)
                f = 2;
        }
        if (f != 2)
            f = processing_arr(&machine, &queue, arr, all);
        t_buf1 = tick();
        if (f == 1 && machine.processed_count % INTER_NEED == 0)
        {
            printf("Количетсво заявок: %d\n", machine.processed_count);
            printf("Текущая длина очереди: %d\n", queue.len);
            printf("Средняя длина очереди: %.2f\n\n", (double)(queue.state / machine.triggering));
        }
        t_buf2 += tick() - t_buf1;
        if (f == 1)
            f = 0;
    }
    time = tick() - time - t_buf2;
    if (f == 2)
        printf("Массив переполнен! Моделирование остановлено. Длина очереди: %d\n", queue.len);
    else
    {
        double model = 0;
        if ((COMING_END + COMING_START) < (PROCESSING_END + PROCESSING_START))
            model = (double)(COMING_END + COMING_START) / 2 * TOTAL_NEED;
        else
            model = (double)(PROCESSING_END + PROCESSING_START) / 2 * TOTAL_NEED * (1 / 0.2);
     
        *mem_used = all * (sizeof(struct queue_slot) - sizeof(struct queue_slot*));
        printf("Ожидаемое время моделирования: %.2f\n", model);
        printf("Полученное время моделирования: %.2f\n", machine.time);
        printf("Погрешность: ~%.2f%%\n\n", fabs((machine.time - model) / model * 100));
        printf("Количество вошедших заявок: %d\n", queue.in_num);
        printf("Количество вышедших заявок: %d\n", machine.processed_count);
        printf("Среднее время в очереди: %.2f\n", queue.total_stay_time / machine.processed_count);
        printf("Время простоя аппарата: %.2f\n", machine.downtime);
        printf("Количество срабатывания аппарата: %d\n\n", machine.triggering);
    }
    free(arr);
    return time;
}

void new_req_arr(double *total_time, struct machine *machine, struct queue *queue, struct queue_slot *array, int mass_len)
{
    double time = get_time(COMING_START, COMING_END);
    *total_time += time;
    if (queue->len == 0 && *total_time > machine->time)
    {
        machine->downtime += *total_time - machine->time;
        machine->time = *total_time;
    }
    if (queue->len > 1 && queue->pin != queue->pout)
    {
        if (queue->pin == array + mass_len - 1)
            queue->pin = array;
        else
            queue->pin++;
    }
    if (queue->len == 1)
    {
        if (queue->pin == array + mass_len - 1)
            queue->pin = array;
        else
            queue->pin++;
    }

    queue->pin->arrival_time = *total_time;
    queue->len++;
    queue->in_num++;
}

int processing_arr(struct machine *machine, struct queue *queue, struct queue_slot *arr, int arr_len)
{
    int f = 0;
    queue->state += queue->len;
    machine->triggering++;
    machine->time += get_time(PROCESSING_START, PROCESSING_END);
    struct queue_slot *buf = queue->pout;
    if (queue->pout == arr + arr_len - 1)
        queue->pout = arr;
    else
        queue->pout++;
    if (!chance())
    {
        if (queue->pin == arr + arr_len - 1)
            queue->pin = arr;
        else
            queue->pin++;
        queue->pin->arrival_time = buf->arrival_time;
    }
    else
    {
        if (queue->len == 1)
            queue->pin = queue->pout;
        queue->total_stay_time += machine->time - buf->arrival_time;
        machine->processed_count++;
        queue->len--;
        f = 1;
    }
    return f;
}
