/* =================================
@AUTHOR : Sudipto Chandra Das DIPU
@UNIV : SUST [2012-331-019]
@COUNTRY : Bangladesh
================================= */
// C headers
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <limits.h>
#include <time.h>
// CPP headers
#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;

//typedefs
typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
//risk-free macros
#define gcd(a,b) __gcd(a,b)
#define logab(a,b) (log(a) / lob(b))
#define mem(a,v) memset(a, v, sizeof(a))
#define _IT ::iterator
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define loop(type, v, it) for(type::iterator it = v.begin(); it != v.end(); ++it)

//main function
int main()
{
    int test;
    int x, y, m, n;

    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d", &x, &y);
        m = y - x;
        n = round(-1 + sqrt(1.0 + 8.0 * (m / 2)));
        printf("%d\n", n);
    }

    return 0;
}
