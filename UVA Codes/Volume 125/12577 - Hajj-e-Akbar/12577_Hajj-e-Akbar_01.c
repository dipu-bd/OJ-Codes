#include <stdio.h>

int main()
{
    char inp[20];
    int n;
    for(n=1;scanf("%s",inp)!=EOF && inp[0]!='*';n++)
    {
        printf("Case %d: ",n);
        if(inp[0]=='H' || inp[0]=='h')
            printf("Hajj-e-Akbar\n");
        else printf("Hajj-e-Asghar\n");
    }
    return 0;
}
