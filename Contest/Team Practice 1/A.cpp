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
/*------------------------------------------------------------------------------------------------*/

int test, cas = 1;

#define MAX 100002
int arr[MAX];
ll tree1[MAX << 2];
ll tree2[MAX << 2];

void build(ll* tree, int nod, int b, int e)
{
    if(b == e)
    {
        tree[nod] = arr[b];
        return;
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;
    build(tree, l, b, m);
    build(tree, r, m + 1, e);
    tree[nod] = tree[l] + tree[r];
}

ll query(ll* tree, int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j) return tree[nod];

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    ll res = 0;
    if(i <= m) res += query(tree, l, b, m, i, j);
    if(j > m) res += query(tree, r, m + 1, e, i, j);

    return res;
}

int main()
{
    #ifdef LOCAL
    //freopen("", "r", stdin);
    #endif // LOCAL

    int n, m;
    scanf("%d", &n);

    REPE(i, 1, n) scanf("%d", arr + i);
    build(tree1, 1, 1, n);

    sort(arr + 1, arr + n + 1);
    build(tree2, 1, 1, n);

    scanf("%d", &m);
    int t, l, r;
    while(m--)
    {
        scanf("%d %d %d", &t, &l, &r);

        ll res = 0;
        if(t == 1) res = query(tree1, 1, 1, n, l, r);
        else res = query(tree2, 1, 1, n, l, r);

        printf("%I64d\n", res);
    }

    return 0;
}

