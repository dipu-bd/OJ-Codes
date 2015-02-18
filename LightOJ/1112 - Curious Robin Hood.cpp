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

#define MAX 100000

int sack[MAX + 10];
int tree[4 * MAX + 10];

void build(int node, int from, int to)
{
    if(from == to)
    {
        tree[node] = sack[to];
        return;
    }

    int mid = (from + to) / 2;
    build(2 * node, from, mid);
    build(2 * node + 1, mid + 1, to);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

void update(int node, int from, int to, int i, int val)
{
    if(i < from || i > to) return;
    if(i == from && i == to)
    {
        if(val < 0)
        {
            printf("%d\n", tree[node]);
            tree[node] = 0;
        }
        else
        {
            tree[node] += val;
        }
        return;
    }

    int mid = (from + to) / 2;
    update(2 * node, from, mid, i, val);
    update(2 * node + 1, mid + 1, to, i, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
    return;
}

int query(int node, int from, int to, int i, int j)
{
    if(from >= i && to <= j) return tree[node];

    int mid, sum = 0;
    mid = (from + to) / 2;
    if(i <= mid) sum += query(2 * node, from, mid, i, j);
    if(j > mid) sum += query(2 * node + 1, mid + 1, to, i, j);
    return sum;
}

int main()
{
    int test, cas = 1;
    int n, q, i, j, x;

    scanf("%d", &test);
    while(test--)
    {
        //get array
        scanf("%d %d", &n, &q);
        for(i = 1; i <= n; ++i)
            scanf("%d", &sack[i]);

        //build segment tree
        build(1, 1, n);

        //take query and update
        printf("Case %d:\n",  cas++);
        while(q--)
        {
            scanf("%d", &x);
            if(x == 1)
            {
                scanf("%d", &i);
                update(1, 1, n, i + 1, -1);
            }
            else if(x == 2)
            {
                scanf("%d %d", &i, &x);
                update(1, 1, n, i + 1, x);
            }
            else
            {
                scanf("%d %d", &i, &j);
                x = query(1, 1, n, i + 1, j + 1);
                printf("%d\n", x);
            }
        }
    }

    return 0;
}

