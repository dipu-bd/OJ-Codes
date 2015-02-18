#include <stdio.h>
#include <string.h>

int main()
{
    register i;
    char inp[50];
    for(i=1; scanf(" %s",inp); i++)
    {
        if(inp[0]=='#') break;
        if(!strcmp(inp,"HELLO"))
            printf("Case %d: ENGLISH",i);
        else if(!strcmp(inp,"HOLA"))
            printf("Case %d: SPANISH",i);
        else if(!strcmp(inp,"HALLO"))
            printf("Case %d: GERMAN",i);
        else if(!strcmp(inp,"BONJOUR"))
            printf("Case %d: FRENCH",i);
        else if(!strcmp(inp,"CIAO"))
            printf("Case %d: ITALIAN",i);
        else if(!strcmp(inp,"ZDRAVSTVUJTE"))
            printf("Case %d: RUSSIAN",i);
        else
            printf("Case %d: UNKNOWN",i);
        putchar('\n');
    }
    return 0;
}
