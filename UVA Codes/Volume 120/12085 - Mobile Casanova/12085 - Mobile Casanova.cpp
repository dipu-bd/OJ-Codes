//c headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
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
using namespace std;

const double EPS = 1E-12;
const double PI = 2.0 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;

#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a,0,sizeof(a))
#define mem(a,b) memset(a,b,sizeof(a))
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define ins insert
#define mp make_pair
#define IT iterator
#define ssort(v) stable_sort(v.begin(), v.end())
#define all(v) (v.begin(), v.end())
#define loop(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i = (x).rbegin(); i != (x).rend(); ++i)
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define LB lower_bound
#define UB upper_bound
template<typename T> inline T sqr(T n)
{
    return n * n;
}
template<typename T> inline T pmod(T n, T m)
{
    return ((n % m + m) % m);
}
template<typename T> inline T power(T n, int p)
{
    if(!p)
    {
        return 1;
    }
    else
    {
        T res = sqr(power(n, p >> 1));
        if(p & 1)
        {
            res *= n;
        }
        return res;
    }
}

int test, cas = 1;

int n;
string init, last, cur;

bool increase(const string& a, const string& b)
{
    ll p, q;
    sscanf(a.data(), "%lld", &p);
    sscanf(b.data(), "%lld", &q);
    return p + 1 == q;
}

void print()
{

    cout << init;
    REP(i, 0, last.size())
    {
        if(last[i] != init[i])
        {
            cout << "-" << last.substr(i, last.size() - i);
            break;
        }
    }
    cout << endl;
}

int main()
{
#ifdef DIPU
    freopen("F.txt", "r", stdin);
#endif // DIPU


    while(scanf("%d", &n) == 1 && n)
    {
        cin >> init;
        last = init;

        printf("Case %d:\n", cas++);
        REP(i, 1, n)
        {
            cin >> cur;
            if(increase(last, cur))
            {
                last = cur;
                continue;
            }

            print();
            init = cur;
            last = cur;
        }

        print();
        cout << endl;
    }

    return 0;
}

