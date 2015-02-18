//c headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
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
using namespace std;

const double EPS = 1E-12;
const double PI = 2.0 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;

#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a,0,sizeof(a))
#define mem(a,b) memset(a,b,sizeof(a))
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define ins insert
#define mp make_pair
#define IT iterator
#define ssort(v) stable_sort(v.begin(), v.end())
#define all(v) (v.begin(), v.end())
#define loop(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i = (x).rbegin(); i != (x).rend(); ++i)
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define LB lower_bound
#define UB upper_bound
template<typename T> inline T sqr(T n) { return n * n; }

int test, cas = 1;

char roles[] = "GDMS";

struct player
{
    int n;
    char name[30];
    char role;
    int ri;
    int record;

    bool scan()
    {
        if(scanf("%d", &n) != 1 || n == 0) return false;

        scanf(" %s", name);
        scanf(" %c", &role);

        ri = 0;
        while(role != roles[ri]) ++ri;

        record = 0;
        int y1, y2;
        while(scanf(" %d-%d", &y1, &y2) == 2)
        {
            record += y2 - y1 + 1;
            if(getchar() != ' ') break;
        }

        return true;
    }

    void print()
    {
        printf("%d %s %c\n", n, name, role);
    }

    bool operator < (const player& r) const
    {
        return n < r.n;
    }
};

vector<player> sel;
vector<player> all[5];

bool compare(int cap, int i)
{
    if(sel[cap].record != sel[i].record)
        return sel[i].record > sel[cap].record;
    return sel[i].n > sel[cap].n;
}

int main()
{
#ifdef DIPU
    freopen("G.txt", "r", stdin);
#endif // DIPU

    player p;
    while(p.scan())
    {
        REP(i, 0, 4)
        {
            all[i].clear();
        }


        all[p.ri].pb(p);
        REP(i, 1, 22)
        {
            p.scan();
            all[p.ri].pb(p);
        }

        int form[4];
        form[0] = 1;
        scanf("%d-%d-%d", &form[1], &form[2], &form[3]);

        sel.clear();
        bool pos = true;
        REP(i, 0, 4)
        {
            ssort(all[i]);
            if(all[i].size() < form[i])
            {
                pos = false;
                break;
            }
            else
            {
                REP(j, 0, form[i])
                {
                    sel.pb(all[i][j]);
                }
            }
        }

        if(!pos)
        {
            puts("IMPOSSIBLE TO ARRANGE\n");
            continue;
        }

        int cap = 0;
        REP(i, 1, sel.size())
        {
            if(compare(cap, i))
            {
                cap = i;
            }
        }

        sel[cap].print();
        REP(i, 0, sel.size())
        {
            if(i == cap) continue;
            sel[i].print();
        }
        putchar('\n');
    }

    return 0;
}

