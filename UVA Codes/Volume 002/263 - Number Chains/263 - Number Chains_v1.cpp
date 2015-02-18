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

vii num;
char tmp[15];

int func(int n)
{
    sprintf(tmp, "%d", n);
    int a, b, m, l;
    l = strlen(tmp);
    sort(tmp, tmp + l);

    m = 1;
    a = b = 0;
    REP(i, 0, l)
    {
        a = a * 10 + tmp[i] - '0';
        b = (tmp[i] - '0') * m + b;
        m *= 10;
    }

    m = b - a;
    printf("%d - %d = %d\n", b, a, m);

    return m;
}

int main()
{
#ifdef LOCAL
    freopen("263.inp", "r", stdin);
#endif // LOCAL

    int n;
    while(scanf("%d", &n) != EOF)
    {
        if(n == 0) break;

        num.push_back(n);
        printf("Original number was %d\n", n);

        while(1)
        {
            int m = func(n);
            vii::IT i = LB(num, m);
            if(i != num.end() && *i == m) break;
            num.insert(i, m);
            n = m;
        }

        printf("Chain length %d\n\n", num.size());
        num.clear();
    }

    return 0;
}
