#include <stdio.h>

int m, n;
char land[110][110];

#define CHECK(a,b) if(land[a][b]) removemine(a, b)

void removemine(int a, int b)
{
    int ma, pa, mb, pb;
    ma = a-1, pa = a+1;
    mb = b-1, pb = b+1;

    land[a][b] = 0;
    if(mb>=0) CHECK(a, mb);
    if(pb<n) CHECK(a, pb);

    if(ma>=0)
    {
        CHECK(ma,b);
        if(mb>=0) CHECK(ma, mb);
        if(pb<n) CHECK(ma, pb);
    }

    if(pa<m)
    {
        CHECK(pa,b);
        if(mb>=0) CHECK(pa, mb);
        if(pb<n) CHECK(pa, pb);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("572_Oil Deposits_01.inp","r",stdin);
#endif

    int i, j, count;
    while(scanf(" %d %d", &m, &n)!=EOF && m>0)
    {
        for(i=0; i<m; ++i)
        {
            getchar();
            for(j=0; j<n; ++j)
                land[i][j] = (getchar()=='@');
        }

        for(count=i=0; i<m; ++i)
            for(j=0; j<n; ++j)
                if(land[i][j])
                {
                    removemine(i,j);
                    ++count;
                }

        printf("%d\n",count);
    }

    return 0;
}

