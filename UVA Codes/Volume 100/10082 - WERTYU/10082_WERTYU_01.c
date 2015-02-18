#include <stdio.h>
#include <string.h>

int main()
{
    const char *set="`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";
    int i,j,p;
    char a[2],inp;
    memset(a,'\0',2);
    while((inp=getchar())!=EOF)
    {
        if(inp==' ' || inp=='\n')
            putchar(inp);
        else
        {
            a[0]=inp;
            p=strcspn(set,a);
            putchar(set[p-1]);
        }
    }

    return 0;
}
