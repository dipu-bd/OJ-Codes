#include <stdio.h>

#define SIZE 10000
int freq[SIZE][10];

void count()
{
    int i,n,t;

    for(t=0; t<10; ++t)
        freq[0][t] = 0;

    for(i=1; i<SIZE; ++i)
    {
        for(t=0; t<10; ++t)
            freq[i][t] = freq[i-1][t];

        for(n=i, t=n/10; n; n=t, t=n/10)
            ++freq[i][n-t*10];
    }
}

int main()
{
    count();

    int t, n,i;
    scanf("%d",&t);

    while(t--)
    {
        scanf("%d",&n);
        for(i=0; i<9; ++i)
            printf("%d ", freq[n][i]);
        printf("%d\n",freq[n][9] );
    }

    return 0;
}

