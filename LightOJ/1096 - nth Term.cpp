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
#define MOD 10007

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

    Matrix operator * (const Matrix& b)
    {
        Matrix res(row, b.col);
        REP(i, 0, row)
        REP(j, 0, b.col)
        {
            res[i][j] = 0;
            REP(k, 0, col)
            {
                res[i][j] += (mat[i][k] * b.mat[k][j]) % MOD;
                res[i][j] %= MOD;
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

Matrix power(Matrix M, int p)
{
    if(p == 0) return UNIT(M.col);
    if(p == 1) return M;
    Matrix res = power(M, p >> 1);
    res = res * res;
    if(p & 1) res = res * M;
    return res;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n, a, b, c;
    Matrix M(4, 4);

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d", &n, &a, &b, &c);

        printf("Case %d: ", cas++);

        if(n <= 2)
        {
            printf("0\n");
            continue;
        }

        //set matrix
        M.clear();
        M[0][0] = a;
        M[0][2] = b;
        M[0][3] = 1;
        M[1][0] = 1;
        M[2][1] = 1;
        M[3][3] = 1;

        //multiply
        Matrix res = power(M, n - 2);

        //show res
        int ans = (c * res[0][3]) % MOD;
        printf("%d\n", ans);
    }

    return 0;
}
