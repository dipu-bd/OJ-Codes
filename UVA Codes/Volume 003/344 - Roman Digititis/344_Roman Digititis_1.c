#include <stdio.h>
#include <math.h>

int toRoman(int x);
int count[5];

int main()
{
    int n;
    register int i;
    while(scanf("%d",&n) && n!=0)
    {
        for(i=0;i<5;i++) count[i]=0;
        for(i=1; i<=n; i++) toRoman(i);
        printf("%d: %d i, %d v, %d x, %d l, %d c\n",n,count[0],count[1],count[2],count[3],count[4]);
    }
    return 0;
}

int toRoman(int x)
{
    register int i,j,d;
    int num[]= {1,5,10,50,100};

    for(i=4; i>=0; i--)
    {
        if(x == 4) {
            count[0]++;
            count[1]++;
            x-=4;
        }
        else if(x == 9) {
            count[0]++;
            count[2]++;
            x-=9;
        }
        else if(x>=40 && x<50) {
            count[2]++;
            count[3]++;
            x-=40;
        }
        else if(x>=90 && x<100) {
            count[2]++;
            count[4]++;
            x-=90;
        }
        else
            for(; x>=num[i]; x-=num[i],count[i]++);
    }
    return 0;
}


