#include <stdio.h>

void toRoman(char *inp);
void toArabic(char *inp);

char res[25];
char inp[25];

const char roman[]="IVXLCDM";
const int arabic[]= {1,5,10,50,100,500,1000,5000};
int len=6;

int main()
{
    while(scanf("%s",inp)!=EOF)
    {
        if(inp[0]>='0' && inp[0]<='9') toRoman(inp);
        else toArabic(inp);
    }
    return 0;
}

void toRoman(char *inp)
{
    int n;
    sscanf(inp,"%d",&n);
    register int i,j,k,d,m,ck,cd;
    for(i=len,k=0; i>=0; i--)
    {
        if(arabic[i]>n) continue;
        m=i%2;
        ck=n+arabic[i-m];
        if(i<len && ck>=arabic[i+1])
            res[k++]=(roman[i-m]), n=ck, i++;
        while(n>=arabic[i])
            res[k++]=(roman[i]), n-=arabic[i];
    }
    res[k]='\0';
    puts(res);
    return;
}

void toArabic(char *inp)
{
    register int n,t,i,j;
    for(i=0,n=0,t=len;inp[i]!='\0';i++,t=j)
    {
        for(j=len;inp[i]!=roman[j];j--);
        if(t<j) n-=arabic[t]*2;
        n+=arabic[j];
    }
    printf("%d\n",n);
    return;
}
