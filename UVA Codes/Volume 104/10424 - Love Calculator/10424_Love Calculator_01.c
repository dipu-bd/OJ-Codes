#include <stdio.h>
#include <ctype.h>

float loveCalc(int nam1, int nam2);
int sum(int num);

int main()
{
    char inp;
    int flag=0,nam1=0,nam2=0;
    while((inp=toupper(getchar()))!=EOF)
    {
        if(inp>='A' && inp<='Z')
        {
            if(flag) nam2+=inp-'A'+1;
            else nam1+=inp-'A'+1;
        }

        if(inp=='\n')
        {
            if(flag && nam1>0 && nam2>0)
            {
                printf("%.2lf %%\n",loveCalc(nam1,nam2));
                flag=0;
                nam1=0;
                nam2=0;
            }
            else if(nam1>0) flag=1;
        }
    }
    return 0;
}

float loveCalc(int nam1, int nam2)
{
    int a,b;
    float res;
    a=sum(nam1);
    b=sum(nam2);
    if(a>b) return (float)(b*100)/a;
    else return (float)(a*100)/b;
}

int sum(int num)
{
    if(num<10) return num;
    num -= 9*(num/100 + num/10);
    return sum(num);
}
