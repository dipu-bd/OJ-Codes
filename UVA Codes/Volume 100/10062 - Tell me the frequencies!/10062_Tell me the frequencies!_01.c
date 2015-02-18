#include <stdio.h>

char inp[1000][1010];
int main()
{
    const int len=128-32,lim=32;
    int dc[len];
    register int max,i,j,k,l,p=0;
    char c=inp[k][i];

    for(i=0,l=0; (c=getchar())!=EOF; i++)
    {
        if(c=='\n')
        {
            inp[l][i]='\0';
            i=-1;
            l++;
        }
        else inp[l][i]=c;
    }

    for(k=0; k<l; k++)
    {
        for(i=0,max=0; i<len; i++) dc[i]=0;
        for(i=0; inp[k][i]!='\0'; i++)
        {
            c=inp[k][i];
            if(c>=32 && c<=127)
                if(++dc[c-lim]>max)
                    max=dc[c-lim];
        }
        for(i=1; i<=max; i++)
            for(j=len-1; j>=0; j--)
                if(dc[j]==i)
                    printf("%d %d\n",j+lim,dc[j]);

        if(k!=l-1) printf("\n");
    }
    return 0;
}
