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
template<typename T> inline T sqr(T n) { return n * n; }

int test, cas = 1;

#define SIZ 400010

vii coins;
int use[SIZ];
bool make[SIZ];

void precalc()
{
    REP(i, 1, 100)
    {
        int n = i * i * i;
        if(n > SIZ) break;
        coins.pb(n);
    }

    int sum = 0;
    REP(i, 1, 500)
    {
        sum += sqr(i);
        if(sum > SIZ) break;
        coins.pb(sum);
    }

    ssort(coins);
}

int bottomup()
{
    mem(use, 0x6f);
    use[0] = 0;
    make[0] = 1;
    loop(c, coins)
    {
        REP(i, *c, SIZ)
        {
            if(make[i - *c])
            {
                make[i] = true;
                use[i] = min(use[i - *c] + 1, use[i]);
            }
        }
    }
}

int main()
{
    precalc();
    bottomup();

    int n;
    while(scanf("%d", &n) == 1 && n > -1)
    {
        printf("%d\n", use[n]);
    }

    return 0;
}

