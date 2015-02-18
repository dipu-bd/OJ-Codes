#include <stdio.h>

int main()
{
    int i,c,s,t;
    for(i=1,c=0; c<1500; ++i)
    {
        t = i;
        for(s=t/2; t>1 && t==s*2; t=s,s=t/2);
        for(s=t/3; t>1 && t==s*3; t=s,s=t/3);
        for(s=t/5; t>1 && t==s*5; t=s,s=t/5);
        if(t<2) c++;
    }

    printf("The %d'th ugly number is %d.\n",c,i-1);

    return 0;
}

