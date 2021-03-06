/* =================================
@AUTHOR : Sudipto Chandra Das DIPU
@UNIV : SUST [2012-331-019]
@COUNTRY : Bangladesh
================================= */
// C headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
// CPP headers
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <bitset>
using namespace std;
#define ENABLE_MACROS
//#define ENABLE_CONSTANTS
//#define ENABLE_FUNCTIONS

//typedefs
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
//risk-free macros
#define gcd(a,b) __gcd(a,b)
#define logab(a,b) (log(a) / lob(b))
#define mem(a,v) memset(a, v, sizeof(a))
#define ssort(v) stable_sort(all(v))
//risky macros
#ifdef ENABLE_MACROS
#define _a first
#define _b second
#define _IT ::iterator
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define all(v) v.begin(), v.end()
#define loop(type, v, it) for(type::iterator it = v.begin(); it != v.end(); ++it)
#endif // ENABLE_MACRO
//constants
#ifdef ENABLE_CONSTANTS
const double PI = acos(-1);
const double EPS = 1E-8; //the value which is bigger than zero
const int CHAR_INF = 0x7F;
const int INT_INF = 0x7F7F7F7F;
const long long LONG_INF = 0X7F7F7F7F7F7F7F7F;
#endif
//pre-functions
#ifdef ENABLE_FUNCTIONS
template<class T> inline T SQR(T num) { return num * num; } //returns square of two nums
template<class T> inline T ABS(T num) { return (num < 0) ? -num : num; }    //returns absolute value of num
template<class T> inline T PMOD(T A, T M) { return (A >= 0) ? (A % M) : (A % M) + ABS(M); } //returns positive modulus
template<class T> T POW(const T& n, const int& b) //calculate [n^p] in log(p)
{
    if(b < 0) return 1 / POW(n, -b);
    if (b & 1) return n * SQR(POW(n, b >> 1)) ;
    else return (b == 0) ? 1 : SQR(POW(n, b >> 1));
}
ll bigmod(const ll& n, const ll& b, const ll& m) //calculate [(n^p) % m] in O(log(p))
{
    if (b & 1) return (n * (SQR(POW(n, b >> 1)) % m)) % m ;
    else return (b == 0 ? 1 : SQR(POW(n, b >> 1))) % m;
}
#endif

//main function
int main()
{
#ifdef DIPU
    freopen("481.inp", "r", stdin);
#endif // DIPU

    vector<int> num;
    vector<int> lis;
    vector<int> res;
    vector<int>::iterator it;

    int x;
    while(scanf("%d", &x) != EOF)
    {
        it = lower_bound(all(lis), x);
        res.pb((int)(it - lis.begin()) + 1);
        num.pb(x);
        if(it == lis.end()) lis.pb(x);
        *it = x;
    }

    x = lis.size();
    printf("%d\n-\n", x);
    lis.clear();

    for(it = res.end() - 1; it >= res.begin(); --it)
        if(*it == x) lis.pb(num[(int)(it - res.begin())]), --x;

    for(it = lis.end() - 1; it >= lis.begin(); --it)
        printf("%d\n", *it);

    return 0;
}
