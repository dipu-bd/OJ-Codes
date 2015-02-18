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

typedef pair<ll, ll> pll;

string num;
pll save[35][2][2];

pll recur(int pos = 0, bool prev = 0, bool imax = 1)
{
    if(pos == num.size()) return mp(0LL, 1LL);

    pll& dp = save[pos][prev][imax];
    if(dp.first != -1) return dp;

    bool b = 0; //take lowest
    bool e = !(imax && !num[pos]); //take largest

    dp = recur(pos + 1, b, (b == e) && imax);
    if(e)
    {
        pll r = recur(pos + 1, e, imax);
        dp.first += r.second * prev + r.first;
        dp.second += r.second;
    }

    return dp;
}

void convert(int n)
{
    if(n == 0) { num = ""; return; }
    convert(n >> 1);
    num.pb(n & 1);
}

int main()
{
    cin.sync();
    int test, cas = 1;

    int n;
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d", &n);
        convert(n);
        mem(save, -1);
        pll r = recur();
        printf("Case %d: %lld\n", cas++, r.first);
    }

    return 0;
}

