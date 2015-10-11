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
#define REPNE(i, a, n) for(int i = a;  i >= n; --i)
//input-output
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d)
#define deb1(a) cout << a << "\n"
#define deb2(a,b) cout << a << " " << b << "\n"
#define deb3(a,b,c) cout << a << " " << b << " " << c << "\n"
#define deb4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << "\n"
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

//const int oo = 1 << 30;
//const int mod = 1000000007;

int test, cas = 1;

#define SIZ 30000005
int save[SIZ + 10];

void build()
{
    for(int i = 1; 3 * i < SIZ; ++i)
    {
        for(int j = 3; i * j < SIZ; j += 2)
        {
            int a = i * j;
            if((a ^ i) % i == 0)
            {
                ++save[a];
            }
        }
    }
    for(int i = 1; i < SIZ; ++i)
    {
        save[i] += save[i - 1];
    }
}

int main()
{
    build();
    return 0;

    int n;
    sf1(test);
    while(test--)
    {
        sf1(n);
        printf("Case %d: %d\n", cas++, save[n]);
    }

    return 0;
}


//
//int len = 5;
//vii data[1000];
//
//void showbin(int n, const char* eol = "\n")
//{
//    printf("%4d: ", n);
//    for(int i = len; i >= 0; --i)
//    {
//        putchar('0' + ((n >> i) & 1));
//    }
//    printf(eol);
//}
//void showsep()
//{
//    for(int i = len + 10; i >= 0; --i)
//    {
//        putchar('-');
//    }
//    putchar('\n');
//}
//
//int backtrack(int A, int B, int pos)
//{
//    if(pos < 0)
//    {
//        if (B > 0 && B < A && A % (A ^ B) == 0 && B % (A ^ B) == 0)
//        {
//            data[A ^ B].pb(A / (A ^ B));
//            return 1;
//        }
//        //showbin(B);
//        return 0;
//    }
//
//    int res = 0;
//    int a = A & (1 << pos);
//    res += backtrack(A, B | a, pos - 1);
//    if(a && B)
//    {
//        res += backtrack(A, B, pos - 1);
//    }
//
//    return res;
//}
//
//int main()
//{
//    int n = 200, res = 0;
//    for(int A = 1; A <= n; ++A)
//    {
//        //showbin(A, " : ");
//        res += backtrack(A, 0, 25);
//    }
//    printf("[%d = %d]\n", n, res);
//
//    REP(i, 1, n)
//    {
//        if(data[i].empty()) continue;
//        printf("%d : ", i);
//        loop(it, data[i])
//        printf("%d ", *it);
//        puts("");
//    }
//
//    return 0;
//}
