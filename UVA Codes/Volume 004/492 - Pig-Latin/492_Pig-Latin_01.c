#include <stdio.h>
#include <ctype.h>

int main()
{
    char c;
    register char i=0,s=0,f=0;
    while((c=getchar())!=EOF)
    {
        if(isalpha(c))
        {
            if(!s)
            {
                f=tolower(c);
                if(f=='a'||f=='e'||f=='i'||f=='o'||f=='u') putchar(c);
                else i=1;
                s=1, f=c ;
            }
            else putchar(c);
        }
        else
        {
            if(s)
            {
                if(i) putchar(f);
                putchar('a');
                putchar('y');
                i=s=0;
            }
            putchar(c);
        }
    }
    return 0;
}
