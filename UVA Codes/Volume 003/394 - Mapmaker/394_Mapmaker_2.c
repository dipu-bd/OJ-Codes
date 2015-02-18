#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[12];
    int base;
    short size;
    short d;
    struct
    {
        short lower;
        short upper;
    } bounds[10];
    short bsiz[10];
} arraydef;

int main()
{
    int n,r;
    scanf("%d %d",&n,&r);

    char nam[12];
    register i,j,m,d,x,t,l;
    int loc[10];

    arraydef ary[n];

    for(i=0; i<n; i++)
    {
        scanf("%s %d %d %d", &ary[i].name, &ary[i].base, &ary[i].size, &ary[i].d);
        for(j=0; j<ary[i].d; j++)
        {
            scanf("%d %d", &ary[i].bounds[j].lower, &ary[i].bounds[j].upper);
            ary[i].bsiz[j] = ary[i].bounds[j].upper - ary[i].bounds[j].lower + 1;
        }
    }


    for(i=0; i<r; i++)
    {
        scanf("%s", &nam);
        printf("%s[",nam);

        for(m=0; m<n; m++)
            if(!strcmp(nam,ary[m].name)) break;

        d = ary[m].d-1;

        for(j=0; j<d; j++)
        {
            scanf("%d", &loc[j]);
            printf("%d, ",loc[j]);
        }
        scanf("%d", &loc[d]);
        printf("%d] = ", loc[d]);

        for(l=0, t=1, j=d; j>=0; j--)
        {
            x = loc[j] - ary[m].bounds[j].lower;
            l += x*t;
            t *= ary[m].bsiz[j];
        }
        l = ary[m].base + l*ary[m].size;
        printf("%d\n",l);
    }

    return 0;
}
