#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

size_t fibonacci( size_t n )
{
	if ( n == 0 )
		return 0;
	if ( n == 1 )
		return 1;
	if ( n == 2 )
		return 1;

	return (fibonacci(n-1)+fibonacci(n-2));	
}

int main(int argc, char **argv)
{
    unsigned long i = 0;
    for (i=0; i<=16; i++)
    printf("%li: %lu\n", i, fibonacci(i));
	return 0;
}
