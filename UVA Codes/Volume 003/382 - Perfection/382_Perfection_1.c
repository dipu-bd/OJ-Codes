#include <stdio.h>
#include <math.h>

void printType(int);

int main()
{
    int n;
    printf("PERFECTION OUTPUT\n");
    while(scanf(" %d",&n)==1 && n!=0) printType(n);
    printf("END OF OUTPUT\n");
    return 0;
}

void printType(int n)
{
    register i,m,d,sum;
    m=sqrt(n);
    for(i=2, sum=1, d=n/i; sum<n && i<=m; i++, d=n/i)
        if(n==d*i) sum+= i +((i==d)?0:d);
    if(n>sum || n==1)
        printf("%5d  DEFICIENT",n);
    else if(n==sum)
        printf("%5d  PERFECT",n);
    else
        printf("%5d  ABUNDANT",n);
    printf("\n");
    return;
}
