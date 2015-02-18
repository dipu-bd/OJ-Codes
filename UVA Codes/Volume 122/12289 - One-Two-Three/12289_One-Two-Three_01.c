#include <stdio.h>

int main()
{
    char num[11];
    int tc,c;
    scanf("%d",&tc);
    for(; tc>0; tc--)
    {
        scanf(" %s",num);
        if(num[3]==0)
        {
            c=0;
            if(num[0]=='o') c++;
            if(num[1]=='n') c++;
            if(num[2]=='e') c++;

            if(c>=2) puts("1");
            else puts("2");
        }
        else puts("3");
    }
    return 0;
}

