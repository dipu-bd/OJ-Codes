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

#define SIZ 110

vii graph[SIZ];
int dist1[SIZ];
int dist2[SIZ];
bool vis[SIZ];

void BFS(int s, int* dist)
{
    clr(vis);
    
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dist[s] = 0;
    
    while(q.size())
    {
        s = q.front();
        q.pop();
        
        int d = dist[s] + 1;
        
        loop(i, graph[s])
        {
            if(!vis[*i])
            {
                q.push(*i);
                vis[*i] = 1;
                dist[*i] = d;
            }
        }
    }
  
}

int main()
{
    int s, d;
    int n, m;
    
    sf1(test);
    while(test--)
    {
        sf2(n, m);
        while(m--)
        {
            sf2(s, d);
            graph[s].pb(d);
            graph[d].pb(s);
        }
        
        sf2(s, d);
        BFS(s, dist1);
        BFS(d, dist2);
        
        int res = 0;
        REP(i, 0, n)
        {
            res = max(res, dist1[i] + dist2[i]); 
        }
        
        printf("Case %d: %d\n", cas++, res);
        
        REP(i, 0, n)
        graph[i].clear();
    }

    return 0;
}