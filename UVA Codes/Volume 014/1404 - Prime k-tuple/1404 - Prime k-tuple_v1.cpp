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
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define fr first
#define sc second
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
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define PCOUNT 98222290
#define SIZE 2000000000

int sz, q;
char flag[1 + (SIZE >> 4)];
int base[10000];
int prime[PCOUNT];

#define GET(i) (flag[(i) >> 3] & (1 << ((i) & 7)))
#define SET(j) (flag[(j) >> 3] |= (1 << ((j) & 7)))
#define isprime(i) (i == 2 || (((i) & 1) && !GET((i) >> 1)))

void sieve()
{
    int i, j, s, l;

    s = SIZE >> 1;
    l = 100 + (int)sqrt(SIZE);
    flag[0] = 0b10010001;

    for(i = 1; i * (i << 1) < l; ++i)
        if(!GET(i))
            for(j = (i << 1) * (i + 1); j < s; j += i + i + 1)
                SET(j);

    s = 0;
    base[s++] = 2;
    for(int i = 3; i < l; i += 2)
        if(!GET(i >> 1)) base[s++] = i;
}

void segment_sieve(int a, int b)
{
    if((ll)b * b > SIZE) return;

    ll m = 1 + (ll)sqrt(b);
    for(int i = 0; base[i] <= m; ++i)
    {
        int p = a + base[i] - a % base[i];
        if(p == base[i]) p = base[i] * base[i];
        for(; p <= b; p += base[i])
            if(p & 1) SET(p >> 1);
    }
}

struct input
{
    int a, b, k, s, p;
    bool operator < (const input& r) const
    {
        if(a == r.a) return b < r.b;
        return a < r.a;
    }
};

void gener(int a, int b)
{
    sz = 0;
    for(int i = a; i <= b; ++i)
        if(isprime(i)) prime[sz++] = i;
}

int ans[30];
vector<input> vinp;

int main()
{
    sieve();

    int a, b;
    input inp;

    scanf("%d", &test);
    REP(i, 0, test)
    {
        inp.p = i;
        scanf("%d %d %d %d", &inp.a, &inp.b, &inp.k, &inp.s);
        if(inp.a > inp.b) swap(inp.a, inp.b);
        vinp.push_back(inp);
    }

    ssort(vinp);

    a = -1;
    loop(i, vinp)
    {
        if(a == -1)
        {
            a = i->a;
            b = i->b;
        }
        else
        {
            if(b < i->a)
            {
                segment_sieve(a, b);
                a = i->a;
                b = i->b;
            }
            else if(b < i->b)
            {
                b = i->b;
            }
        }
    }
    if(a != -1) segment_sieve(a, b);

    loop(it, vinp)
    {
        gener(it->a, it->b);
        ans[it->p] = 0;
        REP(i, (it->k) - 1, sz)
        if(prime[i] - prime[i - (it->k) + 1] == it->s) ++ans[it->p];
    }

    REP(i, 0, test)
    printf("%d\n", ans[i]);

    return 0;
}
