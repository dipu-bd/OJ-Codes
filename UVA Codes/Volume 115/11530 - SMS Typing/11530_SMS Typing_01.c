#include <stdio.h>

int main()
{
    int cc,c,i,key;
    char inp[110];
    const char data[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};

    scanf("%d",&cc);
    for(i=1; i<=cc; i++)
    {
        gets(inp);
        if(inp[0]==0)
        {
            i--;
            continue;
        }

        for(c=0,key=0; inp[c]!=0; c++)
            if(inp[c]==' ') key++;
            else key+=data[inp[c]-'a'];
        printf("Case #%d: %d\n",i,key);
    }
    return 0;
}
