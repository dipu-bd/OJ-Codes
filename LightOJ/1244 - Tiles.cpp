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
typedef unsigned long long ull;
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

#define dim 4
#define MOD 10007

int base[dim];
int mat[dim][dim];
int res[dim][dim];
int tmp[dim][dim];

void unit()
{
    clr(res);
    REP(i, 0, dim) res[i][i] = 1;
}

void COPY(int A[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    res[i][j] = A[i][j];
}

void cross(int A[dim][dim])
{
    REP(i, 0, dim)
    REP(j, 0, dim)
    {
        tmp[i][j] = 0;
        REP(k, 0, dim)
        {
            tmp[i][j] += res[i][k] * A[k][j];
            tmp[i][j] %= MOD;
        }
    }
    COPY(tmp);
}

void power(int n)
{
    if(n == 0) unit();
    else if(n == 1) COPY(mat);
    else
    {
        power(n >> 1);
        cross(res);
        if(n & 1) cross(mat);
    }
}

void init()
{
    clr(mat);
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[0][2] = 1;
    mat[0][3] = 1;
    mat[1][0] = 1;
    mat[2][1] = 1;
    mat[2][3] = 1;
    mat[3][1] = 1;
    mat[3][2] = 1;

    base[0] = 2;
    base[1] = 1;
    base[2] = 1;
    base[3] = 1;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    init();

    scanf("%d", &test);
    while(test--)
    {
        int n;
        scanf("%d", &n);

        power(n - 1);

        int ans = 0;
        REP(i, 0, dim)
        {
            ans += base[i] * res[1][i];
            ans %= MOD;
        }

        printf("Case %d: %d\n", cas++, ans);
    }

    return 0;
}
