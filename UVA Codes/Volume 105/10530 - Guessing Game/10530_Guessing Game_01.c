#include <stdio.h>

#define MAX 10

struct
{
    unsigned char n : 4;
    unsigned char f : 1;
} guess[MAX];

void set(char n, int i, char *t)
{
    guess[i].n = n;
    guess[i].f = (*t=='h');
}

char ishonest(int n, int lim)
{
    while(lim--)
    {
        if(guess[lim].f)
        {
            if(n >= guess[lim].n) return 0;
        }
        else
        {
            if(n <= guess[lim].n) return 0;
        }
    }

    return 1;
}

int main()
{
    char t[15];
    int n, i=0;

    while(scanf("%d",&n)!=EOF && n>0)
    {
        scanf(" %[^\n]", t);
        if(t[0]=='t') set(n, i++, t+4);
        else
        {
            if(ishonest(n, i))
                puts("Stan may be honest");
            else
                puts("Stan is dishonest");
            i=0;
        }
    }
    return 0;
}
