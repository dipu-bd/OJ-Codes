#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,h;
    register c,i,avg,sum,mov;
    char *brick=calloc(51,sizeof(int));
    for(c=1;scanf("%d",&n)==1 && n>0;c++)
    {
        for(sum=0,i=0; i<n &&
            scanf("%d",&h)==1;
            i++, sum+=h)
            brick[i]=h;
        avg=sum/n;

        for(mov=0, i=0; i<n; i++)
            if(brick[i]>avg) mov+=brick[i]-avg;

        printf("Set #%d\nThe minimum number of moves is %d.\n\n",c,mov);
    }
    return 0;
}
