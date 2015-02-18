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

int t;
int indx[1010];
int start, stop;
int team[1000005];
queue<int> tq[1010];
const int MOD = 1003;

void enqueue(int x)
{
    int ti = team[x];
    int& p = indx[ti];
    if(p == 0)
    {
        //set index
        p = stop;
        //clear prev
        while(tq[p].size()) tq[p].pop();
        //increase pos
        stop = 1 + (stop % MOD);
    }

    tq[p].push(x);
    //printf("%d %d %d\n", p, start, stop);
}

void dequeue()
{
    int x;
    if(!tq[start].empty())
    {
        x = tq[start].front();
        printf("%d\n", x);
        tq[start].pop();
    }

    if(tq[start].empty())
    {
        indx[team[x]] = 0;
        if(start == stop) start = stop = 1;
        else start = 1 + (start % MOD);
    }
}

int main()
{
#ifdef LOCAL
    freopen("540.inp", "r", stdin);
#endif // LOCAL

    char inp[20];
    while(scanf("%d", &t) != EOF && t)
    {
        //set start pos
        clr(indx);
        start = stop = 1;

        //get teams
        int n, x;
        REP(i, 0, t)
        {
            scanf("%d", &n);
            while(n--)
            {
                scanf("%d", &x);
                team[x] = i;
            }
        }

        //take input and show result
        printf("Scenario #%d\n", cas++);
        while(scanf(" %s", inp) != EOF)
        {
            if(inp[0] == 'S') break;
            if(inp[0] == 'D') dequeue();
            if(inp[0] == 'E')
            {
                scanf("%d", &x);
                enqueue(x);
            }
        }
        putchar('\n');
    }

    return 0;
}
