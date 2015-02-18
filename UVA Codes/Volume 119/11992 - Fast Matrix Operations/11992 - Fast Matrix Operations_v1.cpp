/*=================================
UVA 11992 - Fast Matrix Operations
Algorithm : Segment Tree
/\u7h0r : 5ud!p70 ch@ndr@ d@5
 =================================*/
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

struct elem
{
    int v;
    int x;
    int sum;
    int mini;
    int maxi;
    elem(int mn = 0, int mx = 0) : v(0), x(0), sum(0), mini(mn), maxi(mx) { }

    void set(const int& p) { if(p) x = p, v = 0; }
    void add(const int& p) { v += p; }

    void operator += (const elem& r)
    {
        sum += r.sum;
        if(r.mini < mini) mini = r.mini;
        if(r.maxi > maxi) maxi = r.maxi;
    }
};

elem* tree;
int row, col;

inline void relax(const int& nod, const int& b, const int& e, const int& m, const int& l, const int& r)
{
    int x = tree[nod].x;
    int v = tree[nod].v;
    tree[nod].x = 0;
    tree[nod].v = 0;

    if(x)
    {
        tree[l].set(x);
        tree[l].sum = x * (m - b + 1);
        tree[l].mini = x;
        tree[l].maxi = x;

        tree[r].set(x);
        tree[r].sum = x * (e - m);
        tree[r].mini = x;
        tree[r].maxi = x;
    }
    if(v)
    {
        tree[l].add(v);
        tree[l].sum += v * (m - b + 1);
        tree[l].mini += v;
        tree[l].maxi += v;

        tree[r].add(v);
        tree[r].sum += v * (e - m);
        tree[r].mini += v;
        tree[r].maxi += v;
    }
}

void update(int nod, int b, int e, int i, int j, const int& type, const int& v)
{
    if(i <= b && e <= j)
    {
        if(type == 1) //add
        {
            tree[nod].add(v);
            tree[nod].sum += v * (e - b + 1);
            tree[nod].mini += v;
            tree[nod].maxi += v;
        }
        else //set
        {
            tree[nod].set(v);
            tree[nod].sum = v * (e - b + 1);
            tree[nod].mini = v;
            tree[nod].maxi = v;
        }
        return;
    }

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    relax(nod, b, e, m, l, r); //relax current node

    if(i <= m) update(l, b, m, i, j, type, v);
    if(j > m) update(r, m + 1, e, i, j, type, v);

    tree[nod].sum = tree[l].sum + tree[r].sum;
    tree[nod].mini = min(tree[l].mini, tree[r].mini);
    tree[nod].maxi = max(tree[l].maxi, tree[r].maxi);
    //printf("[%d = %d %d %d]\n", nod, tree[nod].sum, tree[nod].mini, tree[nod].mini);
}

elem query(int nod, int b, int e, int i, int j)
{
    if(i <= b && e <= j) return tree[nod];

    int m = (b + e) >> 1;
    int l = nod << 1;
    int r = l + 1;

    relax(nod, b, e, m, l, r); //relax current node

    elem res(INT_MAX, INT_MIN);
    if(i <= m) res += query(l, b, m, i, j);
    if(j > m) res += query(r, m + 1, e, i, j);

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("fsmall.in", "r", stdin);
    freopen("fsmall.out", "w", stdout);
#endif // LOCAL

    int q, b, e, v, x;
    int t, x1, x2, y1, y2;
    while(scanf("%d %d %d", &row, &col, &q) != EOF)
    {
        b = 1;
        e = row * col;
        if(tree) delete tree;
        tree = new elem[e << 2];

        while(q--)
        {
            scanf("%d", &t);
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

            if(t == 3)
            {
                elem res(INT_MAX, INT_MIN);

                x = col * (x1 - 2);
                REPE(i, x1, x2)
                {
                    x += col;
                    res += query(1, b, e, x + y1, x + y2);
                }

                printf("%d %d %d\n", res.sum, res.mini, res.maxi);
            }
            else
            {
                scanf("%d", &v);

                x = col * (x1 - 2);
                REPE(i, x1, x2)
                {
                    x += col;
                    update(1, b, e, x + y1, x + y2, t, v);
                }
            }
        }
    }

    return 0;
}
