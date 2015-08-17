
/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 Created: $(NOW_L), $(WEEKDAY)
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
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define unsigned un
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
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
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
TEMPLATE inline T sqr(T n)
{
    return n * n;
}
TEMPLATE inline T pmod(T n, T m)
{
    return ((n % m) + m) % m;
}
TEMPLATE inline T lcm(T a, T b)
{
    return a * (b / gcd(a, b));
}
TEMPLATE T power(T n, ll p)
{
    if(!p) return 1;
    else
    {
        T res = sqr(power(n, p >> 1));
        if(p & 1) res *= n;
        return res;
    }
}
TEMPLATE T bigmod(T n, ll p, T m)
{
    if(!p) return 1;
    else
    {
        T r = sqr(bigmod(n, p >> 1, m)) % m;
        if(p & 1) r = (r * n) % m;
        return r;
    }
}
TEMPLATE T exgcd(T a, T b, T& x, T& y)
{
    if(!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        T g = exgcd(b, a % b, y, x);
        y -= (a / b) * x;
        return g;
    }
}
TEMPLATE T modinv(T a, T m)
{
    T x, y;
    exgcd(a, m, x, y);
    return pmod(x, m);
}
TEMPLATE inline T extract(const string& s, T ret)
{
    stringstream ss(s);
    ss >> ret;
    return ret;
}
TEMPLATE inline string tostring(T n)
{
    stringstream ss;
    ss << n;
    return ss.str();
}
inline double hypot(double x, double y)
{
    return sqrt(sqr(x) + sqr(y));
}
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

typedef pair<bool, int> pbi;

#define SIZ 250010

int test, cas = 1;

int n;
int total;
int arr[55];
int save[2][SIZ + 10];

int bottom_up()
{
    mem(save, 0x82);
    save[0][0] = 0;

    REPE(p, 1, n)
    {
        int i = p & 1;
        int j = (p + 1) & 1;
        REPE(s, 0, total)
        {
            save[i][s] = save[j][s];
            if(abs(s - arr[p]) <= total)
                save[i][s] = max(save[i][s], save[j][abs(s - arr[p])] + arr[p]);
            if(s + arr[p] <= total)
                save[i][s] = max(save[i][s], save[j][s + arr[p]] + arr[p]);
        }
    }

    return save[n & 1][0];
}

int main()
{
    sf1(test);
    while(test--)
    {
        sf1(n);
        total = 0;
        REPE(i, 1, n)
        {
            sf1(arr[i]);
            total += arr[i];
        }

        total >>= 1;
        int res = bottom_up() >> 1;
        printf("Case %d: ", cas++);
        if(res > 0 && res <= total)
            printf("%d\n", res);
        else
            puts("impossible");
    }

    return 0;
}
