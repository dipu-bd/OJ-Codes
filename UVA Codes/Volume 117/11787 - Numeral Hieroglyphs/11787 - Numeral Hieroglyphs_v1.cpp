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
typedef unsigned long long ull;
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
#define LB lower_bound
#define UB upper_bound
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

char inp[550];

int power(char p)
{
    if(p == 'B') return 1;
    if(p == 'U') return 10;
    if(p == 'S') return 100;
    if(p == 'P') return 1000;
    if(p == 'F') return 10000;
    if(p == 'T') return 100000;
    if(p == 'M') return 1000000;
    return -1;
}

bool check(int& val, int& last, int& cnt, char ch)
{
    int q = power(ch);
    if(q == -1) return 0;

    if(q == last)
    {
        ++cnt;
        return 1;
    }
    if(cnt > 9) return 0;
    val += cnt * last;

    if(q < last) return 0;
    last = q;
    cnt = 1;

    return 1;
}

int getval()
{
    int len = strlen(inp) - 1;
    int b = power(inp[0]), e = power(inp[len]);
    if(b <= e)
    {
        //left to right
        int val = 0, last = 0, cnt = 0;
        REPE(i, 0, len) if(!check(val, last, cnt, inp[i])) return -1;;
        if(cnt > 9) return -1;
        val += last * cnt;
        return val;
    }
    else
    {
        //right to left
        int val = 0, last = 0, cnt = 0;
        RREPE(i, len, 0) if(!check(val, last, cnt, inp[i])) return -1;;
        if(cnt > 9) return -1;
        val += last * cnt;
        return val;
    }
}

int main()
{
#ifdef LOCAL
    freopen("11787.inp", "r", stdin);
#endif // LOCAL

    scanf("%d ", &test);
    while(test--)
    {
        gets(inp);
        int v = getval();
        if(v < 0) puts("error");
        else printf("%d\n", v);
    }

    return 0;
}
