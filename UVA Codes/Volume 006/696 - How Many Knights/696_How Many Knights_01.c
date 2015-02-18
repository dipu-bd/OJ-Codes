#include <stdio.h>
#include <math.h>

#define PRINT(r,c,n) printf("%d knights may be placed on a %hd row %hd column board.\n",n,r,c)

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("696_How Many Knights_01.inp","r",stdin);
    #endif

    int n;
    char p;
    short r,c,l,s;
    while(scanf("%hd %hd",&r,&c)!=EOF && r>0)
    {
        if(r>c) l=r, s=c;
        else l=c, s=r;

        if(s==1)
            PRINT(r,c,l);
        else if(s==2)
        {
            n = (l & (~3));
            p = l & 3;
            n += (p<2) ? (p<<1) : 4;
            PRINT(r,c,n);
        }
        else
        {
            n = (r*c + 1) >>1;
            PRINT(r,c,n);
        }
    }

    return 0;
}

