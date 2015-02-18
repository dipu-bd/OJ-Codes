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

#define SIZ 10000

int n;
char inp[SIZ];
int val[SIZ];

int process()
{
    int v;
    int b = 0;
    int sum = 0;
    for(int i = 0; inp[i]; ++i)
    {
        if(i == 0 && (inp[i] == '-' || inp[i] == '+')) continue;

        if(isdigit(inp[i]))
            v = inp[i] - '0';
        else if(isupper(inp[i]))
            v = inp[i] - 'A' + 10;
        else if(islower(inp[i]))
            v = inp[i] - 'a' + 36;
        else return 0;

        if(v > b) b = v;
        sum += v;
    }

    if(b < 1) b = 1;
    for(++b; b <= 62; ++b)
        if(!(sum % (b - 1))) return b;

    return 0;
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    while(gets(inp))
    {
        int r = process();
        if(r) printf("%d\n", r);
        else puts("such number is impossible!");
    }

    return 0;
}
