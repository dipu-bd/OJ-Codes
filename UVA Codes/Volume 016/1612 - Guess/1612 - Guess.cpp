/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
//C headers
#include <stdio.h>
//always useful
#define clr(a) memset(a, 0, sizeof(a))
#define REP(i, a, n) for(int i = a; i < n; ++i)
#define REPE(i, a, n) for(int i = a; i <= n; ++i)
#define RREPE(i, a, n) for(int i = a; i >= n; --i)
//io
#define sf scanf
#define pf printf
#define sf1(a) scanf("%d", &a)

int test, cas = 1;

#define SIZ 16400
int pr[SIZ][8];

inline void swap(int& i, int& j)
{
    int a = i;
    i = j;
    j = a;
}

int main()
{
    int n, x;
    int a1, b1, c1, a2, b2, c2;
    while(sf1(n) == 1 && n)
    {
        REPE(i, 1, n)
        {
            scanf("%d.%d %d.%d %d.%d", &a1, &a2, &b1, &b2, &c1, &c2);
            int p = (int)(a1 * 100 + a2);
            int q = (int)(b1 * 100 + b2);
            int r = (int)(c1 * 100 + c2);
            //sort
            if(p > r) swap(p, r);
            if(q > r) swap(q, r);
            if(p > q) swap(p, q);
            //p < q < r
            pr[i][0] = 0;
            pr[i][1] = p;
            pr[i][2] = q;
            pr[i][3] = r;
            pr[i][4] = p + q;
            pr[i][5] = p + r;
            pr[i][6] = q + r;
            pr[i][7] = p + q + r;
            if(pr[i][3] > pr[i][4]) swap(pr[i][3], pr[i][4]);
        }

        int mx, p = -1;
        bool impos = 0;
        while(n--)
        {
            sf1(x);
            if(impos) continue;

            if(p == -1)
            {
                mx = pr[x][7];
            }
            else
            {
                if(p < x)
                {
                    // (cur <= mx)
                    RREPE(i, 7, 0)
                    {
                        if(pr[x][i] <= mx)
                        {
                            mx = pr[x][i];
                            break;
                        }
                    }
                }
                else // p > x
                {
                    // (cur < mx)
                    impos = 1;
                    RREPE(i, 7, 0)
                    {
                        if(pr[x][i] < mx)
                        {
                            mx = pr[x][i];
                            impos = 0;
                            break;
                        }
                    }
                }
            }
            p = x;
        }

        //show result
        if(impos)
        {
            printf("Case %d: No solution\n", cas++);
        }
        else
        {
            printf("Case %d: %d.%.2d\n", cas++, mx / 100, mx % 100);
        }
    }

    return 0;
}
