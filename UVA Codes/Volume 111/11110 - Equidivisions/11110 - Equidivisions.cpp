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

int n, total, p;
char grid[104][104];
bool vis[104][104];
char inp[1000];

void dfs(int x, int y)
{
    if(x < 0 || y < 0 || x >= n || y >= n) return;
    if(grid[x][y] != p || vis[x][y]) return;
    
    ++total;
    vis[x][y] = 1;
    dfs(x, y + 1);
    dfs(x, y - 1);
    dfs(x + 1, y);
    dfs(x - 1, y);
}

int main()
{
    int x, y;
    
    while(sf1(n) == 1 && n)
    {
        clr(grid);
        
        REP(i, 1, n)
        {
            scanf(" %[^\n]", inp);
            while(sscanf(inp, "%d %d %[^\n]", &x, &y, inp) == 3)
            {
                grid[x - 1][y - 1] = i;
            }
            sscanf(inp, "%d %d", &x, &y);
            grid[x - 1][y - 1] = i;
        }
        
        clr(vis);
        bool ok = true;
        
        REP(i, 0, n)
        {
            REP(j, 0, n)
            if(!vis[i][j])
            {
                total = 0;
                p = grid[i][j];
                dfs(i, j); 
                
                if(total != n)
                {
                    ok = false;
                    break;
                }
            }
            
            if(!ok) break;
        }
        
        if(ok) puts("good");
        else puts("wrong");
    } 
    
    return 0;
}