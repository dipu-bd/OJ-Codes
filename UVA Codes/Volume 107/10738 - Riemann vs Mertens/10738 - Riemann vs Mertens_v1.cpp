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

#define SIZ 1000010

int prime[SIZ];
int mu[SIZ];
int M[SIZ];

void precalc()
{
    mu[1] = M[1] = 1;
    for(int i = 2; i < SIZ; ++i)
    {
        if(prime[i] == 0)
        {
            mu[i] = -1;
            for(int j = i << 1; j < SIZ; j += i)
            {
                if(prime[j] < 0) continue;
                if(!((j / i) % i)) { prime[j] = -1; mu[j] = 0; }
                else { ++prime[j]; mu[j] = (prime[j] & 1) ? -1 : 1; }
            }
        }
    }

    REP(i, 2, SIZ) M[i] = M[i - 1] + mu[i];
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n;
    precalc();

    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;
        printf("%8d%8d%8d\n", n, mu[n], M[n]);
    }

    return 0;
}
