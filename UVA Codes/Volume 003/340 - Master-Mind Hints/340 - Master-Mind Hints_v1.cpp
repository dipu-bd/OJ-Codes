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

#define SIZ 1010

int len;
int  code[SIZ];
int guess[SIZ];
bool took1[SIZ];
bool took2[SIZ];

int main()
{
#ifdef LOCAL
    freopen("340.inp", "r", stdin);
#endif // LOCAL

    int strong, weak;

    while(scanf("%d", &len) != EOF)
    {
        if(len == 0) break;

        REP(i, 0, len) scanf("%d ", &code[i]);

        printf("Game %d:\n", cas++);
        while(true)
        {
            bool zero = 0;
            REP(i, 0, len)
            {
                scanf("%d ", &guess[i]);
                if(!guess[i]) zero = 1;
            }
            if(zero) break;

            clr(took1);
            clr(took2);
            //find strongs
            strong = 0;
            REP(i, 0, len)
            {
                if(code[i] == guess[i])
                {
                    took1[i] = 1;
                    took2[i] = 1;
                    ++strong;
                }
            }
            //find weaks
            weak = 0;
            REP(i, 0, len)
            {
                if(took1[i]) continue;
                REP(j, 0, len)
                {
                    if(!took2[j] && code[i] == guess[j])
                    {
                        took1[i] = 1;
                        took2[j] = 1;
                        ++weak;
                        break;
                    }
                }
            }

            //show result
            printf("    (%d,%d)\n", strong, weak);
        }
    }

    return 0;
}
