#include <stdio.h>

int count=0;
int ismulti(char *inp);

int main()
{
    char inp[1010];
    register int res;
    while(scanf(" %[^\n]",inp)!=EOF)
    {
        if(inp[0]=='0' && inp[1]==0) break;
        count = 0;
        res = ismulti(inp);
        if(res>=0)
            printf("%s is a multiple of 9 and has 9-degree %d.\n",inp,res);
        else
            printf("%s is not a multiple of 9.\n");
    }
    return 0;
}

int ismulti(char *inp)
{
    register int i,sum;
    for(i=0,sum=0; inp[i]!=0; i++) sum+=inp[i]-'0';
    ++count;

    if(sum<9 || sum!=(sum/9)*9) return -1;
    if(sum>9)
    {
        char tmp[30];
        sprintf(tmp,"%d",sum);
        return ismulti(tmp);
    }
    return count;
}

