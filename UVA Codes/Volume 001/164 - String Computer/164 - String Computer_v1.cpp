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

#define SIZ 30
const int INF = 0x7f7f7f7f;

int len1, len2;
char str1[SIZ];
char str2[SIZ];
char inp[SIZ + SIZ];
int save[SIZ][SIZ];
char path[SIZ][SIZ];

int recur(int i, int j)
{
    if(i == len1 && j == len2) return 0;
    if(i > len1 || j > len2) return INF;

    int& dp = save[i][j];
    if(dp != -1) return dp;

    int M = recur(i + 1, j + 1); //change or match
    int D = 1 + recur(i + 1, j); //delete
    int I = 1 + recur(i, j + 1); //insert

    bool match = (str1[i] == str2[j]);
    if(!match) M++;

    if(M <= D && M <= I)
    {
        dp = M;
        path[i][j] = match ? 'M' : 'C';
    }
    else if(I < D)
    {
        dp = I;
        path[i][j] = 'I';
    }
    else
    {
        dp = D;
        path[i][j] = 'D';
    }

    if(dp >= INF) path[i][j] = 'B';
    return dp;
}

void print(int i, int j)
{
    if(i == len1 && j == len2) return;

    char p = path[i][j];

    if(p == 'B') return;

    if(p == 'M')
    {
        print(i + 1, j + 1);
        return;
    }

    if(p == 'C')
    {
        putchar('C');
        putchar(str2[j]);
        printf("%.2d", j + 1);
        print(i + 1, j + 1);
        return;
    }

    if(p == 'D')
    {
        putchar('D');
        putchar(str1[i]);
        printf("%.2d", j + 1);
        print(i + 1, j);
        return;
    }

    if(p == 'I')
    {
        putchar('I');
        putchar(str2[j]);
        printf("%.2d", j + 1);
        print(i, j + 1);
        return;
    }
}

int main()
{
#ifdef LOCAL
    freopen("164.inp", "r", stdin);
#endif // LOCAL

    while(gets(inp))
    {
        if(inp[0] == '#') break;

        int i = 0;
        len1 = len2 = 0;
        while(inp[i])
        {
            if(!islower(inp[i])) break;
            else str1[len1++] = inp[i++];
        }
        ++i;
        while(inp[i])
        {
            if(!islower(inp[i])) break;
            else str2[len2++] = inp[i++];
        }

        str1[len1] = 0;
        str2[len2] = 0;

        //printf("[%s] [%s]\n", str1, str2);

        mem(save, -1);
        recur(0, 0);
        print(0, 0);

        putchar('E');
        putchar('\n');
    }

    return 0;
}
