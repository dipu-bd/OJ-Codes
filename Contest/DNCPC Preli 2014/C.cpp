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

int test, cas = 1;

int n, m, r, p;

ll col[102];
ll tmp[102];
vii adj[102][12];
int mat[102][102];

#define MOD 1000000007
#define MAX 100000
ll save[102][MAX + 2];
int savecas[102][MAX + 2];

ll recur(int u, int t)
{
    if(t == 0) return col[u];

    ll& dp = save[u][t];
    int& cs = savecas[u][t];
    if(cs == cas) return dp;

    cs = cas;
    dp = recur(u, t - 1);
    int l = 1 + ((t - 1) % r);
    loop(i, adj[u][l]) dp = (dp + recur(*i, t - 1)) % MOD;

    return dp;
}

int main()
{
#ifdef LOCAL
    freopen("C.txt", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d", &n, &m, &r, &p);

        //take initial color
        REP(i, 0, n) scanf("%lld", &col[i]);

        //take graph
        mem(mat, 0x0F);
        REP(i, 0, n)
        mat[i][i] = 0;
        REP(i, 0, m)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            mat[u][v] = mat[v][u] = 1;
        }

        //shortest path
        REP(k, 0, n)
        REP(i, 0, n)
        REP(j, 0, n)
        mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);

        //calculate adjacency vectors
        REP(i, 0, n)
        REP(j, 0, n)
        {
            int d = mat[i][j];
            if(d <= r) adj[i][d].pb(j);
        }

        int time = MAX - (MAX % r);
        int mti = time;
        while(mti <= p)
        {
            REP(i, 0, n) tmp[i] = recur(i, time + 1);
            REP(i, 0, n) col[i] = tmp[i];
            mti += time;
        }

        if(p >= mti) p -= mti;
        printf("Case %d:", cas++);
        REP(i, 0, n) printf(" %lld", recur(i, p));
        putchar('\n');
    }


    return 0;
}

