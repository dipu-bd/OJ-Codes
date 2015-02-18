#include <stdio.h>

char matrix[100][100];

int main()
{
    int i,j,n;
    int vs, hs, vc, hc, li,lj;
    while(scanf("%d",&n)!=EOF && n>0)
    {

        for(vc=i=0; i<n; ++i)
        {
            for(vs=j=0; j<n; ++j)
            {
                scanf("%d", matrix[i]+j);
                if(matrix[i][j]) ++vs;
            }
            if(1&vs)
            {
                ++vc, li = i;
            }
        }

        for(hc=j=0; j<n; ++j)
        {
            for(hs=i=0; i<n; ++i)
                if(matrix[i][j]) ++hs;
            if(1&hs)
            {
                ++hc, lj = j;
            }
        }

        if(hc==vc)
            if(vc == 0) puts("OK");
            else if(vc == 1) printf("Change bit (%d,%d)\n",li+1,lj+1);
            else puts("Corrupt");

        else puts("Corrupt");


    }

    return 0;
}
