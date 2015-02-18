#include <stdio.h>
#include <string.h>

char inp1[150], inp2[150];
char data[][4] = {"0000","1111","6248","1397","6464","5555","6666", "1793","6842","1919"};

int main()
{
    int a,b,l;
    while(scanf(" %s %s", inp1, inp2)!=EOF &&
          (inp1[1] || inp1[0]!='0') || (inp2[1] || inp2[0]!='0'))
    {

        l = strlen(inp2);
        a = inp1[strlen(inp1)-1]-'0';
        b = inp2[l-1] - '0';

        if(l==1)
        {
            if(b) printf("%c\n",data[a][b&3]);
            else printf("1\n");
        }
        else
        {
            b += (inp2[l-2]-'0')*10;
            printf("%c\n",data[a][b&3]);
        }
    }

    return 0;
}
