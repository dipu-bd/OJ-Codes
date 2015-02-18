#include <stdio.h>

int main()
{
    int num[10000],i,tc=-1;
    do
        scanf("%d", &num[++tc]);
    while (num[tc]>0);

    for(i=0;i<tc;i++)
    {
        int n=num[i], c=0;
        while(n>=2)
        {
            float div=(float)n/2;
            n=(int)div;
            if (div>n) n++;
            ++c;
         }

        printf("Case %d: %d\n",i+1,c);
    }

    return 0;
}
