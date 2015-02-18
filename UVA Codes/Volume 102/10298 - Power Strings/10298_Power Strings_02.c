#include <stdio.h>

#define MAX 1000000

char inp[MAX];

int main()
{
    char b;
    int i,p,q,sl,cl=1,count;
    while(gets(inp) && inp[0]!='.')
    {
        sl=strlen(inp);

        while(cl<=sl)
        {
            for(i=cl, count=1; i<sl; i+=cl)
            {
                q=b= 0, p=i;
                while(q<cl)
                    if(inp[q]!=inp[p])
                    { b=1; break;}
                    else ++q, ++p;

                if(b) break;
                ++count;
            }

            cl=1+i;
        }

        printf("%d\n", count);
        cl = 1;
    }

    return 0;
}
