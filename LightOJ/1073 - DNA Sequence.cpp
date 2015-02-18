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
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline int extract(const string& s, T ret) { stringstream ss(s); return (ss >> ret); }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;
const int oo = 1 << 30;

int n;
int sub[20];
int len[20];
int join[20][20];
char dna[20][200];
int save[16][1 << 16];
int _save[16][1 << 16];
string res;
vpii indx;

bool issub(int i, int j) //Is dna[j] a substring of dna[i] ?
{
    int n = len[i];
    int m = len[j];
    for(int k = 0; k + m <= n; ++k)
    {
        bool match = true;
        for(int l = 0; l < m; ++l)
        {
            if(dna[i][k + l] != dna[j][l])
            {
                match = false;
                break;
            }
        }
        if(match) return true;
    }
    return false;
}

int getlen(int i, int j) //gen length after joining dna[i] and dna[j]
{
    int n = len[i];
    int m = len[j];
    for(int k = max(0, n - m); k < n; ++k)
    {
        bool match = true;
        for(int l = 0; k + l < n; ++l)
        {
            if(dna[j][l] != dna[i][k + l])
            {
                match = false;
                break;
            }
        }
        if(match) return k;
    }
    return n;
}

int recur(int p, int mask)
{
    if(POPC(mask) == n) return len[p];

    int& dp = save[p][mask];
    int& dpc = _save[p][mask];
    if(dpc == cas) return dp;

    dp = oo;
    dpc = cas;
    REP(i, 0, n)
    if(!(mask & (1 << i)))
    {
        int r = recur(i, mask | sub[i]);
        int l = (p == n) ? 0 : join[p][i];
        dp = min(dp, l + r);
    }

    return dp;
}

pii getmini(int p)
{
    pii mn = indx[0];
    loop(it, indx)
    {
        if(it == indx.begin()) continue;
        int l1 = mn.sc;
        int l2 = it->sc;
        int t1 = l1 + len[mn.fr];
        int t2 = l2 + len[it->fr];
        int match = 0;
        for(int i = 0; i < t1 && i < t2; ++i)
        {
            char ch1 = (i < l1) ? dna[p][i] : dna[mn.fr][i - l1];
            char ch2 = (i < l2) ? dna[p][i] : dna[it->fr][i - l2];
            if(ch1 != ch2)
            {
                match = ch1 - ch2;
                break;
            }
        }
        if(match > 0 || (match == 0 && t2 < t1))
        {
            mn = *it;
        }
    }
    return mn;
}

void pathprint(int p, int mask = 0)
{
    if(POPC(mask) == n)
    {
        res += dna[p];
        return;
    }

    indx.clear();
    REP(i, 0, n)
    if(!(mask & (1 << i)))
    {
        int r = recur(i, mask | sub[i]);
        int l = (p == n) ? 0 : join[p][i];
        if(recur(p, mask) == l + r)
        {
            indx.pb(mp(i, l));
        }
    }

    pii q = getmini(p);
    REP(k, 0, q.sc) res.pb(dna[p][k]);
    pathprint(q.fr, mask | sub[q.fr]);
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
        {
            scanf(" %s", dna[i]);
            len[i] = strlen(dna[i]);
        }

        REP(i, 0, n)
        {
            sub[i] = 0;
            REP(j, 0, n)
            {
                join[i][j] = getlen(i, j);
                if(issub(i, j)) sub[i] |= 1 << j;
            }
        }

        res.clear();
        pathprint(n);

        printf("Case %d: %s\n", cas++, res.data());
    }

    return 0;
}



