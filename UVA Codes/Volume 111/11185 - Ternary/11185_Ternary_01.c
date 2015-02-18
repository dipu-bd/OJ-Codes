#include <stdio.h>
#include <stdlib.h>

void ternary(register d)
{
    char *res = calloc(100,sizeof(int));

    register a,i=80;
    if(d==0) res[i--]='0';
    for(a=d/3; d>0; d=a, a=d/3)
        res[i--] = d-a*3 + '0';
    puts(res+i+1);

    free(res);
    return;
}

int main()
{
    int d;
    while(scanf("%d",&d)==1 && d>=0)
        ternary(d);
    return 0;
}
