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
/*------------------------------------------------------------------------------------------------*/

int sum, limit;
vector<int> sn;
set<int> nums;

void print(set<int>& v)
{
    printf("%d\n", v.size());
    bool sp = false;
    loop(i, v)
    {
        if(sp) putchar(' ');
        else sp = true;
        printf("%d", *i);
    }
    putchar('\n');
}

bool push(int n, int t)
{
    if(n > limit) return 0;

    if(!nums.count(n))
    {
        nums.insert(n);
        return 1;
    }

    if(t <= limit)
    {
        if(push(n | t, t << 1)) return 1;
        if(push(n, t << 1)) return 1;
    }

    return 0;
}

bool build()
{
    nums.clear();

    loop(i, sn)
    {
        if(!push(*i, (*i) << 1)) return 0;
    }

    return 1;
}

bool findsum(int cur, int t, int cnt = 0)
{
    if(cur == sum) return build();

    for(; t > 0; t >>= 1)
    {
        if(cur + t <= sum)
        {
            sn.pb(t);
            if(findsum(cur + t, t, 0)) return 1;
            sn.pp();
        }
    }

    return 0;
}

int main()
{
    scanf("%d %d", &sum, &limit);

    int t = 1;
    while((t << 1) <= limit) t <<= 1;

    if(!findsum(0, t))
        printf("-1\n");
    else
        print(nums);

    return 0;
}

