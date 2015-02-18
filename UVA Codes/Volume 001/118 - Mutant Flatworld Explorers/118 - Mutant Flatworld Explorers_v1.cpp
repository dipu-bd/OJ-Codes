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

int m, n;
int x, y, d;
bool lost;
bool grid[52][52];

char dir[] = "NESW";
int X[] = {0, 1, 0, -1};
int Y[] = {1, 0, -1, 0};

int getdir(char ch)
{
    REP(i, 0, 4) if(dir[i] == ch) return i;
}

bool valid(int x, int y)
{
    return x >= 0 && x <= m && y >= 0 && y <= n;
}

void move()
{
    int p = x + X[d];
    int q = y + Y[d];

    if(valid(p, q))
    {
        x = p;
        y = q;
        return;
    }

    //out of bound here
    if(grid[x][y]) return;
    grid[x][y] = 1;
    lost = true;
}

void turn(int t)
{
    if(t > 0) d = d == 3 ? 0 : d + 1;
    else d = d == 0 ? 3 : d - 1;
}

int main()
{
#ifdef LOCAL
    freopen("118.inp", "r", stdin);
#endif // LOCAL

    scanf("%d %d", &m, &n);

    char ch, *p;
    char line[110];
    while(scanf("%d %d %c", &x, &y, &ch) != EOF)
    {
        lost = false;
        d = getdir(ch);

        scanf(" %s", line);
        for(int i = 0; line[i]; ++i)
        {
            if(line[i] == 'F') move();
            if(line[i] == 'L') turn(-1);
            if(line[i] == 'R') turn(1);
            if(lost) break;
        }

        printf("%d %d %c", x, y, dir[d]);
        if(lost) printf(" LOST");
        putchar('\n');
    }

    return 0;
}
