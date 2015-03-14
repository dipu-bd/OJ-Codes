#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

#define SIZE 201
long long G[SIZE];

int GCD(int a, int b)
{
    if(!b)  return a;
    return GCD(b, a % b);
}

void MAKE(void)
{
    G[2] = 1;
    register long long g;
    for(int n = 3; n < SIZE; ++n)
    {
        g = G[n - 1];
        for(int i = 1; i < n; ++i)
        {
            if(!(n % i)) g += (long long)i;
            else g += (long long)GCD(n, i);
        }
        G[n] = g;
    }

    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    // freopen("11424.inp", "r", stdin);
#endif

    MAKE(); 

    int N;
    while(scanf("%d", &N) != EOF && N > 0)
        printf("%d\n", G[N]);

    return 0;
}
