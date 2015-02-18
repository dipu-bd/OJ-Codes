#include <stdio.h>

int main()
{
    unsigned int n,s,m,i,l;
    l = 8*sizeof(int);
    char b[l+2];
    while(scanf("%u",&n)==1 && n>0)
    {
        m = 1<<(l-1);
        for(s=i=0; m>0; m>>=1, ++i)
        {
            if (m&n) ++s, b[i]='1';
            else b[i] = '0';
        }
        b[i]=0;
        for(i=0;b[i]=='0';++i);
        printf("The parity of %s is %u (mod 2).\n",b+i,s);
    }
    return 0;
}
