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

pii match(string& a, string& b)
{
    REP(i, 0, (int)a.size())
    {
        REP(j, 0, (int)b.size())
        {
            if(a[i] == b[j])
                return mp(i, j);
        }
    }
    return mp(-1, -1);
}

int main()
{ 
    bool nl = false;
    
    string a, b, c, d;
    while(cin >> a && a != "#")
    {
        cin >> b >> c >> d;
        
        if(nl) putchar('\n');
        else nl = true;
        
        pii cross1 = match(a, b);
        pii cross2 = match(c, d);
        if(cross1.fr == -1 || cross2.fr == -1)
        {
            puts("Unable to make two crosses");
            continue;
        }
        
        int hor = max(cross1.sc, cross2.sc);
        int b1 = cross1.fr + 1;
        int b2 = cross2.fr + 1 + ((int)a.size() + 3);  
        
        REP(i, 0, hor)
        {
            bool sub = false;
            int p1 = i - hor + cross1.sc;
            int p2 = i - hor + cross2.sc;
            if(p1 >= 0)
            {
                sub = true;
                printf("%*c", b1, b[p1]);
            }
            if(p2 >= 0)
            {
                int sp = sub ? b2 - b1 : b2;
                printf("%*c", sp, d[p2]);
                sub = true;
            }
            if(sub) putchar('\n');
        }
        
        printf("%s   %s\n", a.data(), c.data());
        
        int e = max(b.size() - cross1.sc, d.size() - cross2.sc);
        REPE(i, 0, e)
        {
            bool sub = false;
            int p1 = i + cross1.sc + 1;
            int p2 = i + cross2.sc + 1;
            if(p1 < (int)b.size())
            {
                sub = true;
                printf("%*c", b1, b[p1]);
            }
            
            if(p2 < (int)d.size())
            {
                int sp = sub ? b2 - b1 : b2;
                printf("%*c", sp, d[p2]);
                sub = true;
            }
            
            if(sub) putchar('\n');
        }
    }
    
    return 0;
}