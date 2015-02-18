#include <stdio.h>

int main()
{
    int tc,g,l;
    register a,b;

    scanf("%d",&tc);
    for(; tc>0; tc--)
    {
        scanf("%d %d",&g,&l);
        if(l%g) printf("-1\n");
        else printf("%d %d\n",g,l);
    }
    return 0;
}
