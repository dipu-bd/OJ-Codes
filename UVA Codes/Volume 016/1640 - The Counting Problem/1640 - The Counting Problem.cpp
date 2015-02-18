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

struct freq
{
    int sol;
    bool flag;
    int arr[10];

    freq(int v = 0)
    {
        clear();
        sol = v;
    }

    void clear()
    {
        sol = 0;
        clr(arr);
        flag = 0;
    }

    void print()
    {
        printf("%d %d %d %d %d %d %d %d %d %d\n",
               arr[0], arr[1], arr[2], arr[3], arr[4],
               arr[5], arr[6], arr[7], arr[8], arr[9]);
    }
};

int len;
char num[20];
freq save[10][2][2];

freq recur(int p = 0, bool imax = 1, bool istart = 0)
{
    if(num[p] == 0) return freq(1);

    freq& dp = save[p][imax][istart];
    if(dp.flag) return dp;

    dp.clear();
    dp.flag = 1;
    int e = imax ? num[p] - '0' : 9;

    REPE(i, 0, e)
    {
        freq t = recur(p + 1, (imax && i == e), (istart || i != 0));
        if(i != 0 || istart) { dp.arr[i] += t.sol; dp.sol += t.sol; }
        REPE(i, 0, 9) dp.arr[i] += t.arr[i];
    }

    return dp;
}

void reset()
{
    REPE(i, 0, 20)
    {
        save[i][0][0].flag = 0;
        save[i][0][1].flag = 0;
        save[i][1][0].flag = 0;
        save[i][1][1].flag = 0;
    }
}

int main()
{
    int a, b;
    while(sf2(a, b) == 2 && (a | b))
    {
        if(b < a) swap(a, b);
        
        clr(save);
        sprintf(num, "%d", b);
        freq bf = recur();

        clr(save);
        sprintf(num, "%d", a - 1);
        freq af = recur();

        REPE(i, 0, 9)
        bf.arr[i] -= af.arr[i];
        
        bf.print();
    }

    return 0;
}
