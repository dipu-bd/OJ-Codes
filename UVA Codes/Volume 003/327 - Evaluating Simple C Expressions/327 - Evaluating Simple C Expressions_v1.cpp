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

typedef pair<int, char*> pic;

int test, cas = 1;

int val[30];
bool used[30];
char inp[150];

void init()
{
    clr(used);
    REPE(i, 'a', 'z')
    val[i - 'a'] = i - 'a' + 1;
}

int& var(char v)
{
    return val[v - 'a'];
}

char* remspace(char *str)
{
    while(*str == ' ') ++str;
    return str;
}

pic increment(char* str)
{
    str = remspace(str);
    if(!(*str == '+' || *str == '-')) return mp(0, str);

    char* cur = remspace(str + 1);
    if(*cur == '+' && *cur == *str) return mp(1, cur + 1);
    else if(*cur == '-' && *cur == *str) return mp(-1, cur + 1);

    return mp(0, str);
}

int evaluate(char *str, int psign = 1)
{
    str = remspace(str);
    if(*str == 0) return 0;

    //get pre plus or minus operators
    pic pre = increment(str);
    str = pre.sc;

    //get variable
    str = remspace(str);
    char v = *str;
    used[v - 'a'] = 1;
    ++str;

    //get post plus or minus operators
    pic post = increment(str);
    str = post.sc;

    //get operator
    str = remspace(str);
    int sign = 0;
    if(*str == '+') sign = 1, ++str;
    else if(*str == '-') sign = -1, ++str;

    //get left hand side
    var(v) += pre.fr;
    int lhs = var(v);
    var(v) += post.fr;

    //get right-hand side
    int rhs = evaluate(str, sign);

    //calculate res
    int res = psign * lhs + rhs;

    return res;
}

int main()
{
#ifdef LOCAL
    freopen("327.inp", "r", stdin);
#endif // LOCAL

    while(gets(inp))
    {
        init();
        int res = evaluate(inp);

        printf("Expression: %s\n", inp);
        printf("    value = %d\n", res);
        REPE(i, 'a', 'z')
        if(used[i - 'a'])
            printf("    %c = %d\n", i, var(i));
    }

    return 0;
}
