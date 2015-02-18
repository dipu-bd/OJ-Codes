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

ll arr[200005];

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    ll n, l, x, y;

    cin >> n >> l >> x >> y;
    REP(i, 0, n) scanf("%I64d", &arr[i]);

    vii alpx, alpy;

    //place x
    bool found1 = false;
    REP(i, 0, n)
    {
        ll dx = arr[i] + x;
        if(dx > l) break;
        ll xd = *LB(arr, arr + n, dx);
        if(xd != dx) alpx.pb(dx);
        else { found1 = true; break; }
    }
    if(!found1)
        RREPE(i, n - 1, 0)
    {
        ll dx = arr[i] - x;
        if(dx < 0) break;
        ll xd = *LB(arr, arr + n, dx);
        if(xd != dx) alpx.pb(dx);
        else { found1 = true; break; }
    }

    //place y
    bool found2 = false;
    REP(i, 0, n)
    {
        ll dy = arr[i] + y;
        if(dy > l) break;
        ll yd = *LB(arr, arr + n, dy);
        if(yd != dy) alpy.pb(dy);
        else { found2 = true; break; }
    }
    if(!found2)
        RREPE(i, n - 1, 0)
    {
        ll dy = arr[i] - y;
        if(dy < 0) break;
        ll yd = *LB(arr, arr + n, dy);
        if(yd != dy) alpy.pb(dy);
        else { found2 = true; break; }
    }

    //solo result
    if(found1 && found2)
    {
        puts("0");
        return 0;
    }

    if(found2)
    {
        printf("1\n");
        cout << x << endl;
        return 0;
    }

    if(found1)
    {
        printf("1\n");
        cout << y << endl;
        return 0;
    }

    //find common

    ssort(alpx);
    ssort(alpy);

    int i = 0;
    int j = 0;
    while(i < (int)alpx.size()
            && j < (int)alpy.size())
    {
        if(alpx[i] < alpy[j]) { ++i; continue; }
        else if(alpy[j] < alpx[i]) { ++j; continue; }
        else
        {
            printf("1\n");
            cout << alpx[i] << endl;
            return 0;
        }
    }

    //dual result
    printf("2\n");
    cout << x << " " << y << endl;

    return 0;
}
