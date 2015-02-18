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

#define MAX 1000002

int sz;
int NOD[MAX + 10];
int RES[MAX + 10];

void precalc()
{ 
    NOD[1] = 1;
    REP(i, 2, MAX)
    {
        if(!NOD[i])
        {
            NOD[i] = 2;
            for(int j = i + i; j <= MAX; j += i)
            {
                int k = 0, p = j;
                while(!(p % i))
                {
                    ++k;
                    p /= i;
                }   
                if(!NOD[j]) NOD[j] = k + 1;
                else NOD[j] *= k + 1;
            }
        }
    }
    
    RES[sz++] = 1;
    while(RES[sz - 1] <= MAX)
	{
		RES[sz] = RES[sz - 1] + NOD[RES[sz - 1]]; 
		++sz;	
	}
}

int main()
{
    precalc();
    int test, cas = 1;
    
    scanf("%d", &test);
    while(test--)
    {
		int a, b;
		scanf("%d %d", &a, &b);
		
		int* p1 = lower_bound(RES, RES + sz, a);
		int* p2 = upper_bound(RES, RES + sz, b);		
		
		printf("Case %d: %d\n", cas++, (int)(p2 - p1));
	}

    return 0;
}
