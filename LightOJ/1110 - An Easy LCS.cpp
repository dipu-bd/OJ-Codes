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
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)

typedef pair<string, int> psi;

int m, n;
char str1[110], str2[110];
string save1[105][105];
int save2[105][105];

psi comp(psi a, psi b)
{
    if(a.second != b.second)
        return (a.second > b.second) ? a : b;
    return (a.first < b.first) ?  a : b;
}

psi LCS(int i = 0, int j = 0)
{
    if(i == m && j == n)
        return mp(string(""), 0);
    if(i==m || j == n)
        return mp(string(""), 0);

    int& r = save2[i][j];
    string& s = save1[i][j];
    if(r != -1) return mp(s, r);

    if(str1[i] == str2[j])
    {
        psi p = LCS(i + 1, j + 1);
        s = str1[i] + p.first;
        r = p.second + 1;
    }
    else
    {
        psi p = comp(LCS(i + 1, j), LCS(i, j + 1));
        s = p.first;
        r = p.second;
    }

    return mp(s, r);
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s %s", str1, str2);
        m = strlen(str1);
        n = strlen(str2);
        mem(save2, -1);
        psi p = LCS();
        printf("Case %d: ", cas++);
        cout << (p.second ? p.first : ":(") << endl;
    }

    return 0;
}

