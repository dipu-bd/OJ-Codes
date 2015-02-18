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
int row[25];
int col[25];
int mat[25][25];
int trow[25];
int tcol[25];
bool found;

void showmat()
{
    REP(i, 0, n)
    REP(j, 0, m)
    {
        printf("%d", mat[i][j]);
        if(j == m - 1) putchar('\n');
        else putchar(' ');
    }
}

void backtrack(int x = 0, int y = 0)
{
    if(x == n)
    {
        found = true;
        return;
    }
    if(y == m)
    {
        if(trow[x] == row[x])
        {  
            backtrack(x + 1, 0);
        }
        return;
    }
    
    REPE(s, 1, 20)
    {
        int r = trow[x] + s;
        int c = tcol[y] + s;
        
        if(r > row[x] || c > col[y]) break;
        if(x == n - 1 && col[y] != c) continue;
        if(y == m - 1 && row[x] != r) continue;
        
        trow[x] += s;
        tcol[y] += s;
        mat[x][y] = s;
        
        backtrack(x, y + 1);
        if(found) return;
        
        trow[x] -= s;
        tcol[y] -= s;
        mat[x][y] = 0;
    }
}

int main()
{
    sf1(test);
    while(test--)
    {
        sf2(n, m);
        REP(i, 0, n) sf1(row[i]);
        REP(i, 0, m) sf1(col[i]);
        
        RREP(i, n - 1, 0) row[i] -= row[i - 1];
        RREP(i, m - 1, 0) col[i] -= col[i - 1];
        
        found = false;
        backtrack(0, 0);
        
        printf("Matrix %d\n", cas++);
        showmat();
        if(test) putchar('\n');
    }
    
    return 0;
}