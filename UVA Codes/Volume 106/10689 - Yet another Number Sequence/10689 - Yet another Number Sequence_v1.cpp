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

#define DIM 5

int mod = 10;

struct Matrix
{
    int row;
    int col;
    int mat[DIM][DIM];

    Matrix(int r, int c)
    {
        row = r;
        col = c;
        clear();
    }
    void clear()
    {
        clr(mat);
    }

    int* operator [](int i)
    {
        return mat[i];
    }

    Matrix operator * (Matrix rhs)
    {
        Matrix res(row, rhs.col);
        REP(i, 0, res.row)
        REP(j, 0, res.col)
        {
            res[i][j] = 0;
            REP(k, 0, col)
            {
                res[i][j] += (mat[i][k] * rhs[k][j]) % mod;
                res[i][j] %= mod;
            }
        }
        return res;
    }
};

Matrix UNIT(int sz)
{
    Matrix res(sz, sz);
    REP(i, 0, sz) res[i][i] = 1;
    return res;
}

Matrix power(Matrix mat, int n)
{
    if(n == 0) return UNIT(mat.col);
    if(n == 1) return mat;
    Matrix res = power(mat * mat, n >> 1);
    if(n & 1) res = mat * res;
    return res;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int a, b, n, m;
    Matrix mat(2, 2);

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d", &a, &b, &n, &m);

        mod = 10;
        REP(i, 1, m) mod *= 10;

        if(n == 0) printf("%d\n", a % mod);
        if(n == 1) printf("%d\n", b % mod);
        if(n <= 1) continue;

        //init mat
        mat.clear();
        mat[0][0] = 1;
        mat[0][1] = 1;
        mat[1][0] = 1;

        //mat expo
        Matrix res = power(mat, n - 1);

        int ans = (b * res[0][0] + a * res[0][1]) % mod;
        printf("%d\n", ans);
    }

    return 0;
}
