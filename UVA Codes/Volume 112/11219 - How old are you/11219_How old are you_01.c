#include <stdio.h>

const int month[]= {31,28,31,30,31,30,31,31,30,31,30,31};
int getIntTime(const int d,const int m,const int y)
{
    int i,val=0;
    for(i=0; i<m; i++) val+=month[i];
    val+=365*y;
    val+=d;
    if(y%4==0 && m>2) val++;
    return val;
}

int main()
{
    int T=0,n,date[3],now,back,diff;
    scanf("%d",&T);

    for(n=0; n<T; n++)
    {
        scanf("%d/%d/%d",&date[0],&date[1],&date[2]);
        now=getIntTime(date[0],date[1],date[2]);
        scanf("%d/%d/%d",&date[0],&date[1],&date[2]);
        back=getIntTime(date[0],date[1],date[2]);

        diff=(now-back)/365;

        if(now<back) printf("Case #%d: Invalid birth date",n+1);
        else if(diff>130) printf("Case #%d: Check birth date",n+1);
        else printf("Case #%d: %d",n+1,diff);
        printf("\n");
    }

    return 0;

}

