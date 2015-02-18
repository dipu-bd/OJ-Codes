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

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n, x, sum;
    char pre[20], num[20], den[20];
    while(scanf("%d", &n) != EOF && n)
    {
        sum = 0;
        REP(i, 0, n)
        {
            scanf("%d", &x);
            sum += x;
        }

        printf("Case %d:\n", cas++);

        bool neg = 0;
        if(sum < 0) neg = 1, sum = -sum;

        if(sum == 0) { printf("0\n"); continue; }

        int g = gcd(sum, n);
        sum /= g, n /= g;

        //avg is integer
        if(n == 1)
        {
            if(neg) printf("- ");
            printf("%d\n", sum);
            continue;
        }

        //fraction
        x = sum / n;
        sum %= n;
        clr(pre);

        sprintf(num, "%d", sum);
        sprintf(den, "%d", n);

        //fraction is negative
        int len = 0;
        if(neg) pre[0] = '-', pre[1] = ' ', len = 2;

        //it has pre value
        if(x) sprintf(pre + len, "%d", x);
        len = strlen(pre);

        int l1 = strlen(num);
        int l2 = strlen(den);

        REP(i, 0, len) putchar(' ');
        REP(i, 0, l2 - l1) putchar(' ');
        printf("%s\n", num);

        printf("%s", pre);
        REP(i, 0, l2) putchar('-');
        putchar('\n');

        REP(i, 0, len) putchar(' ');
        printf("%s\n", den);
    }


    return 0;
}
