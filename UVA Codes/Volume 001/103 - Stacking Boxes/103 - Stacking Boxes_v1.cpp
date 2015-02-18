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

struct Box
{
    int dim;
    int indx;
    int data[12];

    void scan(int n, int p)
    {
        dim = n;
        indx = p;
        REP(i, 0, n) scanf("%d", data + i);
        sort(data, data + n);
    }

    void print()
    {
        printf("%d : ", indx);
        REP(i, 0, dim) printf("%d ", data[i]);
        putchar('\n');
    }

    bool operator < (const Box& b) const
    {
        REP(i, 0, dim)
        {
            if(data[i] != b.data[i])
                return data[i] < b.data[i];
        }

        return indx < b.indx;
    }

    bool fits(const Box& b)
    {
        REP(i, 0, dim)
        {
            if(data[i] >= b.data[i]) return 0;
        }

        return 1;
    }
};

int k, n;
Box seq[35];
int save[35][35];
vii res;

int lis(int i = 1, int p = 0)
{
    if(i > k) return 0;

    int& dp = save[i][p];
    if(dp != -1) return dp;

    dp = lis(i + 1, p);
    if(seq[p].fits(seq[i]))
        dp = max(dp, 1 + lis(i + 1, i));

    return dp;
}

void printpath(int i = 1, int p = 0)
{
    if(i > k) return;

    if(lis(i, p) == lis(i + 1, p))
    {
        printpath(i + 1, p);
        return;
    }

    //seq[i].print();

    res.pb(seq[i].indx);
    printpath(i + 1, i);
}

int main()
{
#ifdef LOCAL
    freopen("103.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%d %d", &k, &n) != EOF)
    {
        REPE(i, 1, k) seq[i].scan(n, i);
        sort(seq + 1, seq + k + 1);

        //putchar('\n');
        //REPE(i, 1, k) seq[i].print();

        //get lcs
        mem(save, -1);
        int l = lis();
        printf("%d\n", l);

        //print path
        res.clear();
        printpath();

        //show result
        loop(i, res)
        {
            if(i == res.begin()) printf("%d", *i);
            else printf(" %d", *i);
        }
        putchar('\n');
    }

    return 0;
}
