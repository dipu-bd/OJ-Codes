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

struct BinTree
{
    char data;
    BinTree* left;
    BinTree* right;

    BinTree(char d = 0)
    {
        data = d;
        left = 0;
        right = 0;
    }

    void clear()
    {
        if(left) { left->clear(); free(left); }
        if(right) { right->clear(); free(right); }
    }
};

char in[30];
char pre[30];

BinTree* build(int pi, int pj, int ii, int ij)
{
    if(pi > pj || ii > ij) return 0;

    int k = ii, len;
    while(in[k] != pre[pi]) ++k;
    len = k - ii;

    //printf("%d %d %d %d\n", pi, pj, ii, ij);

    BinTree* nod = new BinTree(pre[pi]);
    nod->left = build(pi + 1, pi +  len, ii, ii + len - 1);
    nod->right = build(pi + len + 1, pj, ii + len + 1, ij);

    return nod;
}

void post(BinTree* nod)
{
    if(!nod) return;
    post(nod->left);
    post(nod->right);
    putchar(nod->data);
}

int main()
{
#ifdef LOCAL
    freopen("536.inp", "r", stdin);
#endif // LOCAL

    while(scanf(" %s %s", pre, in) != EOF)
    {
        int len = strlen(pre) - 1;
        BinTree* tree = build(0, len, 0, len);
        post(tree);
        putchar('\n');
        tree->clear();
    }

    return 0;
}
