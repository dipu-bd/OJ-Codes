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

struct combi
{
    int a;
    int b;
    int c;
    int s;
    bool cantake(int bit)
    {
        return !((bit & (1 << (a - 1)))
                ||(bit & (1 << (b - 1)))
                ||(bit & (1 << (c - 1))));
    }
    int take(int bit)
    {
        bit |= 1 << (a - 1);
        bit |= 1 << (b - 1);
        bit |= 1 << (c - 1);
        return bit;
    }
};

int n;
combi score[85];
int save[85][515];

int recur(int p = 0, int bit = 0)
{
    if(p == n) 
    {
        return (POPC(bit) == 9) ? 0 : -1;
    }
    
    int& dp = save[p][bit];
    if(~dp) return dp;
    
    dp = recur(p + 1, bit);
    if(score[p].cantake(bit))
    {
        bit = score[p].take(bit);
        int tb = recur(p + 1, bit);
        if(~tb) dp = max(dp, tb + score[p].s);
    }
    
    return dp;
}

int main()
{
    while(~sf1(n) && n)
    {
        REP(i, 0, n) 
        {
            sf4(score[i].a, score[i].b, score[i].c, score[i].s);
        }
        
        mem(save, -1);    
        int res = recur();
        printf("Case %d: %d\n", cas++, res);
    }
    
    return 0;
}