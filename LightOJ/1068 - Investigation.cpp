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
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)

int k, len, d;
char num1[15], num2[15];
int save[10][85][85][2][2];

int recur(int pos = 0, int dgsum = 0, int mod = 0, bool imax = 1, bool imin = 1)
{
    if(pos == len) return (int)(dgsum == 0 && mod == 0);

    int& dp = save[pos][dgsum][mod][imax][imin];
    if(dp != -1) return dp;

    dp = 0;
    int b = (imin && pos >= d) ? num1[pos - d] - '0' : 0;
    int e = imax ? num2[pos] - '0' : 9;
    REPE(i, b, e)
    {
        dp += recur(pos + 1, (dgsum + i) % k, (mod * 10 + i) % k, imax && i == e, imin && i == b);
    }

    return dp;
}

int main()
{
    cin.sync();
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s %s %d", num1, num2, &k);

        int r = 0;
        mem(save, -1);
        len = strlen(num2);
        d = len - strlen(num1);
        if(k < 85) r = recur();
        printf("Case %d: %d\n", cas++, r);
    }

    return 0;
}

