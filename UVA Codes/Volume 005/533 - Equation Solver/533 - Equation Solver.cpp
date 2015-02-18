/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
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
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
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
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct Number
{
    //format : ax + b
#define T int

    T a;
    T b;

    Number(int x = 0, int n = 0) : a(x), b(n) { }

    Number operator + (const Number& r) const
    {
        Number res;
        res.a = a + r.a;
        res.b = b + r.b;
        return res;
    }
    Number operator - (const Number& r) const
    {
        Number res;
        res.a = a - r.a;
        res.b = b - r.b;
        return res;
    }
    Number operator * (const Number& r) const
    {
        Number res;
        res.a = a * r.b + b * r.a;
        res.b = b * r.b;
        return res;
    }
};

int len;
char inp[120];
vector<char> ops;
vector<Number> nums;

void pickall(char ch)
{
    while(ops.size())
    {
        char p = ops.back();
        if(p == '(') break;
        ops.pp();

        int l = nums.size() - 1;
        if(p == '+')
            nums[l - 1] = nums[l - 1] + nums[l];
        else if(p == '-')
            nums[l - 1] = nums[l - 1] - nums[l];
        else if(p == '*')
            nums[l - 1] = nums[l - 1] * nums[l];
        nums.pp();
    }

    if(ch == ')') ops.pp();
    else ops.pb(ch);
}

void print()
{
    loop(i, ops) printf("%c", *i);
    putchar(' ');
    loop(i, nums) printf("%dx%d ", i->a, i->b);
    puts("");
}

Number evaluate(int i, int j)
{
    //clear previous
    ops.clear();
    nums.clear();

    //calculate
    ops.pb('(');
    REPE(k, i, j)
    {
        // x | digits | * | + | - | ( | )
        if(inp[k] == 'x')
        {
            nums.pb(Number(1, 0));
        }
        else if(inp[k] == '(' || inp[k] == '*')
        {
            ops.pb(inp[k]);
        }
        else if(isdigit(inp[k]))
        {
            int x;
            sscanf(inp + k, "%d", &x);
            nums.pb(Number(0, x));
            while(k <= j && isdigit(inp[k])) ++k;
            --k;
        }
        else if(inp[k] == '+' || inp[k] == '-' || inp[k] == ')')
        {
            pickall(inp[k]);
        }
    }

    pickall(')');
    return nums[0];
}

int main()
{
    while(gets(inp))
    {
        //print new line between cases
        if(cas > 1) putchar('\n');

        //last index of string
        len = strlen(inp) - 1;

        //Equation := Expression '=' Expression
        //find equal sign
        int eq = 0;
        while(eq <= len)
        {
            if(inp[eq] == '=') break;
            ++eq;
        }

        //evaluate two expression
        Number left = evaluate(0, eq - 1);
        Number right = evaluate(eq + 1, len);
        Number tot = left - right;

        printf("Equation #%d\n", cas++);
        if(tot.a == tot.b) //infinite solutions
        {
            printf("Infinitely many solutions.\n");
        }
        else if(tot.a == 0) //no solution
        {
            printf("No solution.\n");
        }
        else //print solution
        {
            double x = -(double)tot.b / tot.a;
            printf("x = %.6lf\n", x);
        }
    }

    return 0;
}
