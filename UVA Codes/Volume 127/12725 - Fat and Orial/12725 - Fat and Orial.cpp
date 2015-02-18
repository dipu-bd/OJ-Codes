//c headers
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <string.h>
#include <ctype.h>
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
using namespace std;

const double EPS = 1E-8;
const double E = exp(1.0);
const double PI = 2.0 * acos(0.0);
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vii;
typedef vector<pii> vpii;

#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a,0,sizeof(a))
#define mem(a,b) memset(a,b,sizeof(a))
#define fr first
#define sc second
#define pb push_back
#define pp pop_back
#define ins insert
#define mp make_pair
#define IT iterator
#define ssort(v) stable_sort(v.begin(), v.end())
#define all(v) (v.begin(), v.end())
#define loop(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i = (x).rbegin(); i != (x).rend(); ++i)
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
#define LB lower_bound
#define UB upper_bound

int test, cas = 1;

int main()
{
    int a, b;
    double n, m, x;

    cin >> test;
    while(test--)
    {
        cin >> n >> m >> a >> b;
        x = (m * (a + b) - a * n) / b;

        printf("Case #%d: ", cas++);
        if(x >= 0.0 && x <= 10.0 )
        {
            printf("%.2lf\n", x);
        }
        else
        {
            puts("Impossible");
        }

    }
    return 0;
}
