#include <stdio.h>

#define IN 1
#define OUT 2

main()
{
        int c, nl, nw, nc, state;

        state = OUT;
        nl = nw = nc = 0;
        while ((c=getchar()) != EOF){
                ++nc;
                if (c == '\n')
                        ++nl;
                if (c == ' ' || c == '\n' || c == '\t')
                        state = OUT;
                else if (state == OUT) {
                        state = IN;
                        ++nw;
                }
        }
        printf("%d newline %d words %d characters\n", nl, nw, nc);
}
