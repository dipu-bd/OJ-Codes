#include <stdio.h>

int main()
{
    int t, inp;
    long long money;
    char work[10];

    scanf("%d",&t);
    for(money=0;t>0;t--)
    {
        fflush(stdin);
        scanf("%s",work);
        if(work[0]=='d')
        {
            scanf(" %d",&inp);
            money += inp;
        }
        else printf("%lld\n",money);
    }
    return 0;
}
