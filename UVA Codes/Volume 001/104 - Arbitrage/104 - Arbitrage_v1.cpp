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

int n;
double mat[22][22][22];
int path[22][22][22];

void printpath(int step, int i, int j)
{
    if(step == 1)
    {
        printf("%d ", i);
        return;
    }

    int& k = path[i][j][step];
    printpath(step - 1, i, k);
    printf("%d ", k);
}

int main()
{
#ifdef LOCAL
    freopen("104.inp", "r", stdin);
#endif // LOCAL

    const double profit = 1.01;
    while(scanf("%d", &n) != EOF)
    {
        clr(mat);
        REPE(i, 1, n)
        {
            REPE(j, 1, n)
            {
                if(i == j) mat[i][j][1] = 1.0;
                else scanf("%lf", &mat[i][j][1]);
            }
        }

        bool exist = false;
        REPE(step, 2, n)
        {
            REPE(k, 1, n)
            {
                REPE(i, 1, n)
                {
                    REPE(j, 1, n)
                    {
                        double d = mat[i][k][step - 1] *  mat[k][j][1];
                        if(d > mat[i][j][step])
                        {
                            mat[i][j][step] = d;
                            path[i][j][step] = k;
                        }

                        if(i == j && mat[i][j][step] > profit)
                        {
                            exist = true;
                            printpath(step, i, i);
                            printf("%d\n", i);
                            break;
                        }
                    }
                    if(exist) break;
                }
                if(exist) break;
            }
            if(exist) break;
        }

        if(!exist) puts("no arbitrage sequence exists");
    }

    return 0;
}
