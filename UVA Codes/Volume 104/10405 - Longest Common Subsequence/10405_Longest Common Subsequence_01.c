#include <stdio.h>
#include <string.h>

#define SIZE 1010

int sequence(char *a, char *b)
{
    char *c, *t;
    int i,l,j,m;

    for(m=i=0; a[i]; ++i)
    {
        for(l=0,j=i,t=b; a[j]; ++j)
            if((c=strchr(t, a[j]))) ++l, t=c;

        if(l>m) m=l;
    }

    for(i=0; b[i]; ++i)
    {
        for(l=0,j=i,t=a; b[j]; ++j)
            if((c=strchr(t, b[j]))) ++l, t=c;

        if(l>m) m=l;
    }

    return m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("10405_Longest Common Subsequence_01.inp","r",stdin);
#endif

    char str1[SIZE], str2[SIZE];

    while(gets(str1) && gets(str2))
        printf("%d\n", sequence(str1, str2));


    return 0;
}
