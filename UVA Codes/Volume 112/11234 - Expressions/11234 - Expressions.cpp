/*==================================
 Author : Sudipto Chandra (Dipu)
 Email  : dipu.sudipta@gmail.com
 University : SUST
 ===================================*/
#include <bits/stdc++.h>
using namespace std;

int test, cas = 1;

char inp[10010];
vector<string> level;

int build(int p, int h)
{
    if(level.size() == h)
    {
        level.push_back("");
    }

    level[h].push_back(inp[p]);
    if(islower(inp[p])) return p;

    p = build(p - 1, h + 1);
    p = build(p - 1, h + 1);

    return p;
}

int main()
{
    scanf("%d", &test);
    while(test--)
    {
        scanf(" %s", inp);
        level.clear();
        build(strlen(inp) - 1, 0);
        for(int i = level.size() - 1; i >= 0; --i)
        {
            printf(level[i].data());
        }
        putchar('\n');
    }

    return 0;
}
