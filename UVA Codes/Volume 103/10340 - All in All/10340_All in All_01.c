#include <stdio.h>

char s[1000],t[100000];

int main()
{
    register int i,j;
    while(scanf("%s %[^\n]",s,t)!=EOF)
    {
        for(i=0,j=0;t[i]!='\0' && s[j]!='\0';i++)
            if(t[i]==s[j]) j++;
        if(s[j]=='\0')
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
