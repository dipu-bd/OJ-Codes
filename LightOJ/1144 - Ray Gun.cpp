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
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------------------------*/

#define MAX 1000002

char miu[MAX + 5];

void update(int i)
{
    miu[i] = -1;
    for(int j = i + i; j <= MAX; j += i)
    {
        if(miu[j])
        {
            miu[j] = (miu[j] == -1) ? 1 : -1;
            if(!((j / i) % i)) miu[j] = 0;
        }
    }
}

void sieve()
{
    mem(miu, 5);
    miu[1] = 1;

    update(2);

    for(int i = 3; i < MAX; i += 2)
        if(miu[i] == 5) update(i);
}

int main()
{
    sieve();
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        int m, n, p;
        scanf("%d %d", &m, &n);

        ll res = 0;
        if(m == 0 && n == 0) res = 0;
        else if(m == 0 || n == 0) res = 1;
        else
        {
            res = 2;
            p = min(m, n);
            REPE(i, 1, p) res += (ll)miu[i] * (m / i) * (n / i);
        }

        printf("Case %d: %lld\n", cas++, res);
    }

    return 0;
}

