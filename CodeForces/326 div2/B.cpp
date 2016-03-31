#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define SIZ 2000006

bool flag[SIZ];
set<ll> sqlist;
vector<ll> prime;
vector<ll> fac;

void sieve()
{
    int i, j;
    prime.push_back(2);
    for(i = 4; i < SIZ; i += 2) flag[i] = 1;

    for(i = 3; i * i < SIZ; i += 2)
        if(!flag[i])
        {
            prime.push_back(i);
            for(j = i * i; j < SIZ; j += i + i)flag[j] = 1;
        }

    for( ; i < SIZ; i += 2)
        if(!flag[i]) prime.push_back(i);
}

void factor(ll n, vector<ll>& v)
{
    v.clear();
    for(auto p : prime)
    {
        if(p * p > n) break;
        while(n % p == 0)
        {
            n /= p;
            v.push_back(p);
        }
    }
    if(n > 1)
    {
        v.push_back(n);
    }
}

bool backtrack(vector<ll>& v, int p = 0, ll num = 1ll)
{
    if(p == v.size())
    {
        ll s = (ll)sqrt((double)num);
        if(num > 1 && s * s == num) return true;
        return false;
    }

    if(backtrack(v, p + 1, num)) return true;
    if(backtrack(v, p + 1, num * v[p])) return true;

    return false;
}

bool islovely(ll p)
{
    factor(p, fac);
    return !backtrack(fac);
}

/*
13967553600
97772875200
73329656400
*/

int main()
{
    sieve();

    ll n;
    cin >> n;

    ll m = 1;
    ll t = (ll)(sqrt((double)n));
    for(ll p = 1; p <= t; ++p)
    {
        if(n % p == 0)
        {
            if(islovely(n / p))
            {
                cout << (n / p) << endl;
                return 0;
            }
            else if(islovely(p))
            {
                m = max(m, p);
            }
        }
    }

    cout << m;

    return 0;
}

