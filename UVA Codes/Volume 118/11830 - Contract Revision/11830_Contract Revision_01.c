#include <stdio.h>
int main()
{
    char n, i,j;
    char digits[120], out[120];
    while(scanf(" %c",&n)!=EOF)
    {
        scanf(" %[0-9]", digits);

        if(n=='0' && digits[0]=='0' && !digits[1]) break;

        for(i=j=0; digits[i]; ++i)
            if(digits[i]!=n) out[j++] = digits[i];

        for(i=out[j]=0; out[i]=='0' && i<j; ++i);

        if(i==j) puts("0");
        else puts(out+i);
    }

    return 0;
}
