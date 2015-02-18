#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define div3(year) (!((osum(year)+esum(year))%3))
#define div5(year,len) (year[len-1]=='0' || year[len-1]=='5')
#define div4(year,len) (!((10*year[len-2]+year[len-1]-11*'0')%4))
#define div11(year) (osum(year)==esum(year))
#define div100(year,len) (year[len-1]=='0' && year[len-2]=='0')

#define div15(year,len) (div5(year,len) && div3(year))
#define div55(year,len) (div5(year,len) && div11(year))
#define div400(year,len) (div100(year,len) && div4(year,len-2))


int main()
{
    char year[5000];
    register leap, hulu, bulu,len,nl=0;

    while(scanf("%s",&year)==1)
    {
        if(nl>0) puts("");
        len = strlen(year);
        if(len<4) continue;

        leap = isleap(year,len);
        hulu = div15(year,len);
        bulu = leap && div55(year,len);

        if(leap) puts("This is leap year.");
        if(hulu) puts("This is huluculu festival year.");
        if(bulu) puts("This is bulukulu festival year.");
        if(!leap && !hulu && !bulu) puts("This is an ordinary year.");
        fflush(stdin);
        nl=1;
    }
    return 0;
}

int isleap(char *year, register len)
{
    if(div4(year,len))
        if(div100(year,len))
            return div400(year,len);
        else return 1;
    else return 0;
}

int esum(char *year)
{
    register i,s=year[0]-'0';
    for(i=2; year[i-1]!=0 && year[i]!=0; i+=2) s+=(year[i]-'0');
    return s;
}
int osum(char *year)
{
    register i,s=0;
    for(i=1; year[i-1]!=0 && year[i]!=0; i+=2) s+=(year[i]-'0');
    return s;
}
