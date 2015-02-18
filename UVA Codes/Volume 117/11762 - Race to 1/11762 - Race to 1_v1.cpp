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

#define MAX 1000000

int sz;
int primes[MAX];
bool flag[MAX + 10];

void sieve()
{
    int i, j, m;

    primes[sz++] = 2;
    for(j = 4; j <= MAX; j += 2) flag[j] = 1;

    m = sqrt(MAX);
    for(i = 3; i <= m; i += 2)
    {
        if(!flag[i])
        {
            primes[sz++] = i;
            for(j = i * i; j <= MAX; j += i + i) flag[j] = 1;
        }
    }

    for(; i <= MAX; i += 2)
        if(!flag[i]) primes[sz++] = i;
}

double save[MAX + 10];

double recur(int n)
{
    if(n == 1) return 0;

    double& dp = save[n];
    if(dp > 1e-10) return dp;

    int nd = 0;
    int cnt = (int)(lower_bound(primes, primes + sz, n) - primes);
    if(primes[cnt] == n) cnt++;
    REP(i, 0, cnt)
    {
        int p = primes[i];
        if(n % p) ++nd; //not divisible
        else dp += recur(n / p);
    }

    dp = (cnt + dp) / (cnt - nd);
    return dp;
}


int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    sieve();

    int n;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        printf("Case %d: %.7lf\n", cas++, recur(n));
    }

    return 0;
}
