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
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
#define debug1(a) cout << a << endl
#define debug2(a,b) cout << a << " " << b << endl
#define debug3(a,b,c) cout << a << " " << b << " " << c << endl
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
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
template<typename T> T power(T n, int p) { return (p == 0) ? (T)(1) : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? (T)(1) : ((sqr(bigmod(n, p >> 1, m)) % m) * ((p & 1) * (n - 1) % m + 1)) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int d;
pii nod[50];
int remap[100];

uint mat[50][50];
uint tmp[50][50];
uint ans[50][50];

void makenode()
{
    d = 0;
    REP(i, 0, 10)
    REP(j, i + 2, 10)
    {
        nod[d].fr = i;
        nod[d].sc = j;
        ++d;
    }
}

void makematrix()
{
    clr(mat);
    REP(i, 0, d)
    REP(j, i + 1, d)
    {
        if(abs(nod[i].fr - nod[j].fr) <= 1) continue;
        if(abs(nod[i].fr - nod[j].sc) <= 1) continue;
        if(abs(nod[i].sc - nod[j].fr) <= 1) continue;
        if(abs(nod[i].sc - nod[j].sc) <= 1) continue;
        mat[i][j] = mat[j][i] = 1;
    }
}

void build()
{
    makenode();
    makematrix();
}

void unit()
{
    clr(ans);
    REP(i, 0, d)
    ans[i][i] = 1;
}

void COPY(uint M[50][50])
{
    REP(i, 0, d)
    REP(j, 0, d)
    ans[i][j] = M[i][j];
}

void cross(uint M[50][50])
{
    REP(i, 0, d)
    REP(j, 0, d)
    {
        tmp[i][j] = 0;
        REP(k, 0, d)
        tmp[i][j] += ans[i][k] * M[k][j];
    }
    COPY(tmp);
}

void power(int n)
{
    if(n == 0) unit();
    else if(n == 1) COPY(mat);
    else
    {
        power(n >> 1);
        cross(ans);
        if(n & 1) cross(mat);
    }
}

int main()
{
    build();

    int n;
    sf1(test);
    while(test--)
    {
        sf1(n);

        power(n - 1);

        uint res = 0;
        REP(i, 0, d)
        REP(j, 0, d)
        res += ans[i][j];

        printf("Case %d: ", cas++);
        printf("%u\n", res);
    }

    return 0;
}
