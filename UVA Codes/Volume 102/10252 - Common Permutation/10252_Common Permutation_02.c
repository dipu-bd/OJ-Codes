#include <stdio.h>
#include <string.h>

int t1[256], t2[256];

void print()
{
    int m;
    unsigned char i;
    for(i=32; i<255; ++i)
    {
        m = (t1[i]<t2[i]) ? t1[i] : t2[i];
        if(m) while(m--) putchar(i);
        t1[i] = t2[i] = 0;
    }
    putchar('\n');
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10252_Common Permutation_02.inp","r",stdin);
#endif

    char f=0;
    unsigned char c;

    memset(t1,0,sizeof(t1));
    memset(t2,0,sizeof(t2));

    while(!feof(stdin))
    {
        c = getchar();
        if(c=='\n')
        {
            if(f) print();
            f = !f;
        }
        else
        {
            if(f) ++t2[c];
            else ++t1[c];
        }
    }

    return 0;
}
