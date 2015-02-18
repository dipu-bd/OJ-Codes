#include <stdio.h>
#include <string.h>

int isPalin(const char *num)
{
    int len,i,ib;
    len=strlen(num)-1;
    for(i=0,ib=len; i<=len/2; i++,ib--)
        if(num[i]!=num[ib]) return 0;
    return 1;
}

int main()
{
    int loop,m,n,i,j,a,b,c,t,sc;
    char num[30], inum[30];


    scanf("%d",&loop);
    for(n=0; n<loop; n++)
    {
        scanf("%s",&num);
        for(sc=0;!isPalin(num);sc++)
        {
            m=strlen(num); t=0;
            memset(&inum,'0',29);
            for(i=0,j=m-1;i<m;i++,j--)
            {
                a=num[i]-'0';
                b=num[j]-'0';
                c=a+b+t;
                t=c/10;
                inum[j+1]=(c-t*10)+'0';
            }
            inum[0]=t+'0';
            inum[m+1]='\0';
            for(i=0;inum[i]=='0';i++);
            strcpy(num,strchr(inum,inum[i]));
        }
        printf("%d %s\n",sc,num);
    }

    return 0;
}
