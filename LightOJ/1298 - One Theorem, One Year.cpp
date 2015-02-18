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
typedef pair<int, int> pii;
typedef vector<int> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
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

#define SIZ 4000
#define MOD 1000000007

int sz;
bool flag[SIZ];
int prime[602];
int invprime[602];
int save[502][502];

int exgcd(int a, int b, int& x, int& y)
{
    if (b == 0) { x = 1; y = 0; return a; }
    int g = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
    return g;
}

int modinv(int p)
{
    int x, y;
    exgcd(p, MOD, x, y);
    x = x % MOD;
    if(x < 0) x += MOD;
    return x;
}

void add(int p)
{
    prime[sz] = p;
    invprime[sz] = modinv(prime[sz]);
    sz++;
}

ll plusmod(ll n)
{
    n %= MOD;
    if(n < 0) n += MOD;
    return n;
}

void sieve()
{
    int i, j, m = sqrt(SIZ);

    add(2);
    for(i = 4; i < SIZ; i += 2) flag[i] = 1;

    for(i = 3; i <= m; i += 2)
        if(!flag[i])
        {
            add(i);
            for(j = i * i; j < SIZ; j += i + i) flag[j] = 1;
        }

    for(; i < SIZ; i += 2)
        if(!flag[i]) add(i);
}

int recur(int k, int p)
{
    if(k == 0 && p == -1) return 1;
    if(k == 0 || p == -1) return 0;

    int& dp = save[k][p];
    if(dp != -1) return dp;

    int a = recur(k - 1, p);
    int b = recur(k - 1, p - 1);
    dp = ((ll)(a + b) * prime[p]) % MOD;

    return dp;
}

int main()
{
    int test, cas = 1;

    int k, p;
    sieve();
    mem(save, - 1);

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &k, &p);

        ll res = recur(k, p - 1);
        REP(i, 0, p) res = plusmod(res - res * invprime[i]);

        printf("Case %d: %d\n", cas++, res);
    }

    return 0;
}

