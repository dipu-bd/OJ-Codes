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
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(it, x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, x) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)

#define LIM 150
int len;
bool flag[LIM];
int primes[LIM];

void genprimes()
{
    primes[len++] = 2;
    for(int i = 4; i < LIM; i += 2) flag[i] = 1;
    for(int i = 3; i < LIM; i += 2)
    {
        if(!flag[i])
        {
            primes[len++] = i;
            for(int j = i * i; j < LIM; j += 2 * i) flag[j] = 1;
        }
    }
}

int power(int a, int p)
{
    if(p == 0) return 1;
    int r = power(a, p >> 1);
    if(p & 1) return a * r * r;
    return r * r;
}

int multi[LIM];
set<int> num;
void factor(int n)
{
    REP(i, 0, len)
    {
        if(n <= 1) break;

        int p = primes[i];
        if(!(n % p))
        {
            int c = 1;
            do
            {
                c *= p;
                n /= p;
            }
            while(!(n % p));

            if(c > multi[i]) multi[i] = c;
        }
    }

    if(n > 1) num.insert(n);
}

int npos;
char res[10000];
char out[10000];
void multiply(int n)
{
    int t = 0;
    REP(i, 0, npos)
    {
        t += res[i] * n;
        res[i] = t % 10;
        t /= 10;
    }
    while(t > 0)
    {
        res[npos++] = t % 10;
        t /= 10;
    }
}

void print()
{
    int p = 0;
    while(npos--) out[p++] = res[npos] + '0';
    out[p] = 0;
    puts(out);
}

int main()
{
    #ifdef LOCAL
    freopen("1024.in", "r", stdin);
    freopen("1024.out", "w", stdout);
    #endif // LOCAL

    genprimes();
    int test, cas = 1;

    int n, x;

    scanf("%d", &test);
    while(test--)
    {
        num.clear();
        mem(multi, 0);

        scanf("%d", &n);
        while(n--)
        {
            scanf("%d", &x);
            factor(x);
        }

        npos = 1;
        res[0] = 1;
        REP(i, 0, len) if(multi[i]) multiply(multi[i]);
        loop(i, num) multiply(*i);

        printf("Case %d: ", cas++);
        print();
    }

    return 0;
}

