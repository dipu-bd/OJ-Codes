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

#define SIZ 500005

ll cnt;
int arr[SIZ];
int sub[SIZ];

void mergetwo(int b, int m, int e)
{
    int i = b, i1 = b, i2 = m + 1;
    do
    {
        while(i1 <= m && arr[i1] <= arr[i2]) sub[i++] = arr[i1++];
        while(i2 <= e && arr[i2] < arr[i1])
        {
            cnt += i2 - i;
            sub[i++] = arr[i2++];
        }
    }
    while(i1 <= m && i2 <= e);

    while(i1 <= m) sub[i++] = arr[i1++];
    while(i2 <= e) sub[i++] = arr[i2++];

    memcpy(arr + b, sub + b, sizeof(int) * (i - b));
}

void mergesort(int b, int e)
{
    if(b == e) return;

    int m = (b + e) >> 1;
    mergesort(b, m);
    mergesort(m + 1, e);
    mergetwo(b, m, e);
}

int main()
{
#ifdef LOCAL
    freopen("10810.inp", "r", stdin);
#endif // LOCAL

    int n;
    char ch;
    while(scanf("%d", &n) != EOF && n)
    {
        REPE(i, 1, n) scanf("%d", arr + i);

        cnt = 0;
        mergesort(1, n);

        printf("%lld\n", cnt);
        //REPE(i, 1, n) printf("%d ", arr[i]); puts("");
    }

    return 0;
}
