#include <stdio.h>

int main()
{
    char inp[1010];
    int i,odd,even;
    while(1)
    {
        gets(inp);
        if(inp[0]=='0'&&inp[1]=='\0') break;

        for(i=0,odd=0,even=0; inp[i]!='\0'; i++)
        {
            if(inp[i]<'0'||inp[i]>'9') continue;
            if(i%2)
                odd+=inp[i]-'0';
            else
                even+=inp[i]-'0';
        }

        if((even-odd)%11)
            printf("%s is not a multiple of 11.",inp);
        else
            printf("%s is a multiple of 11.",inp);
        printf("\n");
    }

    return 0;
}
