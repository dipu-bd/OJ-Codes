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

#define MAX 32000

ll D[MAX + 10];
ll N[MAX + 10];
ll S[MAX + 10];

ll FD(int k)
{
    if(D[k]) return D[k];
    return (D[k] = 1 + (ll)log10(k));
}
ll FN(int k)
{
    if(k == 0) return 0;
    if(N[k]) return N[k];
    return (N[k] = FN(k - 1) + FD(k));
}
ll FS(int k)
{
    if(k == 0) return 0;
    if(S[k]) return S[k];
    return (S[k] = FS(k - 1) + FN(k));
}
 
int BS1(ll i)
{
    int mid;
    int low = 1;
    int high = MAX;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        ll r = FS(mid);
        if(r == i) return mid;
        if(r < i) low = mid + 1;
        if(r > i) high = mid - 1;
    }
    
    while(FS(mid) < i) ++mid;
    return mid;
}

int BS2(ll i)
{
    int mid;
    int low = 1;
    int high = MAX;
    while(low <= high)
    {
        mid = (low + high) >> 1;
        ll r = FN(mid);
        if(r == i) return mid;
        if(r < i) low = mid + 1;
        if(r > i) high = mid - 1;
    }
    
    while(FN(mid) < i) ++mid;
    return mid;
}

int main()
{
    ll i;
    int test;
        
    cin >> test;
    while(test--)
    {
        cin >> i;
        int k = BS1(i);
        i -= FS(k - 1);
        int m = BS2(i);
        i -= FN(m - 1);
        char digit[20];
        sprintf(digit, "%d\n", m);
        printf("%c\n", digit[i - 1]);
    }
    
    return 0;
}

