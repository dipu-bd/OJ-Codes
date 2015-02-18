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

#define DIM 55

typedef unsigned int uint;

struct Matrix
{
    int row;
    int col;
    uint mat[DIM][DIM];

    void clear() { clr(mat); }
    Matrix(int r = 0, int c = 0) { row = r; col = c; clear(); }
    uint* operator [] (int n) { return mat[n]; }

    Matrix operator * (const Matrix& b) const
    {
        Matrix res(row, b.col);
        REP(i, 0, row)
        REP(j, 0, b.col)
        REP(k, 0, col)
        res[i][j] += mat[i][k] * b.mat[k][j];
        return res;
    }
};

Matrix unit(int sz)
{
    Matrix res(sz, sz);
    REP(i, 0, sz) res[i][i] = 1;
    return res;
}

Matrix power(const Matrix& A, ll n)
{
    if(n == 0) return unit(A.col);
    if(n == 1) return A;
    Matrix res = power(A * A, n >> 1);
    if(n & 1) res = res * A;
    return res;
}

void init(Matrix& mat, int k)
{
    mat.clear();
    mat.row = k + 1;
    mat.col = k + 1;

    REP(i, 0, k)
    {
        mat[i][0] = 1;
        REPE(j, 1, i)
        mat[i][j] = mat[i - 1][j - 1] + mat[i - 1][j];
    }

    REP(i, 0, k) mat[k][i] = mat[k - 1][i];
    mat[k][k] = 1;
}

int main()
{
#ifdef LOCAL
    freopen("1132.in", "r", stdin);
    freopen("1132.out", "w", stdout);
#endif // LOCAL

    ll n;
    int k;
    Matrix mat, res;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%lld %d", &n, &k);

        init(mat, k + 1);
        res = power(mat, n - 1);

        uint ans = 0;
        REP(i, 0, res.col) ans += res[k + 1][i];
        printf("Case %d: %u\n", cas++, ans);
    }

    return 0;
}
