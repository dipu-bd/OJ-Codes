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

#define SIZ 105
int n;
int par[SIZ];
bool vis[SIZ];
int graph[SIZ][SIZ];

bool bfs(int s, int t)
{
    clr(vis);
    
    queue<int> q;
    q.push(s); 
    vis[s] = true;
    
    while(q.size())
    {
        int v = q.front();
        q.pop();
        
        if(v == t) 
            return true;
        
        REPE(i, 1, n)
        {
            if(graph[v][i] && !vis[i])
            {
                q.push(i);
                par[i] = v;
                vis[i] = 1;
            }
        }
    }
    
    return false;
}

int maxflow(int s, int t)
{ 
    int u, v;
    int total = 0;
    
    while(bfs(s, t))
    {
        int cf = INT_MAX;
        for(v = t; v != s; v = par[v])
        {
            u = par[v];
            cf = min(cf, graph[u][v]);
        }
        
        for(v = t; v != s; v = par[v])
        {
            u = par[v];
            graph[u][v] -= cf;
            //graph[v][u] += cf;
        }
        
        total += cf;
    }
    
    return total;
}

int main()
{
    int s, t, m;
    int u, v, c;
    
    while(sf1(n) == 1 && n)
    {
        clr(graph);
        
        sf3(s, t, m);
        while(m--)
        {
            sf3(u, v, c);
            graph[u][v] += c;
            graph[v][u] += c;
        } 
        
        int res = maxflow(s, t);
        
        printf("Network %d\n", cas++);
        printf("The bandwidth is %d.\n\n", res);
    }

    return 0;
}