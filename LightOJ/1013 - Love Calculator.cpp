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
#define loop(it, cont) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, cont) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)


typedef pair<int, ll> pill;

char str1[32];
char str2[32];
int len1, len2, len;

pill save[32][32][64];

pill call(int i, int j, int p)
{
    if(i == len1 && j == len2)
        return mp(p, 1LL);

    pill& dp = save[i][j][p];
    if(dp.first != -1) return dp;

    if(i == len1)
    {
        dp = call(i, j + 1, p + 1);
    }
    else if(j == len2)
    {
        dp = call(i + 1, j, p + 1);
    }
    else if(str1[i] == str2[j])
    {
        dp = call(i + 1, j + 1, p + 1);
    }
    else
    {
        pill a = call(i, j + 1, p + 1);
        pill b = call(i + 1, j, p + 1) ;
        dp = (a.first <= b.first) ? a : b;
        if(a.first == b.first)
            dp.second = a.second + b.second;
    }

    return dp;
}

int main()
{
#ifdef LOCAL
    freopen("1013.in", "r", stdin);
    //freopen("1013.out", "w", stdout);
#endif

    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s %s", str1, str2);
        mem(save, -1);
        len1 = strlen(str1);
        len2 = strlen(str2);
        len = len1 + len2;
        pill r = call(0, 0, 0);
        printf("Case %d: %d %lld\n", cas++, r.first, r.second);
    }

    return 0;
}

