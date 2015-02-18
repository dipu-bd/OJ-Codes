#include <stdio.h>
#include <math.h>

int main()
{
    int cs,c1;
    scanf("%d",&cs);
    for(c1=0; c1<cs; c1++)
    {
        int n,p,freck[500][500];
        for(n=0; n<500; n++)
            for(p=0; p<500; p++)
                freck[n][p]=0;

        scanf("%d",&n);
        for(p=0; p<n; p++)
        {
            float x,y;
            scanf("%lf %lf",&x,&y);
            freck[(int)x-1][(int)y-1]=1;
        }

        int i,j,t=1;
        float sum=0;

        int x1=0,y1=0;
        for(i=0; i<500; i++)
            for(j=(t?0:499); (t?(j<500):(j>=0)); j+=(t?1:-1))
            {
                if(freck[i][j])
                {
                    sum += sqrt((i+1-x1)*(i+1-x1)+(j+1-y1)*(j+1-y1));
                    x1=i+1;
                    y1=j+1;
                }
                t=!t;
            }

        printf("%.2lf\n",sum);
    }

    return 0;

}
