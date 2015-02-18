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

struct cube
{
    char face[10];
    cube() { clr(face); }

    bool operator == (const cube& b) const
    {
        return !strcmp(face, b.face);
    }

    void takeinput()
    {
        clr(face);
        REPE(i, 0, 5) face[i] = getchar();
    }

    void ver_rotate() //clockwise from front view
    {
        cube n;
        n.face[1] = face[2];
        n.face[2] = face[4];
        n.face[4] = face[3];
        n.face[3] = face[1];
        n.face[0] = face[0];
        n.face[5] = face[5];
        strcpy(face, n.face);
    }

    void hor_rotate() //counter clockwise from top view
    {
        cube n;
        n.face[0] = face[4];
        n.face[1] = face[0];
        n.face[5] = face[1];
        n.face[4] = face[5];
        n.face[2] = face[2];
        n.face[3] = face[3];
        strcpy(face, n.face);
    }

    void front_rotate() //counter clockwise from left view
    {
        cube n;
        n.face[0] = face[2];
        n.face[3] = face[0];
        n.face[5] = face[3];
        n.face[2] = face[5];
        n.face[1] = face[1];
        n.face[4] = face[4];
        strcpy(face, n.face);
    }
};

int main()
{
#ifdef LOCAL
    freopen("253.inp", "r", stdin);
#endif // LOCAL

    char ch;
    cube a, b;
    bool match;
    while(scanf(" %c", &ch) != EOF)
    {
        ungetc(ch, stdin);

        a.takeinput();
        b.takeinput();
        match = false;

        REP(i, 0, 4)
        {
            REP(j, 0, 4)
            {
                REP(k, 0, 4)
                {
                    if(a == b)
                    {
                        match = true;
                        break;
                    }
                    b.hor_rotate();
                }
                if(match) break;
                b.front_rotate();
            }
            if(match) break;
            b.ver_rotate();
        }

        if(match) puts("TRUE");
        else puts("FALSE");
    }

    return 0;
}
