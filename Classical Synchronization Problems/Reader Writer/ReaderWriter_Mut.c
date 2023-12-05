#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t writer_mutex, reader_mutex;
int reader_count = 0;

void reader(int reader_id) {
    pthread_mutex_lock(&reader_mutex);
    reader_count++;
    if (reader_count == 1)
        pthread_mutex_lock(&writer_mutex);
    pthread_mutex_unlock(&reader_mutex);

    printf("Reader %d entered the room\n", reader_id);
    printf("Reader %d is reading the resource\n", reader_id);
    sleep(2);  // Adjusted sleep duration

    pthread_mutex_lock(&reader_mutex);
    reader_count--;
    if (reader_count == 0)
        pthread_mutex_unlock(&writer_mutex);
    pthread_mutex_unlock(&reader_mutex);

    printf("Reader %d has left the room\n", reader_id);
    sleep(1);  // Adjusted sleep duration
}

void writer(int writer_id) {
    pthread_mutex_lock(&writer_mutex);

    printf("Writer %d entered the room\n", writer_id);
    printf("Writer %d is writing the resource\n", writer_id);
    sleep(2);  // Adjusted sleep duration

    pthread_mutex_unlock(&writer_mutex);

    printf("Writer %d has left the room\n", writer_id);
    sleep(1);  // Adjusted sleep duration
}

int main() {
    int num_readers, num_writers;
    pthread_mutex_init(&writer_mutex, NULL);
    pthread_mutex_init(&reader_mutex, NULL);

    printf("Enter the number of readers and writers: ");
    scanf("%d %d", &num_readers, &num_writers);

    pthread_t reader_threads[num_readers], writer_threads[num_writers];

    for (int i = 0; i < num_writers; i++) {
        pthread_create(&writer_threads[i], NULL, (void *)writer, (void *)(intptr_t)i);
    }

    for (int i = 0; i < num_readers; i++) {
        pthread_create(&reader_threads[i], NULL, (void *)reader, (void *)(intptr_t)i);
    }

    for (int i = 0; i < num_readers; i++) {
        pthread_join(reader_threads[i], NULL);
    }

    for (int i = 0; i < num_writers; i++) {
        pthread_join(writer_threads[i], NULL);
    }

    return 0;
}
