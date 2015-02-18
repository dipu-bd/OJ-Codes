#include <stdio.h>
#include <string.h>

#define SIZE 1000010
char data[SIZE];

int main()
{
    int n, a,b,c, i,l;
    for(c=1; scanf(" %[01]", data)!=EOF; ++c)
    {
        l = strlen(data);
        if(!l) return 0;

        scanf("%d ", &n);
        printf("Case %d:\n",c);

        while(n--)
        {
            scanf("%d %d ", &a, &b);
            if(a>b) a^=b^=a^=b;

            if(a>l) { puts("No"); continue;}
            if(b>l) b=l;

            for(i=a; i<b; ++i)
                if(data[i]!=data[b]) break;

            if(i<b) puts("No");
            else puts("Yes");
        }
    }

    return 0;
}

