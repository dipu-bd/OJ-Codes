/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
//cpp headers
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <deque>
#include <list>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long llu;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------------------------*/

#define SQSIZ 10000
#define SIZ 100000010
#define MOD 4294967295

int sz;
int prime[6000000];
uint multi[6000000];
char flag[(SIZ >> 3) + 2];

inline bool check(int n)
{
    return (flag[n >> 3] & (1 << (n & 7)));
}

inline void setp(int n)
{
    flag[n >> 3] |= (1 << (n & 7));
}

inline void sieve()
{
    int i, j;

    prime[sz++] = 2;
    for(j = 4; j < SIZ; j += 2) setp(j);

    for(i = 3; i < SQSIZ; i += 2)
        if(!check(i))
        {
            prime[sz++] = i;
            for(j = i * i; j < SIZ; j += i + i) setp(j);
        }

    for(; i < SIZ; i += 2)
        if(!check(i)) prime[sz++] = i;
}

inline void precalc()
{
    multi[0] = prime[0];
    REP(i, 1, sz) multi[i] = multi[i - 1] * prime[i];
}

inline uint getlcm(int n)
{
    int m = (int)sqrt(n);

    uint res = 1;
    for(int i = 0; i < sz; ++i)
    {
        int& p = prime[i];
        if(p > m) break;

        ll c = p * p;
        while(c < n)
        {
            res *= p;
            c *= p;
        }
        if(c == n) res *= p;
    }

    int* p = lower_bound(prime, prime + sz, n);
    int len = sz - 1;
    if(p)
    {
        len = p - prime;
        if(*p > n) --len;
    }
    res *= multi[len];

    return res;
}

int main()
{
    sieve();
    precalc();
    int n, test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        printf("Case %d: %u\n", cas++, getlcm(n));
    }

    return 0;
}

