// C headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
// CPP headers
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

//predefined macros
#define mp make_pair
#define pb push_back
#define _a first
#define _b second
#define _IT ::iterator
#define gcd(a,b) __gcd(a,b)

#define PI acos(-1)

//typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

//pre-structures
template<class T> struct triad { T x; T y; T z; triad(T a = 0, T b = 0, T c = 0) : x(a), y(b), z(c) { } };
//pre functions
template<class T> inline T square(T num) { return num * num; }
inline ll modulo(ll num, ll mod)
{
    if(num < 0)
        return mod + num % mod;
    return num % mod;
}
ll modexp(ll a, ll p, ll m)
{
    if(p == 0) return 1;
    if(p == 1) return a % m;
    if(p % 2 == 0) return square(modexp(a, p / 2, m)) % m;
    return (a * (square(modexp(a, p / 2, m)) % m)) % m;
}
triad<ll> exgcd(ll a, ll b)
{
    if(b == 0) return triad<ll>(a, 1, 0);
    triad<ll> t = exgcd(b, a % b);
    return triad<ll>(t.x, t.z, t.y - (a / b) * t.z);
}

//other macros
const ll MOD = 1000000007;
const int MAX = 100010;

//global variables, constants

int len;
ll prime[MAX];
ll lob[MAX];

//functions

void sieve()
{
    int i, j, m;
    bool* flag = new bool[MAX + 10];

    prime[len++] = 2;
    for(j = 4; j < MAX; j += 2) flag[j] = true;

    m = (int)sqrt(MAX);
    for(i = 3; i < m; i += 2)
        if(!flag[i])
        {
            prime[len++] = i;
            for(j = i * i; j < MAX; j += i) flag[j] = true;
        }

    for(; i < MAX; i += 2)
        if(!flag[i]) prime[len++] = i;

    prime[len] = INT_MAX;

    for(i = 0; i < len; ++i)
        lob[i] = modulo(exgcd(prime[i] - 1, MOD).y, MOD);
}

//main function
int main()
{
#ifdef DIPU
    //freopen("inp.txt", "r", stdin);
#endif // DIPU

    sieve();

    int test, cas = 1;
    ll n, m;

    cin >> test;
    while(test--)
    {
        scanf("%lld %lld", &n, &m);

        ll hor, res = 1;
        ll sqn = (ll)sqrt((double)n);
        for(int i = 0, cnt; prime[i] <= sqn; ++i)
        {
            ll& p = prime[i];
            if(n % p == 0)
            {
                cnt = 0;
                do
                {
                    cnt++;
                    n /= p;
                }
                while(n % p == 0);

                sqn = (ll)sqrt((double)n);
                hor = modexp(p, cnt * m + 1, MOD) - 1;
                res = (res * modulo(hor * lob[i], MOD)) % MOD;
            }
        }

        if(n > 1)
        {
            hor = modexp(n, m + 1, MOD) - 1;
            ll t = modulo(exgcd(n - 1, MOD).y, MOD);
            res = (res * modulo(hor * t, MOD)) % MOD;
        }

        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}

