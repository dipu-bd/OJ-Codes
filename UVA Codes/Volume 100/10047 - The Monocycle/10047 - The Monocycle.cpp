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
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<int> vii;
typedef vector<pii> vpii;
typedef map<int, int> mpii;
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
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
#define TEMPLATE template<typename T>
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int X[] = {-1, 0, 1, 0}; // +1 : to right
int Y[] = { 0, 1, 0, -1}; // -1 : to left  

int m, n;
char mat[30][30];
int dis[26][26][4][5];

bool isvalid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < m && y < n && mat[x][y] != '#');
}

int BFS(pii S, pii T)
{
    clr(dis);
    queue<int> q;
    q.push(S.fr);
    q.push(S.sc);
    q.push(0); //dir
    q.push(0); //col
    dis[S.fr][S.sc][0][0] = 1;
    while(q.size())
    {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        int d = q.front(); q.pop();
        int c = q.front(); q.pop();
        
        int l = dis[x][y][d][c];
        if(c == 0 && x == T.fr && y == T.sc)
            return (l - 1); 
        
        //turn left
        int nd = pmod(d - 1, 4);
        if(dis[x][y][nd][c] == 0)
        {
            q.push(x);
            q.push(y);
            q.push(nd);
            q.push(c);
            dis[x][y][nd][c] = l + 1;
        }
        
        //turn right
        nd = pmod(d + 1, 4);
        if(dis[x][y][nd][c] == 0)
        {
            q.push(x);
            q.push(y);
            q.push(nd);
            q.push(c);
            dis[x][y][nd][c] = l + 1;
        }
        
        //move one 
        int i = x + X[d];
        int j = y + Y[d];
        c = (c + 1) % 5;
        if(isvalid(i, j) && dis[i][j][d][c] == 0)
        {
            q.push(i);
            q.push(j);
            q.push(d);
            q.push(c);
            dis[i][j][d][c] = l + 1;
        }
    }
    
    return -1;
}

int main()
{
    pii S, T;
    while(sf2(m, n) == 2 && (m | n))
    { 
        REP(i, 0, m)
        {
            scanf(" %s", mat[i]);
            REP(j, 0, n)
            {
                if(mat[i][j] == 'S')
                    S = mp(i, j);
                else if(mat[i][j] == 'T')
                    T = mp(i, j);
            }
        }
        
        if(cas > 1) putchar('\n');
        printf("Case #%d\n", cas++);
         
        int res = BFS(S, T);
        if(res == -1)
        {
            puts("destination not reachable");
        }
        else
        {
            printf("minimum time = %d sec\n", res);
        }
    }
    
    return 0;
}