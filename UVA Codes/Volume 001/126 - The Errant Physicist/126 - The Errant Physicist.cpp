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
TEMPLATE inline T sqr(T n) { return n * n; }
TEMPLATE inline T pmod(T n, T m) { return ((n % m) + m) % m; }
TEMPLATE inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
TEMPLATE T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

typedef pair<string, string> pss;

struct Term
{
    int xpow;
    int ypow;
    int coef;
    Term() : xpow(0), ypow(0), coef(0) { }

    bool operator < (const Term& r) const
    {
        return (xpow > r.xpow) || (xpow == r.xpow && ypow < r.ypow);
    }
    bool operator == (const Term& r) const
    {
        return (xpow == r.xpow && ypow == r.ypow && coef == r.coef);
    }

    Term operator * (const Term& t) const
    {
        Term n;
        n.coef = coef * t.coef;
        n.xpow = xpow + t.xpow;
        n.ypow = ypow + t.ypow;
        return n;
    }

    int scan(const char* str)
    {
        coef = 0;
        xpow = 0;
        ypow = 0;

        //get sign
        int sign = 1;
        if(str[0] == '-') sign = -1;

        //get coefficient
        int s = 0;
        if(str[0] == '+' || str[0] == '-') ++s;
        bool dgs = 0;
        for( ; isdigit(str[s]); ++s)
        {
            dgs = 1;
            coef = coef * 10 + str[s] - '0';
        }
        if(dgs) coef *= sign;
        else coef = sign;

        //get xpow and ypow
        for(int i = 0; i < 2; ++i)
        {
            if(str[s] == 'x')
            {
                ++s;
                dgs = 0;
                for( ; isdigit(str[s]); ++s)
                {
                    dgs = 1;
                    xpow = xpow * 10 + str[s] - '0';
                }
                if(!dgs) xpow = 1;
            }
            else if(str[s] == 'y')
            {
                ++s;
                dgs = 0;
                for( ; isdigit(str[s]); ++s)
                {
                    dgs = 1;
                    ypow = ypow * 10 + str[s] - '0';
                }
                if(!dgs) ypow = 1;
            }
        }
       
        format();
        
        return s;
    }
    
    void format()
    {
        if(coef == 0)
        {
            xpow = 0;
            ypow = 0;
        }
    }

    void print(pss& out)
    { 
        format();
        
        //gather strings
        int n = out.fr.size();
        string c = tostring(abs(coef));
        string x = tostring(xpow);
        string y = tostring(ypow);

        //put sign
        if(n == 0)
        {
            if(coef < 0)
            {
                out.fr.pb(' ');
                out.sc.pb('-');
            }
        }
        else
        {
            out.fr += "   ";
            if(coef < 0) out.sc  += " - ";
            else out.sc += " + ";
        }

        //print coefs
        if(!(xpow | ypow) || ((xpow | ypow) && abs(coef) > 1))
        {
            out.fr += string(c.size(), ' ');
            out.sc += c;
        }

        //print x
        if(xpow)
        {
            out.fr.pb(' ');
            out.sc.pb('x');
            if(xpow > 1)
            {
                out.fr += x;
                out.sc += string(x.size(), ' ');
            }
        }

        //print y
        if(ypow)
        {
            out.fr.pb(' ');
            out.sc.pb('y');
            if(ypow > 1)
            {
                out.fr += y;
                out.sc += string(y.size(), ' ');
            }
        }

    }
};

struct Polynomial
{
    vector<Term> terms;
    Polynomial() { terms.clear(); }

    Polynomial operator * (const Polynomial& r) const
    {
        Polynomial res;
        
        vector<Term> tmp;
        loop(it, terms)
        {
            loop(jt, r.terms)
            tmp.pb((*it) * (*jt));
        }
        
        ssort(tmp);
        for(int i = 0; i + 1 < (int)tmp.size(); ++i)
        {
            Term& a = tmp[i];
            Term& b = tmp[i + 1];
            if(a.xpow == b.xpow && a.ypow == b.ypow)
            {
                b.coef += a.coef;
            }
            else if(a.coef != 0) 
            {
                res.terms.pb(a);
            } 
        }
        if(!tmp.empty() && tmp.back().coef != 0)
        {
            res.terms.pb(tmp.back());
        }
        
        if(res.terms.empty())
        {
            res.terms.pb(Term());
        }
        
        return res;
    }

    void scan(const char* inp)
    {
        Term t;
        terms.clear();
        int sz = strlen(inp);
        for(int i = 0; i < sz; )
        {
            i += t.scan(inp + i);
            terms.pb(t); 
        }
        ssort(terms);
    }

    void print( )
    {
        pss out;
        loop(it, terms)
        {
            it->print(out);
        }
        cout << out.fr << endl;
        cout << out.sc << endl;
    }
};

int main()
{
    char line[100];
    Polynomial a, b, c;

    while(gets(line) && strcmp(line, "#"))
    {
        a.scan(line);

        gets(line);
        b.scan(line);

        c = a * b;
        c.print();
    }

    return 0;
}
