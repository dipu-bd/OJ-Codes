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
#include <bitset>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<int, int> pii;
//some constants
const double PI = 2.0 * acos(0.0);
const double E = exp(1);
//always useful
#define sf scanf
#define pf printf
#define gcd(a,b) __gcd(a,b)
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
//useful with graphs
#define _a first
#define _b second
#define pb push_back
#define mp make_pair
#define _IT ::iterator
#define all(v) v.begin(), v.end()
#define ssort(v) sort(all(v))
#define loop(typ,it,v) for(typ::iterator it = v.begin(); it != v.end(); ++it)

int main()
{
    int total, last;
    unsigned int x, y;
    int up, mid, down;
    int up_seq, down_seq;
    int up_count, down_count;

    while(scanf("%u", &x) != EOF && x != 0)
    {
        total = 1, last = 0;
        up = down = mid = 0;
        up_seq = down_seq = 0;
        up_count = down_count = 0;
        while(scanf("%u", &y) != EOF)
        {
            if(y == 0)
            {
                if(up > 0) up_seq += up, up_count++;
                if(down > 0) down_seq += down, down_count++;
                break;
            }
            else if(x == y)
            {
                if(last == 1) up++;
                else if(last == -1) down++;
                else
                {
                    if(up > 0) up_seq += up, up_count++;
                    if(down > 0) down_seq += down, down_count++;
                    mid++;
                    up = down = 0;
                }
            }
            else if(x < y)
            {
                if(down > 0) down_seq += down, down_count++;
                up += mid + 1;
                mid = down = 0;
                last = 1;
            }
            else
            {
                if(up > 0) up_seq += up, up_count++;
                down += mid + 1;
                up = mid = 0;
                last = -1;
            }

            ++total;
            x = y;
        }

        printf("Nr values = %d:  ", total);

        if(up_count) printf("%lf ", (double)up_seq / up_count);
        else printf("%lf ", 0.0);

        if(down_count) printf("%lf\n", (double)down_seq / down_count);
        else printf("%lf\n", 0.0);
    }

    return 0;
}

