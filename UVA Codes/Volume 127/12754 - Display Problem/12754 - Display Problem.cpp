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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
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
/*--------------------------------------------------------------------------------------------------*/

int row, col;
char grid[40][40];

bool isok(int d)
{
    if(d < 0) return 0;
    if(row != 2 * d + 3 || col != d + 2) return 0;

    if(grid[0][0] != '.' || grid[0][d + 1] != '.') return 0;
    if(grid[d + 1][0] != '.' || grid[d + 1][d + 1] != '.') return 0;
    if(grid[2 * d + 2][0] != '.' || grid[2 * d + 2][d + 1] != '.') return 0;
    REPE(i, 1, d) if(grid[0][i] != '-' || grid[d + 1][i] != '-' || grid[2 * d + 2][i] != '-') return 0;

    REPE(i, 1, d)
    {
        if(grid[i][0] != '|' || grid[i][d + 1] != '|') return 0;
        REPE(j, 1, d) if(grid[i][j] != '.') return 0;
    }
    REPE(i, d + 2, 2 * d + 1)
    {
        if(grid[i][0] != '|' || grid[i][d + 1] != '|') return 0;
        REPE(j, 1, d) if(grid[i][j] != '.') return 0;
    }

    return 1;
}

int main()
{
#ifdef LOCAL
    freopen("D.txt", "r", stdin);
#endif // LOCAL

    int test, cas = 1;

    scanf("%d ", &test);
    while(test--)
    {
        col = -1;
        for(row = 0; gets(grid[row]); ++row)
            if(grid[row][0] == '*') break;

        printf("Case %d: ", cas++);

        col = strlen(grid[0]);
        if(isok(col - 2))
        {
            printf("%d\n", col - 2);
            continue;
        }

        printf("Bad\n");
    }

    return 0;
}


