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
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
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
const int CHAR_INF = 0x7F;
const int INT_INF = 0x7F7F7F7F;
const long long LONG_INF = 0X7F7F7F7F7F7F7F7F;
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p>>1)); if(p&1) res*=n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p>>1, m))%m; if(p&1) r = (r*n)%m; return r; } }
TEMPLATE T exgcd(T a,T b,T& x,T& y) { if(!b) { x=1; y=0; return a; } else { T g = exgcd(b, a%b, y, x); y -= (a/b)*x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

string real = "0123456789+-*/";
const char convert[5][120] = 
{
    "000 .0. 000 000 0.0 000 0.. 000 000 000 .0. ... 0.0 .0.",
    "0.0 .0. ..0 ..0 0.0 0.. 0.. ..0 0.0 0.0 .0. ... 0.0 ...",
    "0.0 .0. 000 000 000 000 000 ..0 000 000 000 000 .0. 000",
    "0.0 .0. 0.. ..0 ..0 ..0 0.0 ..0 0.0 ..0 .0. ... 0.0 ...",
    "000 .0. 000 000 ..0 000 000 ..0 000 ..0 .0. ... 0.0 .0."
};

string str;
char inp[5][120];

char getchar(int p)
{
    int len = strlen(convert[0]);
    for(int j = 0, q = 0; j < len; j += 4, ++q)
    {
        bool match = true;
        REP(i, 0, 5)
        {
            if(!match) break;
            REP(k, 0, 3)
            {
                if(inp[i][p + k] !=  convert[i][j + k])
                {
                    match = false;
                    break;
                }
            }
        }
        if(match) return real[q];
    }
    return -1;
}

int preced(char op)
{
    if(op == '*' || op == '/') 
        return 0;
    else if(op == '+' || op == '-')
        return 1;
    else
        return 2;
}

int solve()
{
    stack<int> val;
    stack<char> op;
    
    int last = 0;
    for(int i = 0; i <= str.size(); ++i)
    {
        if(i < str.size() && isdigit(str[i]))
        {
            last = last * 10 + str[i] - '0';
        }
        else 
        {
            val.push(last);
            last = 0;
            
            int p = 2;
            if(i < str.size()) 
                p = preced(str[i]);
            
            while(op.size())
            {
                char t = op.top();
                if(preced(t) > p) break;
                
                op.pop();
                int b = val.top(); val.pop();
                int a = val.top(); val.pop();
                if(t == '*') val.push(a * b);
                else if(t == '/') val.push(a / b);
                else if(t == '+') val.push(a + b);
                else if(t == '-') val.push(a - b);
            }
            
            if(i < str.size())
                op.push(str[i]);
        }
    }
    
    return val.top();
}

void print(char ch, int p)
{
    int x = 0;
    REP(i, 0, real.size())
    {
        if(real[i] == ch)
        {
            x = i;
            break;
        }
    }
    
    x = 4 * x;
    REP(i, 0, 3)
    putchar(convert[p][x + i]);
}

int main()
{
    char out[100];
    while(!feof(stdin))
    {
        REP(i, 0, 5)
        scanf(" %[^\n] ", inp[i]);
        
        str.clear();
        int len = strlen(inp[0]);
        for(int p = 0; p < len; p += 4)
        {
            str.pb(getchar(p));
        }
        
        if(str == "0") break;
        
        int res = solve();
        sprintf(out, "%d", res);
        
        REP(k, 0, 5)
        {
            for(int i = 0; out[i]; ++i)
            {
                if(i) putchar(' ');
                print(out[i], k);
            }
            putchar('\n');
        }
        putchar('\n');
    }
    
    return 0;
}