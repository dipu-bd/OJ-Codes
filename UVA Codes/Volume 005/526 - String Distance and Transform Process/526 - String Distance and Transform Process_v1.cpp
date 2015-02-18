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
#define LB(v, x) lower_bound(v.begin(), v.end(), x)
#define UB(v, x) upper_bound(v.begin(), v.end(), x)
#define loop(i, x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define rloop(i, x) for(__typeof((x).rbegin()) i=(x.rbegin()); i!=(x).rend(); ++i)
/*--------------------------------------------------------------------------------*/

char str1[85];
char str2[85];
int len1, len2;
int mat[85][85];
int prev[85][85];

void edit_dist()
{
    len1 = strlen(str1 + 1);
    len2 = strlen(str2 + 1);

    REPE(i, 0, len1) mat[i][0] = i;
    REPE(j, 0, len2) mat[0][j] = j;

    REPE(i, 1, len1)
    {
        REPE(j, 1, len2)
        {
            if(str1[i] == str2[j])
            {
                prev[i][j] = 1;
                mat[i][j] = mat[i - 1][j - 1];
            }
            else
            {
                int& a = mat[i][j - 1];
                int& b = mat[i - 1][j];
                int& c = mat[i - 1][j - 1];

                if(a < b && a < c)
                {
                    mat[i][j] = a + 1;
                    prev[i][j] = 2;
                }
                else if(b < c)
                {
                    mat[i][j] = b + 1;
                    prev[i][j] = 3;
                }
                else
                {
                    mat[i][j] = c + 1;
                    prev[i][j] = 4;
                }
            }
        }
    }
}

int print_path()
{
    REPE(i, 0, len1)
    {
        REPE(j, 0, len2)
            printf("%d ", prev[i][j]);
        putchar('\n');
    }

    //if(i == 0 || j == 0) return 0;
    //if(prev)

}

int main()
{
#ifdef LOCAL
    //freopen("", "r", stdin);
#endif // LOCAL

    bool first = true;

    while(scanf(" %s %s", str1 + 1, str2 + 1) != EOF)
    {
        if(first) first = false;
        else putchar('\n');

        edit_dist();
        printf("%d\n", mat[len1][len2]);
        print_path();
    }

    return 0;
}
