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

int n;
char var[10];

void printvar(const char* v)
{
    putchar(v[0]);
    REP(i, 1, n) printf(",%c", v[i]);
}

void printspc(int cnt)
{
    while(cnt--) putchar(' ');
}

void writeline(string& s)
{
    printf("writeln(");
    printvar(s.data());
    printf(")\n");
}

void condition(char a, char b)
{
    printf("if %c < %c then\n", a, b);
}

void recur(string pre, string next, int h = 2)
{
    if(next.size() == 0)
    {
        printspc(h);
        writeline(pre);
        return;
    }

    int sh = h;
    loop(i, pre)
    {
        printspc(sh);
        condition(*i, next[0]);
        sh += 2;
    }

    pre.push_back(next[0]);
    next.erase(next.begin());
    recur(pre, next, sh);

    for(int i = pre.size() - 1; i > 0; --i)
    {
        sh -= 2;
        printspc(sh);
        printf("else\n");
        swap(pre[i], pre[i - 1]);
        recur(pre, next, sh + 2);
    }
}

void printprogram()
{
    puts("program sort(input,output);");

    //variables
    puts("var");
    printvar(var);
    puts(" : integer;");

    puts("begin");

    //read
    printf("  readln(");
    printvar(var);
    puts(");");

    //sort
    recur("", string(var));

    puts("end.");
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);

        var[n] = 0;
        REP(i, 0, n)
        var[i] = i + 'a';

        printprogram();

        if(test) putchar('\n');
    }

    return 0;
}
