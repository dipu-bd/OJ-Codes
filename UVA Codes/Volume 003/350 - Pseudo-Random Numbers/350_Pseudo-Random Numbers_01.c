#include <stdio.h>

int main()
{
    int z, i, m, l, c;
    int len, last;
    for(c=1; scanf("%d %d %d %d", &z,&i,&m,&l)!=EOF && z && i; ++c)
    {
        last=l=(z*l+i) % m;
        len=0;
        do
        {
            l = (z*l+i) % m;
            ++len;
        }
        while(l!=last);

        printf("Case %d: %d\n",c,len);

    }

    return 0;
}
