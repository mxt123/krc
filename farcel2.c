#include <stdio.h>

#define STEP 20
#define MAX 300
#define MIN 0

main()
{
    int fahr;
    printf("this is a header\n");
    for (fahr = MIN; fahr <= MAX; fahr += STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr-32));


}
