#include <stdio.h>

#define SIZE 100000

char line[SIZE];

int main()
{
    int l,i,j;

    while(gets(line))
    {
        l = strlen(line);

        for(i=l-1; i>=0; --i)
            if(line[i]=='[')
            {
                for(j=i+1; j<l && line[j]; ++j)
                    if(line[j]==']') break;
                    else putchar(line[j]);
                line[i] = 0;
            }

        for(i=0; i<l; ++i)
        {
            while(i<l && line[i]&& line[i]!=']')
                putchar(line[i++]);

            while(line[i]!=']' && i<l) ++i;
        }

        putchar('\n');
    }

    return 0;
}
