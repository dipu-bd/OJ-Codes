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
#include <assert.h>
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

int d = 35;
int mod = 1000000007;

string nodes[50];
map<string, int> nodnum;

ll mat[50][50];
ll tmp[50][50];
ll ans[50][50];

void makenode(int t, string took)
{
    if(t > 5) return;
    if(took.size() == 7)
    {
        if(t == 5)
        {
            nodes[d] = took;
            nodnum[took] = d++;
        }
        return;
    }

    makenode(t, took + "0");
    makenode(t + 1, took + "1");
}

void makemove(int x, int p = 0, string mov = "0000000")
{
    //move complete
    if(p == 7)
    {
        int y = nodnum[mov];
        mat[x][y] = 1;
        return;
    }

    //not a person
    if(nodes[x][p] == '0')
    {
        makemove(x, p + 1, mov);
        return;
    }

    //move left
    if(p > 0 && mov[p - 1] == '0')
    {
        mov[p - 1] = nodes[x][p];
        makemove(x, p + 1, mov);
        mov[p - 1] = '0';
    }

    //move right
    if(p < 6 && mov[p + 1] == '0')
    {
        mov[p + 1] = nodes[x][p];
        makemove(x, p + 1, mov);
        mov[p + 1] = '0';
    }
}

void build()
{
    //make nodes
    d = 0;
    makenode(1, "");

    //make conntections
    clr(mat);
    REP(i, 0, d)
    makemove(i);
}

void unit()
{
    clr(ans);
    REP(i, 0, d)
    ans[i][i] = 1;
}

void COPY(ll M[50][50])
{
    REP(i, 0, d)
    REP(j, 0, d)
    ans[i][j] = M[i][j];
}

void CROSS(ll M[50][50])
{
    REP(i, 0, d)
    REP(j, 0, d)
    {
        tmp[i][j] = 0;
        REP(k, 0, d)
        tmp[i][j] += (ans[i][k] * M[k][j]) % mod;
        tmp[i][j] %= mod;
    }
    COPY(tmp);
}

void power(ll n)
{
    if(n == 0) unit();
    else if(n == 1) COPY(mat);
    else
    {
        power(n >> 1);
        CROSS(ans);
        if(n & 1) CROSS(mat);
    }
}

int main()
{
    build();

    ll n;
    char ch;
    string str;

    sf1(test);
    while(test--)
    {
        scanf("%lld", &n);

        str.clear();
        REP(i, 0, 7)
        {
            scanf(" %c", &ch);
            if(ch == '0') str.pb('0');
            else str.pb('1');
        }

        printf("Case %d: ", cas++);
        if(n == 1)
        {
            printf("1\n");
            continue;
        }

        power(n - 1);
        int p = nodnum[str];

        ll res = 0;
        REP(i, 0, d)
        {
            res += ans[p][i];
            res %= mod;
        }

        printf("%lld\n", res);
    }

    return 0;
}
