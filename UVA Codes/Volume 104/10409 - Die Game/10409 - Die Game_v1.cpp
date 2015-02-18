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

struct Die
{
    int top;
    int bottom;
    int north;
    int south;
    int east;
    int west;

    Die()
    {
        top = 1;
        bottom = 6;

        north = 2;
        south = 5;

        west = 3;
        east = 4;
    }

    void print()
    {
        printf("top = %d bottom = %d north = %d south = %d west = %d east = %d\n",
               top, bottom, north, south, west, east);
    }
};


void move_north(Die& d)
{
    Die n = d;

    d.north = n.top;
    d.south = n.bottom;

    d.top = n.south;
    d.bottom = n.north;
}

void move_south(Die& d)
{
    Die n = d;

    d.south = n.top;
    d.north = n.bottom;

    d.top = n.north;
    d.bottom = n.south;
}

void move_east(Die& d)
{
    Die n = d;

    d.east = n.top;
    d.west = n.bottom;

    d.top = n.west;
    d.bottom = n.east;
}

void move_west(Die& d)
{
    Die n = d;

    d.west = n.top;
    d.east = n.bottom;

    d.top = n.east;
    d.bottom = n.west;
}

int main()
{
#ifdef LOCAL
    freopen("10409.inp", "r", stdin);
#endif // LOCAL

    int n;
    char inp[20];
    while(scanf("%d", &n) != EOF && n)
    {
        Die d;
        while(n--)
        {
            scanf(" %s", inp);
            if(inp[0] == 'n') move_north(d);
            if(inp[0] == 'e') move_east(d);
            if(inp[0] == 's') move_south(d);
            if(inp[0] == 'w') move_west(d);
        }
        printf("%d\n", d.top);
    }

    return 0;
}
