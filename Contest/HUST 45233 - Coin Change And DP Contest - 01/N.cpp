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
#define memsz(a,b,s) memset(a, b, sizeof(*a)*(s))
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
#define loop(it, cont) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, cont) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)

#define SIZ 100000
int use[SIZ + 10];
bool make[SIZ + 10];

int main()
{
    cin.sync();
    int test, cas = 1;

    int n, m;
    int coin[105];
    int avail[105];

    cin >> test;
    while(test--)
    {
        cin >> n >> m;
        REP(i, 0, n) cin >> coin[i];
        REP(i, 0, n) cin >> avail[i];

        clr(make);
        int cnt = 0;
        make[0] = 1;
        REP(i, 0, n)
        {
            memsz(use, 0, m + 5);
            REPE(j, coin[i], m)
            {
                int p = j - coin[i];
                if(make[p] && !make[j] && use[p] < avail[i])
                {
                    ++cnt;
                    make[j] = 1;
                    use[j] = use[p] + 1;
                }
            }
        }

        printf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}

