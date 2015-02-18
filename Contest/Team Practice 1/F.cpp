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
/*------------------------------------------------------------------------------------------------*/

int test, cas = 1;

vii tmp;

int recur(int i)
{
    int x = tmp[i];
    while(i > 0 && tmp[i - 1] == x) --i;

    int cnt = 0;
    while(tmp[i] == x && i < tmp.size())
    {
        tmp.erase(tmp.begin() + i);
        ++cnt;
    }

    if(cnt < 3) return 0;
    return cnt + recur(i);
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n, k, x, p;
    scanf("%d %d %d", &n, &k, &x);

    vii lst;
    REP(i, 0, n)
    {
        scanf("%d", &p);
        lst.pb(p);
    }

    int mr = 0;
    REP(i, 1, n)
    {
        if(lst[i] == x && lst[i - 1] == x)
        {
            tmp = lst;
            tmp.insert(tmp.begin() + i, x);
            int r = recur(i) - 1;
            if(r > mr) mr = r;
        }
    }

    printf("%d\n", mr);

    return 0;
}
