/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 METHOD : Segment Tree
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

#define SIZ 250000

struct elem
{
    int v;   //set with v
    bool ps; //pending set
    int stl; //st count
    int ndl; //nd count
    ll stsum; //sum of st vals
    ll ndsum; //sum of nd vals
    ll sum;  //sum of all child

    elem()
    {
        v = 0;
        sum = 0;
        clear();
    }

    void A(int _st)
    {
        ++stl;
        stsum += _st;
    }
    void B(int _nd)
    {
        ++ndl;
        ndsum += _nd;
    }
    void C(int n)
    {
        v = n;
        ps = 1;
        stl = 0;
        ndl = 0;
        stsum = 0;
        ndsum = 0;
    }

    void clear()
    {
        ps = 0;
        stl = 0;
        ndl = 0;
        stsum = 0;
        ndsum = 0;
    }
    void setvsum(int b, int e)
    {
        sum = (ll)(e - b + 1) * v;
    }
    void addstsum(int b, int e, int l, ll s)
    {
        sum += (ll)(e - b + 1) * (-2 * s + l * (b + e + 2)) / 2;
    }
    void addndsum(int b, int e, int l, ll s)
    {
        sum += (ll)(e - b + 1) * (2 * s - l * (b + e - 2)) / 2;
    }
};

elem tree[SIZ << 2];

inline void relax(int nod, int l, int r, int b, int e, int m)
{
    if(tree[nod].ps)
    {
        tree[l].C(tree[nod].v);
        tree[l].setvsum(b, m);
        tree[r].C(tree[nod].v);
        tree[r].setvsum(1 + m, e);
    }

    if(tree[nod].stl)
    {
        tree[l].stl += tree[nod].stl;
        tree[l].stsum += tree[nod].stsum;
        tree[l].addstsum(b, m, tree[nod].stl, tree[nod].stsum);
        tree[r].stl += tree[nod].stl;
        tree[r].stsum += tree[nod].stsum;
        tree[r].addstsum(1 + m, e, tree[nod].stl, tree[nod].stsum);
    }

    if(tree[nod].ndl)
    {
        tree[l].ndl += tree[nod].ndl;
        tree[l].ndsum += tree[nod].ndsum;
        tree[l].addndsum(b, m, tree[nod].ndl, tree[nod].ndsum);
        tree[r].ndl += tree[nod].ndl;
        tree[r].ndsum += tree[nod].ndsum;
        tree[r].addndsum(1 + m, e, tree[nod].ndl, tree[nod].ndsum);
    }

    tree[nod].clear();
}

void update(int nod, int b, int e, int i, int j, char typ, int v = 0)
{
    if(i <= b && e <= j)
    {
        if(typ == 'A')
        {
            tree[nod].A(i);
            tree[nod].addstsum(b, e, 1, i);
        }
        if(typ == 'B')
        {
            tree[nod].B(j);
            tree[nod].addndsum(b, e, 1, j);
        }
        if(typ == 'C')
        {
            tree[nod].C(v);
            tree[nod].setvsum(b, e);
        }

        return;
    }

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, l, r, b, e, m);

    if(i <= m) update(l, b, m, i, j, typ, v);
    if(j > m) update(r, 1 + m, e, i, j, typ, v);

    tree[nod].sum = tree[l].sum + tree[r].sum;
}

ll query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j) return tree[nod].sum;

    int l = nod << 1;
    int r = l + 1;
    int m = (b + e) >> 1;

    relax(nod, l, r, b, e, m);

    ll sum = 0;
    if(i <= m) sum += query(l, b, m, i, j);
    if(j > m) sum += query(r, 1 + m, e, i, j);

    return sum;
}

int main()
{
#ifdef LOCAL
    freopen("12436.inp", "r", stdin);
#endif // LOCAL

    int n;
    scanf("%d", &n);

    char ch;
    int x, y, v;
    while(n--)
    {
        scanf(" %c %d %d", &ch, &x, &y);
        if(ch == 'S')
        {
            ll sum = query(1, 1, SIZ, x, y);
            printf("%lld\n", sum);
        }
        else
        {
            if(ch == 'C') scanf("%d", &v);
            update(1, 1, SIZ, x, y, ch, v);
        }
    }

    return 0;
}
