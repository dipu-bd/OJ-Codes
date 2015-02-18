// C header files
#include <stdio.h>
#include <ctype.h>
#include <string.h>
// C++ header files
#include <iostream>
#include <vector>
// default namespace
using namespace std;

#define MAX 36

long long power(long long a, long long n)
{
    if(n == 0) return 1;
    if(n & 1)
    {
        long long res = power(a, (n - 1) >> 1);
        return a * res * res;
    }
    else
    {
        long long res = power(a, n >> 1);
        return (res * res);
    }
}

int main()
{

#ifndef ONLINE_JUDGE
   freopen("343.inp", "r", stdin);
#endif

    char a[150], b[150];
    int amax, bmax, alen, blen;
    bool notfound;
    long long num;
    vector<long long> na;

    while(scanf(" %s %s", a, b) == 2)
    {
        for(alen = amax = 0; a[alen]; ++alen)
            if(amax < a[alen]) amax = a[alen];
        amax -= (isdigit(amax) ? '0' : 'A' - 10);
        amax = (amax < 1) ? 2 : amax + 1;

        for(blen = bmax = 0; b[blen]; ++blen)
            if(bmax < b[blen]) bmax = b[blen];
        bmax -= (isdigit(bmax) ? '0' : 'A' - 10);
        bmax = (bmax < 1) ? 2 : bmax + 1;

        //if both strings are equal
//        if(!strcmp(a, b))
//        {
//            printf("%s (base %d) = %s (base %d)\n", a, amax, b, bmax);
//            na.push_back(49);
//            continue;
//        }

        //convert first number to decimal
        for(int base = amax; base <= MAX;  ++base)
        {
            for(int i = num = 0, j = alen, ch; j--; ++i)
            {
                ch = a[i];
                ch -= (isdigit(ch) ? '0' : 'A' - 10);
                num += (long long)ch * power(base, j);
            }
            na.push_back(num);
        }

        //show result
        notfound = true;
        for(int base = bmax; base <= MAX && notfound;  ++base)
        {
            for(int i = num = 0, j = blen, ch; j--; ++i)
            {
                ch = b[i];
                ch -= (isdigit(ch) ? '0' : 'A' - 10);
                num += (long long)ch * power(base, j);
            }

            vector<long long>::iterator it = na.begin();
            for(int i = amax; it < na.end(); ++it, ++i)
                if(num == *it)
                {
                    printf("%s (base %d) = %s (base %d)\n", a, i, b, base);
                    notfound = false;
                    break;
                }
        }

        if(notfound)
            printf("%s is not equal to %s in any base 2..36\n", a, b);

        na.clear();
    }

    return 0;
}
