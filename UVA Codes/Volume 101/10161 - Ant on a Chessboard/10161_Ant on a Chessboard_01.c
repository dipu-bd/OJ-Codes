#include<stdio.h>
#include<math.h>

#define PRINT(i,j) printf("%d %d\n",i,j)

int main()
{
    int n,i,j,k;
    while(scanf("%d",&n)==1 && n>0)
    {
        i = ceil(sqrt(n));
        j = i*i-i+1 - n;
        k = (j<0)? i+j : i-j;

        if(i%2)
            (j>0) ? PRINT(i,k) : PRINT(k,i);
        else
            (j<0) ? PRINT(i,k) : PRINT(k,i);
    }
    return 0;
}
