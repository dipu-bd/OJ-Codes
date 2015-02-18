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

char key[10][10] =
{
    "010101",
    "000010",
    "001000",
    "010010",
    "000001",
    "000100"
};

void rotate()
{
    char tmp[10][10];
    REP(i, 0, 6)
    REP(j, 0, 6)
    tmp[i][j] = key[5 - j][i];

    REP(i, 0, 6)
    REP(j, 0, 6)
    key[i][j] = tmp[i][j];
}

char cipher[10000];
char code[10][10];
char text[10000];

void convert(int b)
{
    REP(i, 0, 6)
    REP(j, 0, 6)
    code[i][j] = cipher[b + i * 6 + j];
}

void decrypt(int& b)
{
    REP(r, 0, 4)
    {
        REP(i, 0, 6)
        REP(j, 0, 6)
        {
            if(key[i][j] == '1')
                text[b++] = code[i][j];
        }
        rotate();
    }
    text[b] = 0;
}

int main()
{
#ifdef LOCAL
    freopen("795.inp", "r", stdin);
#endif // LOCAL

    while(gets(cipher))
    {
        int len = strlen(cipher);
        if((!len) || (len % 36))
        {
            puts(cipher);
            continue;
        }

        int pb = 0;
        for(int i = 0; i < len; i += 36)
        {
            convert(i);
            decrypt(pb);
        }

        reverse(text, text + pb);

        while(pb > 0 && text[pb - 1] == '#') --pb;
        text[pb] = 0;

        puts(text);
    }

    return 0;
}
