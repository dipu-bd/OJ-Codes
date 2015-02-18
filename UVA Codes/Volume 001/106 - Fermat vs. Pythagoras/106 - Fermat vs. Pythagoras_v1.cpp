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

struct triad
{
    int x;
    int y;
    int z;

    bool operator < (const triad& r) const
    {
        return z < r.z;
    }

    void print()
    {
        printf("%d %d %d\n", x, y, z);
    }
};

const int SIZ = 1000000;
const int SQSIZ = (int)sqrt(SIZ);
int* sqr = new int[SQSIZ + 10];

int sz;
triad triple[200000];
bool flag[SIZ + 10];

bool compare(const triad& a, const int& b)
{
    return a.z < b;
}

void mark(int x, int y, int z)
{
    triple[sz].x = x;
    triple[sz].y = y;
    triple[sz].z = z;
    ++sz;
}

void gentriple()
{
    REPE(i, 1, SQSIZ) sqr[i] = i * i;

    REPE(n, 1, SQSIZ)
    {
        REPE(m, n + 1, SQSIZ)
        {
            if(sqr[m] + sqr[n] > SIZ) break;

            if(((m - n) & 1) && gcd(m, n) == 1)
                mark(sqr[m] - sqr[n], (m * n) << 1, sqr[m] + sqr[n]);
        }
    }

    stable_sort(triple, triple + sz);
}

int main()
{
#ifdef LOCAL
    freopen("106.inp", "r", stdin);
#endif // LOCAL

    gentriple();

    int n;
    while(scanf("%d", &n) != EOF)
    {
        int pos = (int)(lower_bound(triple, triple + sz, n, compare) - triple);
        while(triple[pos].z == n) ++pos;

        clr(flag);
        int cnt = 0;
        REP(i, 0, pos)
        {
            for(int x = 0, y = 0, z = 0; ;)
            {
                x += triple[i].x;
                y += triple[i].y;
                z += triple[i].z;
                if(z > n) break;
                if(!flag[x]) ++cnt, flag[x] = 1;
                if(!flag[y]) ++cnt, flag[y] = 1;
                if(!flag[z]) ++cnt, flag[z] = 1;
            }
        }

        printf("%d %d\n", pos, n - cnt);
    }

    return 0;
}
