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

int digitsum(int n)
{
    int sum = 0;
    while(n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

#define MAX 32000
int sz;
bool flag[MAX + 10];
int primes[MAX];
int dgsum[MAX];

void sieve()
{
    int i, j, m;

    dgsum[sz] = 2;
    primes[sz++] = 2;
    for( i = 4; i < MAX; i += 2) flag[i] = 1;
    for(i = 3, m = sqrt(MAX); i < m; i += 2)
    {
        if(!flag[i])
        {
            dgsum[sz] = digitsum(i);
            primes[sz++] = i;
            for(j = i * i; j < MAX; j += 2 * i) flag[j] = 1;
        }
    }
    for(; i < MAX; i += 2)
    {
        if(!flag[i])
        {
            dgsum[sz] = digitsum(i);
            primes[sz++] = i;
        }
    }
}

bool issmith(int n)
{
    if(n < MAX && !flag[n]) return false;

    int asum = digitsum(n);
    int bsum = 0;

    bool isprime = true;
    REP(i, 0, sz)
    {
        int p = primes[i];
        if(n <= p) break;

        if(n % p == 0)
        {
            do
            {
                bsum += dgsum[i];
                n /= p;
            }
            while(n % p == 0);
            isprime = false;
        }
    }

    if(isprime) return false;
    if(n > 1) bsum += digitsum(n);
    return (asum == bsum);
}

int main()
{
    sieve();

    int test;
    scanf("%d", &test);

    while(test--)
    {
        int n;
        scanf("%d", &n);

        ++n;
        while(!issmith(n)) n++;

        printf("%d\n", n);
    }

    return 0;
}
