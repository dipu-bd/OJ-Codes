#include <stdio.h>

int main()
{
    int road, num;
    register i,r;
    for(i=1; scanf("%d %d", &road, &num)==2 && road>0; i++)
    {
        r = (road-1)/num;
        if(r>26)
            printf("Case %d: impossible\n",i);
        else
            printf("Case %d: %d\n",i,r);
    }
    return 0;
}
