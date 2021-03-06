/*============================
/\u7h0r : 5ud!p70 ch@ndr@ d@5
=============================*/
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
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
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
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct point
{ 
    double x;
    double y;
    double operator - (const point& r) const
    {
        double dx = x - r.x;
        double dy = y - r.y;
        return sqrt(dx*dx + dy*dy);
    }
};

#define SIZ 210
int source, sink;
int n, m, s, v;
point gopher[SIZ];
point hole[SIZ];
int graph[SIZ][SIZ];
int par[SIZ];
bool vis[SIZ];

void buildgraph()
{
    //clr values
    clr(graph);
    source = 0;
    sink = n + m + 1;
    
    //connect source to gophers
    REPE(i, 1, n)
    graph[source][i] = 1;
    
    //connect gophers to holes
    double md = (double)v * s;
    REPE(i, 1, n)
    {
        REPE(j, 1, m)
        {
            double d = gopher[i] - hole[j];
            if(d <= md) graph[i][n + j] = 1;
        }
    }
    
    //connect holes to sink
    REPE(i, 1, m)
    graph[n + i][sink] = 1;
}

bool BFS()
{
    clr(vis);
    queue<int> q;
    q.push(source);
    vis[source] = 1;
    par[source] = -1;
    while(q.size())
    {
        int i = q.front();
        q.pop();
        
        if(i == sink) return true;
        
        REPE(j, source, sink)
        {
            if(graph[i][j] > 0 && !vis[j])
            {
                q.push(j);
                vis[j] = 1;
                par[j] = i;
            }
        }
    }
    return false;
}

int maxflow()
{
    int res = 0;
    while(BFS())
    {
        ++res;
        int v = sink;
        int u = par[v];
        while(u != -1)
        {
            graph[u][v] -= 1;
            graph[v][u] += 1;
            v = u;
            u = par[v];
        }
    }
    return res;
}

int main()
{
    while(cin >> n >> m >> s >> v)
    {
        REPE(i, 1, n)
        {
            scanf("%lf %lf", &gopher[i].x, &gopher[i].y);
        }
        
        REPE(i, 1, m)
        {
            scanf("%lf %lf", &hole[i].x, &hole[i].y);
        }
        
        buildgraph();
        int mf = maxflow();
        
        int res = n - mf;
        printf("%d\n", res);
    }
    
    return 0;
}