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
typedef unsigned long long ull;
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
#define LB lower_bound
#define UB upper_bound
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

int test, cas = 1;

char inp[1000];

int state(int i, int j)
{
    if(i > j) return 0;
    if(i == j)
    {
        return (inp[i] == 'A') ? 1 : 0;
    }
    
    if(j - i < 2) 
    {
        return 0;
    }
    else if(inp[j - 1] == 'A' && inp[j] == 'B')
    {
        return state(i, j - 2) ? 2 : 0;
    }
    else if(inp[i] == 'B' && inp[j] == 'A')
    {
        return state(i + 1, j - 1) ? 3 : 0;
    }

    return 0;
}

int main()
{ 
    scanf("%d", &test);
    
    while(test--)
    {
        scanf(" %s", inp);
        int len = strlen(inp);
        int s = state(0, len - 1);

        if(s == 1)
        {
            puts("SIMPLE");
        }
        else if(s == 2)
        {
            puts("FULLY-GROWN");
        }
        else if(s == 3)
        {
            puts("MUTAGENIC");
        }
        else
        {
            puts("MUTANT");
        }
    }

    return 0;
}
