#include <stdio.h>
#include <ctype.h>

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("11878_Homework Checker_01.inp","r",stdin);
    #endif

    char p, c;
    int n, a,b,r, q;

    for(n=0; scanf("%d%c%d=",&a,&p,&b)!=EOF; )
    {
        c = getchar();
        if(c=='?' ) continue;
        fseek(stdin,-1,SEEK_CUR);
        scanf("%d", &r);
        q = (p=='+')? a+b : a-b;
        if(r == q) ++n;
    }

    printf("%d\n",n);

    return 0;
}
