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
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

struct state
{
    int d;
    pii A;
    pii B;
    pii C;

    state() { d = 0; }

    int hash(int n) const
    {
        int a = (A.fr * n + A.sc);
        int b = (B.fr * n + B.sc);
        int c = (C.fr * n + C.sc);
        return (a * (n * n) + b) * (n * n) + c;
    }

    void advance(int x, int y, int n, char mat[15][15])
    {
        pii a = move(A, x, y, n, mat);
        pii b = move(B, x, y, n, mat);
        pii c = move(C, x, y, n, mat);

        if(a == A)
        {
            if(b == A) b = B;
            if(c == A) c = C;
        }
        if(b == B)
        {
            if(a == B) a = A;
            if(c == B) c = C;
        }
        if(c == C)
        {
            if(a == C) a = A;
            if(b == C) b = B;
        }

        A = a;
        B = b;
        C = c;
    }

    pii move(const pii& p, int x, int y, int n, char mat[15][15])
    {
        x += p.fr;
        y += p.sc;
        if(x >= 0 && x < n && y >= 0 && y < n && mat[x][y] != '#')
        {
            return mp(x, y);
        }
        return p;
    }
};

int n;
queue<state> q;
int vis[1000010];
char mat[15][15];

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

bool finished(const state& s)
{
    return mat[s.A.fr][s.A.sc] == 'X' &&
           mat[s.B.fr][s.B.sc] == 'X' &&
           mat[s.C.fr][s.C.sc] == 'X';
}

bool isvalid(const state& s)
{
    if(s.A == s.B || s.B == s.C || s.C == s.A) return false;
    return vis[s.hash(n)] != cas;
}

void init(state& s)
{
    REP(i, 0, n)
    REP(j, 0, n)
    {
        if(mat[i][j] == 'A')
            s.A = mp(i, j);
        else if(mat[i][j] == 'B')
            s.B = mp(i, j);
        else if(mat[i][j] == 'C')
            s.C = mp(i, j);
    }
}

int BFS()
{
    state s, t;
    q = queue<state>();

    init(s);

    q.push(s);
    vis[s.hash(n)] = cas;
    while(q.size())
    {
        s = q.front();
        q.pop();

//        printf("%d %d : %d %d : %d %d : %d [%d]\n", s.A.fr, s.A.sc, s.B.fr, s.B.sc, s.C.fr, s.C.sc, s.d, s.hash(n));

        if(finished(s))
        {
            return s.d;
        }

        REP(i, 0, 4)
        {
            t = s;
            t.advance(X[i], Y[i], n, mat);
            if(isvalid(t))
            {
                t.d++;
                q.push(t);
                vis[t.hash(n)] = cas;
            }
        }
    }

    return -1;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    sf1(test);
    while(test--)
    {
        sf1(n);
        REP(i, 0, n)
        scanf(" %s", mat[i]);

        int res = BFS();

        printf("Case %d: ", cas++);
        if(res == -1) puts("trapped");
        else printf("%d\n", res);
    }

    return 0;
}
