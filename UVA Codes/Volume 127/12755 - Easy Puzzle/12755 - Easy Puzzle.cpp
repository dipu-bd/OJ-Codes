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
#define _a first
#define _b second
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
/*--------------------------------------------------------------------------------------------------*/

int n, cnt;
int arr[250005];
int pos[250005];

void increase(int& z)
{
    if(z == 0)
    {
        while(pos[z] == z && z < n) z++;
        if(z < n)
        {
            arr[0] = arr[z];
            pos[arr[z]] = 0;
            arr[z] = 0;
            pos[0] = z;
            ++cnt;
        }
    }
}

void move_zero(int& z)
{
    int p = pos[z];
    pos[0] = p;
    arr[p] = 0;
    pos[z] = z;
    arr[z] = z;
    z = p;
    ++cnt;
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);

        n *= n;
        REP(i, 0, n)
        {
            scanf("%d", arr + i);
            pos[arr[i]] = i;
        }

        cnt = 0;
        int z = pos[0]; //current position of zero
        increase(z); //if zero is in zero move it to next pos
        while(z < n)
        {
            move_zero(z);
            increase(z);
        }

        printf("Case %d: %d\n", cas++, cnt);
    }

    return 0;
}
