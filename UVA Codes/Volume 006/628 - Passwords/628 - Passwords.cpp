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
#define ENABLE_FUNCTIONS

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
#endif

//other macros
const int MAX = 0;
const int MOD = 0;
const int LIMIT = 0;

void incr(char* m, int len)
{
    int r = 1;
    while(r && len)
    {
        --len;
        m[len] += r;
        r = m[len] / 10.0;
        m[len] %= 10.0;
    }
}

void show(vector<string> & vs, const char* str)
{
    int numc = 0;
    for(int i = 0; str[i]; ++i)
        if(str[i] == '0') numc++;

    char* m = new char[numc + 2];
    int cnt = POW(10, numc);
    loop(vector<string>, vs, i)
    {
        mem(m, 0);
        for(int j = 0; j < cnt; ++j)
        {
            for(int k = 0, p = 0; str[k]; ++k)
            {
                if(str[k] == '#') printf(i->c_str());
                else printf("%d", m[p++]);
            }
            puts("");
            incr(m, numc);
        }
    }
}

//main function
int main()
{
#ifdef DIPU
    //freopen("inp.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif // DIPU

    int test, cas = 1;
    string inp;

    int n, m;
    while(scanf("%d ", &n) != EOF)
    {
        puts("--");

        vector<string> vs;
        while(n--)
        {
            cin >> inp;
            vs.pb(inp);
        }

        scanf("%d", &m);
        while(m--)
        {
            cin >> inp;
            show(vs, inp.c_str());
        }
    }

    return 0;
}

