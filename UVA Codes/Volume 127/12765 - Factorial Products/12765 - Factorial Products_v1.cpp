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

int main()
{
#ifdef LOCAL
    freopen("12765.inp", "r", stdin);
#endif // LOCAL

    int n, m, x;
    int arr1[10];
    int arr2[10];
    bool match;

    while(scanf("%d %d", &n, &m) != EOF && (n || m))
    {
        clr(arr1);
        clr(arr2);
        while(n--)
        {
            scanf(" %d", &x);
            REPE(i, 2, x) arr1[i]++;
        }
        while(m--)
        {
            scanf(" %d", &x);
            REPE(i, 2, x) arr2[i]++;
        }

        arr1[2] += arr1[4] * 2 + arr1[6] + arr1[8] * 3;
        arr1[3] += arr1[6] + arr1[9] * 2;

        arr2[2] += arr2[4] * 2 + arr2[6] + arr2[8] * 3;
        arr2[3] += arr2[6] + arr2[9] * 2;

        match = arr1[2] == arr2[2] && arr1[3] == arr2[3] &&
                arr1[5] == arr2[5] && arr1[7] == arr2[7];

        if(match) puts("YES");
        else puts("NO");
    }


    return 0;
}
