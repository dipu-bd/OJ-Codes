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

#define MAX 500

const int n = 6;
const int chinf = 0x7f;
const int inf = 0x7f7f7f7f;
int coin[n] = {1, 2, 4, 10, 20, 40}; //divided by 5

int avail[n];
int use[MAX + 10];
int vis[MAX + 10];
int normal[MAX + 10];

int main()
{
#ifdef LOCAL
    freopen("166.inp", "r", stdin);
#endif // LOCAL

    //change needed for unlimited coins -> for seller
    mem(normal, chinf);
    normal[0] = 0;
    REP(i, 0, n)
    REP(j, coin[i], MAX)
    normal[j] = min(normal[j], normal[j - coin[i]] + 1);

    //main program
    while(!feof(stdin))
    {
        //get available coins
        bool exit = true;
        REP(i, 0, n)
        {
            scanf("%d", avail + i);
            if(avail[i]) exit = false;
        }
        if(exit) break;

        //get amount to make
        int a, b, m;
        scanf("%d.%d", &a, &b);
        m = (a * 100 + b) / 5;

        //make upto max
        mem(use, chinf);
        use[0] = 0;
        REP(i, 0, n)
        {
            clr(vis);
            REP(j, coin[i], MAX)
            {
                int p = j - coin[i];
                if(vis[p] < avail[i])
                {
                    vis[j] = vis[p] + 1;
                    use[j] = min(use[j], use[p] + 1);
                }
            }
        }

        //get minimum change
        int res = inf;
        REP(i, m, MAX)
        {
            if(use[i] != inf)
            {
                //printf("%d:%d:%d ", i, use[i], normal[i - m]);
                res = min(res, use[i] + normal[i - m]);
            }
        }

        //show result
        printf("%3d\n", res);
    }

    return 0;
}
