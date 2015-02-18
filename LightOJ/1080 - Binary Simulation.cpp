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

#define SIZ 100005

char inp[SIZ];
char tree[SIZ << 2];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node] = (inp[b] == '1');
        return;
    }

    int m = (b + e) / 2;
    build(2 * node, b, m);
    build(2 * node + 1, m + 1, e);
    tree[node] = 0;
}

void update(int node, int b, int e, int i, int j)
{
    if(b >= i && e <= j)
    {
        tree[node] = !tree[node];
        return;
    }

    int m = (b + e) / 2;
    if(i <= m) update(2 * node, b, m, i, j);
    if(j > m) update(2 * node + 1, m + 1, e, i, j);
}

void query(int node, int b, int e, int i, char carry = 0)
{
    if(b >= i && e <= i)
    {
        carry = carry ^ tree[node];
        printf("%d\n", carry);
        return;
    }

    int m = (b + e) / 2;
    carry = carry ^ tree[node];
    if(i <= m) query(2 * node, b, m , i, carry);
    else query(2 * node + 1, m + 1, e, i, carry);
}

int main()
{
    int test, cas = 1;

    char ch;
    int n, q, i, j;

    scanf("%d", &test);
    while(test--)
    {
        //get input
        scanf(" %s", inp + 1);

        //build tree
        n = strlen(inp + 1);
        build(1, 1, n);

        //get queries
        scanf("%d", &q);
        printf("Case %d:\n", cas++);
        while(q--)
        {
            scanf(" %c", &ch);
            if(ch == 'I')
            {
                scanf("%d %d", &i, &j);
                update(1, 1, n, i, j);
            }
            else
            {
                scanf("%d", &i);
                query(1, 1, n, i);
            }
        }
    }

    return 0;
}

