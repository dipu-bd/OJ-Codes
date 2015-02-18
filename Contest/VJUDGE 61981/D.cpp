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
template<typename T> inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
template<typename T> T gcd_iter(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<typename T> T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod_iter(T b, T p, T m) { T r = 1; while(p > 0) { if(p & 1) r = (r * b) % m; p >>= 1; b = (b * b) % m; } return r; }
template<typename T> T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int m, ml;
int pi[70];
char str[12][70];
char maxpat[70];

void copystring(char* to, const char* from, int len)
{
    int l = 0;
    REP(i, 0, len)
    to[l++] = from[i];
    to[l] = 0;
}

bool lesser(char* a, char* b, int len)
{
    REP(i, 0, len)
    if(a[i] != b[i])
        return a[i] < b[i];
    return false;
}

void compute(const char* pat, int len)
{
    pi[0] = -1;
    int q = -1;
    REP(i, 1, len)
    {
        while(q >= 0 && pat[i] != pat[q + 1]) q = pi[q];
        if(pat[i] == pat[q + 1]) ++q;
        pi[i] = q;
    }
}

bool KMP(char* text, char* pat, int len)
{
    int q = -1;
    for(int i = 0; text[i]; ++i)
    {
        while(q >= 0 && text[i] != pat[q + 1]) q = pi[q];
        if(text[i] == pat[q + 1]) ++q;
        if(q + 1 == len) return true;
    }
    return false;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    sf1(test);
    while(test--)
    {
        sf1(m);
        REP(i, 0, m)
        scanf(" %s", str[i]);

        ml = 0;
        int n = strlen(str[0]);
        REP(i, 0, n)
        {
            char* pat = str[0] + i;
            compute(pat, n - i);
            RREPE(j, n - 1, i + 2)
            {
                int len = j - i + 1;
                if(len < ml) break;

                bool match = true;
                REP(k, 1, m)
                {
                    match = KMP(str[k], pat, len);
                    if(!match) break;
                }

                if(match && ml <= len)
                {
                    if(ml < len || lesser(pat, maxpat, len))
                    {
                        copystring(maxpat, pat, len);
                    }
                    ml = len;
                }
            }
        }

        if(ml > 0) puts(maxpat);
        else puts("no significant commonalities");
    }

    return 0;
}