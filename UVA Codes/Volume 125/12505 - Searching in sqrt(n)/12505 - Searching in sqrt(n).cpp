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
#define debug1(a) cout << a << endl
#define debug2(a,b) cout << a << " " << b << endl
#define debug3(a,b,c) cout << a << " " << b << " " << c << endl
#define debug4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl
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
//variables and functions
const double EPS = 1E-10;
const double PI = 2.0 * acos(0.0);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> inline T lcm(T a, T b) { return a * (b / gcd(a, b)); }
template<typename T> T gcd_iter(T a, T b) { while(b) b ^= a ^= b ^= a %= b; return a; }
template<typename T> T power(T n, int p) { if(!p) return 1; else { T res = sqr(power(n, p >> 1)); if(p & 1) res *= n; return res; } }
template<typename T> T bigmod_iter(T b, T p, T m) { T r = 1; while(p > 0) { if(p & 1) r = (r * b) % m; p >>= 1; b = (b * b) % m; } return r; }
template<typename T> T bigmod(T n, int p, T m) { if(!p) return 1; else { T r = sqr(bigmod(n, p >> 1, m)) % m; if(p & 1) r = (r * n) % m; return r; } }
template<typename T> T exgcd(T a, T b, T& x, T& y) { if(!b) { x = 1; y = 0; return a; } else { T g = exgcd(b, a % b, y, x); y -= (a / b) * x; return g; } }
template<typename T> T modinv(T a, T m) { T x, y; exgcd(a, m, x, y); return pmod(x, m); }
/*------------------------------------------------------------------------------------*/

int test, cas = 1;

struct BITNUM
{
    string num;

    BITNUM() { *this = 0; }
    BITNUM(int n) { *this = n; }

    void reformat()
    {
        while(num.size() && *num.rbegin() == '0')
            num.erase(num.end() - 1);
        if(num.empty()) num.push_back('0');
        reverse(num.begin(), num.end());
    }

    BITNUM& operator = (int n)
    {
        num.clear();
        while(n > 0)
        {
            num.push_back((n & 1) + '0');
            n >>= 1;
        }
        reformat();
        return *this;
    }

    BITNUM operator << (int p) const
    {
        BITNUM res = *this;
        if(res.iszero()) return res;
        while(p--) res.num.push_back('0');
        return res;
    }

    BITNUM operator >> (int p) const
    {
        BITNUM res = *this;
        if(!p || res.iszero()) return res;
        if(res.num.size() <= p) res.num = "0";
        else res.num.erase(res.num.end() - p, res.num.end());
        return res;
    }

    bool operator < (const BITNUM& b) const
    {
        if(num.size() != b.num.size())
            return num.size() < b.num.size();
        return num < b.num;
    }

    BITNUM operator + (const BITNUM& b) const
    {
        BITNUM res;
        res.num = "";
        char carry = 0;
        int i = num.size() - 1;
        int j = b.num.size() - 1;
        while(i >= 0 || j >= 0 || carry)
        {
            carry += (i >= 0 ? num[i--] - '0' : 0) +
                     (j >= 0 ? b.num[j--] - '0' : 0);
            res.num.push_back((carry & 1) + '0');
            carry >>= 1;
        }
        res.reformat();
        return res;
    }

    BITNUM operator - (const BITNUM& b) const
    {
        BITNUM res;
        res.num = "";
        char carry = 0;
        int i = num.size() - 1;
        int j = b.num.size() - 1;
        while(i >= 0)
        {
            carry = (num[i--] - '0') - carry -
                    (j >= 0 ? b.num[j--] - '0' : 0);
            res.num.push_back(((carry + 2) & 1)  + '0');
            carry = (carry < 0);
        }
        res.reformat();
        return res;
    }

    bool iszero() const
    {
        return (num == "0");
    }

    friend ostream& operator << (ostream& out, const BITNUM& n)
    {
        out << n.num;
        return out;
    }

    int size() const
    {
        return num.size();
    }
};

int main()
{
    int n;
    string str;

    sf1(test);
    while(test--)
    {
        sf1(n);
        cin >> str;

        BITNUM num(n);
        BITNUM bit(1);
        BITNUM res(0);

        int dcpt = num.size() / 2 + (num.size() & 1);

        bit = bit << 40;
        while(num < bit)
            bit = bit >> 2;

        bit = bit << 250;
        num = num << 250;

        while(!bit.iszero())
        {
            BITNUM tmp = res + bit;
            if(num < tmp)
            {
                res = res >> 1;
            }
            else
            {
                num = num - tmp;
                res = (res >> 1) + bit;
            }
            bit = bit >> 2;
        }

        REP(i, 0, 110)
        {
            int pos = i + dcpt;
            if(res.num.substr(pos, str.size()) == str)
            {
                printf("%d\n", i);
                break;
            }
        }
    }

    return 0;
}
