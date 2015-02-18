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
#define loop(it, x) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, x) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)

struct node
{
    int has;
    int next[2];
} tree[100000];

int main()
{
    #ifdef LOCAL
    freopen("11488.inp", "r", stdin);
    #endif // LOCAL

    int test;
    int n, siz;
    char inp[250];

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);

        siz = 0;
        clr(tree);
        int goodness = 0;
        while(n--)
        {
            scanf(" %s", inp);

            int tmp = 0, i;
            for(i = 0; inp[i]; ++i)
            {
                node& tn = tree[tmp];

                int id = inp[i] - '0';
                if(!tn.next[id]) tn.next[id] = ++siz;

                ++tn.has;
                tmp = tn.next[id];
                goodness = max(goodness, i * tn.has);
            }
            ++tree[tmp].has;
            goodness = max(goodness, i * tree[tmp].has);
        }

        printf("%d\n", goodness);
    }

    return 0;
}
