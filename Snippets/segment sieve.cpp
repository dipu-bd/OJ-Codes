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

#define SIZE 2000000000
#define PCOUNT 98222290

int sz;
char flag[1 + (SIZE >> 3)];
vector<int> base;
int prime[PCOUNT];

#define GET(i) (flag[(i) >> 3]  & (1 << ((i) & 7)))
#define SET(i) (flag[(i) >> 3] |= (1 << ((i) & 7)))

void sieve()
{
    int i, j;
    int l = 1 + (int)sqrt(SIZE);
    
    SET(0); 
    SET(1);

    base.pb(2);
    for(j = 4; j <= l; j += 2) SET(j);

    for(i = 3; i * i <= l; i += 2)
        if(!GET(i))
        {
            base.pb(i);
            for(j = i * i; j <= l; j += i) SET(j);
        }

    for(; i <= l; i += 2)
        if(!GET(i)) base.pb(i);
}

void segment_sieve(int a, int b)
{
    ll m = 1 + (ll)sqrt(b);
    for(ll i = 0; base[i] <= m; ++i)
    {
        int p = a + base[i] - a % base[i];
        if(p == base[i]) p = base[i] * base[i];
        for(; p <= b; p += base[i]) SET(p);
    }

    sz = 0;
    for(int i = a; i <= b; ++i)
        if(!GET(i)) prime[sz++] = i;
}

int main()
{
    sieve();

    int a, b, k, s, cnt;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d", &a, &b, &k, &s);
        if(a > b) swap(a, b);

        segment_sieve(a, b);
        
        cnt = 0;
        REP(i, k - 1, sz)
        {
            if(prime[i] - prime[i - k + 1] == s) cnt++;
        }

        printf("%d\n", cnt);
    }

    return 0;
}
