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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(it, cont) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, cont) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)

struct
{
    ll prop;
    ll sum;
} tree[400005];

void update(int node, int b, int e, int i, int j, ll v)
{
    if(b >= i && e <= j)
    {
        tree[node].prop += v;
        tree[node].sum += (ll)v * (e - b + 1);
        return;
    }

    int left, right, mid;
    left = node << 1;
    right = left + 1;
    mid = (b + e) >> 1;
    if(i <= mid) update(left, b, mid, i, j, v);
    if(j > mid) update(right, mid + 1, e, i, j, v);
    tree[node].sum = tree[left].sum + tree[right].sum +
                     (ll)(e - b + 1) * tree[node].prop;
}

ll query(int node, int b, int e, int i, int j, ll carry = 0)
{
    if(b >= i && e <= j)
    {
        return tree[node].sum + (ll)(e - b + 1) * carry;
    }

    int left, right, mid;
    left = node << 1;
    right = left + 1;
    mid = (b + e) >> 1;

    ll sum = 0;
    carry += tree[node].prop;
    if(i <= mid) sum += query(left, b, mid, i, j, carry);
    if(j > mid) sum += query(right, mid + 1, e, i, j, carry);
    return sum;
}

int main()
{
    int test, cas = 1;
    int n, q, i, j, x;

    scanf("%d", &test);
    while(test--)
    {
        clr(tree);
        scanf("%d %d", &n, &q);

        printf("Case %d:\n", cas++);
        while(q--)
        {
            scanf("%d", &x);
            if(x == 0)
            {
                scanf("%d %d %d", &i, &j, &x);
                update(1, 1, n, i + 1, j + 1, x);
            }
            else
            {
                scanf("%d %d", &i, &j);
                ll s = query(1, 1, n, i + 1, j + 1);
                printf("%lld\n", s);
            }
        }
    }

    return 0;
}

