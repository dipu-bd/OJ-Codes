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
#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, int> pill;
typedef vector<int> vii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
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
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)
#define rloop(typ,it,v) for(typ::reverse_iterator it = v.rbegin(); it != v.rend(); ++it)
#define cloop(typ,it,v) for(typ::const_iterator it = v.begin(); it != v.end(); ++it)
#define rcloop(typ,it,v) for(typ::const_reverse_iterator it = v.rbegin(); it != v.rend(); ++it)

int FIB = 75;
const ll inf = 1000000000000000LL;

ll fib[100], sum[100];
void set_fibs()
{
    fib[0] = fib[1] = sum[1] = 1;
    REPE(i, 2, FIB)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        sum[i] = sum[i - 1] + i * fib[i - 1];
    }
}

int get_n(ll N)
{
    REPE(n, 0, FIB)
    {
        if(sum[n] > N)
            return n - 1;
    }

    return -1;
}

ll ones[100];
ll get_one(int n)
{
    if(n <= 0) return 0;
    if(n == 1) return 1;
    if(ones[n] > 0) return ones[n];

    ones[n] = get_one(n - 1) + get_one(n - 2) + fib[n - 1];
    return ones[n];
}

int one_in(ll N, int p)
{
    ll s = 0, cnt = 0;
    for(int i = FIB; i >= 0 && p > 0; --i)
    {
        if(s + fib[i] <= N)
        {
            s += fib[i];
            cnt++;
        }

        if(s == N) break;
        if(s > 0) p--;
    }

    return cnt;
}

ll count_one(ll N)
{
    if(N == 0) return 0;

    //first calc
    int n = get_n(N);
    ll res = get_one(n);

    //sec calc
    N -= sum[n];
    int m = N / (n + 1);
    res += get_one(m - 1) + m;

    //last calc
    int p = N - m * (n + 1);
    N = fib[n + 1] + m;
    res += one_in(N, p);

    return res;
}

int main()
{
    set_fibs();

    REPE(i, 0, FIB)
    {
        cout << "i = " << i << " : " << get_one(i) << endl;
    }

    ll N;
    while(cin >> N)
    {
        cout << count_one(N) << endl;
    }

    return 0;
}

