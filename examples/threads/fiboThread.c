#include <err.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void* fiboThread(void* arg)
{
	size_t n = ( size_t )arg, fib;
	int ern;
	pthread_t thID1, thID2;
	void* returnValue;
    
	switch ( n )
    {
		case 0: return ( void* )0;
		case 1: return ( void* )1;
		case 2: return ( void* )1;
		default: break;
	}
    
	if ((ern = pthread_create(&thID1, 0, fiboThread, (void *)( n - 1 ))))
        err(ern, "pthread_create");
	if ((ern = pthread_create(&thID2, 0, fiboThread, (void *)( n - 2 ))))
        err(ern, "pthread_create");
	if ((ern = pthread_join(thID1, &returnValue)))
		err(ern, "pthread_join");
	fib = ( size_t )returnValue;
	if ((ern = pthread_join(thID2, &returnValue)))
		err(ern, "pthread_join");
	fib += ( size_t )returnValue;

	return ( void* )fib;
}

size_t fibo( size_t n )
{
	return ( size_t )fiboThread(( void* )n );
}

int main(int argc, char **argv)
{
    unsigned long i = 0;
    for (i=0; i<=16; i++)
        printf("%lu: %lu\n", i, fibo(i));
	return 0;
}
