#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline); // getline is in stdio nowdays :o)
void copy(char to[], char from[]);

main()
{
        int len;
        int max;
        char line[MAXLINE];
        char longest[MAXLINE];

        max = 0;
        while ((len = getLine(line, MAXLINE)) > 0)
        {
                if (len > max) {
                        max = len;
                        copy(longest, line);
                }      
                if (len > 10)
                {
                    printf("longer than 10 :%s",line);
                }
        }  
          if (max > 0) 
                printf("%d:%s", max, longest);
        return 0;
}

int getLine(char s[], int lim)
{
        int c, i;

        for (i=0; i < lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
                s[i] = c;
        if (c == '\n') {
                s[i] = c;
                ++i;
        }
        s[i] = '\0';
        return i;
}

void copy(char to[], char from[])
{
        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0')
                ++i;
}
