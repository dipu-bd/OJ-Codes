#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main()
{
    int test;
    ll fact[25];

    for(int i = fact[0] = 1; i <= 20; ++i)
        fact[i] = fact[i - 1] * i;

    scanf("%d", &test);
    while(test--)
    {
        int p;
        ll num;
        string inp;

        cin >> inp >> num;

        sort(inp.begin(), inp.end());

        for(int n = inp.size() - 1; n > 0; --n)
        {
            p = num / fact[n];
            num %= fact[n];
            putchar(inp[p]);
            inp.erase(p + inp.begin());
        }

        printf("%c\n", inp[0]);
    }

    return 0;
}
