/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#include <assert.h>
//#include <time.h>
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
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
#define debug1(a) cout << a << endl
#define debug2(a,b) cout << a << " " << b << endl
#define debug3(a,b,c) cout << a << " " << b << " " << c << endl
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, int p) { return (p == 0) ? (T)(1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? (T)(1) : ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m; }
template<typename T> T GCD(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int n, m;

pii employ[210];
pii job[210];
int graph[500][500];

bool connected(pii& a, pii& b)
{
    return (a.fr <= b.fr && b.fr <= a.sc &&
            a.fr <= b.sc && b.sc <= a.sc);
}

void makegraph()
{
    clr(graph);
    REPE(i, 1, n)
    {
        REPE(j, 1, m)
        {
            int q = n + j;
            if(connected(employ[i], job[j]))
                graph[i][q] = graph[q][i] = 1;
        }
    }
}

int match[500];
bool vis[500];
bool dfs(int u)
{
    for(int i = 1; i <= n + m; i++)
    {
        if(graph[u][i] && vis[i] == 0)
        {
            vis[i] = 1;

            if(match[i] < 0 || dfs(match[i]))
            {
                match[i] = u;
                return true;
            }

        }
    }
    return false;
}

int main()
{
    int hh, mm;

    sf1(test);
    while(test--)
    {
        sf2(n, m);
        REPE(i, 1, n)
        {
            scanf("%d:%d", &hh, &mm);
            employ[i].fr = hh * 60 + mm;
            scanf("%d:%d", &hh, &mm);
            employ[i].sc = hh * 60 + mm;
        }
        REPE(i, 1, m)
        {
            scanf("%d:%d", &hh, &mm);
            job[i].fr = hh * 60 + mm;
            scanf("%d:%d", &hh, &mm);
            job[i].sc = hh * 60 + mm;
        }

        makegraph();

        int anss = 0;
        mem(match, -1);
        REPE(i, 1, n)
        {
            clr(vis);
            if(dfs(i)) anss++;
        }

        pf("%d\n", anss);

    }

    return 0;
}
