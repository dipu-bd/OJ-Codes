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

int n, m;
char choice[50][2][6];
int graph[100][100];
int par[100];
bool vis[100];
int source, sink;

int indx(char* siz)
{
    //XS
    if(siz[1] == 'S')
        return 1;
    //S
    if(siz[0] == 'S') 
        return 2;
    //M
    if(siz[0] == 'M')
        return 3;
    //L
    if(siz[0] == 'L')
        return 4;
    //XL
    if(siz[1] == 'L')
        return 5;
    //XXL
    return 6;
}

void buildgraph()
{
    clr(graph);
    source = 0;
    sink = m + 7;
    
    //source to m people
    REPE(i, 1, m)
    graph[source][i] = 1;
    
    //people to shirt
    REPE(i, 1, m)
    {
        int a = indx(choice[i][0]) + m;
        int b = indx(choice[i][1]) + m;
        graph[i][a] = 1;
        graph[i][b] = 1;
    }
    
    //shirt to sink
    REPE(i, m + 1, m + 6)
    {
        graph[i][sink] = n / 6;
    }
    
}

bool BFS()
{
    clr(vis);
    
    queue<int> q;
    q.push(source);
    par[source] = -1;
    vis[source] = 1;
    
    while(q.size())
    {
        int v = q.front();
        q.pop();
        
        REPE(i, 0, sink)
        {
            if(graph[v][i] > 0 && !vis[i])
            {
                q.push(i);
                vis[i] = 1;
                par[i] = v;
            }
        }
    }
    
    return vis[sink];
}

int MaxFlow()
{
    int u, v, d;
    int flow = 0;
    while(BFS())
    {
        //get maximum flow
        v = sink;
        u = par[v];
        d = INT_MAX;
        while(u != -1)
        {
            if(graph[u][v] < d) 
                d = graph[u][v];
            v = u;
            u = par[v];
        }
        
        //set augmented path
        v = sink;
        u = par[v];
        while(u != -1)
        {
            graph[u][v] -= d;
            graph[v][u] += d;
            v = u;
            u = par[v];
        }
        
        //add to total flow
        flow += d; 
    }
    
    return flow;
}

int main()
{
    sf1(test);
    while(test--)
    {
        sf2(n, m);
        REPE(i, 1, m)
        {
            scanf(" %s %s", choice[i][0], choice[i][1]);
        }
        
        buildgraph();
        int flow = MaxFlow();
        
        if(flow >= m) puts("YES");
        else puts("NO");
    }

    return 0;
}