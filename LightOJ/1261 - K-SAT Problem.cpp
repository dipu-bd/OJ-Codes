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
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)
#define rloop(typ,it,v) for(typ::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
#define cloop(typ,it,v) for(typ::const_iterator it = v.begin(); it != v.end(); ++it)
#define rcloop(typ,it,v) for(typ::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        //take request set
        int n, m, k;
        vii accept[50];
        vii reject[50];
        scanf("%d %d %d", &n, &m, &k);
        REP(i, 0, n)
        {
            REP(j, 0, k)
            {
                int x;
                scanf("%d", &x);
                if(x < 0) reject[i].pb(-x);
                else accept[i].pb(x);
            }
        }

        //take object set
        int p;
        set<int> num;
        scanf("%d", &p);
        REP(i, 0, p)
        {
            int x;
            scanf("%d", &x);
            num.insert(x);
        }

        //check if it is valid
        bool valid = true;
        REP(i, 0, n)
        {
            //check if any accept req kept
            bool ac = false;
            loop(vii, it, accept[i])
            {
                if(num.count(*it))
                {
                    ac = true;
                    break;
                }
            }
            if(ac) continue;

            //or check if all reject req fullfilled
            bool rej = false;
            loop(vii, it, reject[i])
            {
                if(!num.count(*it))
                {
                    rej = true;
                    break;
                }
            }
            if(rej) continue;

            //or this is not valid set
            valid = false;
            break;
        }

        //show result
        printf("Case %d: ", cas++);
        if(valid) puts("Yes");
        else puts("No");
    }

    return 0;
}

