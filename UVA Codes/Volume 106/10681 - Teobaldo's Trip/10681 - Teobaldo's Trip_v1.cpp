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

int C, L;
int mat[105][105];
int res[105][105];
int tmp[105][105];

void UNIT()
{
    clr(res);
    REP(i, 0, C)
    res[i][i] = 1;
}

void COPY(int m[105][105])
{
    REP(i, 0, C)
    REP(j, 0, C)
    res[i][j] = m[i][j];
}

void CROSS(int m[105][105])
{
    REP(i, 0, C)
    REP(j, 0, C)
    {
        tmp[i][j] = 0;
        REP(k, 0, C)
        tmp[i][j] += res[i][k] * m[k][j];
        tmp[i][j] %= 1000;
    }
    COPY(tmp);
}

void POWER(int n)
{
    if(n == 0) UNIT();
    else if(n == 1) COPY(mat);
    else
    {
        POWER(n >> 1);
        CROSS(res);
        if(n & 1) CROSS(mat);
    }
}

int main()
{
#ifdef LOCAL
    freopen("10681.inp", "r", stdin);
#endif // LOCAL

    int a, b;
    int s, e, d;

    while(scanf("%d %d", &C, &L) != EOF)
    {
        if(C == 0) break;

        clr(mat);
        while(L--)
        {
            scanf("%d %d", &a, &b);
            --a;
            --b;
            mat[a][b] = 1;
            mat[b][a] = 1;
        }

        scanf("%d %d %d", &s, &e, &d);
        POWER(d);

        if(res[s - 1][e - 1])
            puts("Yes, Teobaldo can travel.");
        else
            puts("No, Teobaldo can not travel.");
    }

    return 0;
}
