#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const double EPS = 1e-10;

int main()
{
    int test, cas = 1;

    double L, W;
    double xl, xr, midl, midr;
    double vol, vl, vr;

    cin >> test;
    while(test--)
    {
        cin >> L >> W;

        xl = EPS;
        xr = min(L, W) * 0.5 - EPS;
        do
        {
            midl = .75 * xl + .25 * xr;
            midr = .25 * xl + .75 * xr;

            vl = midl * (L - 2 * midl) * (W - 2 * midl);
            vr = midr * (L - 2 * midr) * (W - 2 * midr);

            if(vl > vr)
            {
                vol = vl;
                xr = midr - EPS;
            }
            else
            {
                vol = vr;
                xl = midl + EPS;
            }
        }
        while(xr - xl > EPS);

        printf("Case %d: %.8lf\n", cas++, vol);
    }

    return 0;
}
