/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//#include <bits/stdc++.h>
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>
//#include <assert.h>
//#include <time.h>
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
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define memsz(a,b,n) memset(a, b, n * sizeof(*a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
//useful with graphs
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define mp make_pair
#define ins insert
#define IT iterator
#define allof(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB lower_bound
#define UB upper_bound
#define POPC __builtin_popcount
#define loop(i, x) for(__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x).rbegin(); i!=(x).rend(); ++i)
//variables and functions
const double PI = 2.0 * acos(0.0);
const double EXP1 = exp(1);
template<typename T> inline T sqr(T n) { return n * n; }
inline double hypot(double x, double y) { return sqrt(sqr(x) + sqr(y)); }
template<typename T> inline T pmod(T n, T m) { return ((n % m) + m) % m; }
template<typename T> T power(T n, int p) { return (p == 0) ? 1 : sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1); }
template<typename T> T bigmod(T n, int p, T m) { return (p == 0) ? 1 : (sqr(power(n, p >> 1)) * ((p & 1) * (n - 1) + 1)) % m; }
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

int B1 = 129;
int B2 = 133;
int M = 1000000;

char text[10000];
char pattern[10000];

void rabin_karp()
{
    int n = strlen(text);
    int m = strlen(pattern);

    int Hp1 = 0, Hp2 = 0;
    REP(i, 0, m)
    {
        Hp1 = pmod(Hp1 * B1 + pattern[i], M);
        Hp2 = pmod(Hp2 * B2 + pattern[i], M);
    }

    int Ht1 = 0, Ht2 = 0;
    REP(i, 0, m)
    {
        Ht1 = pmod(Ht1 * B1 + text[i], M);
        Ht2 = pmod(Ht2 * B2 + text[i], M);
    }

    bool match = false;
    if(Ht1 == Hp1 && Ht2 == Hp2)
    {
        if(!strncmp(text, pattern, m))
        {
            match = true;
            printf("%d ", 0);
        }
    }

    int B1pow = bigmod(B1, m - 1, M);
    int B2pow = bigmod(B2, m - 1, M);
    REP(i, m, n)
    {
        Ht1 = pmod((Ht1 - text[i - m] * B1pow) * B1 + text[i], M);
        Ht2 = pmod((Ht2 - text[i - m] * B2pow) * B2 + text[i], M);

        if(Ht1 == Hp1 && Ht2 == Hp2)
        {
            if(!strncmp(text + i - m + 1, pattern, m))
            {
                match = true;
                printf("%d ", i - m + 1);
            }
        }
    }

    if(match) printf("\n\tMATCH FOUND!\n");
    else printf("NO MATCH FOUND!\n");
}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    while(true)
    {
        printf("Text : ");
        gets(text);
        printf("Pattern : ");
        gets(pattern);

        printf("Match : ");
        rabin_karp();

        puts("");
    }

    set<T> sfasf;

    return 0;
}
