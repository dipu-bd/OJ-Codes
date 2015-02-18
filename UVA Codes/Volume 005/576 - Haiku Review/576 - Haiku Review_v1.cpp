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

bool isvowel(char* line, int p)
{
    if(p < 0) return 0;
    return
        line[p] == 'a' ||
        line[p] == 'e' ||
        line[p] == 'i' ||
        line[p] == 'o' ||
        line[p] == 'u' ||
        line[p] == 'y';
}

int syllable(char* line)
{
    int syl = 0;
    for(int i = 0; line[i]; ++i)
    {
        if(isvowel(line, i) && !isvowel(line, i - 1)) ++syl;
    }

    return syl;
}

int main()
{
#ifdef LOCAL
    freopen("576.inp", "r", stdin);
#endif // LOCAL

    char line1[210];
    char line2[210];
    char line3[210];
    while(scanf(" %[^\/]/%[^\/]/%[^\n]", line1, line2, line3) != EOF)
    {
        if(!strcmp(line1, "e") && !strcmp(line2, "o") && !strcmp(line3, "i")) break;

        if(syllable(line1) != 5) puts("1");
        else if(syllable(line2) != 7) puts("2");
        else if(syllable(line3) != 5) puts("3");
        else puts("Y");

    }

    return 0;
}
