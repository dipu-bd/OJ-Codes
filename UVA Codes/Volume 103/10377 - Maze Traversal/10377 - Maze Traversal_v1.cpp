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

#define SIZ 100

int n, m;
char graph[SIZ][SIZ];
int curx, cury, face;
char dir[] = "NESW";
int X[] = { -1, 0, 1,  0};
int Y[] = {  0, 1, 0, -1};

inline int getindx(char ch)
{
    REP(i, 0, 4) if(dir[i] == ch) return i;
}

inline void step()
{
    int px = curx + X[face];
    int py = cury + Y[face];
    if(px <= 0 || py <= 0 || px >= n || py >= m) return;
    if(graph[px][py] == ' ') curx = px, cury = py;
}

inline void movright()
{
    face = (face + 1) % 4;
}

inline void movleft()
{
    face = (face == 0) ? (3) : (face - 1);
}

int main()
{
#ifdef LOCAL
    freopen("10377.inp", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &n, &m);
        REPE(i, 1, n) scanf(" %[^\n]", graph[i] + 1);

        char ch;
        face = 0;
        scanf("%d %d", &curx, &cury);
        while(scanf(" %c", &ch) != EOF)
        {
            if(ch == 'Q') break;
            if(ch == 'R') movright();
            if(ch == 'L') movleft();
            if(ch == 'F') step();
        }

        printf("%d %d %c\n", curx, cury, dir[face]);
        if(test) putchar('\n');
    }

    return 0;
}
