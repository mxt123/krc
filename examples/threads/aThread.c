#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t threadID[3];

void *callFunction(void *arg)
{    
    pthread_t id = pthread_self();
    int numberID = -1;
    
    if( pthread_equal(id,threadID[0]))
        numberID = 0;
    else if (pthread_equal(id,threadID[1]))
        numberID = 1;
    else if (pthread_equal(id,threadID[2]))
        numberID = 2;
	
	int i = 0;
    for(i=1; i<=5; i++)
	{
        printf("Thread %i printing %i\n", numberID, i);
		sleep(1);
	}
    
    return 0;
}

int main(int argc, char **argv)
{
	int i = 0;
    for(i=0; i<=2; i++)
    {
        int ret = pthread_create(&(threadID[i]), NULL, &callFunction, NULL);
        if(ret != 0)
            printf("Error creating thread number %i\n", i);
    }

    sleep(5);
	return 0;
}
