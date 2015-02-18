#include <stdio.h>
#include <stdlib.h>

int p[4];

int compare(const int *a, const int *b)
{
    return (*a) - (*b);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d %d %d %d", p, p+1, p+2, p+3);
            qsort(p, 4, sizeof(int), compare);

            if((p[0] + p[1] + p[2]) > p[3])
                if((p[0]==p[1]) && (p[2]==p[3]))
                    if(p[1] == p[2]) puts("square");
                    else puts("rectangle");
                else puts("quadrangle");
            else puts("banana");
        }
    }

    return 0;
}
