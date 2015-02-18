#include <stdio.h>
#include <stdlib.h>

#define SIZE 5000
int num[SIZE];

int compare(const int *a, const int *b)
{
    return (*a)-(*b);
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("10954.inp", "r", stdin);
#endif

    int n,i;
    long long int s;
    while(scanf("%d",&n)!=EOF && n>0)
    {
        for(i=0;i<n;++i) scanf("%d",num+i);
        qsort(num,n,sizeof(int),compare);

        for(s=0, i=1; i<n; ++i)
             s += (num[i] += num[i-1]);

        printf("%d\n", s);
    }

    return 0;
}
