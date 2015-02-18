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

char inp[10100];
char text[10100];
char square[110][110];

int magic()
{
    int len = 0;
    for(int i = 0; inp[i]; ++i)
        if(isalpha(inp[i])) text[len++] = inp[i];

    int m = sqrt(len);
    if(m * m != len) return -1;

    REP(i, 0, m)
    REP(j, 0, m)
    square[i][j] = text[i * m + j];

    for(int i = 0, j = m - 1; i <= j; ++i, --j)
    {
        for(int k = 0; k < m; ++k)
        {
            if(square[i][k] != square[j][m - k - 1]) return -1;
            if(square[k][i] != square[m - k - 1][j]) return -1;
        }
    }

    return m;
}

int main()
{
#ifdef LOCAL
    freopen("11221.inp", "r", stdin);
#endif // LOCAL

    scanf("%d ", &test);
    while(test--)
    {
        gets(inp);
        printf("Case #%d:\n", cas++);
        int m = magic();
        if(m == -1) printf("No magic :(\n");
        else printf("%d\n", m);
    }

    return 0;
}
