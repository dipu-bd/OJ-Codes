#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <limits.h>
using namespace std;

bool isprime(int n)
{
    if(n < 2) return false;
    if(n == 2) return true;

    int m = sqrt(n);
    for(int i = 3; i <= m; i += 2)
        if(n % i == 0) return false;
    return true;
}

int func(int n, int a, int b)
{
    return n * n + a * n + b;
}

int main()
{
    int mn = 0, ma, mb;

    for(int a = -1000; a <= 1000; ++a)
    {
        for(int b = -1000; b <= 1000; ++b)
        {
            int n = -1, p;
            do
            {
                n++;
                p = func(n, a, b);
            }
            while(isprime(p));
            if(n > mn) mn = n, ma = a, mb = b;
        }
    }

    printf("n = %d, a = %d, b = %d\n", mn, ma, mb);
    printf("Product = %d\n", (ma * mb));

    return 0;
}
