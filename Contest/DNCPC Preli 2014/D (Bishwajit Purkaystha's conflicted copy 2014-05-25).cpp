/*============================
TEAM: SUST_Nexus
CODER: Sudipto Chandra. DIPU
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
typedef long long ull;
typedef pair<ll, ll> pll;
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

#define MOD 1000000007

int test, cas = 1;

int main()
{
#ifdef LOCAL
    //freopen(".txt", "r", stdin);
#endif // LOCAL

    int n, x, c;
    ll num, den;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &x);

        bool tgcd = true;
        num = den = 1;
        while(n--)
        {
            scanf("%d", &c);

            if(tgcd)
            {
                ll g = gcd(num, den);
                num /= g, den /= g;
            }
            else
            {
                num = (num * (x - c)) % MOD;
                den = (den * x) % MOD;
            }
        }

        printf("Case %d: ", cas++);

        if(num == 0) printf("0\n");
        else if(num == den) printf("1\n");
        else printf("%lld/%lld\n", num, den);
    }

    return 0;
}

