#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int fact[12];

bool isnum(const int& n)
{
    int sum = 0, t = n;
    while(t)
    {
        sum += fact[t % 10];
        t /= 10;
    }

    return (sum == n);
}

int main()
{
    fact[0] = 1;
    for(int i = 1; i <= 10; ++i)
        fact[i] = i * fact[i - 1];

    int sum = 0;
    for(int n = 4, m = 100000; n < m; ++n)
        if(isnum(n)) sum += n;

    printf("%d\n", sum);

    return 0;
}
