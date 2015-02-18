#include <stdio.h>

int main()
{
    int count=0, i,j,l;
    int res[10000];

    while(1)
    {

        char inp[1000];
        l=0;
        while((inp[l]=getchar())!='\n')
            if(inp[l]!='.' && inp[l]!=',' && inp[l]!='!'
                    && inp[l]!='?' && inp[l]!=' ') ++l;

        if(inp[0]=='D'&&inp[1]=='O'&&inp[2]=='N'&&inp[3]=='E') break;

        inp[l--]='\0';
        int flag=1;
        for(i=0,j=l; i<=l/2; ++i,--j)
        {
            char a=inp[i], b=inp[j];
            if(a>='A' && a<='Z') a+='a'-'A';
            if(b>='A' && b<='Z') b+='a'-'A';
            if(a != b)
            {
                flag=0;
                break;
            }
        }

        res[count++]=flag;
    }

    for(i=0; i<count; i++)
    {
        if(res[i])
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }

    return 0;
}
