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
    freopen("12136.inp", "r", stdin);
#endif // LOCAL

    int mod = 24 * 60;

    int hh, mm;
    int meet[2], wife[2];
    bool flag[mod + 10];

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d:%d", &hh, &mm);
        meet[0] = (hh * 60 + mm) % mod;
        scanf("%d:%d", &hh, &mm);
        meet[1] = (hh * 60 + mm) % mod;

        scanf("%d:%d", &hh, &mm);
        wife[0] = (hh * 60 + mm) % mod;
        scanf("%d:%d", &hh, &mm);
        wife[1] = (hh * 60 + mm) % mod;

        clr(flag);
        for(int i = meet[0]; i != meet[1]; i = (i + 1) % mod) flag[i] = 1;
        flag[meet[1]] = 1;

        bool match = true;
        for(int i = wife[0]; i != wife[1]; i = (i + 1) % mod)
            if(flag[i]) { match = false; break;}
        if(flag[wife[1]]) { match = false;}

        printf("Case %d: ", cas++);
        if(match) puts("Hits Meeting");
        else puts("Mrs Meeting");
    }

    return 0;
}
