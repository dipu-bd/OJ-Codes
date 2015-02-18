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

bool isall(int p, int m)
{
    return p == (1 << m) - 1;
}
bool isall(int* vis, int n, int m)
{
    int f = (1 << m) - 1;
    REP(i, 0, n) if(vis[i] != f) return false;
    return true;
}

bool enabled(int p, int m)
{
    return !(p & (1 << m));
}
void disable(int& p, int m)
{
    p |= (1 << m);
}

int main()
{
    int test, cas = 1;
    int n, m, x, time;
    int vis[30], pos;
    int wheel[30];
    mem(wheel, -1);

    scanf("%d", &test);
    while(test--)
    {
        list<int> wait;

        scanf("%d %d", &n, &m);

        pos = 0;
        time = 0;
        clr(vis);
        REP(i, 0, n) wait.push_back(i);
        do
        {
            int& w = wheel[pos];
            if(w != -1 && !isall(vis[w], m))
            {
                wait.push_back(w);
                disable(vis[w], pos);
                w = -1;
            }

            loop(d, wait)
            {
                if(enabled(vis[*d], pos))
                {
                    w = *d;
                    wait.erase(d);
                    break;
                }
            }

            //printf("Pos = %d | Ferri = ", pos);
            //REP(i, 0, m) printf("%d ", wheel[i]);
            //printf(" | wait = ");
            //loop(d, wait) printf("%d ", *d);
            //puts("");

            time += 5;
            pos = (pos + 1) % m;
        }
        while(!isall(vis, n, m));

        printf("Case %d: %d\n", cas++, time);
    }

    return 0;
}

