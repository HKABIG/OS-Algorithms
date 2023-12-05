#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t forks[NUM_PHILOSOPHERS];

void Think(int philosopher_id) {
    printf("Philosopher %d is thinking.\n", philosopher_id);
    sleep(1);
}

void Eat(int philosopher_id) {
    printf("Philosopher %d is eating.\n", philosopher_id);
    sleep(1);
}

void philosopher(int philosopher_id) {
    while (1) {
        Think(philosopher_id);
        sem_wait(&forks[philosopher_id]);
        sem_wait(&forks[(philosopher_id + 1) % NUM_PHILOSOPHERS]);

        Eat(philosopher_id);
        
        sem_post(&forks[philosopher_id]);
        sem_post(&forks[(philosopher_id + 1) % NUM_PHILOSOPHERS]);
    }
}

int main() {
    pthread_t philosophers[NUM_PHILOSOPHERS];

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_init(&forks[i], 0, 1);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_create(&philosophers[i], NULL, (void *)philosopher, (void *)(intptr_t)i);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        sem_destroy(&forks[i]);
    }

    return 0;
}
