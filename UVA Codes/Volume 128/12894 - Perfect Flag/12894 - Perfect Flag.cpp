/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 ===================================*/
#include <bits/stdc++.h>
int test, cas = 1;

int xa, ya, xb, yb, cx, cy, r;

bool isvalid()
{
    int l = abs(xb - xa), w = abs(yb - ya);
    if(6 * l != 10 * w) return 0;
    if(l != 5 * r) return 0;
    if(2 * (cy - ya) != w) return 0;
    if(20 * (cx - xa) != 9 * l) return 0;

    return 1;
}

int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf("%d %d %d %d %d %d %d", &xa, &ya, &xb, &yb, &cx, &cy, &r);

        if(isvalid())
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }

    return 0;
}
