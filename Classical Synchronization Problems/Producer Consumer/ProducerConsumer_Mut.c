#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define BUFFER_SIZE 5
#define MAX_ITEMS 20

pthread_mutex_t buffer_mutex;
int produced_count = 0, consumed_count = 0, items_in_buffer = 0;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void producer(int producer_id) {
    int item = 1;
    while (produced_count < MAX_ITEMS) {
        pthread_mutex_lock(&buffer_mutex);
        if (items_in_buffer == BUFFER_SIZE) {
            printf("Buffer is full. Producer %d is waiting...\n", producer_id);
            pthread_mutex_unlock(&buffer_mutex);
            sleep(1);
            continue;
        }
        buffer[in % BUFFER_SIZE] = item;
        printf("Producer %d produced item %d\n", producer_id, item);

        item++;
        produced_count++;
        items_in_buffer++;
        in++;

        pthread_mutex_unlock(&buffer_mutex);
        sleep(1);
    }
}

void consumer(int consumer_id) {
    while (consumed_count < MAX_ITEMS) {
        pthread_mutex_lock(&buffer_mutex);
        if (items_in_buffer == 0) {
            printf("Buffer is empty. Consumer %d is waiting...\n", consumer_id);
            pthread_mutex_unlock(&buffer_mutex);
            sleep(1);
            continue;
        }
        printf("Consumer %d consumed item %d\n", consumer_id, buffer[out % BUFFER_SIZE]);

        consumed_count++;
        items_in_buffer--;
        buffer[out % BUFFER_SIZE] = 0;
        out++;

        pthread_mutex_unlock(&buffer_mutex);
        sleep(1);
    }
}

int main() {
    int num_consumers, num_producers;
    printf("Enter the number of producers and consumers: ");
    scanf("%d %d", &num_consumers, &num_producers);

    pthread_mutex_init(&buffer_mutex, NULL);

    pthread_t producer_threads[num_producers], consumer_threads[num_consumers];

    for (int i = 0; i < num_producers; i++) {
        pthread_create(&producer_threads[i], NULL, (void *)producer, (void *)(intptr_t)i);
    }

    for (int j = 0; j < num_consumers; j++) {
        pthread_create(&consumer_threads[j], NULL, (void *)consumer, (void *)(intptr_t)j);
    }

    for (int i = 0; i < num_producers; i++) {
        pthread_join(producer_threads[i], NULL);
    }

    for (int j = 0; j < num_consumers; j++) {
        pthread_join(consumer_threads[j], NULL);
    }

    return 0;
}
