#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *cypher = calloc(110,sizeof(char));
    char *text = calloc(110,sizeof(char));
    while(scanf(" %[^\n] %[^\n]",cypher,text)==2)
    {
        substitute(cypher);
        puts(cypher);
        puts("");
        if(checkmatch(cypher,text))  puts("YES");
        else puts("NO");
    }
    return 0;
}

void substitute(char *cypher)
{
    int i;
    for(i=0;cypher[i]!=0;i++)
        if(cypher[i]=='A') cypher[i]='Z';
        else cypher[i]-=1;
    return;
}

int checkmatch(char *cypher,char *text)
{
    register i,j,f;
    for(i=0;cypher[i]!=0;i++)
    {
        for(j=0,f=0;text[j]!=0;j++)
        {
            f=(text[j]==cypher[i]);
            if(f) break;
        }
        if(!f) return 0;
        text[j]=' ';
    }
    return 1;
}


