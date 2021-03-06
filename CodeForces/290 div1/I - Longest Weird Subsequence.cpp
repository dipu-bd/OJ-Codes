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
//#include <bits/stdc++.h>
//#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef char C;
typedef string S;
typedef unsigned long long UNL;

//some constants
const double PI = 2.0 * acos(0.0);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define LOG(x,BASE) (log10(x)/log10(BASE))
#define rep(i, a, n) for(int i = a; i < n; ++i)
#define rrep(i, a, n) for(int i = a; i > n; --i)
#define repe(i, a, n) for(int i = a; i <= n; ++i)
#define rrepe(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
#define sz(a) (int)a.size()
#define sf scanf
#define pf printf
#define NL pf("\n")
#define sf1(a) scanf("%d",&a)
#define sf2(a,b) scanf("%d %d",&a,&b)
#define sf3(a,b,c) scanf("%d %d %d", &a,&b, &c)
#define sf4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define sf5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define sf6(a,b,c,d,e,f) scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f)
#define __ freopen("in.in", "r", stdin)
#define ___ freopen("out.out", "w", stdout)
#define oo 1000000000
#define ____ freopen("in.in", "w", stdout)
/*--------------------------------------------------------------------------------------------------*/


const double EPS = 1e-9;
//ll Pow(ll B,ll P){  ll R=1; while(P>0)  {if(P%2==1) R=(R*B);P/=2;B=(B*B);}return R;}

//ll extGcd(ll a, ll b, ll& x, ll& y){if (b == 0){x = 1;y = 0;return a;}else{ll g = extGcd(b, a % b, y, x);y -= a / b * x;return g;}}
//ll modInv(ll a, ll m){ll x, y; extGcd(a, m, x, y); x %= m; while (x < 0){x += m;} return x;}
//ll bigmod(ll a,ll b,ll m){if(b == 0) return 1%m;ll x = bigmod(a,b/2,m);x = (x * x) % m;if(b % 2 == 1) x = (x * a) % m;return x;}
//ll BigMod(ll B,ll P,ll M){ ll R=1%M; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;} ret urn R;} /// (B^P)%M

//template <class T> inline T gcd(T a, T b){if(b == 0) return a;return gcd(b,a%b);}
//template <class T> inline T lcm(T a, T b){return (a/gcd(a,b)) * b;}

//int x[] = {0,0,-1,1};//4-way
//int y[] = {-1,1,0,0};//4-way
//ll x[] = {-1,-1,-1,0,0,1,1,1};//8-way
//ll y[] = {-1,0,1,-1,1,-1,0,1};//8-way
//int dx[] = {+1,+1,+2,+2,-1,-1,-2,-2}; //knight moves
//int dy[] = {+2,-2,+1,-1,+2,-2,+1,-1}; // knight moves
//inline long FastMax(long x, long y) { return (((y-x)>>(32-1))&(x^y))^y; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//inline long FastMin(long x, long y) { return (((y-x)>>(32-1))&(x^y))^x; }
//v.resize( unique(all(v)) - v.begin() );

//#include<conio.h>
//#define wait getch()

//if (N mod 2) = 0
//  if (N mod 4) = 0 then r = N else r = N+1
//else
//  if (N mod 4) = 1 then r = 1 else r = 0

int cases = 1;
ii L[2005];
int I[2005], n;
C str[2005], s[2005];

void read(void)
{
    return ;
}

int solve(void)
{
    int i;
    I[0] = -oo;
    for(int i=1; i<=n; i++) I[i] = oo;
    int length = 0;
    for(int i=0; i<n; i++)
    {
        int low, high, mid;
        low = 0;
        high = length;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(I[mid] <= str[i] - 'a')
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = str[i] - 'a';
        L[i].fr = low;
        if(length < low)
            length = low;
    }
    for(int i=n-1, j=0; i>=0; i--, j++) s[j] = str[i];
    I[0] = -oo;
    for(int i=1; i<=n; i++) I[i] = oo;
    length = 0;
    for(int i=0; i<n; i++)
    {
        int low, high, mid;
        low = 0;
        high = length;
        while(low <= high)
        {
            mid = (low + high) / 2;
            if(I[mid] <= s[i] - 'a')
                low = mid + 1;
            else
                high = mid - 1;
        }
        I[low] = s[i] - 'a';
        L[i].sc = low;
        if(length < low)
            length = low;
    }

    for(int i=0; i<n; i++)
        pf("(%d,%d) ",L[i].fr,L[i].sc);
    NL;

    return 0;
}

int main()
{
    int test;
    sf1(test);
    while(test--)
    {
        sf(" %s",str);
        n = strlen(str);
        int ans = solve();
        pf("%d\n", ans);
    }
    return 0;
}


















