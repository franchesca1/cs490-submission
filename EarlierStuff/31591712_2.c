// pi_pthread.c
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct {
    long start;
    long end;
    double sum;
} ThreadData;

void* compute_pi(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    double local_sum = 0.0;

    for (long i = data->start; i < data->end; i++) {
        double term = ((i % 2 == 0) ? 1.0 : -1.0) / (2 * i + 1);
        local_sum += term;
    }

    data->sum = local_sum;
    return NULL;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <num_terms> <num_threads>\n", argv[0]);
        return 1;
    }

    long num_terms = atol(argv[1]);
    int num_threads = atoi(argv[2]);

    pthread_t threads[num_threads];
    ThreadData thread_data[num_threads];

    long terms_per_thread = num_terms / num_threads;

    for (int i = 0; i < num_threads; i++) {
        thread_data[i].start = i * terms_per_thread;
        thread_data[i].end = (i == num_threads - 1) ? num_terms : (i + 1) * terms_per_thread;
        pthread_create(&threads[i], NULL, compute_pi, &thread_data[i]);
    }

    double total_sum = 0.0;
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
        total_sum += thread_data[i].sum;
    }

    printf("Approximation of π = %.15f\n", 4.0 * total_sum);
    return 0;
}
