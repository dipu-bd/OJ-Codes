#include <stdio.h>

int main()
{
    int ccount,i,j,k,l,t;
    scanf("%d",&ccount);

    int r,s[50000],sum,min;
    for(i=0;i<ccount;i++)
    {
        scanf("%d",&r);
        for(j=0;j<r;j++)
            scanf("%d",&s[j]);

        for(k=0;k<r;k++)
        {
            sum=0;
            for(l=0;l<r;l++)
            {
                t=s[k]-s[l];
                sum+=(t<0)?-t:t;
            }

            if(k==0) min=sum;
            if(sum<min) min=sum;
        }
        printf("%d\n",min);
    }

    return 0;
}
