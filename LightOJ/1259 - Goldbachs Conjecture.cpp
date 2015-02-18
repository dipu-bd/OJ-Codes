#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define MAX 10000002

bool prime[MAX + 10];
vector<int> primes;

void sieve()
{
    prime[0] = prime[1] = 1;

    int m = sqrt(MAX);
    for(int i = 2; i <= m; ++i)
        if(!prime[i])
        {
            primes.push_back(i);
            for(int j = i * i; j < MAX; j += i)
                prime[j] = 1;
        }

    for(int i = m + 1; i < MAX; ++i)
        if(!prime[i]) primes.push_back(i);
}

int main()
{
    sieve();

    int t, cas = 1;
    int n, way;

    scanf("%d", &t);
    while(t--)
    {
        scanf("%d", &n);

        way = 0;
        int m = n >> 1;
        vector<int>::iterator it;
        for(it = primes.begin();
                it != primes.end(); ++it)
        {
            if(*it > m) break;
            if(!prime[n - *it]) way++;
        }

        printf("Case %d: %d\n", cas++, way);
    }

    return 0;
}
