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

struct BTree
{
    int dat;
    BTree* left;
    BTree* right;

    BTree(int d = 0)
    {
        dat = d;
        left = 0;
        right = 0;
    }

    void clear()
    {
        if(left) { left->clear(); free(left); }
        if(right) { right->clear(); free(right); }
    }
};

BTree* build()
{
    char ch;
    scanf(" %c", &ch); //rem (
    scanf(" %c", &ch); //rem immediate )
    if(ch == ')') return 0;
    ungetc(ch, stdin);

    BTree* nod = new BTree();
    scanf(" %d", &nod->dat); //rem int
    nod->left = build(); //rem left child
    nod->right = build(); //rem righ child

    scanf(" %c", &ch); //rem )
    return nod;
}

bool contains(BTree* nod, int& n, int sum = 0)
{
    if(!nod) return 0;

    sum += nod->dat;

    if(!(nod->left || nod->right))
        return sum == n;

    return contains(nod->left, n, sum)
        || contains(nod->right, n, sum);
}

int main()
{
#ifdef LOCAL
    freopen("112.inp", "r", stdin);
#endif // LOCAL

    int n;
    while(scanf("%d", &n) != EOF)
    {
        BTree* tree = build();
        if(tree && contains(tree, n)) puts("yes");
        else puts("no");
        if(tree) { tree->clear(); free(tree); }
    }

    return 0;
}
