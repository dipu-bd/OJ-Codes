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
int prime[5000];
bool flag[100005];
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

int prime_count(int a, int b)
{
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
    int cnt = 0;
    REPE(i, 0, m) if(!flag[i]) cnt++;

    return cnt;
}

int main()
{
    sieve();

    scanf("%d", &test);
    while(test--)
    {
        int a, b;
        scanf("%d %d", &a, &b);

        int res = 0;
        if(a == 1) ++a;
        if(a <= b) res = prime_count(a, b);

        printf("Case %d: %d\n", cas++, res);
    }

    return 0;
}
