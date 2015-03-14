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
TEMPLATE T power(T n, ll p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
TEMPLATE T bigmod(T n, ll p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
TEMPLATE T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
TEMPLATE T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
TEMPLATE inline T extract(const string& s, T ret) { stringstream ss(s); ss >> ret; return ret; }
TEMPLATE inline string tostring(T n) { stringstream ss; ss << n; return ss.str(); }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

struct Number // 23/11
{
    ll num;
    ll den;
    Number() : num(0), den(1) { }
    Number(ll n) : num(n), den(1) { }

    void reduce()
    {
        ll g = gcd(abs(num), den);
        num /= g;
        den /= g;
    }

    void print() const
    {
        if(den == 1) printf("%lld", num);
        else printf("%lld/%lld", num, den);
    }

    Number operator + (const Number& r) const
    {
        Number res;
        res.num = num * r.den + den * r.num;
        res.den = den * r.den;
        res.reduce();
        return res;
    }

    Number operator - (const Number& r) const
    {
        Number res;
        res.num = num * r.den - den * r.num;
        res.den = den * r.den;
        res.reduce();
        return res;
    }

    Number operator - (void) const
    {
        Number res = *this;
        res.num = -res.num;
        return res;
    }

    Number operator * (const Number& r) const
    {
        Number res;
        res.num = num * r.num;
        res.den = den * r.den;
        res.reduce();
        return res;
    }

    Number operator / (const Number& r) const
    {
        Number res;
        res.num = num * r.den;
        res.den = den * r.num;
        if(res.den < 0)
        {
            res.den = -res.den;
            res.num = -res.num;
        }
        res.reduce();
        return res;
    }

    Number& operator = (ll n)
    {
        num = n;
        den = 1;
        return *this;
    }

    bool operator == (const Number& r) const
    {
        return num * r.den == den * r.num;
    }

    bool operator == (int r) const
    {
        return num == den * r;
    }
};

struct Term //Ax + B
{
    Number A;
    Number B;
    Term() { }

    void show() const
    {
        A.print();
        printf("x + ");
        B.print();
        putchar('\n');
    }

    Term operator + (const Term& r) const
    {
        Term res;
        res.A = A + r.A;
        res.B = B + r.B;
        return res;
    }

    Term operator - (const Term& r) const
    {
        Term res;
        res.A = A - r.A;
        res.B = B - r.B;
        return res;
    }

    Term operator * (const Term& r) const
    {
        Term res;
        res.A = A * r.B + B * r.A;
        res.B = B * r.B;
        return res;
    }

    bool operator == (const Term& r) const
    {
        return A == r.A && B == r.B;
    }

};

void popuntil(const char* bad, stack<char>& op, stack<Term>& res)
{
    while(op.size())
    {
        char t = op.top();
        for(int i = 0; bad[i]; ++i)
        {
            if(t == bad[i]) return;
        }
        op.pop();

        Term b = res.top();
        res.pop();
        Term a = res.top();
        res.pop();
        if(t == '*') res.push(a * b);
        if(t == '+') res.push(a + b);
        if(t == '-') res.push(a - b);
    }
}

char* parsedigit(char* inp, ll& d)
{
    d = 0;
    do
    {
        d = d * 10 + *inp - '0';
        ++inp;
    }
    while(isdigit(*inp));
    return inp - 1;
}

Term evaluate(char* inp)
{
    stack<char> op;
    stack<Term> res;
    for( ; *inp; ++inp)
    {
        if(*inp == 'x')
        {
            Term t;
            t.A = 1LL;
            res.push(t);
        }
        else if(isdigit(*inp))
        {
            Term t;
            inp = parsedigit(inp, t.B.num);
            res.push(t);
        }
        else if(*inp == '(')
        {
            op.push(*inp);
        }
        else if(*inp == '*')
        {
            popuntil("+-(", op, res);
            op.push(*inp);
        }
        else if(*inp == ')' || *inp == '+' || *inp == '-')
        {
            popuntil("(", op, res);
            if(*inp == ')') op.pop();
            else op.push(*inp);
        }
    }

    popuntil("", op, res);
    return res.top();
}

int main()
{
    char inp[150];

    sf1(test);
    while(test--)
    {
        scanf(" %s", inp);
        printf("Case %d: ", cas++);

        char* part1 = strtok(inp, "=");
        char* part2 = strtok(NULL, "=");
        Term lhs = evaluate(part1);
        Term rhs = evaluate(part2);
        Term res = lhs - rhs;
        if(res.A == 0)
        {
            if(lhs == rhs)
                puts("infinitely many solutions");
            else
                puts("no solution");
        }
        else
        {
            (-res.B / res.A).print();
            putchar('\n');
        }
    }

    return 0;
}
