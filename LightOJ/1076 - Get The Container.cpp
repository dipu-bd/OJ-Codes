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
#include <bitset>
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
#define FOR(i, a, n) for(int i = a; i < n; ++i)
#define RFOR(i, a, n) for(int i = a; i > n; --i)
#define FORE(i, a, n) for(int i = a; i <= n; ++i)
#define RFORE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)
#define cloop(typ,it,v) for(typ::const_iterator it = v.begin(); it != v.end(); ++it)
#define rloop(typ,it,v) for(typ::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
#define rcloop(typ,it,v) for(typ::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)

int main()
{
    int test, cas = 1;
    cin >> test;

    int n, m;
    int cont[1010];
    int mid, low, high, best;

    while(test--)
    {
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; ++i)
            scanf("%d", cont + i);

        low = 0, high = 2000000000;
        while(low <= high)
        {
            mid = (low + high) / 2;

            int s = 0, cnt = 1;
            for(int i = 0; i < n; ++i)
            {
                if(cont[i] > mid)
                {
                    cnt = m + 1;
                    break;
                }

                s += cont[i];
                if(s > mid)
                {
                    s = cont[i];
                    cnt++;
                }
            }

            //printf("%d %d : %d , %d %d %d\n", low, high, mid, cnt, m, s);

            if(cnt == m)
            {
                best = mid;
                if(s == mid) break;
                else if(s < mid) high = mid - 1;
                else low = mid + 1;
            }
            else if(cnt < m)
            {
                high = mid - 1;
                best = mid;
            }
            else low = mid + 1;
        }

        printf("Case %d: %d\n", cas++, best);
    }

    return 0;
}

