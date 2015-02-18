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
const int CHAR_INF = 0x7F;
const int INT_INF = 0x7F7F7F7F;
const long long LONG_INF = 0X7F7F7F7F7F7F7F7F;
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

char player;
char board[10][10];
int row[10];
int col[10];
int diag[10][10];

bool adjacent(int ii, int ij, int fi, int fj)
{
    if(ii == fi && ij == fj) return false;
    if(ii == fi || ij == fj) return true;
    return (abs(ii - fi) == abs(ij - fj));
}

void countup()
{
    //count row
    REP(i, 0, 8)
    {
        row[i] = 0;
        REP(j, 0, 8)
        if(board[i][j] == player) ++row[i];
    }
    
    //count col
    REP(j, 0, 8)
    {
        col[j] = 0;
        REP(i, 0, 8)
        if(board[i][j] == player) ++col[j];
    }
    
    //count diag
    REP(i, 0, 8)
    REP(j, 0, 8)
    {
        diag[i][j] = 0;
        REP(x, 0, 8)
        REP(y, 0, 8)
        {
            if(x == i && y == j) continue;
            if(abs(i - x) != abs(j - y)) continue;
            if(board[x][y] == player) ++diag[i][j];
        }
    }
}

void movetoward(int fi, int fj, int& i, int& j)
{
    if(fi < i) --i;
    if(fi > i) ++i;
    
    if(fj < j) --j;
    if(fj > j) ++j;
}

bool canmove(int ii, int ij, int fi, int fj)
{   
    int space = max(abs(ii - fi), abs(ij - fj));
    if(!(space == row[fi] + col[fj] || 
         space == diag[fi][fj])) 
       return false;
    
    if(board[fi][fj] != '.' && 
          board[fi][fj] == player)
       return false;
     
    movetoward(fi, fj, ii, ij);
    while(!(ii == fi && ij == fj))
    {
        if(board[ii][ij] != '.' && board[ii][ij] != player) return false;
        movetoward(fi, fj, ii, ij); 
    }
    
    return true;
}

int main()
{
    while(!feof(stdin))
    {
        REP(i, 0, 8)
        scanf(" %s", board[i]);
        
        scanf(" %c ", &player);
        
        bool pos = false;
        if(cas == 1) cas = 2;
        else putchar('\n');
        
        countup();
        
        REP(i, 0, 8)
        REP(j, 0, 8)
        if(board[i][j] == player)
        {
            REP(x, 0, 8)
            REP(y, 0, 8)
            if(adjacent(i, j, x, y) && canmove(i, j, x, y))
            {
                printf("%c%c-%c%c\n", 'A'+i, '1'+j, 'A'+x, '1'+y);
                pos = true;
            }
        }
        
        if(!pos) puts("No moves are possible");
    }
    
    return 0;
}