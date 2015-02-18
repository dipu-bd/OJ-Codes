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
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//useful with graphs
#define _fr first
#define _sc second
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
/*------------------------------------------------------------------------------------------------*/

int test, cas = 1;

int index(char d)
{
    if(d == 'N') return 0;
    if(d == 'S') return 1;
    if(d == 'E') return 2;
    return 3;
}
int rev(int p)
{
    if(p == 0) return 1;
    if(p == 1) return 0;
    if(p == 2) return 3;
    return 2;
}

int X[] = {0, 0, 1, -1};
int Y[] = {1, -1, 0, 0};

int n;
int ax, ay, bx, by;
ll save[35][35];
bool block[35][35][4];

ll recur(int i, int j)
{
    if(i == bx && j == by) return 1;
    if(i > n || i < 1 || j > n || j < 1) return 0;

    ll& way = save[i][j];
    if(way != -1) return way;

    way = 0;
    if(!block[i][j][0]) way += recur(i + X[0], j + Y[0]);
    if(!block[i][j][2]) way += recur(i + X[2], j + Y[2]);

    return way;
}

int main()
{
#ifdef LOCAL
    freopen("926.inp", "r", stdin);
#endif //LOCAL

    char ch;
    int w, x, y;

    scanf("%d", &test);
    while(test--)
    {
        clr(block);

        scanf("%d", &n);
        scanf("%d %d", &ax, &ay);
        scanf("%d %d", &bx, &by);

        scanf("%d", &w);
        while(w--)
        {
            scanf("%d %d %c", &x, &y, &ch);
            int p = index(ch);
            block[x][y][p] = 1;
            x += X[p], y += Y[p];
            if(x <= n && x >= 1 && y <= n && y >= 1)
                block[x][y][rev(p)] = 1;
        }

        mem(save, -1);
        ll w = recur(ax, ay);

        printf("%lld\n", w);
    }

    return 0;
}
