#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define TOTALTHREADS 3

struct threadData
{
   int threadNumber;
   int n;
   char *message;
};

struct threadData threadArray[TOTALTHREADS];
pthread_t threadID[TOTALTHREADS];

void *printData(void *arg)
{
    struct threadData *myData = arg;
    int id = myData->threadNumber;
    printf("%s %i from thread with ", myData->message, myData->n);
    printf("thread ID %lu.\n", threadID[id]);
    return 0;
}

int main (int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < TOTALTHREADS; i++)
    {
        threadArray[i].threadNumber = i;
        threadArray[i].n = i*i;
        threadArray[i].message = "Hello";
    }
    
    for (i = 0; i < TOTALTHREADS; i++)
    {
        int ret = pthread_create(&threadID[i], NULL, &printData, (void *) &threadArray[i]);
        if(ret != 0)
            printf("Error creating thread number %i\n", i);
    }

	sleep(5);
	return 0;
}
