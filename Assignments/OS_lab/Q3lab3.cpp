#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>

#define NUM_ITERATIONS 5

int turn;
bool flag[2] = {false, false};

void enter_critical_section(int self) {
    int other = 1 - self;
    flag[self] = true;
    turn = other;
    while (flag[other] && turn == other);
}

void exit_critical_section(int self) {
    flag[self] = false;
}

void *process(void *arg) {
    int self = *(int *)arg;
    for (int i = 0; i < NUM_ITERATIONS; i++) {
        enter_critical_section(self);

        // Critical Section
        printf("Process %d is in the critical section.\n", self);
        sleep(1);
        printf("Process %d is leaving the critical section.\n", self);

        exit_critical_section(self);
        sleep(1); // Simulating other work outside the critical section
    }
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    int id1 = 0, id2 = 1;

    pthread_create(&thread1, NULL, process, &id1);
    pthread_create(&thread2, NULL, process, &id2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}