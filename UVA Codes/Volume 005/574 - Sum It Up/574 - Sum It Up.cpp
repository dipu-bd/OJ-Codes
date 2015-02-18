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
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) sort(all(v))
#define loop(typ,it,v) for(typ::const_iterator it = v.begin(); it != v.end(); ++it)
#define rloop(typ,it,v) for(typ::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)

typedef vector<int> vii;

int t, n;
int num[20];
bool visit[20];
vii taken;
set<vii> res;

void backtrack(int p, int sum)
{
    if(sum > t) return;

    if(sum == t)
    {
        res.insert(taken);
        return;
    }

    for(int i = p + 1; i < n; ++i)
        if(!visit[i])
        {
            visit[i] = 1;
            taken.pb(num[i]);
            backtrack(i, sum + num[i]);
            taken.pp();
            visit[i] = 0;
        }
}

int main()
{
    while(scanf("%d %d", &t, &n) != EOF && n)
    {
        for(int i = 0; i < n; ++i)
            scanf("%d", num + i);

        printf("Sums of %d:\n", t);

        res.clear();
        backtrack(-1, 0);
        if(res.empty()) puts("NONE");
        else rloop(set<vii>, i, res)
        {
            bool pls = false;
            loop(vii, j, (*i))
            {
                if(pls) putchar('+');
                else pls = true;
                printf("%d", *j);
            }
            putchar('\n');
        }
    }

    return 0;
}

