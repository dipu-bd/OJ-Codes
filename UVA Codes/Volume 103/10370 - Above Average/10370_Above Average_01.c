#include<stdio.h>

int main()
{
    int count,i;
    scanf("%d",&count);

    float res[count];
    for(i=0;i<count;i++)
    {
        int ic;
        scanf("%d",&ic);
        int num[ic],sum=0,p;
        for(p=0;p<ic;p++)
        {
            scanf("%d",&num[p]);
            sum+=num[p];
        }
        float avrg = sum/ic;
        int auc=0;
        for(p=0;p<ic;p++)
            if(num[p]>avrg) auc++;

        res[i]=(float)(auc*100)/ic;
    }

    for(i=0;i<count;i++)
        printf("%.3lf%%\n",res[i]);

    return 0;
}
