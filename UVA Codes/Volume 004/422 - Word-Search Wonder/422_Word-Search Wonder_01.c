#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int LENGTH=0;
char matrix[110][110]={};

int main()
{
    int i;
    /* GET INPUT */
    scanf("%d",&LENGTH);
    for(i=0;i<LENGTH;++i)
        scanf(" %[^\n]",matrix[i]);

    /*GET WORDS AND CHECK*/
    char query[110];
    while(scanf(" %[^\n]",query)==1 && query[0]!='0')
    {


    }
    return 0;
}

int check_vertical(const char *query)
{
    int i,siz,a,b;
    siz = strlen(query);
    for(i=0;i<LENGTH; ++i)
    {
        for(j=0;j<siz && (query[j]==matrix[j][i]); ++j);
        if(siz==j) return 1;

    }
    return 0;
}

int check_horizontal(const char *query)
{
    int i,j,siz;
    siz = strlen(query);
    for(i=0;i<LENGTH; ++i)
    {
        for(j=0;j<siz && (query[j]==matrix[j][i]); ++j);
        if(siz==j) return 1;
    }
    return 0;
}

int check_diagonal(const char *query)
{
    int i,siz;
    siz = strlen(query);
    for(i=0;i<LENGTH; ++i)
    {
        for(j=0;j<siz && (query[j]==matrix[j][i]); ++j);
        if(siz==j) return 1;
    }
    return 0;
}
