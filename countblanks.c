#include <stdio.h>

main()
{
    int c, nl;

    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            printf("X");
        }
        else
        {
            printf("%c",c);
        }
    }
    //printf("%d\n", nl);
}
