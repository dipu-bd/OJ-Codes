#include <stdio.h>
#include <math.h>

typedef struct
{
    double pos;
    double val;
} Points;

int compare(void *a, void *b)
{
    double p = ((Points*)a)->pos;
    double q = ((Points*)b)->pos;
    if(p>q) return 1;
    else if(p==q) return 0;
    else return -1;
}

int main()
{
    Points p[100];

    int t, i,nl;
    double a,a1,b,b1,r;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&nl);

        /*get points */
        i = 0;
        while(nl--)
        {
            scanf("%lf %lf %lf %lf %lf",&a,&a1,&b,&b1,&r);
            if(a>b) a=(a+b)-(b=a);  /* exchange value */
            p[i++] = (Points){a,r};
            p[i++] = (Points){b,1.0/r};
        }

        /*sort points*/
        qsort(p,i,sizeof(Points),compare);

        /*show result*/
        printf("%d\n",i+1);
        r = 1.0;
        printf("-inf %.3lf %.3lf\n",p[0].pos, 1.0);
        for(nl=0;nl<i-1;++nl)
        {
            r *= p[nl].val;
            /*if(nl>0) if(p[nl].pos == p[nl-1].pos) continue;*/
            printf("%.3lf %.3lf %.3lf\n",p[nl].pos, p[nl+1].pos, r);
        }
        printf("%.3lf +inf %.3lf\n",p[i-1].pos, 1.0);

        if(t>0) putchar('\n');
    }

    return 0;
}
