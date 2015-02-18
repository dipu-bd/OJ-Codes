/*============================
 /\u7h0r : 5ud!p70 ch@ndr@ d@5
 =============================*/
//C headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//cpp headers
#include <iostream>
#include <algorithm>
using namespace std;
//typedefs
typedef long long ll;
typedef pair<ll, int> pll;
//always useful
#define clr(a) memset(a, 0, sizeof(a))
#define mem(a,b) memset(a, b, sizeof(a))
#define mp make_pair
//-----------------------------------------

int maxone, maxdiff;
int start, stop, ideal;
ll save1[30][30][30][2][2][3][7];
int save2[30][30][30][2][2][3][7];

pll recur(int pos, int k = 0, int one = 0, bool imin = 1, bool imax = 1, int three = 0, int seven = 0)
{
    if(one > maxone || k > maxdiff) return mp(0LL, 0);
    if(pos == -1)
    {
        if(three == 0 && seven != 0) return mp(0LL, 1);
        return mp(0LL, 0);
    }

    ll& dp1 = save1[pos][k][one][imin][imax][three][seven];
    int& dp2 = save2[pos][k][one][imin][imax][three][seven];
    if(dp2 != -1) return mp(dp1, dp2);

    dp1 = dp2 = 0;
    int two = 1 << pos;
    char b = (imin && (start & two));
    char e = !(imax && !(stop & two));
    for(char i = b; i <= e; i++)
    {
        pll r = recur(pos - 1, // move to next position
                      k + (i != ((ideal & two) > 0)), //if i != ideal[pos] increase difference
                      one + i, //increase number of one
                      (i == b && imin), //check if minimum value is taken
                      (i == e && imax), //check if maximum value is taken
                      (three + i * two) % 3, //calc the number mod 3
                      (seven + i * two) % 7); //calc the number mod 7

        dp1 += r.first + (ll)i * r.second * two; //add sum of numbers
        dp2 += r.second; //add solution count
    }

    return mp(dp1, dp2);
}

int getlen(int a, int b)
{
    if(a == 0 && b == 0) return 0;
    return getlen(a >> 1, b >> 1) + 1;
}

int main()
{
    int test, cas = 1;

    scanf("%d", &test);
    while(test--)
    {
        int b, e, d;
        scanf("%d %d %d %d %d", &start, &stop, &maxone, &ideal, &maxdiff);

        mem(save2, -1);
        ll r = recur(getlen(stop, ideal) - 1).first;
        printf("Case %d: %lld\n", cas++, r);
    }

    return 0;
}
