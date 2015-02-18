#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct node
{
    bool last;
    bool visit;
    int next[10];

    int& operator [] (int i)
    {
        return next[i];
    }
};

#define MAX 100000
node par[MAX];

int main()
{
    int test, cas = 1;

    int n, siz;
    bool flag;
    char num[20];

    scanf("%d", &test);
    while(test--)
    {
        siz = 1;
        flag = true;
        memset(par, 0, sizeof(par));

        scanf("%d", &n);
        while(n--)
        {
            scanf(" %s", num);
            if(!flag) continue;

            int p = 0;
            for(int i = 0; num[i]; ++i)
            {
                if(par[p].last) { flag = false; break; }

                int t = num[i] - '0';
                if(par[p][t] == 0)
                {
                    par[p][t] = siz++;
                    par[p].visit = true;
                }

                p = par[p][t];
            }

            if(flag)
            {
                par[p].last = true;
                flag = !par[p].visit;
            }
        }

        printf("Case %d: ", cas++);
        if(flag) printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}
