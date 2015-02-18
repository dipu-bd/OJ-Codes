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

char chx;
int n, m;
char line[35][90];
bool visited[35][90];

int X[] = { -1,  0, 1,  0};
int Y[] = {  0, -1, 0,  1};

inline bool valid(int x, int y)
{
    return (x >= 0) && (y >= 0) && (x < n) && (y < m)
           && (line[x][y] == ' ') && (!visited[x][y]) ;
}

inline bool contour(int x, int y)
{
    return (x >= 0) && (y >= 0) && (x < n) && (y < m)
           && (line[x][y] != ' ') && (line[x][y] != '#') ;
}

void floodfill(int x, int y)
{
    visited[x][y] = 1;
    REP(i, 0, 4)
    {
        int p = x + X[i];
        int q = y + Y[i];
        if(valid(p, q)) floodfill(p, q);
        if(contour(p, q)) line[x][y] = '#';
    }
}

int main()
{
#ifdef LOCAL
    freopen("782.inp", "r", stdin);
#endif // LOCAL

    sscanf(gets(line[0]), "%d", &test);
    while(test--)
    {
        clr(visited);
        mem(line, ' ');

        int x, y;
        bool found = 0;

        m = 0;
        for(n = 0; gets(line[n]); n++)
        {
            if(line[n][0] == '_') break;

            int len = strlen(line[n]);
            m = max(len + 1, m);
            line[n][len] = ' ';

            if(found) continue;
            REP(i, 0, len)
            if(line[n][i] == '*')
            {
                x = n;
                y = i;
                found = 1;
                break;
            }
        }

        line[x][y] = ' ';
        floodfill(x, y);

        REP(i, 0, n)
        {
            int j = m;
            while(j >= 0 && line[i][j] == ' ') --j;

            line[i][j + 1] = 0;
            puts(line[i]);
        }
        puts(line[n]);
    }

    return 0;
}
