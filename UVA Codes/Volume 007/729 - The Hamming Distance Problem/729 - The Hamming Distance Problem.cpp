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
#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define sf scanf
#define pf printf
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)

void print(int p, int bit)
{
    if(p == 0) return;
    print(p - 1, bit >> 1);
    putchar((bit & 1) + '0');
}

int n;
vector<int> v;
void recur(int r, int p, int bit)
{
    if(r == 0)
    {
        v.pb(bit);
        return;
    }

    for(int mask = (1 << (++p)); p < n; ++p, mask <<= 1)
        if(!(bit & mask)) recur(r - 1, p, (bit | mask));
}

int main()
{
    int test;
    scanf("%d", &test);

    while(test--)
    {
        int r;
        scanf("%d %d", &n, &r);
        recur(r, -1, 0);
        ssort(v);
        loop(vector<int>, it, v)
        {
            print(n, *it);
            putchar('\n');
        }
        if(test) putchar('\n');
        v.clear();
    }

    return 0;
}
