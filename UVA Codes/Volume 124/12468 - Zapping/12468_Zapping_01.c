#include <stdio.h>
#include <math.h>

int main()
{
    int f,t;
    register r;
    while(scanf("%d %d",&f,&t)==2 && f>-1 && t>-1)
    {
        r = abs(f-t);
        if(r>50) r = 100-r;
        printf("%d\n",r);
    }
    return 0;
}
