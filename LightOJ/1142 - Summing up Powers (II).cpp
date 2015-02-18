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

#define DIM 35

int mod = 1000;

struct Matrix
{
    int row, col;
    int mat[DIM][DIM];

    void clear() { clr(mat); }
    int* operator [](int i) { return mat[i]; }
    Matrix(int r = 0, int c = 0) { row = r; col = c; clear(); }

    Matrix& operator = (const Matrix& rhs)
    {
        row = rhs.row;
        col = rhs.col;
        REP(i, 0, row)
        REP(j, 0, col)
        mat[i][j] = rhs.mat[i][j];
    }

    Matrix operator * (const Matrix& rhs)
    {
        Matrix res(row, rhs.col);
        REP(i, 0, res.row)
        REP(j, 0, res.col)
        {
            res[i][j] = 0;
            REP(k, 0, col) res[i][j] = (res[i][j] + (mat[i][k] * rhs.mat[k][j])) % mod;
        }
        return res;
    }

    Matrix operator + (const Matrix& rhs)
    {
        Matrix res(row, col);
        REP(i, 0, row)
        REP(j, 0, col)
        {
            res[i][j] = mat[i][j] + rhs.mat[i][j];
            res[i][j] %= mod;
        }
        return res;
    }
};

Matrix unit;
Matrix zero;
Matrix mat[2][2];
Matrix res[2][2];
Matrix tmp[2][2];

void setunit(int n)
{
    unit = Matrix(n, n);
    REP(i, 0, n) unit[i][i] = 1;
}

void COPY(Matrix A[2][2])
{
    REP(i, 0, 2)
    REP(j, 0, 2)
    res[i][j] = A[i][j];
}

void CROSS(Matrix A[2][2])
{
    REP(i, 0, 2)
    REP(j, 0, 2)
    {
        tmp[i][j] = zero;
        REP(k, 0, 2) tmp[i][j] = tmp[i][j] + (res[i][k] * A[k][j]);
    }

    COPY(tmp);
}

void power(int k)
{
    if(k == 1)
    {
        COPY(mat);
    }
    else if(k == 0)
    {
        REP(i, 0, 2)
        REP(j, 0, 2)
        res[i][j] = unit;
    }
    else
    {
        power(k >> 1);
        CROSS(res);
        if(k & 1) CROSS(mat);
    }
}

int main()
{
#ifdef LOCAL
    freopen("1142.inp", "r", stdin);
#endif // LOCAL

    int n, k;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &k);

        Matrix A(n, n);
        REP(i, 0, n)
        REP(j, 0, n)
        scanf("%d", &A[i][j]);

        printf("Case %d:\n", cas++);

        //init mat
        setunit(n);
        zero = Matrix(n, n);
        mat[0][0] = A;
        mat[0][1] = unit;
        mat[1][1] = unit;
        mat[1][0] = zero;

        //find res
        power(k);
        Matrix ans = res[0][1] * A;

        REP(i, 0, n)
        {
            REP(j, 0, n)
            putchar('0' + ans[i][j] % 10);

            putchar('\n');
        }
    }

    return 0;
}
