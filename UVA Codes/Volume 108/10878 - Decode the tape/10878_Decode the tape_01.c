#include <stdio.h>

char line[12];

int main()
{
    gets(line);
    while(gets(line) && line[0]!='_') put();
    gets(line);

    return 0;
}

void put()
{
    char i, c = 0;
    unsigned char m = 128;

    for(i=0; line[i]; ++i)
        if(line[i]=='o') c |= m, m>>=1;
        else if(line[i]==' ') m >>=1;

    putchar(c);
}
