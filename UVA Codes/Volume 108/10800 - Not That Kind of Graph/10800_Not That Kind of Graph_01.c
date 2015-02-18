#include <stdio.h>
#include <string.h>

int h, w;
char graph[60][60];
char inp[60];

int main()
{
    int i,j, t;
    scanf("%d", &t);
    for(i=1; i<=t; ++i)
    {
        printf("Case #%d:\n", i);
        scanf(" %[^\n]", inp);
        generateGraph();
        printGraph();
    }


    return 0;
}

void generateGraph()
{
    memset(graph,0,sizeof(graph));
    int i, p, l;

    l = strlen(inp);
    memset(graph[0]+1, '-', (l+2)*sizeof(char));
    graph[0][0]='+';
    graph[1][0]='|';

    h = p = 1, w = 2;
    for(i=0; i<l; ++i)
    {
        if(inp[i]=='R')
        {
            graph[p++][w++] = '/';
            if(p>h) graph[(h=p)][0] = '|';
        }
        else if(inp[i]=='C')
            graph[p][w++] = '_';
        else
            graph[--p][w++] = '\\';
    }

}

void printGraph()
{
    int i,j;

    for(i=h; i>=0; --i)
    {
        for(j=0; j<w; ++j)
            if(graph[i][j])
                putchar(graph[i][j]);
            else putchar(' ');

        putchar('\n');
    }
    putchar('\n');
}
