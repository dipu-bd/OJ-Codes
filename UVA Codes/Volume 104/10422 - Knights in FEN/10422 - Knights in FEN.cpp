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
#include <bitset>
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

//knight move
int X[] = { -2, -2, -1, -1, 1, 1, 2, 2};
int Y[] = { -1, 1, -2,  2, -2, 2, -1, 1};

vii TO[25];
char inp[8][8];
map<string, int> dis;

void loc(int p, int& x, int& y)
{
    x = p / 5;
    y = p % 5;
}

int indx(int x, int y)
{
    return x * 5 + y;
}

bool valid(int x, int y)
{
    return (x >= 0 && y >= 0 && x < 5 && y < 5);
}

void jump()
{
    int x, y, px, py;
    REP(p, 0, 25)
    {
        loc(p, x, y);
        REP(i, 0, 8)
        {
            px = x + X[i];
            py = y + Y[i];
            if(valid(px, py))
            {
                TO[p].pb(indx(px, py));
            }
        }
    }
}

//start pos 
string start = "111110111100 110000100000"; 
//run dfs
void precalc()
{
    jump();
    
    queue<string> q;
    q.push(start);
    dis[start] = 1;
    
    while(q.size())
    {
        string s = q.front();
        q.pop();
        
        int& d = dis[s];
        if(d == 11) continue;
        
        int i = 0;
        while(s[i] != ' ') ++i;
        
        loop(j, TO[i])
        {
            swap(s[i], s[*j]);
            int& td = dis[s];
            if(td == 0)
            {
                q.push(s);
                td = d + 1;
            }
            swap(s[i], s[*j]);
        }
    }
}

string convert()
{
    string res;
    REP(i, 0, 5)
    REP(j, 0, 5)
    res.pb(inp[i][j]);
    return res;
}

int main()
{
    precalc(); 

    scanf("%d ", &test);
    while(test--)
    {
        REP(i, 0, 5)
        gets(inp[i]);

        string goal = convert();
        int md = dis[goal] - 1;
        
        if(md >= 0) printf("Solvable in %d move(s).\n", md);
        else printf("Unsolvable in less than 11 move(s).\n");
    }

    return 0;
}
