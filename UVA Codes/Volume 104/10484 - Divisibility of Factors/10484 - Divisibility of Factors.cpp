#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void factorize(ll t, map<int, int>& fact)
{
    for(ll p = 2; p * p <= t; ++p)
    {
        if(t % p == 0)
        {
            int cnt = 0;
            while(t % p == 0)
            {
                t /= p;
                ++cnt;
            }
            fact[p] += cnt;
        }
    }
    if(t > 1) fact[t]++;
}


int main()
{
    int n, d;
    map<int, int> factn, factd;

    while(scanf("%d %d", &n, &d) == 2, d)
    {
        if(d < 0)
        {
            puts("0");
            continue;
        }

        factn.clear();
        for(int i = 2; i <= n; ++i)
        {
            factorize(i, factn);
        }

        factd.clear();
        factorize(d, factd);

        bool out = false;
        for(auto p : factd)
        {
            int &t = factn[p.first];
            if(t < p.second)
            {
                out = true;
                break;
            }
            t -= p.second;
        }

        ll res = 0;
        if(!out)
        {
            res = 1;
            for(auto p : factn)
            {
                res *= p.second + 1;
            }
        }

        printf("%lld\n", res);
    }

    return 0;
}
