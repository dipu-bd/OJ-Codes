#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 101

char **inp;
int *len;

int main()
{
    register i,j,m,l,c;

    inp = calloc(MAX,sizeof(char*));
    len = calloc(MAX,sizeof(int));

    for(i=0,m=0; i<MAX; i++)
    {
        inp[i] = calloc(MAX, sizeof(char));
        if(scanf(" %[^\n]",inp[i])==EOF) break;
        len[i] = strlen(inp[i]);
        if(len[i]>m) m=len[i];
    }

    c=i-1;
    for(j=0; j<m; j++)
    {
        for(i=c; i>=0; i--)
            (j<len[i]) ? putchar(inp[i][j]) : putchar(' ');
        putchar('\n');
    }
    return 0;
}
