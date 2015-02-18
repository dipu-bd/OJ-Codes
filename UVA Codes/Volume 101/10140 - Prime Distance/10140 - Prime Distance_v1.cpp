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
#include <time.h>
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

int sz;
vii arr;
int prime[5000];
bool flag[1000006];
const int MAX = 46400;

void sieve()
{
    int i, j, m = sqrt(MAX);

    prime[sz++] = 2;
    for(i = 4; i <= MAX; i += 2) flag[i] = 1;

    for(i = 3; i <= m; i += 2)
        if(!flag[i])
        {
            prime[sz++] = i;
            for(j = i * i; j <= MAX; j += i + i) flag[j] = 1;
        }

    for(; i <= MAX; i += 2)
        if(!flag[i]) prime[sz++] = i;
}

void segment_sieve(int a, int b)
{
    if(a > b) return;
    memset(flag, 0, (b - a + 3));

    int m = sqrt(b);
    REP(i, 0, sz)
    {
        int& p = prime[i];
        if(p > m) break;

        ll j = (ll)ceil((double)a / p);
        j = (j - 1) ? j * p : (ll)p * p;

        for( ; j <= b; j += p) flag[j - a] = 1;
    }

    m = b - a;
    REPE(i, 0, m) if(!flag[i]) arr.pb(i);
}

void findres(int s)
{
    int la, lb, ha, hb;
    int d1 = 1 << 30, d2 = 0;
    loop(i, arr)
    {
        if(i == arr.begin()) continue;

        int& p = *i;
        int& q = *(i - 1);
        int d = p - q;
        if(d < d1)
        {
            d1 = d;
            la = q, lb = p;
        }
        if(d > d2)
        {
            d2 = d;
            ha = q, hb = p;
        }
    }

    la += s, lb += s, ha += s, hb += s;
    printf("%d,%d are closest, %d,%d are most distant.\n", la, lb, ha, hb);
}

int main()
{
    sieve();

    int a, b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        arr.clear();

        if(a == 1) ++a;
        segment_sieve(a, b);

        if(arr.size() > 1) findres(a);
        else printf("There are no adjacent primes.\n");
    }

    return 0;
}

/*
2146483647 2147483647
*/
