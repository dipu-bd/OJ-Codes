/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
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
typedef pair<int, int> pii;
typedef vector<int> vii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
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
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

struct fraction
{
    int num;
    int den;
    int mant;

    void normalize()
    {
        num += mant * den;
        int g = gcd(num, den);
        num /= g, den /= g;

        if(num > den)
        {
            mant = num / den;
            num %= den;
        }
    }

    fraction() : mant(0), num(0), den(1) { }

    fraction operator * (const fraction& b)
    {
        fraction res;
        res.den = den * b.den;
        res.num = (num + mant * den);
        res.num *= (b.num + b.mant * b.den);
        res.normalize();
        return res;
    }

    friend ostream& operator << (ostream& out, const fraction& f)
    {
        if(f.mant) out << f.mant;
        if(f.num || !f.mant)
        {
            if(f.mant) out << '-';
            out << f.num;
        }
        if(f.den > 1) out << '/' << f.den;

        return out;
    }
};

int main()
{
#ifdef LOCAL
    freopen("11148.inp", "r", stdin);
#endif // LOCAL

    char ch;
    fraction res;

    scanf("%d ", &test);
    while(test--)
    {
        res.num = 1;
        res.den = 1;
        res.mant = 0;

        while((ch = getchar()) != EOF)
        {
            if(ch == '\n') break;
            if(isdigit(ch))
            {
                fraction f;

                do
                {
                    f.num = f.num * 10 + ch - '0';
                }
                while(isdigit(ch = getchar()));

                if(ch == '-')
                {
                    f.mant = f.num;
                    f.num = 0;
                    while(isdigit(ch = getchar()))
                        f.num = f.num * 10 + ch - '0';
                }

                if(ch == '/')
                {
                    f.den = 0;
                    while(isdigit(ch = getchar()))
                        f.den = f.den * 10 + ch - '0';
                }

                f.normalize();
                res = res * f;
            }
        }

        cout << res << endl;
    }

    return 0;
}
