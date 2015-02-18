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

#define SIZ 100005

int ind;
int test, cas = 1;
int arr[SIZ];
pii range[SIZ];
int tree[SIZ << 2];

void build(int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod] = range[b].sc - range[b].fr + 1;
        return;
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    build(l, b, m);
    build(r, 1 + m, e);

    tree[nod] = max(tree[l], tree[r]);
}

int query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j)
    {
        return tree[nod];
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    int res = 0;
    if(i <= m) res = max(res, query(l, b, m, i, j));
    if(j > m) res = max(res, query(r, 1 + m, e, i, j));

    return res;
}

int getmax(int x, int y)
{
    if(x > y) swap(x, y);

    int i = arr[x];
    int j = arr[y];
    if(i == j) return y - x + 1;

    int left = range[i].sc - x + 1;
    int right = y - range[j].fr + 1;
    if(i + 1 == j) return max(left, right);

    int mid = query(1, 1, ind, i + 1, j - 1);
    return max(left, max(right, mid));
}

int main()
{
    #ifdef LOCAL
    freopen("11235.inp", "r", stdin);
    #endif // LOCAL

    int n, q, x, y;
    while(sf1(n) == 1 && n)
    {
        sf1(q);

        ind = 0;
        int cur, pb, pe;
        REPE(i, 1, n)
        {
            sf1(x);
            if(i == 1 || cur != x)
            {
                cur = x;
                ++ind;
                range[ind].fr = i;
            }
            range[ind].sc = i;
            arr[i] = ind;
        }

        build(1, 1, ind);

        while(q--)
        {
            sf2(x, y);
            int res = getmax(x, y);
            printf("%d\n", res);
        }
    }

    return 0;
}
