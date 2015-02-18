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

int n;
vii unit;
int seq[300];
int tmp[300];
char str[300];
char out[300];

vii getseq(int k) //apply seq for k times
{
    if(k == 0) return unit;
    vii res = getseq(k >> 1);
    //apply res = res * res
    REP(i, 0, n) tmp[i] = res[res[i]];
    //copy tmp and apply res = (res) * x
    REP(i, 0, n)
    {
        if(k & 1) res[i] = tmp[seq[i]];
        else res[i] = tmp[i];
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("306.inp", "r", stdin);
#endif // LOCAL

    while(scanf("%d", &n) != EOF && n)
    {
        unit.clear();
        REP(i, 0, n)
        {
            scanf("%d", seq + i);
            --seq[i];
            unit.pb(i);
        }

        int k;
        out[n] = 0;
        while(scanf("%d", &k) != EOF && k)
        {
            getchar();
            scanf("%[^\n]", str);
            REP(i, strlen(str), n) str[i] = ' ';

            vii res = getseq(k);
            REP(i, 0, n) out[res[i]] = str[i];
            puts(out);
        }
        puts("");
    }

    return 0;
}
