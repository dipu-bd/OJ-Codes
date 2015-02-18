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
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) stable_sort(all(v))
#define loop(it, cont) for(__typeof((x).begin()) it=(x.begin()); it!=(x).end(); ++it)
#define rloop(it, cont) for(__typeof((x).rbegin()) it=(x.rbegin()); it!=(x).rend(); ++it)


int n;
char inp[110];
char pre[110];
char post[110];
int totf[110];
int freq[110][110];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    cin.sync();

    int k, cost;
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        clr(freq);
        clr(totf);
        bool match = true;

        //get input and preprocess
        scanf("%d ", &n);
        REP(i, 0, n)
        {
            gets(inp);
            if(!match) continue;

            k = -1;
            for(int j = 0; inp[j]; ++j)
            {
                if(k < 0 || post[k] != inp[j])
                    post[++k] = inp[j];

                ++freq[i][k];
                ++totf[k];
            }
            post[++k] = 0;

            if(i == 0) strcpy(pre, post);
            else if(strcmp(pre, post)) match = false;
        }

        //calculate cost
        cost = 0;
        if(match)
        {
            REP(i, 0, k)
            {
                int avg = totf[i] / n;
                REP(j, 0, n)
                {
                    cost += abs(freq[j][i] - avg);
                }
            }
        }

        printf("Case #%d: ", cas++);
        if(match)
            printf("%d\n", cost);
        else
            puts("Fegla Won");
    }

    return 0;
}

