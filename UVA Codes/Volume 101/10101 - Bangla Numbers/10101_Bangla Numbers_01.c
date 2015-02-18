#include <stdio.h>
#include <string.h>

char inp[20];
char show(int i, int j);

int main()
{
    int t;
    for(t=1; scanf(" %s", inp)!=EOF; ++t)
    {
        printf("%4d.", t);
        if(!show(0, strlen(inp)))
            printf(" 0");

        putchar('\n');
    }

    return 0;
}

/* recursive function */
char show(int i, int j)
{
    switch(j-i)
    {
    case 1:
        if(inp[i]!='0')
            return printf(" %c", inp[i]);
        return 0;

    case 2:
        if(inp[i]!='0' || inp[i+1]!='0')
        {
            putchar(' ');
            if(inp[i]!='0') putchar(inp[i]);
            putchar(inp[i+1]);
            return 1;
        }
        return 0;

    case 3:
        if(inp[i]!='0')
        {
            printf(" %c shata", inp[i]);
            show(i+1,j);
            return 1;
        }
        return show(i+1, j);

    case 4:
        if(inp[i]!='0')
        {
            printf(" %c hajar", inp[i]);
            show(i+1,j);
            return 1;
        }
        return show(i+1, j);

    case 5:
        if(inp[i]!='0' || inp[i+1]!='0')
        {
            putchar(' ');
            if(inp[i]!='0') putchar(inp[i]);
            putchar(inp[i+1]);
            printf(" hajar");
            show(i+2,j);
            return 1;
        }
        return show(i+2, j);

    case 6:
        if(inp[i]!='0')
        {
            printf(" %c lakh", inp[i]);
            show(i+1,j);
            return 1;
        }
        return show(i+1, j);

    case 7:
        if(inp[i]!='0' || inp[i+1]!='0')
        {
            putchar(' ');
            if(inp[i]!='0') putchar(inp[i]);
            putchar(inp[i+1]);
            printf(" lakh");
            show(i+2,j);
            return 1;
        }
        return show(i+2, j);

    default :
        if(show(i, j-7))
        {
            printf(" kuti");
            show(j-7, j);
            return 1;
        }
        return show(j-7, j);
    }
}
