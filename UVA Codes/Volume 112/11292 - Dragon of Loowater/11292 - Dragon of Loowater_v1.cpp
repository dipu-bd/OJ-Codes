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

int n, m;
int dragon[20005];
int knight[20005];

ll getcost()
{
    if(m < n) return -1;

    int k = 0;
    ll sum = 0;

    for(int i = 0, k = 0; i < n; ++i)
    {
        if(k >= m) return -1;
        while(k < m && dragon[i] > knight[k]) k++;
        sum += knight[k++];
    }

    return sum;
}

int main()
{
#ifdef LOCAL
    freopen("11292.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%d %d", &n, &m) != EOF  && n && m)
    {
        REP(i, 0, n) scanf("%d", dragon + i);
        REP(i, 0, m) scanf("%d", knight + i);
        sort(dragon, dragon + n);
        sort(knight, knight + m);

        ll res = getcost();
        if(res < 0) puts("Loowater is doomed!");
        else printf("%lld\n", res);
    }

    return 0;
}
