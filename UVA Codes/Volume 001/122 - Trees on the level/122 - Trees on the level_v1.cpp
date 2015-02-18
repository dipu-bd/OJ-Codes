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

struct elem
{
    bool isin;
    int isok;
    int data;
    int left;
    int right;
};

int sz;
char seq[300];
elem tree[300];
vii nodes[300];

void push(int nod, int dat, char* seq)
{
    if(!*seq)
    {
        ++tree[nod].isok;
        tree[nod].isin = 1;
        tree[nod].data = dat;
        return;
    }

    if(*seq == 'L')
    {
        tree[nod].isin = 1;
        if(!tree[nod].left) tree[nod].left = sz++;
        push(tree[nod].left, dat, seq + 1);
    }
    else
    {
        tree[nod].isin = 1;
        if(!tree[nod].right) tree[nod].right = sz++;
        push(tree[nod].right, dat, seq + 1);
    }
}

bool traverse(int nod, int n = 0)
{
    if(!tree[nod].isin) return true;
    if(tree[nod].isok != 1) return false;

    nodes[n].pb(tree[nod].data);

    bool val = 1;
    if(tree[nod].left) val = val && traverse(tree[nod].left, n + 1);
    if(tree[nod].right) val = val && traverse(tree[nod].right, n + 1);

    return val;
}

int main()
{
#ifdef LOCAL
    freopen("122.inp", "r", stdin);
#endif // LOCAL

    while(!feof(stdin))
    {
        int n;
        char ch;
        sz = 2;
        clr(tree);
        while(scanf(" %c ", &ch) != EOF)
        {
            scanf(" %c ", &ch);
            if(ch == ')') break;

            ungetc(ch, stdin);

            n = 0;
            while((ch = getchar()) != ',')
            {
                n = n * 10 + ch - '0';
            }

            int i = 0;
            while((ch = getchar()) != ')')
            {
                if(ch == ')') break;
                if(ch == 'L' || ch == 'R') seq[i++] = ch;
            }
            seq[i] = 0;

            push(1, n, seq);
        }


        bool valid = traverse(1);

        if(valid) printf("%d", nodes[0][0]);
        nodes[0].clear();
        REP(i, 1, sz)
        {
            if(valid) loop(p, nodes[i]) printf(" %d", *p);
            nodes[i].clear();
        }

        if(!valid) printf("not complete");

        putchar('\n');

    }

    return 0;
}
