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
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

#define SIZ 1003

int W, H;
char graph[SIZ][SIZ + 10];
int vis[SIZ][SIZ];
int par[SIZ][SIZ];
queue<int> q;
vii mov;

//right = +1; left = -1; E S W N
int X[] = { 0, 1,  0, -1 };
int Y[] = { 1, 0, -1,  0 };

inline bool valid(int x, int y)
{
    return (x > 0 && y > 0 && x <= H && y <= W &&
            graph[x][y] == '*' && vis[x][y] != cas);
}

void BFS(int x, int y)
{
    while(q.size()) q.pop();

    q.push(x);
    q.push(y);
    vis[x][y] = cas;
    par[x][y] = -1;
    while(q.size())
    {
        x = q.front();
        q.pop();
        y = q.front();
        q.pop();

        REP(i, 0, 4)
        {
            int tx = x + X[i];
            int ty = y + Y[i];
            if(valid(tx, ty))
            {
                q.push(tx);
                q.push(ty);
                vis[tx][ty] = cas;
                par[tx][ty] = (i + 2) & 3;
            }
        }
    }
}

void pathfind(int x, int y)
{
    mov.clear();
    int p = par[x][y];
    while(p != -1)
    {
        x += X[p];
        y += Y[p];
        mov.pb((p + 2) & 3);
        p = par[x][y];
    }
}

inline void printfirst(int dir)
{
    if(dir == 0)
        printf("Turn to the east.\n");
    else if(dir == 1)
        printf("Turn to the south.\n");
    else if(dir == 2)
        printf("Turn to the west.\n");
    else
        printf("Turn to the north.\n");
}

int main()
{
    bool first;
    int km, dir;
    int sx, sy, dx,  dy;

    sf1(test);
    while(test--)
    {
        scanf("%d %d ", &W, &H);

        REP(i, 0, H + 2) gets(graph[i]);

        { sf2(sy, sx); ++sx; ++sy; }
        { sf2(dy, dx); ++dx; ++dy; }

        ++cas;
        BFS(sx, sy);

        if(vis[dx][dy] != cas)
        {
            printf("No route found.\n\n");
            continue;
        }

        pathfind(dx, dy);

        km = 0;
        first = true;
        rloop(i, mov)
        {
            if(first) //set direction
            {
                printfirst(*i);
                first = false;
                km = 1;
                dir = *i;
                continue;
            }

            if(dir == *i) //forward
            {
                ++km;
                dir = *i;
                continue;
            }

            if(((dir + 1) & 3) == *i) //right
            {
                printf("Continue %d km.\n", km);
                printf("Turn right.\n");
            }
            else if(((*i + 1) & 3) == dir) //left
            {
                printf("Continue %d km.\n", km);
                printf("Turn left.\n");
            }

            km = 1;
            dir = *i;
        }

        printf("Continue %d km.\n", km);
        printf("You have reached your destination.\n\n");
    }

    return 0;
}
