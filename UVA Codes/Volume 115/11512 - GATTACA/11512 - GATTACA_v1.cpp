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

int len;
char seq[1010];
char save1[125000001];
char save2[125000001];
char has[125000001];

bool GET(char* arr, int p) { return arr[p >> 3] & (1 << (p & 7)); }
void SET(char* arr, int p) { arr[p >> 3] |= (1 << (p & 7)); }

int match(int i, int j, int l)
{
    if(l == 1) return seq[i] - seq[j];

    int p = (i * len + j) * len + l;
    if(GET(has, p)) return (GET(save1, p) - GET(save2, p));

    int m = l >> 1;
    char dp = match(i, j, m); //first part
    if(!dp) dp = match(i + m, j + m, l - m); //second part

    SET(has, p);
    if(dp > 0) SET(save1, p);
    if(dp < 0) SET(save2, p);

    return dp;
}

pii maxsegment()
{
    int ml, sb;
    bool found = false;

    RREPE(l, len - 1, 1)
    {
        RREPE(j, len - l, 0)
        {
            RREPE(i, j - 1, 0)
            {
                if(!match(i, j, l))
                {
                    if(found)
                    {
                        if(match(i, sb, l) < 0) sb = i;
                    }
                    else
                    {
                        sb = i;
                        found = true;
                    }
                    break;
                }
            }
        }

        if(found) return mp(sb, l);
    }

    return mp(-1, -1);
}

int repcount(int i, int l)
{
    int cnt = 0;
    RREPE(j, len - l, 0)
    {
        if(i == j) ++cnt;
        else if(!match(i, j, l)) ++cnt;
    }
    return cnt;
}

int main()
{
#ifdef LOCAL
    freopen("11512.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", seq);
        len = strlen(seq);

        pii p = maxsegment();

        if(p.fr < 0)
            puts("No repetitions found!");
        else
        {
            REP(i, 0, p.sc) putchar(seq[i + p.fr]);
            printf(" %d\n", repcount(p.fr, p.sc));
        }

        memset(has, 0, (len * len * len + 10) >> 3);
    }

    return 0;
}
