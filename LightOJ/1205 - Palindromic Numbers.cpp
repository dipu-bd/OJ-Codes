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
#define IT iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(v.begin(), v.end())
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------------------------*/

int run;
char num[20];
ll save[20][20][2][2];
int curcas[20][20][2][2];

ll recur(int i, int j, bool imax = 1, bool cont = 0)
{
	if(j < i) return cont;
	
	ll& dp = save[i][j][imax][cont];
	int& ret = curcas[i][j][imax][cont];
	if(ret == run) return dp;
	
	ret = run;
	int m = imax ? num[i] : 9;
	if(!cont) dp = recur(i + 1, j, 0, 0);
	REPE(i, 1, m) dp += recur(i + 1, j - 1, i == m && imax, 1);
		
	return dp;
}

int convert(ll n)
{
	if(n == 0) return 0; 
	int p = convert(n / 10);
	num[p] = n % 10;
	return p + 1;	
}

int main()
{		
	int test, cas = 1;
		
    scanf("%d", &test);
    while(test--)
    {
		int len;
		ll a, b, r1, r2;
		scanf("%lld %lld", &a, &b);		
		
		++run;
		len = convert(b);
		r1 = recur(0, len - 1);
				
		++run;
		len = convert(a - 1);
		r2 = recur(0, len - 1);
				
		printf("Case %d: %lld\n", cas++, r1 - r2);		
	}
	
    return 0;
}
