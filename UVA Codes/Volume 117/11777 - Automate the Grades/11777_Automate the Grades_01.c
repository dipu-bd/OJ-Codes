#include <stdio.h>

int main()
{
    int i,t;
    int term1,term2,final, atten, test1,test2,test3;
    int total,cTest;

    scanf("%d",&t);
    for(i=1,total=0,cTest=0;i<=t;i++)
    {
        scanf("%d %d %d %d %d %d %d",&term1,&term2,&final,&atten,&test1,&test2,&test3);
        cTest = test1 + test2 + test3;
        cTest -= (test1<test2 && test1<test3)?test1:((test2<test3)?test2:test3);
        total = term1+term2+final+atten+cTest/2;

        printf("Case %d: ",i);
        if(total>=90) printf("A");
        else if(total>=80) printf("B");
        else if(total>=70) printf("C");
        else if(total>=60) printf("D");
        else printf("F");
        printf("\n");
    }

    return 0;
}
