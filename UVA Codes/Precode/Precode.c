/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
/* C headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <assert.h>
#include <time.h>
/* typedefs */
#define ll long long
#define ull unsigned long long 
#define uint unsigned int
/* always useful */
#define PI (2.0 * acos(0.0))
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
/* io */
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/* variables and functions */
const double EPS = 1E-10;
const int CHAR_INF = 0x7F;
const int INT_INF = 0x7F7F7F7F;
const long long LL_INF = 0X7F7F7F7F7F7F7F7F;
ll sqr(ll n) { return n * n; }
ll pmod(ll n, ll m) { return ((n % m) + m) % m; }
ll gcd(ll a, ll b) { return (b < 0) ? gcd(a, -b) : (b == 0 ? a : gcd(b, a % b)); }
ll lcm(ll a, ll b) { return a * (b / gcd(a, b)); }
ll power(ll n, int p) { return (p == 0) ? 1 : sqr(power(n, p>>1)) * ((p & 1) ? n : 1); }
ll bigmod(ll n, int p, ll m) { if(!p) return 1; else { ll r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
ll exgcd(ll a, ll b, ll *x, ll *y) { if(!b) { (*x)=1; (*y)=0; return a; } else { ll g = exgcd(b, a%b, y, x); (*y) -= (*x)*(a/b); return g; } }
ll modinv(ll a, ll m) { ll x=1, y=0; exgcd(a, m, &x, &y); return pmod(x, m); }
double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

int main()
{
    return 0;
}