#include <stdio.h>
#include <string.h>

#define SIZE 30
char team[SIZE], judge[SIZE];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("11734_Big Number of Teams will Solve This_01.inp", "r", stdin);
#endif

    char c, comp;
    int t, tc, i, j, sp1, sp2;
    sscanf(gets(team), "%d ", &t);

    for(tc = 1; t--; ++tc)
    {
        i = sp1 = 0;
        while((c = getchar()) != '\n' || i==0)
        {
            if(c == ' ') ++sp1;
            else team[i++] = c;
        }
        team[i]=0;

        i = sp2 = 0;
        while((c = getchar()) != '\n' || i==0)
        {
            if(c == ' ') ++sp2;
            else judge[i++] = c;
        }
        judge[i]=0;

        comp = strcmp(team, judge);
        if(comp)
            printf("Case %d: Wrong Answer\n", tc);
        else if(sp1 == sp2)
            printf("Case %d: Yes\n", tc);
        else
            printf("Case %d: Output Format Error\n", tc);
    }

    return 0;
}

