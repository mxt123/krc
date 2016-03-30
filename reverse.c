#include <stdio.h>
#define MAXLINE 1000

int getLine(char line[], int maxline); // getline is in stdio nowdays :o)
void reverse(char line[], int len);

main()
{
        int len;
        char line[MAXLINE];

        while ((len = getLine(line, MAXLINE)) > 0)
        {
            reverse(line, len);
            printf("%s",line);
        }  
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

void reverse(char line[], int len)
{
    char result[len];
    int i , j;
    i = j = 0;

    for (i = len -1; i>=0; --i)
    {
        result[j] = line[i];
        j++;
    }

    result[j] = '\0';
    
    for (i=0; i < len; ++i)
    {
        line[i] = result[i];
    }
}
