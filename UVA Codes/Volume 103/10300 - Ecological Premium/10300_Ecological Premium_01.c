#include <stdio.h>

int main()
{
    int tc, f, sz, ani, ef, res;
    scanf("%d",&tc);
    while(tc--)
    {
        scanf("%d",&f);
        res = 0;
        while(f--)
        {
            scanf("%d %d %d",&sz, &ani, &ef);
            res += sz*ef;
        }
        printf("%d\n",res);
    }
    return 0;
}
