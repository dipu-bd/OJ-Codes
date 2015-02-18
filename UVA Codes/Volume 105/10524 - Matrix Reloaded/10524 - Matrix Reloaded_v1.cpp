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
#define LB lower_bound
#define UB upper_bound
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define dim 100

struct Matrix
{
    int siz;
    double mat[dim][dim];

    void clear() { clr(mat); }
    Matrix(int n) { siz = n; clear(); }
    double* operator [] (int n) { return mat[n]; }

    Matrix transpose()
    {
        Matrix res(siz);
        REP(i, 0, siz)
        REP(j, 0, siz)
        res[j][i] = mat[i][j];
        return res;
    }

    Matrix cofact(int r, int c)
    {
        Matrix res(siz - 1);
        REP(i, 0, r)
        {
            REP(j, 0, c) res[i][j] = mat[i][j];
            REP(j, c + 1, siz) res[i][j - 1] = mat[i][j];
        }
        REP(i, r + 1, siz)
        {
            REP(j, 0, c) res[i - 1][j] = mat[i][j];
            REP(j, c + 1, siz) res[i - 1][j - 1] = mat[i][j];
        }
        return res;
    }

    double det()
    {
        if(siz == 0) return 1;

        double d = 0;
        REP(j, 0, siz)
        {
            int sign = ((j & 1) ? -1 : 1);
            d += (sign * mat[0][j]) * (cofact(0, j).det());
        }

        return d;
    }

    Matrix inverse()
    {
        if(siz <= 1) return Matrix(-1);

        double d = det();
        if(d == 0) return Matrix(-1);

        Matrix res(siz);
        REP(i, 0, siz)
        REP(j, 0, siz)
        {
            res[i][j] = cofact(i, j).det();
            res[i][j] *= ((i + j) & 1) ? -1 : 1;
        }

        res = res.transpose();

        REP(i, 0, siz)
        REP(j, 0, siz)
        res[i][j] /= d;


        return res;
    };

};

int main()
{
#ifdef LOCAL
    freopen("10524.inp", "r", stdin);
#endif // LOCAL

    int n;
    while(scanf("%d", &n) != EOF && n)
    {
        Matrix mat(n);

        REP(i, 0, n)
        REP(j, 0, n)
        scanf("%lf", &mat[i][j]);

        Matrix res = mat.inverse();
        if(res.siz < 0)
        {
            puts("Impossible\n");
            continue;
        }

        REP(i, 0, res.siz)
        {
            REP(j, 0, res.siz)
            {
                if(j) putchar(' ');
                printf("%lf", res[i][j]);
            }
            putchar('\n');
        }
        putchar('\n');
    }

    return 0;
}
