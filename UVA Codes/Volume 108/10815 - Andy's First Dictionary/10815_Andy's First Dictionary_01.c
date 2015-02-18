#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD 500000
#define WORD_SIZE 30

char words[MAX_WORD][WORD_SIZE] = {};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in","r",stdin);
#endif

    char c;
    int i,j;
    i = j = 0;

    /* get input */
    while((c=tolower(getchar()))!=EOF)
    {

        if(isalpha(c))
            words[i][j++] = c;
        else if(strlen(words[i]))  j=0, ++i;
    }

    /* qsort */
    qsort(words, i, WORD_SIZE, strcmp);

    /* print */
    puts(words[0]);
    char *last = words[0];
    for(j=0; j<i; ++j)
        if(strcmp(words[j], last))
        {
            puts(words[j]);
            last = words[j];
        }

    return 0;
}

