#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;

void* callFunction(void *arg)
{
    pthread_mutex_lock(&lock);

    unsigned long i = 0;
    counter += 1;
    printf("Work %d started\n", counter);
    for(i=0; i<10000000000;i++);
    printf("Work %d finished\n", counter);

    pthread_mutex_unlock(&lock);
    return 0;
}

int main(int argc, char **argv)
{
    int i = 0;

    if (pthread_mutex_init(&lock, NULL) != 0)
    {
        printf("Error initialising mutex.\n");
        return -1;
    }

	for (i = 0; i<2; i++)
    {
        int ret = pthread_create(&(tid[i]), NULL, &callFunction, NULL);
        if (ret != 0)
            printf("Error creating thread %i.\n", i);
    }

    pthread_join(tid[0], NULL);
    pthread_join(tid[1], NULL);
    pthread_mutex_destroy(&lock);

    return 0;
}
