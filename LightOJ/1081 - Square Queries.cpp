/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <stdio.h>
#include <iostream>
using namespace std;
//always useful
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREP(i, a, n) for(int i = a; i > n; --i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)
#define sf2(a, b) scanf("%d %d", &a, &b)
#define sf3(a, b, c) scanf("%d %d %d", &a, &b, &c);
#define sf4(a, b, c, d) scanf("%d %d %d %d", &a, &b, &c, &d);
/*------------------------------------------------------------------------------------*/

const int oo = 1 << 30;
const int mod = 1000000007;

int test, cas = 1;

int mat[505][505];
int tree[4000010];
int x1, y1, x2, y2;

void build(int nod, int xb, int yb, int xe, int ye)
{
    if(xb > xe || yb > ye)
    {
        tree[nod] = 0;
        return;
    }
    if(xb == xe && yb == ye)
    {
        tree[nod] = mat[xb][yb];
        return;
    }

    int nc1 = (nod << 2);
    int nc2 = (nod << 2) + 1;
    int nc3 = (nod << 2) + 2;
    int nc4 = (nod << 2) + 3;
    int xm = (xb + xe) >> 1;
    int ym = (yb + ye) >> 1;

    build(nc1, xb, yb, xm, ym);
    build(nc2, xm + 1, yb, xe, ym);
    build(nc3, xb, ym + 1, xm, ye);
    build(nc4, xm + 1, ym + 1, xe, ye);

    tree[nod] = max(max(tree[nc1], tree[nc2]), max(tree[nc3], tree[nc4]));
}

int query(int nod, int xb, int yb, int xe, int ye)
{
    if(x1 <= xb && xe <= x2 && y1 <= yb && ye <= y2)
    {
        return tree[nod];
    }

    int nc1 = (nod << 2);
    int nc2 = (nod << 2) + 1;
    int nc3 = (nod << 2) + 2;
    int nc4 = (nod << 2) + 3;
    int xm = (xb + xe) >> 1;
    int ym = (yb + ye) >> 1;

    int res = 0;
    if(x1 <= xm && y1 <= ym)
        res = max(res, query(nc1, xb, yb, xm, ym));
    if(x2 > xm && y1 <= ym)
        res = max(res, query(nc2, xm + 1, yb, xe, ym));
    if(x1 <= xm && y2 > ym)
        res = max(res, query(nc3, xb, ym + 1, xm, ye));
    if(x2 > xm && y2 > ym)
        res = max(res, query(nc4, xm + 1, ym + 1, xe, ye));
    return res;
}

int main()
{
    int n, q, x, y, s;

    sf1(test);
    while(test--)
    {
        scanf("%d %d", &n, &q);
        REPE(i, 1, n)
        REPE(j, 1, n)
        scanf("%d", mat[i] + j);

        build(1, 1, 1, n, n);

        printf("Case %d:\n", cas++);
        REP(i, 0, q)
        {
            scanf("%d %d %d", &x, &y, &s);
            x1 = x, y1 = y;
            x2 = x + s - 1;
            y2 = y + s - 1;
            int res = query(1, 1, 1, n, n);
            printf("%d\n", res);
        }
    }

    return 0;
}
