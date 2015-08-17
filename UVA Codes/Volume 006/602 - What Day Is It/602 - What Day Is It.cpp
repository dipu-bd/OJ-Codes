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
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
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
TEMPLATE T power(T n, ll p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, ll p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;
//const int oo = 1 << 30;
//const int mod = 1000000007;

char weeks[][20] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
char months[][20] = { "", "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
int daysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
int cumDaysInMonth[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };

const int weekInJul = 4;
const int weekInGreg = 0;
const int weekIn1752 = 2;

bool isleap(int year)
{
    if(year <= 1752) return (year % 4 == 0); //julian leap year
    return (year % 4 == 0) && (year % 100 != 0 || year % 400 == 0);
}

bool isvalid(int day, int mon, int year)
{
    if(day < 1 || day > 31) return false;
    if(mon < 1 || mon > 12) return false;
    if(year < 0) return false;

    if(mon == 2)
    {
        return ((day <= 28) || ((day == 29 && isleap(year))));
    }
    else
    {
        return day <= daysInMonth[mon];
    }
}

ll getDaysInYear(int year)
{
    if(year == 0) return 0;

    if(year < 1752)
    {
        ll day = year * 365LL;
        day += year / 4;
        if(isleap(year)) --day;
        return day;
    }
    else if(year > 1752)
    {
        ll day = (year - 1753) * 365LL;
        day += year / 4 - 1752 / 4;
        day -= year / 100 - 1752 / 100;
        day += year / 400 - 1752 / 400;
        if(isleap(year)) --day;
        return day;
    }
    else
    {
        return 0;
    }
}

int getweek(int day, int mon, int year)
{
    if(!isvalid(day, mon, year))
    {
        return -1;
    }

    ll diy = getDaysInYear(year); // cumulative days in year
    ll dim = cumDaysInMonth[mon - 1];  //cumulative days in month
    ll week = diy + dim + day;
    if(mon > 2 && isleap(year)) week++; // add leapday or not

    if(year < 1752)
    {
        week += weekInJul;
    }
    else if(year > 1752)
    {
        week += weekInGreg;
    }
    else // year == 1752
    {
        if(mon == 9 && day > 2 && day < 14)
        {
            return -1;
        }

        week += weekIn1752;
        if(mon > 9 || mon == 9 && day >= 14)
        {
            week -= 11;
        }
    }

    return (int)(week % 7);
}

int main()
{
    int mon, day, year;
    while(scanf("%d%d%d", &mon, &day, &year) == 3 && (mon | day | year))
    {
        int w = getweek(day, mon, year);
        if(w == -1)
        {
            printf("%d/%d/%d is an invalid date.\n", mon, day, year);
        }
        else
        {
            printf("%s %d, %d is a %s\n", months[mon], day, year, weeks[w]);
        }
    }


    return 0;
}
