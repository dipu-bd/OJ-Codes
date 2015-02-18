#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
    double x;
    double y;
} Point;

Point frekls[110];

int compare(const Point *a, const Point *b)
{
    return (a->x + b->x)*(a->x - b->x) + (a->y + b->y)*(a->y - b->y);
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("10034_Freckles_02.inp","r",stdin);
    #endif

    int t,n,i;
    double res;

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);

        for(i=0; i<n; ++i)
            scanf("%lf %lf", &frekls[i].x, &frekls[i].y);

        qsort(frekls, n, sizeof(Point), compare);

        for(res=0, i=1; i<n; ++i)
            res += sqrt((frekls[i].x - frekls[i-1].x)*(frekls[i].x - frekls[i-1].x)
                         + (frekls[i].y - frekls[i-1].y)*(frekls[i].y - frekls[i-1].y));

        printf("%.2lf\n",res);
        if(t>0) putchar('\n');
    }

    return 0;
}

/*
5

3
1.0 1.0
2.0 2.0
2.0 4.0

3
1.0 1.0
2.0 2.0
2.0 4.0

3
1.0 1.0
2.0 2.0
2.0 4.0

3
1.0 1.0
2.0 2.0
2.0 4.0

3
1.0 1.0
2.0 2.0
2.0 4.0
*/
