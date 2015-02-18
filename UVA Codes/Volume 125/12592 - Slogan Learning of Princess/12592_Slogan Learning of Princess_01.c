#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char part1[105];
    char part2[105];
} Slogan;

char input[105];
Slogan slogan[20];

int compare(const char *a, const Slogan *b)
{
    return strcmp(a, b->part1);
}

int main()
{
    int n,r, i,j;

    while(scanf("%d", &n)!=EOF)
    {
        for(i=0; i<n; ++i)
        {
            scanf(" %[^\n]", (slogan+i)->part1);
            scanf(" %[^\n]", (slogan+i)->part2);
        }

        scanf("%d",&r);
        for(i=0; i<r; ++i)
        {
            scanf(" %[^\n]", input);

            for(j=0; j<n; ++j)
                if(!strcmp(input, (slogan+j)->part1))
                {
                    puts((slogan+j)->part2);
                    break;
                }
        }
    }

    return 0;
}
