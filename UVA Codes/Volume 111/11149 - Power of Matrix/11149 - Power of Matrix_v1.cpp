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

#define DIM 42

int mod = 1000;

struct Matrix
{
    int row, col;
    int mat[DIM][DIM];

    void clear() { clr(mat); }
    Matrix(int r = 0, int c = 0) { row = r, col = c; clear(); }

    int* operator [] (int n) { return mat[n]; }

    Matrix operator + (const Matrix& b)
    {
        Matrix res(row, b.col);
        REP(i, 0, res.row)
        REP(j, 0, res.col)
        {
            res[i][j] = mat[i][j] + b.mat[i][j];
            res[i][j] %= mod;
        }
        return res;
    }

    Matrix operator * (const Matrix& b)
    {
        Matrix res(row, col);
        REP(i, 0, res.row)
        REP(j, 0, res.col)
        {
            res[i][j] = 0;
            REP(k, 0, col)
            {
                res[i][j] += (mat[i][k] * b.mat[k][j]);
                res[i][j] %= mod;
            }
        }
        return res;
    }
};

Matrix A, I, Z;
Matrix mat[2][2];
Matrix ans[2][2];
Matrix tmp[2][2];

void UNIT()
{
    ans[0][0] = I;
    ans[0][1] = Z;
    ans[1][0] = Z;
    ans[1][1] = I;
}

void COPY(Matrix ma[2][2])
{
    REP(i, 0, 2)
    REP(j, 0, 2)
    ans[i][j] = ma[i][j];
}

void CROSS(Matrix ma[2][2])
{
    REP(i, 0, 2)
    REP(j, 0, 2)
    {
        tmp[i][j] = Z;
        REP(k, 0, 2)
        tmp[i][j] = tmp[i][j] + ans[i][k] * ma[k][j];
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
        CROSS(ans);
        if(n & 1) CROSS(mat);
    }
}

void init(int n)
{
    Z.clear();
    Z.row = n;
    Z.col = n;

    I.clear();
    I.row = n;
    I.col = n;
    REP(i, 0, n) I[i][i] = 1;

    mat[0][0] = A;
    mat[0][1] = I;
    mat[1][0] = Z;
    mat[1][1] = I;
}

Matrix func(int n, int k)
{
    init(n);
    POWER(k);
    return (A * ans[0][1]);
}

int main()
{
#ifdef LOCAL
    freopen("11149.inp", "r", stdin);
#endif // LOCAL

    int n, k;

    while(scanf("%d %d", &n, &k) != EOF && n)
    {
        A.row = n;
        A.col = n;
        REP(i, 0, n)
        REP(j, 0, n)
        {
            scanf("%d", &A[i][j]);
            A[i][j] %= mod;
        }

        Matrix res = func(n, k);
        REP(i, 0, n)
        {
            REP(j, 0, n)
            {
                if(j) putchar(' ');
                printf("%d", (res[i][j] % 10));
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}
