#include <stdio.h>
#include <string.h>

#define ISVOWEL(c) (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')

char inp1[25];
char inp2[25];

int main()
{
    int tc;
    scanf("%d",&tc);

    while(tc--)
    {
        scanf(" %s %s", inp1, inp2);
        if(isequal()) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}

int isequal()
{
    if(strlen(inp1)!=strlen(inp2)) return 0;
    int i;
    for(i=0; inp1[i]; ++i)
        if(inp1[i]!=inp2[i])
            if(!(ISVOWEL(inp1[i]) && ISVOWEL(inp2[i]))) return 0;

    return 1;
}
