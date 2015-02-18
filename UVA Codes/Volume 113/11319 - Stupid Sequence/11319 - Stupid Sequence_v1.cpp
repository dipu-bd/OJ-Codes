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

typedef unsigned long long ull;

int A[10];
double matrix[10][10];

void makematrix()
{
    REPE(row, 1, 7)
    {
        ll x = 1;
        REPE(col, 1, 7)
        {
            matrix[row][col] = x;
            x *= row;
        }
    }
}

bool reduce()
{
    REPE(p, 1, 7)
    {
        //make pivot 1
        double pivot = matrix[p][p];
        if(pivot != 1)
        {
            REPE(c, 1, 8) matrix[p][c] = matrix[p][c] / pivot;
        }

        //make rest of the cols 0
        REPE(r, 1, 7)
        {
            if(r != p)
            {
                double col = matrix[r][p];
                REPE(c, 1, 8) matrix[r][c] = matrix[r][c] - matrix[p][c] * col;
            }
        }
    }

    //set A vals
    REPE(p, 0, 6)
    {
        A[p] = (int)matrix[p + 1][8];
        if(A[p] < 0 || A[p] > 1000) return false;
        if(A[p] != matrix[p + 1][8]) return false;
    }

    return true;
}

bool check(int n, ull& F)
{
    ull res = 0;
    RREPE(p, 6, 0) res = (res * n) + A[p];
    return (res == F);
}

void showres()
{
    printf("%d", A[0]);
    REPE(i, 1, 6) printf(" %d", A[i]);
    putchar('\n');
}

int main()
{
#ifdef LOCAL
    freopen("11319.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        makematrix();

        ull F;
        REPE(n, 1, 7)
        {
            scanf("%llu", &F);
            matrix[n][8] = F;
        }

        bool valid = reduce();

        REPE(n, 8, 1500)
        {
            scanf("%llu", &F);
            if(valid) valid = check(n, F);
        }

        if(valid) showres();
        else puts("This is a smart sequence!");
    }

    return 0;
}
