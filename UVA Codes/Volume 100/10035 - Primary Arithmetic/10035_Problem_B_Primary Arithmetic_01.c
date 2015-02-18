#include <stdio.h>

int main()
{
    while(1)
    {
        long long int num1,num2;
        scanf("%lld %lld",&num1,&num2);
        if(num1==0 && num2==0) break;

        int i,mt=1,t=0,count=0;
        for(i=25; i>0; i--)
        {
            int a,b,c;
            a = (num1%(mt*10)-num1%(mt))/mt;
            b = (num2%(mt*10)-num2%(mt))/mt;
            mt*=10;

            c=a+b+t;
            t=(c>=10);

            if(t) count++;
        }

        if(count==0) printf("No carry operation.\n");
        else if(count==1) printf("1 carry operation.\n");
        else printf("%d carry operations.\n",count);

    }

    return 0;
}
