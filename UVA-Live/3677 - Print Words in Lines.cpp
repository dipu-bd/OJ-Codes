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

#define SIZ 10010
int n, m;
int arr[SIZ];
ll save[SIZ][105];
int calc[SIZ][105];

ll recur(int l = 0, int t = 0)
{
    if(l == n) return sqr((ll)m - t);

    ll& dp = save[l][t];
    int& dpc = calc[l][t];
    if(dpc == cas) return dp;

    dpc = cas;
    dp = LONG_LONG_MAX;
    if(t > 0) dp = recur(l, 0) + sqr((ll)m - t);
    int q = (t == 0) ? arr[l] : t + 1 + arr[l];
    if(q <= m) dp = min(dp, recur(l + 1, q));

    return dp;
}


int main()
{
    scanf("%d ", &test);
    while(test--)
    {
        scanf("%d %d", &m, &n);
        REP(i, 0, n)
        {
            scanf("%d", arr + i);
        }

        ++cas;
        ll res = recur();
        printf("%lld\n", res);
    }

    return 0;
}


