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
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define REPES(i, a, n, s) for(int i = a; i <= n; i += s)
#define RREPES(i, a, n, s) for(int i = a; i >= n; i -= s)
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
const double EPS = 1E-10;
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
template<typename T> T gcd_iter(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<typename T> T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod_iter(T b, T p, T m) { T r = 1; while(p > 0) { if(p & 1) r = (r * b) % m; p >>= 1; b = (b * b) % m; } return r; }
template<typename T> T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
double combi(ll n, ll k) { if(2 * k > n) return combi(n, n - k); double res = 1.0; REP(i, 0, k) res *= (double)(n - i) / (i + 1); return res; }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int dist[26][26][26];
int vis[26][26][26];
int forbid[26][26][26];
string constraint[3];

void markforbid()
{
    loop(i, constraint[0])
    loop(j, constraint[1])
    loop(k, constraint[2])
    forbid[*i - 'a'][*j - 'a'][*k - 'a'] = cas;
}

inline int& getdis(string& s)
{
    return dist[s[0] - 'a'][s[1] - 'a'][s[2] - 'a'];
}

inline int& getvis(string& s)
{
    return vis[s[0] - 'a'][s[1] - 'a'][s[2] - 'a'];
}

inline bool isok(string& s)
{
    return vis[s[0] - 'a'][s[1] - 'a'][s[2] - 'a'] != cas &&
           forbid[s[0] - 'a'][s[1] - 'a'][s[2] - 'a'] != cas;
}

int BFS(string start, string stop)
{
    if(!isok(start) || !isok(stop)) return -1;

    queue<string> q;
    q.push(start);
    getdis(start) = 0;
    getvis(start) = cas;
    while(q.size())
    {
        start = q.front();
        q.pop();

        int d = getdis(start);
        if(start == stop) return d;

        string tmp = start;
        REP(i, 0, 3)
        {
            start[i] = pmod(start[i] - 'a' + 1, 26) + 'a';
            if(isok(start))
            {
                q.push(start);
                getvis(start) = cas;
                getdis(start) = d + 1;
            }
            start = tmp;

            start[i] = pmod(start[i] - 'a' - 1, 26) + 'a';
            if(isok(start))
            {
                q.push(start);
                getvis(start) = cas;
                getdis(start) = d + 1;
            }
            start = tmp;
        }
    }

    return -1;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    int n;
    string start, stop;

    sf1(test);
    while(test--)
    {
        cin >> start >> stop;

        sf1(n);
        while(n--)
        {
            cin >> constraint[0]
                >> constraint[1]
                >> constraint[2];
            markforbid();
        }

        int res = BFS(start, stop);
        printf("Case %d: %d\n", cas++, res);
    }

    return 0;
}

