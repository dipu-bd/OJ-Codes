#include <stdio.h>

int dec(int m)
{
    int count=0;
    do
    {
        if(m%2 == 1) count++;
        m /= 2;
    } while(m!=0);
    return count;
}

int hexa(int m)
{
    int num;
    char hex[20];
    sprintf(hex,"%d",m);
    sscanf(hex,"%x",&num);
    return dec(num);
}

int  main()
{
    int a,b,n,m,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&m);
        a = dec(m);
        b = hexa(m);
        printf("%d %d\n",a,b);
    }

    return 0;
}
