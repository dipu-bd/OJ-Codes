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

int len1, len2;
char astr[20], bstr[20];

ll add(int b)
{
    ll r = 0;
    int sum = 0, tb = 1;
    int i = len1, j = len2;
    while(i > 0 || j > 0 || sum)
    {
        sum += (i > 0 ? astr[--i] : 0) + (j > 0 ? bstr[--j] : 0); 
        r += (sum % b) * tb;
        sum /= b;
        tb *= 10;
    }
    return r;
}

int minvalid(int x)
{
    int m = 0;
    while(x)
    {
        m = max(m, x % 10);
        x /= 10;
    }
    return m + 1;
}

bool isbaseone(int a, int b, int c)
{
    int ac, bc, cc;
    ac = bc = cc = 0;
    
    while(a)
    {
        if(a % 10 != 1) return false;
        a /= 10;
        ++ac;
    }
    while(b)
    {
        if(b % 10 != 1) return false;
        b /= 10;
        ++bc;
    }
    while(c)
    {
        if(c % 10 != 1) return false;
        c /= 10;
        ++cc;
    }
    return (ac + bc == cc);
}

int getbase(int a, int b, int c)
{
    if(a + b == c && c == 0) return 2;
    if(isbaseone(a, b, c)) return 1;
    
    sprintf(astr, "%d", a);
    sprintf(bstr, "%d", b);
    len1 = strlen(astr);
    len2 = strlen(bstr);
    REP(i, 0, len1) astr[i] -= '0';
    REP(i, 0, len2) bstr[i] -= '0';
    
    int beg = minvalid(a);
    beg = max(beg, minvalid(b)); 
    if(beg < 2) beg = 2;
     
    REPE(i, beg, 50)
    {
        if(add(i) == c) return i;
    }
    
    return 0;
}

int main()
{
    int a, b, c, r;
    
    sf1(test);
    while(test--)
    {
        scanf("%d + %d = %d", &a, &b, &c);
        r = getbase(a, b, c);
        printf("%d\n", r);    
    }
    
    return 0;
}